#include <QDebug>
#include "ATM.h"
#include "CustomerConsole.h"
#include "CardReader.h"
#include "CashDispenser.h"
#include "EnvelopeAcceptor.h"
#include "Log.h"
#include "NetworkToBank.h"
#include "OperatorPanel.h"
#include "ReceiptPrinter.h"
#include "Money.h"
#include "Session.h"

std::exception_ptr atm::ATM::p_cancelled = nullptr;

atm::ATM::ATM(const int &a_id, const QString &a_place, const QString &a_bankName, const QString &a_bankAddress) : ATMThread()
{
    m_id = a_id;
    m_place = a_place;
    m_bankName = a_bankName;
    m_bankAddress = a_bankAddress;

    // Create objects corresponding to component parts
    // Components parts are present for the life duration of
    // the application

    mp_log = new atm::physical::Log();
    mp_cardReader = new atm::physical::CardReader(this);
    mp_cashDispenser = new atm::physical::CashDispenser(mp_log);
    mp_customerConsole = new atm::physical::CustomerConsole();
    mp_envelopeAcceptor = new atm::physical::EnvelopeAcceptor(mp_log);
    mp_networkToBank = new atm::physical::NetworkToBank(mp_log, a_bankAddress);
    mp_operatorPanel = new atm::physical::OperatorPanel(this);
    mp_receiptPrinter = new atm::physical::ReceiptPrinter();


    // Set up initial conditions when ATM first created

    m_state = OFF_STATE;
    m_switchOn = false;
    m_cardInserted = false;
    m_ATMThreadStopped = false;


    // connect own signal to own slot and hence "translate" it
    connect(this, SIGNAL(performStartupSignal()),
                   this, SLOT(performStartup()),Qt::BlockingQueuedConnection);
    connect(this, SIGNAL(customerConsoleDisplaySignal(const QString&)),
                   this, SLOT(customerConsoleDisplay(const QString&)),Qt::BlockingQueuedConnection);

    connect(this, SIGNAL(createSessionSignal()),
                   this, SLOT(createSession()));

    startATMThread();
}
atm::ATM::~ATM()
{
    delete mp_log;
    mp_log = nullptr;

    delete mp_cardReader;
    mp_cardReader = nullptr;

    delete mp_cashDispenser;
    mp_cashDispenser = nullptr;

    delete mp_customerConsole;
    mp_customerConsole = nullptr;

    delete mp_envelopeAcceptor;
    mp_envelopeAcceptor = nullptr;

    delete mp_networkToBank;
    mp_networkToBank = nullptr;

    delete mp_operatorPanel;
    mp_operatorPanel = nullptr;

    delete mp_receiptPrinter;
    mp_receiptPrinter = nullptr;

    if(ATMThread.joinable()){
        qDebug()<< "Thread joined";
        ATMThread.join();
    }
    stopATMThread();


}

void atm::ATM::run()
{


    while (!m_ATMThreadStopped)
    {
        switch (m_state) {
            case OFF_STATE :
            {
                emit customerConsoleDisplaySignal("Not currently available");
                // wait for ATM to be turned ON
                std::unique_lock<std::mutex> lock(m_mxdataMuMutex);
                try {
                    while (!m_switchOn && !m_ATMThreadStopped){ // loop to avoid spurious wakeups
                        m_conditionVariable.wait(lock,[&]{return m_switchOn || m_ATMThreadStopped;});
                    }

                } catch (std::exception const& e) {
                    qDebug()<< e.what();
                }
                if (m_switchOn) {
                   emit performStartupSignal();
                   // wait for startup process
                   qDebug()<< "statrtup finished";
                   m_state = IDLE_STATE;
                }
                break;
            }
            case IDLE_STATE :
            {

                qDebug()<< "IDLE_STATE";
                emit customerConsoleDisplaySignal("Please insert your Card");


                std::unique_lock<std::mutex> lock(m_mxdataMuMutex);
                try {
                    while (!m_cardInserted && !m_ATMThreadStopped && m_switchOn){ // loop to avoid spurious wakeups
                        m_conditionVariable.wait(lock,[&]{return m_cardInserted || !m_switchOn || m_ATMThreadStopped;});
                    }
                } catch (std::exception const& e) {
                    qDebug()<< e.what();
                }
                qDebug()<< "m_cardInserted"<<m_cardInserted;
                if (m_cardInserted) {
                    // construct session object
                    qDebug()<< "construct session Object";

                    //emit createSessionSignal();
                    mp_currentSession = new atm::Session(this);
                    m_state = SERVING_CUSTOMER_STATE;
                }
                else if (!m_switchOn){
                    qDebug()<< "ATM turned OFF";

                    performShutdown();
                    m_state = OFF_STATE;
                }
                break;
            }
            case SERVING_CUSTOMER_STATE :
            {
                qDebug()<< "SERVING_CUSTOMER_STATE";
                // The following will not return until the session has
                // completed
                mp_currentSession->performSession();


                m_state = IDLE_STATE;
                // destruct session object
                qDebug()<< "destruct session Object after session completed";
                delete mp_currentSession;
                mp_currentSession = nullptr;
                qDebug()<< "destruct Card Object after session completed";


                break;
            }
        }

    }
    // destruct session object if still exist
//    qDebug()<< "destruct session Object";
//    delete lp_currentSession;
//    lp_currentSession = nullptr;
qDebug() << "main loop thread exited";
}


void atm::ATM::customerConsoleDisplay(const QString &ar_text)
{
    mp_customerConsole->display(ar_text);


}

void atm::ATM::startATMThread()
{

        ATMThread = std::thread(&atm::ATM::run,this);
}

void atm::ATM::switchOn()
{
    {
        std::lock_guard<std::mutex> lock(m_mxdataMuMutex);
        m_switchOn = true;
    }
    m_conditionVariable.notify_one();
}

void atm::ATM::switchOff()
{
    {
        std::lock_guard<std::mutex> lock(m_mxdataMuMutex);
        m_switchOn = false;
    }
    m_conditionVariable.notify_one();
}

void atm::ATM::cardInserted()
{
    {
        std::lock_guard<std::mutex> lock(m_mxdataMuMutex);
        m_cardInserted = true;
    }
    m_conditionVariable.notify_one();

}

void atm::ATM::mainWindowClosed()
{

    stopATMThread();

}
bool atm::ATM::isATMThreadRunning()
{
    if (m_ATMThreadStopped){
        return false;
    } else {
        return true;
    }

}

void atm::ATM::stopATMThread()
{
    {
        std::lock_guard<std::mutex> lock(m_mxdataMuMutex);
        m_ATMThreadStopped = true;
    }
    m_conditionVariable.notify_one();


}

void atm::ATM::performStartup()
{


    qDebug()<< "Perform System Startup";
    banking::Money *lp_initialCash = mp_operatorPanel->getInitialCash();

//    mp_cashDispenser->setInitialCashOnATM(&l_initialCash);
//    mp_networkToBank->openConnection();

}

void atm::ATM::createSession()
{
    mp_currentSession = new atm::Session(this);
}

void atm::ATM::readCard()
{
    {
        std::lock_guard<std::mutex> lock(m_mxdataMuMutex);
        mp_card = mp_cardReader->readCard();
    }
//mp_currentSession->mp_card = getCardReader()->readCard();
//    std::lock_guard<std::mutex> lock(m_mxcardReadingFinished);
//    m_cardReadingFinished = true;
//    mp_atm->m_conditionVariable.notify_one();


}

void atm::ATM::readPIN(const QString &ar_text)
{
    try
    {
        {
            std::lock_guard<std::mutex> lock(m_mxdataMuMutex);
            m_pin = mp_customerConsole->readPIN(ar_text);
        }
    }
    catch (atm::physical::CustomerConsole::Cancelled &e) {
        qDebug()<< "ATM e.what()"<<e.what();
        p_cancelled = std::current_exception();

    }

}

banking::Card* atm::ATM::getCard() const
{
       return mp_card;

}

int atm::ATM::getPin() const
{
    return m_pin;

}

void atm::ATM::performShutdown()
{
    qDebug()<< "Perform System Shutdown";
    mp_networkToBank->closeConnection();

}

int atm::ATM::getID() const
{
    return m_id;
}

QString atm::ATM::getPlace() const
{
    return m_place;
}

QString atm::ATM::getBankName() const
{
    return m_bankName;
}

QString atm::ATM::getBankAddress() const
{
    return m_bankAddress;
}

atm::physical::CardReader* atm::ATM::getCardReader() const
{
    return mp_cardReader;
}

atm::physical::CashDispenser* atm::ATM::getCashDispenser() const
{
    return mp_cashDispenser;
}

atm::physical::CustomerConsole* atm::ATM::getCustomerConsole() const
{
    return mp_customerConsole;
}

atm::physical::EnvelopeAcceptor* atm::ATM::getEnvelopeAcceptor() const
{
    return mp_envelopeAcceptor;
}

atm::physical::Log* atm::ATM::getLog() const
{
    return mp_log;
}

atm::physical::NetworkToBank* atm::ATM::getNetworkToBank() const
{
    return mp_networkToBank;
}

atm::physical::OperatorPanel* atm::ATM::getOperatorPanel() const
{
    return mp_operatorPanel;
}

atm::physical::ReceiptPrinter* atm::ATM::getReceiptPrinter() const
{
    return mp_receiptPrinter;
}

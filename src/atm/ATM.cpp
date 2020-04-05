#include <QDebug>
#include <QThread>
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

atm::ATM::ATM(int a_id, QString a_place, QString a_bankName, QString a_bankAddress) : ATMThread()
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
    m_stopATMThread = false;

    // connect to own signal to own slot and hence "translate" it
    connect(this, SIGNAL(performStartupSignal()),
                   this, SLOT(performStartup()));
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


}

void atm::ATM::run()
{
    Session *lp_currentSession = nullptr;
    while (!m_stopATMThread)
    {
        //qDebug()<< "enter while loop";

        switch (m_state) {
            case OFF_STATE :
            {
                qDebug()<< "OFF_STATE";
                mp_customerConsole->display("Not currently available");
                std::unique_lock<std::mutex> lock(m_mxswitchOn);
                try {
                    while (!m_switchOn && !m_stopATMThread){ // loop to avoid spurious wakeups
                        m_conditionVariable.wait(lock,[this]{return m_switchOn || m_stopATMThread;});
                    }

                } catch (std::exception const& e) {
                    qDebug()<< e.what();
                }
                if (m_switchOn) {
                   emit performStartupSignal();
                   m_state = IDLE_STATE;
                }
                break;
            }
            case IDLE_STATE :
            {
                qDebug()<< "IDLE_STATE";
                mp_customerConsole->display("Please insert your Card");
                m_cardInserted = false;
                std::unique_lock<std::mutex> lock(m_mxcardInserted);
                try {
                    while (!m_cardInserted && !m_stopATMThread && m_switchOn){ // loop to avoid spurious wakeups
                        m_conditionVariable.wait(lock,[this]{return m_cardInserted || !m_switchOn || m_stopATMThread;});
                    }
                } catch (std::exception const& e) {
                    qDebug()<< e.what();
                }
                qDebug()<< "m_cardInserted"<<m_cardInserted;
                if (m_cardInserted) {
                    // construct session object
                    qDebug()<< "construct session Object";
                    lp_currentSession = new atm::Session(this);
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
                lp_currentSession->performSession();
                m_state = IDLE_STATE;
                // destruct session object
                qDebug()<< "destruct session Object after session completed";
                delete lp_currentSession;
                lp_currentSession = nullptr;
                break;
            }
        }

    }
    // destruct session object if still exist
//    qDebug()<< "destruct session Object";
//    delete lp_currentSession;
//    lp_currentSession = nullptr;
qDebug() << "loop thread exited";
}


void atm::ATM::startATMThread()
{
        ATMThread = std::thread(&atm::ATM::run,this);
}

void atm::ATM::switchOn()
{
    std::lock_guard<std::mutex> lock(m_mxswitchOn);
    m_switchOn = true;
    m_conditionVariable.notify_one();
}

void atm::ATM::switchOff()
{
    std::lock_guard<std::mutex> lock(m_mxswitchOn);
    m_switchOn = false;
    m_conditionVariable.notify_one();
}

void atm::ATM::cardInserted()
{
    std::lock_guard<std::mutex> lock(m_mxcardInserted);
    m_cardInserted = true;
    m_conditionVariable.notify_one();

}

void atm::ATM::mainWindowClosed()
{

    stopATMThread();

}

void atm::ATM::stopATMThread()
{
    m_stopATMThread = true;
    m_conditionVariable.notify_one();

}

void atm::ATM::performStartup()
{


    qDebug()<< "Perform System Startup";
    banking::Money *lp_initialCash = mp_operatorPanel->getInitialCash();

//    mp_cashDispenser->setInitialCashOnATM(&l_initialCash);
//    mp_networkToBank->openConnection();

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

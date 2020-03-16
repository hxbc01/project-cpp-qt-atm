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

atm::ATM::ATM()
{

}

atm::ATM::ATM(int a_id, QString a_place, QString a_bankName, QString a_bankAddress)
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
}

void atm::ATM::operator()()
{
    Session *lp_currentSession = nullptr;
    while (true)
    {
        switch (m_state) {
            case OFF_STATE :
            {
                mp_customerConsole->display("Not currently available");
                try {
                    std::unique_lock<std::mutex> lk(m_mxswitchOn);
                    m_cvswitchOn.wait(lk,[this]{return m_switchOn;});

                } catch (std::exception const& e) {
                    qDebug()<< e.what();
                }
                if (m_switchOn) {
                   performStartup();
                   m_state = IDLE_STATE;
                }
                break;
            }
            case IDLE_STATE :
            {
                mp_customerConsole->display("Please insert your Card");
                m_cardInserted = false;
                try {
                    std::unique_lock<std::mutex> lk(m_mxcardInserted);
                    m_cvswitchOn.wait(lk,[this]{return m_cardInserted;});
                } catch (std::exception const& e) {
                    qDebug()<< e.what();
                }
                if (m_cardInserted) {
                    lp_currentSession = new Session(this);
                    m_state = SERVING_CUSTOMER_STATE;
                }
                else if (!m_switchOn){
                    performShutdown();
                    m_state = OFF_STATE;
                }
                break;
            }
            case SERVING_CUSTOMER_STATE :
            {
                // The following will not return until the session has
                // completed
                lp_currentSession->performSession();
                m_state = IDLE_STATE;
                break;
            }
        }
    }

}

void atm::ATM::switchOn()
{
    std::lock_guard<std::mutex> lk(m_mxswitchOn);
    m_switchOn = true;
    m_cvswitchOn.notify_one();
}

void atm::ATM::switchOff()
{
    std::lock_guard<std::mutex> lk(m_mxswitchOn);
    m_switchOn = false;
    m_cvswitchOn.notify_one();
}

void atm::ATM::cardInserted()
{
    std::lock_guard<std::mutex> lk(m_mxcardInserted);
    m_cardInserted = true;
    m_cvcardInserted.notify_one();

}

void atm::ATM::performStartup()
{
    qDebug()<< "Perform System Startup";
    banking::Money *l_initialCash = mp_operatorPanel->getInitialCash();
    mp_cashDispenser->setInitialCashOnATM(*l_initialCash);
    mp_networkToBank->openConnection();

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

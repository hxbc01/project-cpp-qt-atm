#include <QDebug>
#include "ATM.h"
#include "CardReader.h"
#include "CashDispenser.h"
#include "CustomerConsole.h"
#include "EnvelopeAcceptor.h"
#include "Log.h"
#include "NetworkToBank.h"
#include "OperatorPanel.h"
#include "ReceiptPrinter.h"

atm::ATM::ATM()
{

}

atm::ATM::ATM(int id, QString a_place, QString a_bankName, QString a_bankAddress)
{
    m_id = id;
    m_place = a_place;
    m_bankName = a_bankName;
    m_bankAddress = a_bankAddress;

    // Create objects corresponding to component parts
    // Components parts are present for the life duration of
    // the application

    atm::physical::Log *mp_log = new atm::physical::Log();
    atm::physical::CardReader *mp_cardReader
            = new atm::physical::CardReader(this);
    atm::physical::CashDispenser *mp_cashDispenser
            = new atm::physical::CashDispenser(mp_log);
    atm::physical::CustomerConsole *mp_customerConsole
            = new atm::physical::CustomerConsole();
    atm::physical::EnvelopeAcceptor *mp_envelopeAcceptor
            = new atm::physical::EnvelopeAcceptor(mp_log);
    atm::physical::NetworkToBank *mp_networkToBank
            = new atm::physical::NetworkToBank(mp_log, a_bankAddress);
    atm::physical::OperatorPanel *mp_operatorPanel
            = new atm::physical::OperatorPanel(this);
    atm::physical::ReceiptPrinter *mp_receiptPrinter
            = new atm::physical::ReceiptPrinter();


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

#include <QDebug>
#include "ATM.h"

atm::ATM::ATM()
{

}

atm::ATM::ATM(int id, QString place, QString bankName, InetAddress bankAddress)
{
    m_id = id;
    m_place = place;
    m_bankName = bankName;
    m_bankAddress = bankAddress;

    // Create objects corresponding to component parts

    log = new Log();
    m_cardReader = new CardReader(this);
    m_cashDispenser = new CashDispenser(log);
    m_customerConsole = new CustomerConsole();
    m_envelopeAcceptor = new EnvelopeAcceptor(log);
    m_networkToBank = new NetworkToBank(log, bankAddress);
    m_operatorPanel = new OperatorPanel(this);
    m_receiptPrinter = new ReceiptPrinter();

    // Set up initial conditions when ATM first created

    m_state = OFF_STATE;
    m_switchOn = false;
    m_cardInserted = false;
}
atm::ATM::~ATM()
{

}

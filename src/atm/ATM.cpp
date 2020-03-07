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

atm::ATM::ATM(int id, QString place, QString bankName, InetAddress bankAddress)
{
    m_id = id;
    m_place = place;
    m_bankName = bankName;
    m_bankAddress = bankAddress;

    // Create objects corresponding to component parts
    // Components parts are present for the life duration of
    // the application

    Log *mp_log = new Log();
    CardReader *mp_cardReader = new CardReader(this);
    CashDispenser *mp_cashDispenser = new CashDispenser(mp_log);
    CustomerConsole *mp_customerConsole = new CustomerConsole();
    EnvelopeAcceptor *mp_envelopeAcceptor = new EnvelopeAcceptor(mp_log);
    NetworkToBank *mp_networkToBank = new NetworkToBank(mp_log, bankAddress);
    OperatorPanel *mp_operatorPanel = new OperatorPanel(this);
    ReceiptPrinter *mp_receiptPrinter = new ReceiptPrinter();


    // Set up initial conditions when ATM first created

    m_state = OFF_STATE;
    m_switchOn = false;
    m_cardInserted = false;
}
atm::ATM::~ATM()
{

}

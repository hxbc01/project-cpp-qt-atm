#include <QDebug>
#include "Deposit.h"

atm::transaction::Deposit::Deposit()
{

}
atm::transaction::Deposit::Deposit(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin): Transaction(ap_atm,ap_session,ap_card,a_pin)
{

}

atm::transaction::Deposit::~Deposit()
{

}

banking::Message* atm::transaction::Deposit::getTransactionChoice() //throws CustomerConsole.Cancelled
{
//    m_to = atm.getCustomerConsole().readMenuChoice(
//        "Account to deposit to",
//        AccountInformation.ACCOUNT_NAMES);

//    amount = atm.getCustomerConsole().readAmount("Amount to deposit");

//    return new Message(Message.INITIATE_DEPOSIT,
//                       card, pin, serialNumber, -1, to, amount);

}


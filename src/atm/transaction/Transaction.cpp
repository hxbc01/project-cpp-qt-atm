#include <QDebug>
#include "Transaction.h"
#include "Balances.h"

atm::transaction::Transaction::Transaction()
{

}

atm::transaction::Transaction::Transaction(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin)
{
    mp_atm = ap_atm;
    mp_session = ap_session;
    mp_card = ap_card;
    m_pin = a_pin;
    m_serialNumber = m_nextSerialNumber ++;
    mp_balances = new banking::Balances();
    m_state = GETTING_SPECIFICS_STATE;

}


atm::transaction::Transaction::~Transaction()
{
    delete mp_balances;
    mp_balances = nullptr;

}

atm::transaction::Transaction* atm::transaction::Transaction::makeTransaction(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin)
{
    int choice = mp_atm-> .getCustomerConsole().readMenuChoice(
                "Please choose transaction type", TRANSACTION_TYPES_MENU);

        switch(choice)
        {
            case 0:

                return new Withdrawal(atm, session, card, pin);

            case 1:

                return new Deposit(atm, session, card, pin);

            case 2:

                return new Transfer(atm, session, card, pin);

            case 3:

                return new Inquiry(atm, session, card, pin);

            default:

                return null;    // To keep compiler happy - should not happen!
        }


}


#include <QDebug>
#include "Receipt.h"

banking::Receipt::Receipt()
{

}
banking::Receipt::Receipt(ATM a_atm, Card a_card, Transaction a_transaction, Balances a_balances , QDateTime a_currentDate)
{
    // Heading portion of the receipt

    m_headingPortion.append(a_currentDate.currentDateTime().toString());
    m_headingPortion.append(a_atm.getBankName());
    m_headingPortion.append("ATM #" + a_atm.getID() + " " + a_atm.getPlace());
    m_headingPortion.append("CARD " + a_card.getNumber() +
                            " TRANS #" + a_transaction.getSerialNumber());

    // The constructor for each subclass will fill in the details array
    // appropriately

    // Balances portion of the receipt

    m_balancesPortion.append("TOTAL BAL: " + a_balances.getTotal().toString());
    m_balancesPortion.append("AVAILABLE: " + a_balances.getAvailable().toString());

}

banking::Receipt::~Receipt()
{

}





#include <QDebug>
#include "Receipt.h"
#include "ATM.h"
#include "Transaction.h"
#include "Card.h"
#include "Balances.h"
#include "Money.h"

banking::Receipt::Receipt()
{

}
banking::Receipt::Receipt(atm::ATM *ap_atm, Card *ap_card, atm::transaction::Transaction *ap_transaction, Balances *ap_balances, QStringList a_detailsPortion, QDateTime a_currentDate)
{
    // Heading portion of the receipt

    m_headingPortion.append(a_currentDate.currentDateTime().toString());
    m_headingPortion.append(ap_atm->getBankName());
    m_headingPortion.append("ATM #" + QString::number(ap_atm->getID()) + " " + ap_atm->getPlace());
    m_headingPortion.append("CARD " + QString::number(ap_card->getNumber()) +
                            " TRANS #" + QString::number(ap_transaction->getSerialNumber()));

    // details postion specific to each transaction
    m_detailsPortion=a_detailsPortion;
    // Balances portion of the receipt

    m_balancesPortion.append("TOTAL BAL: " + ap_balances->getTotal()->toString());
    m_balancesPortion.append("AVAILABLE: " + ap_balances->getAvailable()->toString());

    // construct the hole receipt
    m_AllReceiptPortions.append(m_headingPortion);
    m_AllReceiptPortions.append(m_detailsPortion);
    m_AllReceiptPortions.append(m_balancesPortion);
}

banking::Receipt::~Receipt()
{

}

bool banking::Receipt::hasMoreLines()
{
    return m_it != m_AllReceiptPortions.end();

}

QString banking::Receipt::getNextLine()
{

    return *m_it++;
}




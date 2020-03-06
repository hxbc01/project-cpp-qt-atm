/**
 * @file Receipt.h
 * @brief Header file of the Receipt class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef RECEIPT_H
#define RECEIPT_H
#include <QStringList>
#include <QDateTime>
#include "Balances.h"
#include "Transaction.h"
#include "Card.h"
#include "ATM.h"
/** Abstract base class for representation of a receipt to be printed.  Each
 *  specific type of transaction creates an instance of a concrete subclass
 *  of this class.
 */

namespace banking
{
class Receipt
{
    /** Default Constructor
     */
    Receipt();
    /** Constructor.  This base class constructor will create the portions of the
     *  receipt that are common to all types of transaction, and the subclass
     *  constructor will create the details portion unique to each type.
     *
     *  @param atm the ATM where the transaction was done
     *  @param card the card that was used
     *  @param transaction the Transaction object for the transaction
     *  @param balances Balances object giving final balances for account used
     */
    Receipt(ATM a_atm, Card a_card, Transaction a_transaction, Balances a_balances, QDateTime a_currentDate);
    /** Destructor
     */
    ~Receipt();
public:


protected:

    /** Transaction details portion of the receipt - specific to each type of
     *  transaction, and therefore filled in by subclasses
     */
    QStringList m_detailsPortion;

private:

    /** Heading portion of the receipt - common to all forms of receipt
     */
    QStringList m_headingPortion;
    /** Ending balances portion of the receipt - common to all forms of receipt
     */
    QStringList m_balancesPortion;
};
}

#endif // RECEIPT_H



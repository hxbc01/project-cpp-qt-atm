/**
 * @file Transaction.h
 * @brief Header file of the Transaction class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QStringList>
/** Abstract base class for classes representing the various kinds of
 *  transaction the ATM can perform
 */
namespace atm
{
class ATM;
class Session;
}
namespace banking
{
class Card;
class Balances;
class Message;
}
namespace atm
{
namespace transaction
{
class Transaction
{

public:
    /** Default Constructor
     */
    Transaction();
    /** Constructor
     *
     *  @param atm the ATM used to communicate with customer
     *  @param session the session in which this transaction is being performed
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     */
    Transaction(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin);

    /** Destructor
     */
    ~Transaction();
    /** Create a transaction of an appropriate type by asking the customer
     *  what type of transaction is desired and then returning a newly-created
     *  member of the appropriate subclass
     *
     *  @param atm the ATM used to communicate with customer
     *  @param session the session in which this transaction is being performed
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     *  @return a newly created Transaction object of the appropriate type
     *  @exception CustomerConsole.Cancelled if the customer presses cancel instead
     *         of choosing a transaction type
     */
    static Transaction* makeTransaction(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin);


    /** Peform a transaction.  This method depends on the three abstract methods
     *  that follow to perform the operations unique to each type of transaction
     *  in the appropriate way.
     *
     *  @return true if customer indicates a desire to do another transaction;
     *          false if customer does not desire to do another transaction
     *  @exception CardRetained if card was retained due to too many invalid PIN's
     */
    //->public boolean performTransaction() throws CardRetained

    /** Perform the Invalid PIN Extension - reset session pin to new value if successful
     *
     *  @return status code returned by bank from most recent re-submission
     *          of transaction
     *  @exception CustomerConsole.Cancelled if customer presses the CANCEL key
     *             instead of re-entering PIN
     *  @exception CardRetained if card was retained due to too many invalid PIN's
     */
    //->public Status performInvalidPINExtension() throws CustomerConsole.Cancelled,
                                                      //CardRetained*/

    /** Get serial number of this transaction
     *
     *  @return serial number
     */
    int getSerialNumber() const;

    /** Get specifics for the transaction from the customer - each
     *  subclass must implement this appropriately.
     *
     *  @return message to bank for initiating this transaction
     *  @exception CustomerConsole.Cancelled if customer cancelled this transaction
     */
    //->protected abstract Message getSpecificsFromCustomer() throws CustomerConsole.Cancelled;

    /** Complete an approved transaction  - each subclass must implement
     *  this appropriately.
     *
     *  @return receipt to be printed for this transaction
     *  @exception CustomerConsole.Cancelled if customer cancelled this transaction
     */
    //->protected abstract Receipt completeTransaction() throws CustomerConsole.Cancelled;


    // Local class representing card retained exception


    /** Exception that is thrown when the customer's card is retained due to too
     *  many invalid PIN entries
     */
    /*public static class CardRetained extends Exception
    {
        /** Constructor
         */
        /*public CardRetained()
        {
            super("Card retained due to too many invalid PINs");
        }
    }*/
protected:
    // Instance variables


    /** ATM to use for communication with the customer
     */
    ATM *mp_atm=nullptr;

    /** Session in which this transaction is being performed
     */
    Session *mp_session=nullptr;

    /** Customer card for the session this transaction is part of
     */
    banking::Card *mp_card=nullptr;
    /** Used to return account balances from the bank
     */
    banking::Balances *mp_balances=nullptr;
    /** Message to bank describing this transaction
     */
    banking::Message *mp_message=nullptr;

    /** PIN entered or re-entered by customer
     */
    int m_pin;

    /** Serial number of this transaction
     */
    int m_serialNumber;


private:
    /** List of available transaction types to display as a menu
     */
    static const QStringList TRANSACTION_TYPES_MENU;

    /** Next serial number - used to assign a unique serial number to
     *  each transaction
     */
    static int m_nextSerialNumber;

    /** The current state of the transaction
     */
    int m_state;

    // Possible values for state

    /** Getting specifics of the transaction from customer
     */
    static const int GETTING_SPECIFICS_STATE = 1;

    /** Sending transaction to bank
     */
    static const int SENDING_TO_BANK_STATE = 2;

    /** Performing invalid PIN extension
     */
    static const int INVALID_PIN_STATE = 3;

    /** Completing transaction
     */
    static const int COMPLETING_TRANSACTION_STATE = 4;

    /** Printing receipt
     */
    static const int PRINTING_RECEIPT_STATE = 5;

    /** Asking if customer wants to do another transaction
     */
    static const int ASKING_DO_ANOTHER_STATE = 6;

};
}
}
#endif // TRANSACTION_H


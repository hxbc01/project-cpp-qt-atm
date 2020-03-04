/**
 * @file Message.h
 * @brief Header file of the Message class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include "Card.h"
#include "Money.h"


/** Representations of a message from the ATM to the bank.
 *  Messages to the bank use a fixed format with fixed slots, not all of which
 *  pertain to any given type of transaction.  Each type of transaction creates
 *  one or more subclasses using the slots that it needs, and supplying appropriate
 *  "not needed" values for the rest.
 */
namespace banking
{
class Message
{

public:
    /** Constructor
     *
     *  @param messageCode identifying the type of message
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     *  @param serialNumber serial number of the transaction
     *  @param fromAccount the type of the "from" account of the transaction - can
     *         be -1 if the particular type of transaction does not have a "from"
     *         account (e.g. a deposit)
     *  @param toAccount the type of the "to" account of the transaction - can
     *         be -1 if the particular type of transaction does not have a "to"
     *         account (e.g. a withdrawal)
     *  @param amount the amount of the transaction - can be null if the particular
     *         type of transaction does not have an amount (e.g. an inquiry)
     */
    explicit Message(int a_messageCode, Card a_card, int a_pin,
                     int a_serialNumber, int a_fromAccount,
                     int a_toAccount, Money a_amount);

    /** Destructor
     */
    ~Message();
    /** Create a printable string representing this message
     *
     *  @return string representation
     */
    QString toString();
    /** Set PIN to a new value (if original pin was invalid and customer is
     *  asked to re-enter PIN)
     *
     *  @param pin the new pin to set
     */
    void setPIN(int a_pin);
    /** Accessor for message code
     *
     *  @return the code identifying the type of message
     */
    int getMessageCode();
    /** Accessor for customer's card
     *
     *  @return the customer's card
     */
    Card getCard();
    /** Accessor for PIN
     *
     *  @return the PIN entered by the customer
     */
    int getPIN();
    /** Accessor for transaction serial number
     *
     *  @return the serial number of the transaction
     */
    int getSerialNumber();
    /** Accessor for "from" account
     *
     *  @return the type of the "from" account
     */
    int getFromAccount();
    /** Accessor for "to" account
     *
     *  @return the type of the "to" account
     */
    int getToAccount();
    /** Accessor for acmount
      *
      *  @return the transaction amount
      */
    Money getAmount();

    // Possible values for messageCode

    /** messageCode value for a cash withdrawal message
     */
    static const int WITHDRAWAL = 0;
    /** messageCode value for a message initiating a deposit
     */
    static const int INITIATE_DEPOSIT = 1;
    /** messageCode value for a message completing a deposit (envelope received).
     */
    static const int COMPLETE_DEPOSIT = 2;
    /** messageCode value for a transfer between accounts message
     */
    static const int TRANSFER = 3;
    /** messageCode value for an inquiry message
     */
    static const int INQUIRY = 4;

protected:


private:
    /** Code identifying the type of message - one of the above values
      */
    int m_messageCode;

    /** The customer's card
     */
    Card m_card;

    /** PIN entered by customer
     */
    int m_pin;

    /** Serial number of the transaction
     */
    int m_serialNumber;

    /** "From" account specified by customer - if needed (else - 1)
     */
    int m_fromAccount;

    /** "To" account specified by customer - if needed (else - 1)
     */
    int m_toAccount;

    /** Transaction amount specified by customer - if needed (else $0.00)
     */
    Money m_amount;

};
}

#endif // MESSAGE_H



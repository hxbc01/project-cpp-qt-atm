/**
 * @file Deposit.h
 * @brief Header file of the Deposit class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef DEPOSIT_H
#define DEPOSIT_H
/** Representation for a deposit transaction
 */
class ATM;
class Session;
class Card;
class Money;

namespace atm
{
namespace transaction
{
class Deposit : public Transaction
{

public:
    /** Default Constructor
     */
    Deposit();
    /** Constructor
     *
     *  @param atm the ATM used to communicate with customer
     *  @param session the session in which the transaction is being performed
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     */
    Deposit(ATM *ap_atm, Session *ap_session, Card *ap_card, int a_pin);

    /** Destructor
     */
    ~Deposit();
    /** Get specifics for the transaction from the customer
     *
     *  @return message to bank for initiating this transaction
     *  @exception CustomerConsole.Cancelled if customer cancelled this transaction
     */

    //->Message getSpecificsFromCustomer() throws CustomerConsole.Cancelled

    /** Complete an approved transaction
     *
     *  @return receipt to be printed for this transaction
     *  @exception CustomerConsole.Cancelled if customer cancelled or
     *             transaction timed out
     */
    //->Receipt completeTransaction() throws CustomerConsole.Cancelled
protected:


private:
    /** Account to deposit to
     */
    int m_to;

    /** Amount of money to deposit
     */
    Money amount;

};
}
}
#endif // DEPOSIT_H


/**
 * @file Withdrawal.h
 * @brief Header file of the Withdrawal class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "Transaction.h"
/** Representation for a cash withdrawal transaction
 */
namespace atm
{
class ATM;
class Session;
}
namespace banking
{
class Card;
class Money;
}
namespace atm
{
namespace transaction
{
class Withdrawal : public Transaction
{

public:
    /** Default Constructor
     */
    Withdrawal();
    /** Constructor
     *
     *  @param atm the ATM used to communicate with customer
     *  @param session the session in which the transaction is being performed
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     */
    Withdrawal(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin);

    /** Destructor
     */
    ~Withdrawal();
    /** Get specifics for the transaction from the customer
     *
     *  @return message to bank for initiating this transaction
     *  @exception CustomerConsole.Cancelled if customer cancelled this transaction
     */
    //->Message getSpecificsFromCustomer() throws CustomerConsole.Cancelled

    /** Complete an approved transaction
     *
     *  @return receipt to be printed for this transaction
     */
    //->Receipt completeTransaction()
protected:


private:
    /** Account to withdraw from
     */
    int m_from;

    /** Amount of money to withdraw
     */
    banking::Money *mp_amount=nullptr;

};
}
}
#endif // WITHDRAWAL_H

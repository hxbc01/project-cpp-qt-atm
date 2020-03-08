/**
 * @file Transfer.h
 * @brief Header file of the Transfer class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef TRANSFER_H
#define TRANSFER_H
/** Representation for a transfer transaction
 */
class ATM;
class Session;
class Card;
class Money;

namespace atm
{
namespace transaction
{
class Transfer : public Transaction
{

public:
    /** Default Constructor
     */
    Transfer();
    /** Constructor
     *
     *  @param atm the ATM used to communicate with customer
     *  @param session the session in which the transaction is being performed
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     */
    Transfer(ATM *ap_atm, Session *ap_session, Card *ap_card, int a_pin);

    /** Destructor
     */
    ~Transfer();
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
    /** Accounts to transfer from
     */
    int m_from;

    /** Account to transfer to
     */
    int m_to;

    /** Amount of money to transfer
     */
    Money m_amount;

};
}
}
#endif // TRANSFER_H

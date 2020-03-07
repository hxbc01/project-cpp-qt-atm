/**
 * @file ATM.h
 * @brief Header file of the ATM class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef ATM_H
#define ATM_H
#include <QString>
class CardReader;
class CashDispenser;
class CustomerConsole;
class EnvelopeAcceptor;
class Log;
class NetworkToBank;
class OperatorPanel;
class ReceiptPrinter;


/** Representation for the ATM itself.  An object of this class "owns"
 *  the objects representing the component parts of the ATM, and the
 *  communications network, and is responsible for creating customer
 *  sessions which then use it to gain access to the component parts.
 *  This is an active class - when an instance of the class is created,
 *  a thread is executed that actually runs the system.
 */
namespace atm
{
class ATM
{

public:
    /** Default Constructor
     */
    ATM();
    /** Constructor
     *
     *  @param id the unique ID for this ATM
     *  @param place the physical location of this ATM
     *  @param bankName the name of the bank owning this ATM
     *  @param bankAddress the Internet address of the bank
     */
    ATM(int id, QString place, QString bankName, QString bankAddress);

    /** Destructor
     */
    ~ATM();
    /** Accessor for number
      *
      *  @return the number of the card
      */
    int getNumber() const;


protected:


private:
    // Instance variables recording information about the ATM


    /** Unique ID for this ATM
     */
    int m_id;

    /** Physical location of this ATM
     */
    QString m_place;

    /** Name of the bank owning this ATM
     */
    QString m_bankName;

    /** Internet address of the bank
     */
    QString m_bankAddress;


    // Instance variables referring to the omponent parts of the ATM

    /** The ATM's card reader
     */
    CardReader *mp_cardReader=nullptr;

    /** The ATM's cash dispenser
     */
    CashDispenser *mp_cashDispenser=nullptr;

    /** The ATM's customer console
     */
    CustomerConsole *mp_customerConsole=nullptr;


    /** The ATM's envelope acceptor
     */
    EnvelopeAcceptor *mp_envelopeAcceptor=nullptr;


    /** The ATM's log
     */
    Log *mp_log=nullptr;

    /** The ATM's network connection to the bank
     */
    NetworkToBank *mp_networkToBank=nullptr;

    /** The ATM's operator panel
     */
    OperatorPanel *mp_operatorPanel=nullptr;

    /** The ATM's receipt printer
     */
    ReceiptPrinter *mp_receiptPrinter=nullptr;


    // State information
    // Possible values for state

    /** The ATM is off.  The switch must be turned on before it can operate
     */
    static const int OFF_STATE = 0;

    /** The ATM is on, but idle.  It can service a customer, or it can be shut down
     */
    static const int IDLE_STATE = 1;

    /** The ATM is servicing a customer.
     */
    static const int SERVING_CUSTOMER_STATE = 2;


    /** The current state of the ATM - one of the possible values listed below
     */
    int m_state;

    /** Becomes true when the operator panel informs the ATM that the switch has
     *  been turned on - becomes false when the operator panel informs the ATM
     *  that the switch has been turned off.
     */
    bool m_switchOn;

    /** Becomes true when the card reader informs the ATM that a card has been
     *  inserted - the ATM will make this false when it has tried to read the
     *  card
     */
    bool m_cardInserted;

};
}

#endif // ATM_H

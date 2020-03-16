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
#include <mutex>
#include <condition_variable>
/** Representation for the ATM itself.  An object of this class "owns"
 *  the objects representing the component parts of the ATM, and the
 *  communications network, and is responsible for creating customer
 *  sessions which then use it to gain access to the component parts.
 *  This is an active class - when an instance of the class is created,
 *  a thread is executed that actually runs the system.
 */
namespace atm
{
namespace physical
{
class CustomerConsole;
class CardReader;
class CashDispenser;
class EnvelopeAcceptor;
class Log;
class NetworkToBank;
class OperatorPanel;
class ReceiptPrinter;
} // namespace physical
} // namespace atm
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
    ATM(int a_id, QString a_place, QString a_bankName, QString a_bankAddress);

    /** Destructor
     */
    ~ATM();
    /** Overload () operator to make ATM objects callable.
      * This method contains the code to be executed by the
      * ATM thread
      */
    void operator()();
    /** Inform the ATM (thread) that the switch on the operator console has been moved
     *  to the "on" position.
     */
    void switchOn();
    /** Inform the ATM that the switch on the operator console has been moved
     *  to the "off" position.
     */
    void switchOff();
    /** Inform the ATM that a card has been inserted into the card reader.
     */
    void cardInserted();

    // The following methods allow objects of other classes to access component
    // parts of the ATM

    /** Accessor for id
     *
     *  @return unique id of this ATM
     */
    int getID() const;
    /** Accessor for place
     *
     *  @return physical location of this ATM
     */
    QString getPlace() const;
    /** Accessor for bank name
     *
     *  @return name of bank owning this ATM
     */
    QString getBankName() const;
    /** Accessor for bank address
     *
     *  @return address of bank owning this ATM
     */
    QString getBankAddress() const;
    /** Accessor for card reader
     *
     *  @return card reader component of this ATM
     */
    atm::physical::CardReader* getCardReader() const;
    /** Accessor for cash dispenser
       *
       *  @return cash dispenser component of this ATM
       */
    atm::physical::CashDispenser* getCashDispenser() const;
    /** Accessor for customer console
     *
     *  @return customer console component of this ATM
     */
    atm::physical::CustomerConsole* getCustomerConsole() const;
    /** Accessor for envelope acceptor
     *
     *  @return envelope acceptor component of this ATM
     */
    atm::physical::EnvelopeAcceptor* getEnvelopeAcceptor() const;
    /** Accessor for log
     *
     *  @return log component of this ATM
     */
    atm::physical::Log* getLog() const;
    /** Accessor for network to bank
     *
     *  @return network connection to bank of this ATM
     */
    atm::physical::NetworkToBank* getNetworkToBank() const;
    /** Accessor for operator panel
     *
     *  @return operator panel component of this ATM
     */
    atm::physical::OperatorPanel* getOperatorPanel() const;
    /** Accessor for receipt printer
     *
     *  @return receipt printer component of this ATM
     */
    atm::physical::ReceiptPrinter* getReceiptPrinter() const;




protected:


private:
    // Private methods

     /** Perform the System Startup use case when switch is turned on
      */
    void performStartup();
    /** Perform the System Shutdown use case when switch is turned off
     */
    void performShutdown();

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
    atm::physical::CardReader *mp_cardReader=nullptr;

    /** The ATM's cash dispenser
     */
    atm::physical::CashDispenser *mp_cashDispenser=nullptr;

    /** The ATM's customer console
     */
    atm::physical::CustomerConsole *mp_customerConsole=nullptr;


    /** The ATM's envelope acceptor
     */
    atm::physical::EnvelopeAcceptor *mp_envelopeAcceptor=nullptr;


    /** The ATM's log
     */
    atm::physical::Log *mp_log=nullptr;

    /** The ATM's network connection to the bank
     */
    atm::physical::NetworkToBank *mp_networkToBank=nullptr;

    /** The ATM's operator panel
     */
    atm::physical::OperatorPanel *mp_operatorPanel=nullptr;

    /** The ATM's receipt printer
     */
    atm::physical::ReceiptPrinter *mp_receiptPrinter=nullptr;


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
     *  that the switch has been turned off. This is a shared data
     */
    bool m_switchOn;

    /** Becomes true when the card reader informs the ATM that a card has been
     *  inserted - the ATM will make this false when it has tried to read the
     *  card
     */
    bool m_cardInserted;

    /** mutex object to protect shared data : bool m_switchOn
     */
    std::mutex m_mxswitchOn;
    /** mutex object to protect shared data : bool m_cardInserted
     */
    std::mutex m_mxcardInserted;
    /** condition variable associated with shared data : bool m_cardInserted
     */
    std::condition_variable m_cvcardInserted;
    /** condition variable associated with shared data : bool m_switchOn
     */
    std::condition_variable m_cvswitchOn;


};
} // namespace atm

#endif // ATM_H

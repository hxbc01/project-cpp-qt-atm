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
#include <QObject>
#include <thread>
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
class Session;
}

namespace banking
{
class Card;
}


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
class ATM : public QObject
{
    Q_OBJECT

public:
    /** Constructor
     *
     *  @param id the unique ID for this ATM
     *  @param place the physical location of this ATM
     *  @param bankName the name of the bank owning this ATM
     *  @param bankAddress the Internet address of the bank
     */
    ATM(const int &a_id, const QString &a_place, const QString &a_bankName, const QString &a_bankAddress);

    /** Destructor
     */
    ~ATM();
    /** This method contains the code to be executed by the
      * ATM thread
      */
    void run();

    /** Start the ATM thread
      */
    void startATMThread();
    /** Stop the ATM thread
      */
    void stopATMThread();
    /** Inform the ATM (thread) that the switch on the operator console has been moved
     *  to the "on" position.
     */
    void switchOn();
    /** Inform the ATM (thread) that the switch on the operator console has been moved
     *  to the "off" position.
     */
    void switchOff();
    /** Inform the ATM (thread) that a card has been inserted into the card reader.
     */
    void cardInserted();
    /** Inform the ATM (thread) that the main window is closed
     */
    void mainWindowClosed();

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
    /** Accessor for Card
     *
     *  @return Card component of the user
     */
    banking::Card* getCard() const;
    /** Accessor for PIN
     *
     *  @return Pin number of the user
     */
    int getPin() const;

    /** Is ATM Thread running
     *
     *  @return Thread running status
     */
    bool isATMThreadRunning();


    static std::exception_ptr p_cancelled;
protected:

signals:
     void performStartupSignal();
     void customerConsoleDisplaySignal(const QString &ar_text);
     //void readCardSignal();
     void createSessionSignal();

private slots:
     /** Perform the System Startup use case when switch is turned on
      */
    void performStartup();
    void customerConsoleDisplay(const QString &ar_text);
    void readCard();
    void createSession();
    void readPIN(const QString &ar_text);



private:
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
    /** The ATM's session
     */
    atm::Session *mp_currentSession = nullptr;
    /** Card Object
     */
    banking::Card *mp_card=nullptr;
    /** The PIN entered (or re-entered) by the customer
     */
    int m_pin;

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
    /** mutex object to protect shared data
     */
    std::mutex m_mxdataMuMutex;

    /** condition variable associated with shared data
     */
    std::condition_variable m_conditionVariable;

    /** ATM thread object
     */
    std::thread ATMThread;
    /** ATM thread stopped
     */
    std::atomic<bool> m_ATMThreadStopped;



};
} // namespace atm

#endif // ATM_H


/**
 * @file Simulation.h
 * @brief Header file of the Simulation class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMULATION_H
#define SIMULATION_H
/** Simulation of the physical components of the ATM, including its network
 *  connection to the bank.  An instance is created at startup by either the
 *  application's main() program or the applet's init() method.
 *
 *  The individual components are displayed in a panel belonging to class GUI.
 *  The bank is simulated by an object belonging to class SimulatedBank.  The
 *  constructor for this class creates one instance of each.
 *
 *  The static method getInstance() allows components of the ATM to access the one
 *  and only instance of this class in order to simulate various operations.  The
 *  remaining methods simulate specific operations of the ATM, and are forwarded
 *  to either the GUI panel or the simulated bank to actually carry them out.
 */
namespace banking
{
class Status;
class Message;
class Balances;
}
namespace atm
{
class ATM;
}
namespace simulation
{
class SimOperatorPanel;
class SimCardReader;
class SimDisplay;
class SimCashDispenser;
class SimEnvelopeAcceptor;
class SimReceiptPrinter;
class SimKeyboard;
class GUI;
class SimulatedBank;
}
namespace simulation
{
class Simulation
{

public:
    /** Default Constructor
     */
    Simulation();
    /** Constructor
     *
     *  @param atm the ATM being simulated
     */
    Simulation(atm::ATM *ap_atm);

    /** Destructor
     */
    ~Simulation();
    /** Accessor for the one and only instance of this class
     *
     *  @return the instance of this class
     */
    Simulation* getInstance();
    /** Simulate sending a message to bank
     *
     *  @param message the message to send
     *  @param balances (out) balances in customer's account as reported
     *         by bank
     *  @return status code returned by bank
     */
    banking::Status* sendMessage(banking::Message *ap_message, banking::Balances *ap_balances);

    /** Notify the ATM that the state of the on-off switch has been changed
     *
     *  @param on true if state is now "on", false if it is "off"
     */
    void switchChanged(const bool &on);
    /** Notify ATM that a card has been inserted
     */
    void cardInserted();
    /** Accessor for GUI Panel that simulates the ATM
     *
     *  @return the GUI Panel
     */
    GUI* getGUI();

    /* Possible values for mode parameter to readInput() */

    /** Read input in PIN mode - allow user to enter several characters,
     *  and to clear the line if the user wishes; echo as asterisks
     */
    static const int PIN_MODE = 1;

    /** Read input in amount mode - allow user to enter several characters,
     *  and to clear the line if the user wishes; echo what use types
     */
    static const int AMOUNT_MODE = 2;

    /** Read input in menu choice mode - wait for one digit key to be pressed,
     *  and return value immediately.
     */
    static const int MENU_MODE = 3;

protected:


private:
    /** The ATM object for the ATM being simulated
     */
    atm::ATM *mp_atm=nullptr;
    /** The simulated operator panel
     */
    SimOperatorPanel *mp_operatorPanel=nullptr;

    /** The simulated card reader
     */
    SimCardReader *mp_cardReader=nullptr;

    /** The simulated display
     */
    SimDisplay *mp_display=nullptr;

    /** The simulated keyboard
     */
    SimKeyboard *mp_keyboard=nullptr;

    /** The simulated cash dispenser
     */
    SimCashDispenser *mp_cashDispenser=nullptr;

    /** The simulated envelope acceptor
     */
    SimEnvelopeAcceptor *mp_envelopeAcceptor=nullptr;

    /** The simulated receipt printer
     */
    SimReceiptPrinter *mp_receiptPrinter=nullptr;

    /** Panel containing the GUI that simulates the ATM
     */
    GUI *mp_gui=nullptr;

    /** Simulated bank
     */
    SimulatedBank *mp_simulatedBank=nullptr;
    /** The one and only instance of this class
     */
    Simulation *mp_theInstance=nullptr;

};
} // namespace simulation

#endif // SIMULATION_H


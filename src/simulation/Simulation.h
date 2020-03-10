/**
 * @file Card.h
 * @brief Header file of the Card class
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
    static Simulation* getInstance();
    /** Simulate sending a message to bank
     *
     *  @param message the message to send
     *  @param balances (out) balances in customer's account as reported
     *         by bank
     *  @return status code returned by bank
     */
    banking::Status* sendMessage(banking::Message *ap_message, banking::Balances *ap_balances);



protected:


private:
    /** The ATM object for the ATM being simulated
     */
    atm::ATM *mp_atm;
    /** The one and only instance of this class
     */
    static Simulation *mp_theInstance;

};
} // namespace simulation

#endif // SIMULATION_H


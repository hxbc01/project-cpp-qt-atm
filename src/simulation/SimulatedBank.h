/**
 * @file Card.h
 * @brief Header file of the Card class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMULATEDBANK_H
#define SIMULATEDBANK_H
/** Simulation of the bank.  A set of simulated accounts is initalized at startup.
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
class Simulation;
}
namespace simulation
{
class SimulatedBank
{

public:
    /** Default Constructor
     */
    SimulatedBank();
    /** Destructor
     */
    ~SimulatedBank();
    /** Simulate the handling of a message
     *
     *  @param message the message to send
     *  @param balances (out) balances in customer's account as reported
     *         by bank
     *  @return status code returned by bank
     */
    banking::Status handleMessage(banking::Message *ap_message, banking::Balances *ap_balances);
    /** Simulate sending a message to bank
     *
     *  @param message the message to send
     *  @param balances (out) balances in customer's account as reported
     *         by bank
     *  @return status code returned by bank
     */
    banking::Status* sendMessage(banking::Message *ap_message, banking::Balances *ap_balances);
    /** Simulate processing of a withdrawal
      *
      *  @param message the message describing the withdrawal requested
      *  @param balances (out) balances in account after withdrawal
      *  @return status code derived from current values
      */
    banking::Status* withdrawal(banking::Message *ap_message, banking::Balances *ap_balances);
    /** Simulate initiation of a deposit. At this point, the bank only approves
     *  the validity of the deposit - no changes to the records are made until
     *  the envelope is actually inserted
     *
     *  @param message the message describing the deposit requested
     *  @return status code derived from current values
     */
    banking::Status initiateDeposit(banking::Message *ap_message);
    /** Simulate completion of a deposit
      *
      *  @param message the message describing the deposit requested
      *  @param balances (out) balances (not updated until completed)
      *  @return status code - must always be success in this case
      */
     banking::Status completeDeposit(banking::Message *ap_message, banking::Balances *ap_balances);
     /** Simulate processing of a transfer
      *
      *  @param message the message describing the transfer requested
      *  @param balances (out) balances in "to" account after transfer
      *  @return status code derived from current values
      */
     banking::Status transfer(banking::Message *ap_message, banking::Balances *ap_balances);
     /** Simulate processing of an inquiry
      *
      *  @param message the message describing the inquiry requested
      *  @param balances (out) balances in account
      *  @return status code derived from current values
      */
     banking::Status inquiry(banking::Message *ap_message, banking::Balances *ap_balances);



protected:


private:
    /** The ATM object for the ATM being simulated
     */
    atm::ATM *mp_atm=nullptr;
    /** The one and only instance of this class
     */
    static simulation::Simulation *mp_theInstance=nullptr;

};
} // namespace simulation

#endif // SIMULATEDBANK_H


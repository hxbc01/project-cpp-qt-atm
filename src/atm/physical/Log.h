/**
 * @file Log.h
 * @brief Header file of the Log class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef LOG_H
#define LOG_H

/** Manager for the ATM's internal log.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device.
 */
// forward declared dependencies
class Message;
class Status;
class Money;

namespace atm
{
namespace physical
{
class Log
{

public:
    /** Default Constructor
     */
    Log();
    /** Destructor
     */
    ~Log();
    /** Log the sending of a message to the bank
     *
     *  @param message the message to be logged
     */
    void logSend(Message *ap_message);
    /** Log a response received from the bank
     *
     *  @param status the status object returned by the bank in response
     */
    void logResponse(Status *ap_response);
    /** Log the dispensing of cash by the cash dispenser
     *
     *  @param amount the amount of cash being dispensed
     */
    void logCashDispensed(Money *ap_amount);
    /** Log accepting an envelope.  This method is only called if an envelope
     *  is actually received from the customer
     */
    void logEnvelopeAccepted();

protected:


private:


};
}
}

#endif // LOG_H

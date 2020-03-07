/**
 * @file EnvelopeAcceptor.h
 * @brief Header file of the EnvelopeAcceptor class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef ENVELOPEACCEPTOR_H
#define ENVELOPEACCEPTOR_H
#include "Log.h"
/** Manager for the ATM's envelope acceptor.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device.
 */
// forward declared dependencies
//class Message;
//class Status;
//class Money;

namespace atm
{
namespace physical
{
class EnvelopeAcceptor
{

public:
    /** Default Constructor
     */
    EnvelopeAcceptor();
    /** Constructor
     *
     *  @param log the log in which to record receiving an envelope
     */
    EnvelopeAcceptor(Log *ap_log);
    /** Destructor
     */
    ~EnvelopeAcceptor();
    /** Accept an envelope from customer.
     *
     *  @exception CustomerConsole.Cancelled if operation timed out or the
     *             customer cancelled it
     */
    void acceptEnvelope();

protected:


private:
    Log m_log;

};
}
}

#endif // ENVELOPEACCEPTOR_H

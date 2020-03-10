/**
 * @file NetworkToBank.h
 * @brief Header file of the NetworkToBank class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef NETWORKTOBANK_H
#define NETWORKTOBANK_H
#include <QString>
#include "Log.h"
/** Manager for the ATM's network connection.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device.
 */
namespace banking
{
class Message;
class Status;
class Balances;
}
namespace atm
{
namespace physical
{
class NetworkToBank
{

public:
    /** Default Constructor
     */
    NetworkToBank();
    /** Constructor
     *
     *  @param log the log in which to record sending of messages and responses
     *  @param bankAddress the network address of the bank
     */
    NetworkToBank(Log *ap_log, QString a_bankAddress);

    /** Destructor
     */
    ~NetworkToBank();
    /** Open connection to bank at system startup
     */
    void openConnection();
    /** Close connection to bank at system shutdown
     */
    void closeConnection();
    /** Send a message to bank
     *
     *  @param message the message to send
     *  @param balances (out) balances in customer's account as reported
     *         by bank
     *  @return status code returned by bank
     */
    banking::Status* sendMessage(banking::Message *ap_message, banking::Balances *ap_balances);


protected:


private:

    // Log into which to record messages

    Log *mp_log = nullptr;

    // Network address of the bank

    QString m_bankAddress;

};
}
}

#endif // NETWORKTOBANK_H



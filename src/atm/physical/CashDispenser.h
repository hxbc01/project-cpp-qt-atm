/**
 * @file CashDispenser.h
 * @brief Header file of the CashDispenser class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef CASHDISPENSER_H
#define CASHDISPENSER_H
#include "Log.h"

/** Manager for the ATM's cash dispenser.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device.
 */
namespace banking
{
class Money;
}
namespace atm
{
namespace physical
{
class CashDispenser
{

public:
    /** Default Constructor
     */
    CashDispenser();
    /** Constructor
     *
     *  @param log the log in which to record dispensing cash
     */
    explicit CashDispenser(Log *ap_log);

    /** Destructor
     */
    ~CashDispenser();
    /** Set the amount of cash initially on ATM
     *
     *  @param initialCash the amount of money in the dispenser
     */
    void setInitialCashOnATM(banking::Money *a_initialCash);
    /** See if there is enough cash on hand to satisfy a request
     *
     *  @param amount the amount of cash the customer wants
     *  @return true if at least this amount of money is available
     */
    bool checkCashOnATM(const banking::Money *ap_amount);
    /** Dispense cash to a customer
      *
      *  @param amount the amount of cash to dispense
      *
      *  Precondition: amount is <= cash on hand
      */
    void dispenseCash(const banking::Money *ap_amount);


protected:


private:
    /** Log into which cash amounts dispensed will be recorded
     */
    Log *mp_log=nullptr;

    /** Current cash on ATM
     */
    banking::Money *mp_cashOnATM=nullptr;

};
}
}

#endif // CASHDISPENSER_H


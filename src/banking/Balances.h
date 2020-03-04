/**
 * @file Balances.h
 * @brief Header file of the Balances class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef BALANCES_H
#define BALANCES_H
#include "Money.h"
/** Representation for customer's current account balances as returned by the
 *  bank.  An empty object of this class is created and sent along with the
 *  transaction message; the bank fills it in with values.
 */
namespace banking
{
class Balances
{

public:
    /** Constructor.  Create an object whose values will be filled in later, when
     *  returning a value to the creator.
     */
    Balances();
    /** Destructor
     */
    ~Balances();
    /** Mutator.  Fill in values
     *
     *  @param total the total balance in the account
     *  @param available the available balance
     */
    void setBalances(Money a_total, Money a_available);
    /** Accessor for total balance
     *
     *  @return total balance in the account
     */
    Money getTotal();
    /** Accessor for available balance
     *
     *  @return available balance
     */
    Money getAvailable();

protected:


private:
    // Instance variables

    /** Current total balance in the account
    */
    Money m_total;

    /** Current available balance in the account
     */
    Money m_available;

};
}

#endif // BALANCES_H



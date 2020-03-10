/**
 * @file CustomerConsole.h
 * @brief Header file of the CustomerConsole class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef CUSTOMERCONSOLE_H
#define CUSTOMERCONSOLE_H
#include <QString>
/** Manager for the ATM's customer console.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device (actually two separate
 *  devices - the display and the keyboard.)
 */
namespace atm
{
namespace physical
{
class CustomerConsole
{

public:
    /** Default Constructor
     */
    CustomerConsole();
    /** Destructor
     */
    ~CustomerConsole();
    /** Display a message to the customer
     *
     *  @param message the message to display
     */
    void display(QString a_message);
    /** Read a PIN entered by the customer (echoed as asterisks)
     *
     *  @param prompt the message to display prompting the customer to enter PIN
     *  @return the PIN that was entered
     *  @exception Cancelled if customer presses the CANCEL key before pressing ENTER
     */

    //->int readPIN(QString prompt) throws Cancelled

    /** Display a menu of options and return choice made by customer
       *
       *  @param prompt message to display before the list of options
       *  @param menu the options
       *  @return the number of the option chosen (0 .. # of options - 1)
       *  Note: the options are numbered 1 .. # of options when displayed for the
       *  customer - but the menu array indices and the final result returned are in
       *  the range 0 .. # of options - 1
       *
       *  @exception Cancelled if customer presses the CANCEL key before choosing option
       */

      //->public synchronized int readMenuChoice(String prompt, String[] menu) throws Cancelled

    /** Read a money amount entered by the customer
     *
     *  @param prompt the message to display prompting the customer to enter amount
     *  @return the amount entered by the customer
     *  @exception Cancelled if customer presses the CANCEL key before pressing ENTER
     */

    //->public synchronized Money readAmount(String prompt) throws Cancelled

    /** Exception thrown when the user presses the cancel key while the ATM is
     *  waiting for some action
     */

    //->public static class Cancelled extends Exception


protected:


private:


};
}
}
#endif // CUSTOMERCONSOLE_H


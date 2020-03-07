/**
 * @file OperatorPanel.h
 * @brief Header file of the OperatorPanel class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef OPERATORPANEL_H
#define OPERATORPANEL_H
/** Manager for the ATM's operator panel.  In a real ATM, this would
 *  manage a physical device; in this simulation,  it uses classes
 *  in package simulation to simulate the device.
 */
class ATM;
class Money;
namespace atm
{
namespace physical
{
class OperatorPanel
{

public:
    /** Default Constructor
     */
    OperatorPanel();
    /** Constructor
     *
     *  @param atm the ATM this panel is part of
     */
    OperatorPanel(ATM *ap_atm);

    /** Destructor
     */
    ~OperatorPanel();
    // In a real ATM, code would be needed to sense a change in the state of the
    // switch and notify the ATM - simulated in this case by a button in the GUI

    /** Get the amount of cash in the cash dispenser from the operator at start up
     *
     *  @return dollar value of the bills in the cash dispenser (# of bills x $20)
     */

    Money getInitialCash();

protected:


private:
    /** ATM this panel is part of.  The ATM object will be notified when
     * the switch on the panel is turned on or off
     */
    ATM *mp_atm;

};
}
}
#endif // OPERATORPANEL_H


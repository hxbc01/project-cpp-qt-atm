/**
 * @file GUI.h
 * @brief Header file of the GUI class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef GUI_H
#define GUI_H
#include <QWidget>
/** The GUI for the ATM simulation
 */
QT_BEGIN_NAMESPACE
class QStackedWidget;
class QLabel;
QT_END_NAMESPACE
namespace simulation
{
class SimOperatorPanel;
class SimCardReader;
class SimDisplay;
class SimKeyboard;
class SimCashDispenser;
class SimEnvelopeAcceptor;
class SimReceiptPrinter;
class ATMPanel;
}
namespace simulation
{
class GUI : public QWidget
{

public:
    /** Default Constructor
     */
    GUI();
    /** Constructor.
     *
     *  @param operatorPanel the simulation of the operator panel
     *  @param cardReader the simulation of the card reader
     *  @param display the simulation of the display
     *  @param keyboard the simulation of the keyboard
     *  @param cashDispenser the simulation of the cash dispenser
     *  @param receiptPrinter the simulation of the receipt printer
     */
    GUI(SimOperatorPanel *ap_operatorPanel,
        SimCardReader *ap_cardReader,
        SimDisplay *ap_display,
        SimKeyboard *ap_keyboard,
        SimCashDispenser *ap_cashDispenser,
        SimEnvelopeAcceptor *ap_envelopeAcceptor,
        SimReceiptPrinter *ap_receiptPrinter);
    /** Destructor
     */
    ~GUI();

protected:


private:
    /** The panel displaying the ATM itself
     */
    ATMPanel *mp_atmPanel=nullptr;
    /** The overall GUI of the ATM
     */
    QStackedWidget *mp_atmGUI=nullptr;

};
}

#endif // GUI_H


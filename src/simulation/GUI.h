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
class QVBoxLayout;
QT_END_NAMESPACE
namespace banking
{
class Card;
class Money;
}
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
class LogPanel;
class CardPanel;
class BillsPanel;
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
    /** Accessor for the stacked widget that simulates the ATM
     *
     *  @return the stacked widget
     */
    QStackedWidget* getStackedWidget() const;
    /** Accessor for the log panel
     *
     *  @return the log panel
     */
    LogPanel* getLogPanel() const;
    /** Accessor for the ATM panel
     *
     *  @return the ATM panel
     */
    ATMPanel* getATMPanel() const;
    /** Simulate reading of a card
     *
     *
     *  @return Card object representing information on the card if read
     *          successfully, null if read not successfully
     */
    banking::Card* readCard();
    /** Simulate getting the amount of cash in the cash dispenser from the operator
     *  at start up
     *
     *  @return dollar value of the bills in the cash dispenser (# of bills x $20)
     */

    banking::Money* getInitialCash();



protected:


private:
    /** displaying the ATM panel itself
     */
    ATMPanel *mp_atmPanel=nullptr;
    /** displaying the Log panel
     */
    LogPanel *mp_logPanel=nullptr;
    /** displaying the Card panel
     */
    CardPanel *mp_cardPanel=nullptr;
    /** displaying the Bills panel
     */
    BillsPanel *mp_billsPanel=nullptr;
    /** Card Object
     */
    banking::Card *mp_card=nullptr;
    /** Money Object
     */
    banking::Money *mp_money=nullptr;
    /** overall GUI of the ATM
     */
    QStackedWidget *mp_atmGUI=nullptr;
    /** layout for the stacked GUI Windows
     */
    QVBoxLayout *mp_GUIVLayout =nullptr;

};
}

#endif // GUI_H


/**
 * @file ATMPanel.h
 * @brief Header file of the ATMPanel class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef ATMPANEL_H
#define ATMPANEL_H
#include <QWidget>

/** The GUI panel that simulates the ATM itself
 */
QT_BEGIN_NAMESPACE
class QVBoxLayout;
class QLabel;
QT_END_NAMESPACE

namespace simulation
{
class GUI;
class SimOperatorPanel;
class SimCardReader;
class SimDisplay;
class SimKeyboard;
class SimCashDispenser;
class SimEnvelopeAcceptor;
class SimReceiptPrinter;
}

namespace simulation
{
class ATMPanel : public QWidget
{

public:
    /** Default Constructor
     */
    ATMPanel();
    /** Constructor
     *
     *  @param gui the the overall GUI
     *  @param operatorPanel the simulation of the operator panel
     *  @param cardReader the simulation of the card reader
     *  @param display the simulation of the display
     *  @param keyboard the simulation of the keyboard
     *  @param cashDispenser the simulation of the cash dispenser
     *  @param receiptPrinter the simulation of the receipt printer
     */
    ATMPanel(const GUI *ap_gui,
             SimOperatorPanel *ap_operatorPanel,
             SimCardReader *ap_cardReader,
             SimDisplay *ap_display,
             SimKeyboard *ap_keyboard,
             SimCashDispenser *ap_cashDispenser,
             SimEnvelopeAcceptor *ap_envelopeAcceptor,
             SimReceiptPrinter *ap_receiptPrinter);
    /** Destructor
     */
    ~ATMPanel();

protected:


private:
    // main layout for the ATM GUI Window
    QVBoxLayout *mp_ATMLayout =nullptr;
    // Top label for the ATM GUI Window
    QLabel *mp_ATMLabel =nullptr;


};
}

#endif // ATMPANEL_H


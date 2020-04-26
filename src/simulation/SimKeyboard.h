/**
 * @file SimKeyboard.h
 * @brief Header file of the SimKeyboard class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMKEYBOARD_H
#define SIMKEYBOARD_H
#include <QWidget>
#include <QEventLoop>
#include "Simulation.h"
/** Simulate the keyboard portion of the customer console
 */
QT_BEGIN_NAMESPACE
class QGridLayout;
class QPushButton;
QT_END_NAMESPACE
namespace simulation
{
class SimDisplay;
class SimEnvelopeAcceptor;
}
namespace simulation
{
class SimKeyboard : public QWidget
{
    Q_OBJECT

private slots:

    /** Handle a digit key
      *
      *  @param digit the value on the key
      */
    void digitKeyPressed(int digit);
    /** Handle the ENTER key
     */
    void enterKeyPressed();
    /** Handle the CLEAR key
     */
    void clearKeyPressed();
    /** Handle the CANCEL KEY
      */
    void cancelKeyPressed();


public:
    /** Default Constructor
     */
    SimKeyboard(SimDisplay *ap_display, SimEnvelopeAcceptor *ap_envelopeAcceptor);
    /** Destructor
     */
    ~SimKeyboard();
    /** Read input from the keyboard
      *
      *  @param mode the input mode to use - one of the constants defined below.
      *  @param maxValue the maximum acceptable value (used in MENU_MODE only)
      *  @return the line that was entered - null if user pressed CANCEL.
      */
     QString* readInput(const int &a_mode, const int &a_maxValue);

     // eventloop to wait until PIN number of card entered
     QEventLoop m_eventLoop;
protected:


private:

    /** Set the echo string displayed on the display
    *
    *  @param echo the text to set the echo to (the whole line)
    */
    void setEcho(const QString &echo);

    // grid layout for the keyboard
    QGridLayout *mp_keyboardGridLayout=nullptr;
    // number of buttons
    enum { m_buttons = 16};
    // left buttons array
    QPushButton *mp_button[m_buttons];
    // left buttons labels
    QStringList m_buttonsLabels = {"1", "2", "3","CANCEL", "4", "5", "6", "CLEAR","7", "8", "9", "ENTER", "", "0", "", ""};

    /** The display onto which to echo input
     */
    SimDisplay *mp_display=nullptr;

    /** The envelope acceptor to notify if CANCEL is pressed while not awaiting
     *  customer input
     */
    SimEnvelopeAcceptor *mp_envelopeAcceptor=nullptr;

    /** Current input mode - one of the values defined below
     */
    int m_mode;

    /** Not currently reading input - ignore keys (except CANCEL)
     */
    static const int IDLE_MODE = 0;

    /** Read input in PIN mode - allow user to enter several characters,
     *  and to clear the line if the user wishes; echo as asterisks
     */
    static const int PIN_MODE = Simulation::PIN_MODE;

    /** Read input in amount mode - allow user to enter several characters,
     *  and to clear the line if the user wishes; echo what use types
     */
    static const int AMOUNT_MODE = Simulation::AMOUNT_MODE;

    /** Read input in menu choice mode - wait for one digit key to be pressed,
     *  and return value immediately.
     */
    static const int MENU_MODE = Simulation::MENU_MODE;

    /** Current partial line of input
     */
    QString m_currentInput;

    /** Cancellation flag - set to true if user cancels
     */
    bool m_cancelled;

    /** Maximum valid value - used in MENU_MODE only
     */
    int m_maxValue;


};
}

#endif // SIMKEYBOARD_H


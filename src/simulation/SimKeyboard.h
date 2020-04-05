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

public:
    /** Default Constructor
     */
    SimKeyboard(SimDisplay *ap_display, SimEnvelopeAcceptor *ap_envelopeAcceptor);
    /** Destructor
     */
    ~SimKeyboard();

protected:


private:
    // grid layout for the keyboard
    QGridLayout *mp_keyboardGridLayout=nullptr;
    // number of buttons
    enum { m_buttons = 16};
    // left buttons array
    QPushButton *mp_button[m_buttons];
    // left buttons labels
    QStringList m_buttonsLabels = {"1", "2", "3","CANCEL", "4", "5", "6", "CLEAR","7", "8", "9", "ENTER", "", "0", "", ""};


};
}

#endif // SIMKEYBOARD_H


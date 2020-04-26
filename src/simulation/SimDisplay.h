/**
 * @file SimDisplay.h
 * @brief Header file of the SimDisplay class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMDISPLAY_H
#define SIMDISPLAY_H
#include <QWidget>
/** Simulate the display portion of the customer console
 */
QT_BEGIN_NAMESPACE
class QLabel;
class QVBoxLayout;
class QPushButton;
class QHBoxLayout;
class QTextEdit;
QT_END_NAMESPACE
namespace simulation
{
class SimDisplay : public QWidget
{

public:
    /** Default Constructor
     */
    SimDisplay();
    /** Destructor
     */
    ~SimDisplay();
    /** Clear the display
       */
    void clearDisplay();
    /** Add text to the display - may contain one or more lines delimited by \n
      *
      *  @param text the text to display
      */
    void display(const QString &text);
    /** Set echoed input on the display
       *
       *  @param echo the line to be echoed - always the entire line
       */
   void setEcho(const QString &echo);


protected:


private:
    // vertical layout for the dislay left buttons
    QVBoxLayout *mp_buttonLeftVLayout=nullptr;
    // vertical layout for the dislay right buttons
    QVBoxLayout *mp_buttonRightVLayout=nullptr;
    // number of buttons
    enum { m_numLeftButtons = 4, m_numRightButtons = 4};
    // left buttons array
    QPushButton *mp_leftButtons[m_numLeftButtons];
    // right buttons array
    QPushButton *mp_rightButtons[m_numRightButtons];
    // horizontal layout for the display
    QHBoxLayout *mp_displayHLayout=nullptr;
    // display screen
    QTextEdit *mp_mainDisplay=nullptr;
    // The following are used only for setting the ATM main display size
    const int ATM_MAIN_DISPLAY_WIDTH = 300;
    const int ATM_MAIN_DISPLAY_HEIGHT = 260;


};
}

#endif // SIMDISPLAY_H


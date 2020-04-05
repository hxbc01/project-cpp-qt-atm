/**
 * @file CardPanel.h
 * @brief Header file of the CardPanel class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef CARDPANEL_H
#define CARDPANEL_H
#include <QWidget>
#include <mutex>
#include <condition_variable>
#include <QEventLoop>
/** The GUI panel that simulates the reading of the ATM card's magnetic stripe
 *  by asking the user to enter a Card number
 */
QT_BEGIN_NAMESPACE
class QLabel;
class QVBoxLayout;
class QPushButton;
class QHBoxLayout;
class QLineEdit;
QT_END_NAMESPACE
namespace simulation
{
class CardPanel : public QWidget
{
    Q_OBJECT

private slots:

    /**
     * validate entered number of bills
     */
    void validateText();

public:
    /** Default Constructor
     */
    CardPanel();
    /** Destructor
     */
    ~CardPanel();
    /** Ask the customer to enter the number on the card
     *
     *  @return the number entered
     */
    int readCardNumber();

    // eventloop to wait until number of card entered
    QEventLoop m_loop;


protected:


private:
    // information about card number
    QLabel *mp_infoLabel = nullptr;
    // input card number
    QLineEdit *mp_cardNumberField = nullptr;
    // vertical layout for the Card panel
    QVBoxLayout *mp_cardPanelVLayout = nullptr;
    // Card number
    int m_cardNumber;

};
}

#endif // CARDPANEL_H


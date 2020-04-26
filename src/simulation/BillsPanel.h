/**
 * @file BillsPanel.h
 * @brief Header file of the BillsPanel class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef BILLSPANEL_H
#define BILLSPANEL_H
#include <QWidget>
#include <QEventLoop>
/** The GUI panel that allows the operator to enter the number of bills in the
 *  ATM at startup
 */
QT_BEGIN_NAMESPACE
class QLabel;
class QVBoxLayout;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE
namespace simulation
{
class BillsPanel : public QWidget
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
    BillsPanel();
    /** Destructor
     */
    ~BillsPanel();
    /** Ask the operator to enter the number of bills in the cash dispenser
     *
     *  @return the number entered
     */
    int readBills();

    // eventloop to wait until number of bills entered
    QEventLoop m_eventLoop;

protected:


private:
    // input bills number
    QLineEdit *mp_billsNumberField = nullptr;
    // information about bills
    QLabel *mp_infoLabel = nullptr;
    // vertical layout for the bills panel
    QVBoxLayout *mp_billsPanelVLayout = nullptr;
    // bills number
    int m_billsNumber;



};
}

#endif // BILLSPANEL_H


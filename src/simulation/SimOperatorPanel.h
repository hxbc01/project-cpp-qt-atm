/**
 * @file SimOperatorPanel.h
 * @brief Header file of the SimOperatorPanel class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SIMOPERATORPANEL_H
#define SIMOPERATORPANEL_H
#include <QWidget>
/** Simulate the operator panel
 */
QT_BEGIN_NAMESPACE
class QLabel;
class QVBoxLayout;
class QPushButton;
class QHBoxLayout;
QT_END_NAMESPACE

namespace simulation
{
class Simulation;
}
namespace simulation
{
class SimOperatorPanel : public QWidget
{
    Q_OBJECT

private slots:
    /**
     * On/OFF button clicked
     */
    void pushATMButton();
    /**
     * log show button clicked
     */
    void pushShowLogButton();
public:
    /** Default Constructor
     */
    SimOperatorPanel();
    /** Constructor
     *
     *  @param simulation the overall simulation object
     */
    SimOperatorPanel(const Simulation *ap_simulation);

    /** Destructor
     */
    ~SimOperatorPanel();


protected:



private:
    // label On/Off Info
    QLabel *mp_infoLabel=nullptr;
    // ATM On/Off button
    QPushButton *mp_buttonONOFF=nullptr;
    // log show button
    QPushButton *mp_showLogButton =nullptr;
    // vertical layout for the On/Off button
    QVBoxLayout *mp_buttonONOFFVLayout=nullptr;
    // vertical layout for the operator panel
    QHBoxLayout *mp_operatorHLayout=nullptr;
    /** simulation object
     */
    const Simulation *mp_simulation=nullptr;


};
}

#endif // SIMOPERATORPANEL_H


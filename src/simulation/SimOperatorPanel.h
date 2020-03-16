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
    // Label On/Off Info
    QLabel *mp_infoLabel=nullptr;
    // Button On/Off
    QPushButton *mp_buttonONOFF=nullptr;
    // Layout for the operator panel
    QVBoxLayout *mp_operatorLayout=nullptr;


private:


};
}

#endif // SIMOPERATORPANEL_H


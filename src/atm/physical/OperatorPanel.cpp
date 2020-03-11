#include <QDebug>
#include "OperatorPanel.h"
#include "Money.h"
atm::physical::OperatorPanel::OperatorPanel()
{

}
atm::physical::OperatorPanel::OperatorPanel(ATM *ap_atm)
{
    mp_atm = ap_atm;

}

atm::physical::OperatorPanel::~OperatorPanel()
{

}

banking::Money* atm::physical::OperatorPanel::getInitialCash()
{
    //return Simulation.getInstance().getInitialCash();
}

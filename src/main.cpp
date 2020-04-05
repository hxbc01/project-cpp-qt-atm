#include <QApplication>
#include "ATMMainWindow.h"
#include <thread>
#include <QDebug>
#include <ATM.h>
#include <Simulation.h>
#include <ThreadGuard.h>

int main(int argc, char *argv[])
{
    QApplication ATMApp(argc, argv);
    // Create an ATM Object
    atm::ATM myATM(42, "Gordon College", "First National Bank of Podunk",
                   "nullptr" /* We're not really talking to a bank! */);

    simulation::Simulation *p_ATMSimulation = simulation::Simulation::getInstance(&myATM);

    ATMMainWindow ATMMain(p_ATMSimulation);
    ATMMain.show();
    myATM.startATMThread();

    //qDebug()<<ATMMain.size();
    return ATMApp.exec();
}

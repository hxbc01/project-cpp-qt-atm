#include <QApplication>
#include "ATMMainWindow.h"
#include <thread>
#include <QDebug>
//#include <ATM.h>
#include <Simulation.h>
#include <ThreadGuard.h>

int main(int argc, char *argv[])
{
    QApplication ATMApp(argc, argv);
    // Create an ATM Object
//    atm::ATM *p_myATM = new atm::ATM(42, "Gordon College", "First National Bank of Podunk",
//                          "nullptr" /* We're not really talking to a bank! */);

    atm::ATM *p_myATM=nullptr;
    simulation::Simulation *p_ATMSimulation = new simulation::Simulation(p_myATM);

    ATMMainWindow ATMMain(p_ATMSimulation);

    // Start the Thread that runs the ATM

//    std::thread ATMThread(p_myATM);
//    utils::ThreadGuard threadGuard(ATMThread);


    ATMMain.show();
    //qDebug()<<ATMMain.size();
    return ATMApp.exec();
}

#include <QDebug>
#include <thread>
#include "Simulation.h"

simulation::Simulation::Simulation()
{

}
simulation::Simulation::Simulation(atm::ATM *ap_atm)
{
    mp_atm = ap_atm;
    mp_theInstance = this;

}

simulation::Simulation::~Simulation()
{

}

simulation::Simulation* simulation::Simulation::getInstance()
{
    return mp_theInstance;
}

banking::Status* simulation::Simulation::sendMessage(banking::Message *ap_message, banking::Balances *ap_balances)
{
    // Simulate time taken to send message over network

    try{
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    catch(std::exception const& e){
        qDebug()<< e.what();
    }
}





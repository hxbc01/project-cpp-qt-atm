#include <QDebug>
#include <thread>
#include "Simulation.h"
#include "ATM.h"
#include "GUI.h"
#include "SimOperatorPanel.h"
#include "SimCardReader.h"
#include "SimDisplay.h"
#include "SimCashDispenser.h"
#include "SimEnvelopeAcceptor.h"
#include "SimReceiptPrinter.h"
#include "SimKeyboard.h"
//#include "SimulatedBank.h"

simulation::Simulation* simulation::Simulation::mp_theInstance = nullptr;

simulation::Simulation::Simulation(atm::ATM *ap_atm)
{
    // ATM object
    mp_atm = ap_atm;

    // Create the simulated individual components of the ATM's GUI
    mp_operatorPanel = new SimOperatorPanel(this);
    mp_cardReader = new SimCardReader(this);
    mp_display = new SimDisplay();
    mp_cashDispenser = new SimCashDispenser("Cash Dispenser");
    mp_envelopeAcceptor = new SimEnvelopeAcceptor("Envelope Acceptor");
    mp_receiptPrinter = new SimReceiptPrinter("Receipt Printer");
    mp_keyboard = new SimKeyboard(mp_display, mp_envelopeAcceptor);

//    // Create the GUI containing the above widgets

    mp_gui = new GUI(mp_operatorPanel,
                     mp_cardReader,
                     mp_display,
                     mp_keyboard,
                     mp_cashDispenser,
                     mp_envelopeAcceptor,
                     mp_receiptPrinter);
//    // Create the simulation of the bank

//     mp_simulatedBank = new SimulatedBank();


}

simulation::Simulation::~Simulation()
{

}

simulation::Simulation* simulation::Simulation::getInstance(atm::ATM *ap_atm)
{
    if (mp_theInstance==nullptr){// Only allow one instance of class to be generated.
       mp_theInstance = new Simulation(ap_atm);
    }
    return mp_theInstance;
}

banking::Money* simulation::Simulation::getInitialCash()
{
    return mp_gui->getInitialCash();
}

//banking::Status* simulation::Simulation::sendMessage(banking::Message *ap_message, banking::Balances *ap_balances)
//{
    // Simulate time taken to send message over network

//    try{
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//    }
//    catch(std::exception const& e){
//        qDebug()<< e.what();
//    }
    //return simulatedBank.handleMessage(message, balances);
//}


void simulation::Simulation::switchChanged(const bool &on) const
{
    // The card reader is only enabled when the switch is on
    mp_cardReader->setVisible(on);
    if (on)
        mp_atm->switchOn();
    else
        mp_atm->switchOff();


}

void simulation::Simulation::mainWindowClosed() const
{
    mp_atm->mainWindowClosed();

}

void simulation::Simulation::cardInserted() const
{
    mp_atm->cardInserted();

}

simulation::GUI* simulation::Simulation::getGUI() const
{
    return mp_gui;

}


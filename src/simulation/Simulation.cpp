#include <QDebug>
#include <thread>
#include "Simulation.h"
#include "ATM.h"
#include "SimOperatorPanel.h"
#include "SimCardReader.h"
#include "SimDisplay.h"
#include "SimCashDispenser.h"
#include "SimEnvelopeAcceptor.h"
#include "SimReceiptPrinter.h"
#include "SimKeyboard.h"
#include "GUI.h"
#include "SimulatedBank.h"

simulation::Simulation::Simulation()
{

}
simulation::Simulation::Simulation(atm::ATM *ap_atm)
{
    mp_atm = ap_atm;

    // Create the simulated individual components of the ATM's GUI
    mp_operatorPanel = new SimOperatorPanel(this);
    mp_cardReader = new SimCardReader(this);
    mp_display = new SimDisplay();
    mp_cashDispenser = new SimCashDispenser();
    mp_envelopeAcceptor = new SimEnvelopeAcceptor();
    mp_receiptPrinter = new SimReceiptPrinter();
    mp_keyboard = new SimKeyboard(display, envelopeAcceptor);

    // Create the GUI containing the above

    mp_gui = new GUI(mp_operatorPanel, mp_cardReader, mp_display, mp_keyboard,
                  mp_cashDispenser, mp_envelopeAcceptor, mp_receiptPrinter);
    // Create the simulation of the bank

     mp_simulatedBank = new SimulatedBank();

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
    //return simulatedBank.handleMessage(message, balances);
}


void simulation::Simulation::switchChanged(const bool &on)
{
    // The card reader is only enabled when the switch is on

    cardReader.setVisible(on);

    if (on)
        mp_atm->switchOn();
    else
        mp_atm->switchOff();


}

void simulation::Simulation::cardInserted()
{
    mp_atm->cardInserted();

}


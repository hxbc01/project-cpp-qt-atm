#include <QDebug>
#include "CardReader.h"


atm::physical::CardReader::CardReader()
{

}

atm::physical::CardReader::CardReader(ATM *ap_atm)
{
    mp_atm = ap_atm;

}
atm::physical::CardReader::~CardReader()
{

}

banking::Card* atm::physical::CardReader::readCard()
{
    //return Simulation.getInstance().readCard();
}

void atm::physical::CardReader::ejectCard()
{
    //Simulation.getInstance().ejectCard();

}

void atm::physical::CardReader::retainCard()
{
    //Simulation.getInstance().retainCard();

}

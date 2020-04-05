#include <QDebug>
#include "SimCardReader.h"
#include "Simulation.h"

simulation::SimCardReader::SimCardReader(const Simulation *ap_simulation) : QPushButton("Click to insert Card")
{
    // simulation object
    mp_simulation = ap_simulation;

    connect(this,SIGNAL(clicked()),this,SLOT(pushCardReaderButton()));


}

simulation::SimCardReader::~SimCardReader()
{
    //qDebug()<< "Destructor simCardReader";


}

void simulation::SimCardReader::pushCardReaderButton()
{
    qDebug()<< "Card Reader Button Clicked";
    mp_simulation->cardInserted();

}


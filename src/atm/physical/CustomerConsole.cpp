
#include <QDebug>
#include "CustomerConsole.h"

atm::physical::CustomerConsole::CustomerConsole()
{

}

atm::physical::CustomerConsole::~CustomerConsole()
{

}

void atm::physical::CustomerConsole::display(QString a_message) const
{
    qDebug()<< a_message;
    //Simulation.getInstance().clearDisplay();
    //Simulation.getInstance().display(message);
}

int atm::physical::CustomerConsole::readPIN(QString prompt) const
{
//    Simulation.getInstance().clearDisplay();
//    Simulation.getInstance().display(prompt);
//    Simulation.getInstance().display("");

    //String input = Simulation.getInstance().readInput(Simulation.PIN_MODE, 0);

    //Simulation.getInstance().clearDisplay();

//    if (input == null)
//        throw new Cancelled();
//    else
//        return Integer.parseInt(input);
}

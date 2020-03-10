
#include <QDebug>
#include "CustomerConsole.h"

atm::physical::CustomerConsole::CustomerConsole()
{

}

atm::physical::CustomerConsole::~CustomerConsole()
{

}

void atm::physical::CustomerConsole::display(QString a_message)
{
    qDebug()<< a_message;
}


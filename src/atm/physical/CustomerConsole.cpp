
#include <QDebug>
#include "CustomerConsole.h"
#include "Simulation.h"
#include "Money.h"

atm::physical::CustomerConsole::CustomerConsole()
{

}

atm::physical::CustomerConsole::~CustomerConsole()
{

}

void atm::physical::CustomerConsole::display(const QString &ar_message)
{
    qDebug()<< ar_message;
    simulation::Simulation::getInstance()->clearDisplay();
    simulation::Simulation::getInstance()->display(ar_message);

}

int atm::physical::CustomerConsole::readPIN(const QString &ar_prompt)
{
    simulation::Simulation::getInstance()->clearDisplay();
    simulation::Simulation::getInstance()->display(ar_prompt);
    simulation::Simulation::getInstance()->display("");
    QString *l_input = simulation::Simulation::getInstance()->readInput(simulation::Simulation::PIN_MODE, 0);


    simulation::Simulation::getInstance()->clearDisplay();


    if (l_input == nullptr)
    {
        qDebug()<< "exception thrown";
        throw Cancelled();
    }
    else
    {
        qDebug()<< "l_input"<<(*l_input).toInt();
        return (*l_input).toInt();
    }
}

int atm::physical::CustomerConsole::readMenuChoice(const QString &ar_prompt, const QStringList &ar_menu)
{
    simulation::Simulation::getInstance()->clearDisplay();
    simulation::Simulation::getInstance()->display(ar_prompt);

    for (int i = 0; i < ar_menu.length(); i ++)
    {
        simulation::Simulation::getInstance()->display(QString::number(i+1) + ") " + ar_menu.at(i));
    }

    QString *l_input = simulation::Simulation::getInstance()->readInput(simulation::Simulation::MENU_MODE, ar_menu.length());

    simulation::Simulation::getInstance()->clearDisplay();

    if (l_input == nullptr)
    {
        qDebug()<< "exception thrown";
        throw Cancelled();
    }
    else
    {
        qDebug()<< "l_input"<<(*l_input).toInt();
        return (*l_input).toInt()-1;
    }


}

banking::Money* atm::physical::CustomerConsole::readAmount(QString &ar_prompt)
{
    simulation::Simulation::getInstance()->clearDisplay();
    simulation::Simulation::getInstance()->display(ar_prompt);
    simulation::Simulation::getInstance()->display("");

    QString *l_input = simulation::Simulation::getInstance()->readInput(simulation::Simulation::AMOUNT_MODE, 0);

    simulation::Simulation::getInstance()->clearDisplay();

    if (l_input == nullptr)
    {
        qDebug()<< "exception thrown";
        throw Cancelled();
    }
    else
    {
        int dollars = (*l_input).toInt() / 100;
        int cents = (*l_input).toInt() % 100;
        return new banking::Money(dollars, cents);
    }


}

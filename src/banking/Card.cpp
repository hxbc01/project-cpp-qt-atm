#include <QDebug>
#include "Card.h"

banking::Card::Card()
{

}
banking::Card::Card(int a_number):m_number(a_number)
{

}

banking::Card::~Card()
{

}

int banking::Card::getNumber()
{
    return m_number;
}




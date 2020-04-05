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

int banking::Card::getNumber() const
{
    return m_number;
}


void banking::Card::setNumber(int a_number)
{
    m_number = a_number;
}

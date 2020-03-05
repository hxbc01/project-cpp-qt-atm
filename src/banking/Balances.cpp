#include <QDebug>
#include "Balances.h"

banking::Balances::Balances()
{

}


banking::Balances::~Balances()
{

}

void banking::Balances::setBalances(Money a_total, Money a_available)
{
    m_total = a_total;
    m_available = a_available;
}


banking::Money banking::Balances::getTotal()
{
    return m_total;
}

banking::Money banking::Balances::getAvailable()
{
    return m_available;
}




#include "Money.h"

banking::Money::Money(int a_dollars): Money(a_dollars,0)
{


}

banking::Money::Money(int a_dollars, int a_cents)
{
    this->m_cents = (100 * a_dollars) + a_cents;
}

banking::Money::Money(const Money & a_toCopy)
{
    this->m_cents = a_toCopy.m_cents;
}

banking::Money::~Money()
{

}

void banking::Money::add(Money a_amountToAdd)
{
    this->m_cents += a_amountToAdd.m_cents;
}

void banking::Money::subtract(Money a_amountToSubtract)
{
    this->m_cents -= a_amountToSubtract.m_cents;
}

bool banking::Money::lessEqual(Money a_compareTo)
{
    return this->m_cents <= a_compareTo.m_cents;
}

QString banking::Money::toString()
{
 return "$" + QString::number(m_cents/100) + (m_cents %100 >= 10  ? "." + QString::number(m_cents % 100) : ".0" + QString::number(m_cents % 100));
}

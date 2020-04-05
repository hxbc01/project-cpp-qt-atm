#include <QDebug>
#include "Money.h"

banking::Money::Money():Money(0)
{


}

banking::Money::Money(int a_dollars): Money(a_dollars,0)
{


}

banking::Money::Money(int a_dollars, int a_cents)
{
    m_cents = (100 * a_dollars) + a_cents;
}

banking::Money::Money(const Money & a_toCopy)
{
    m_cents = a_toCopy.m_cents;
}

banking::Money::~Money()
{

}

void banking::Money::add(const Money *a_amountToAdd)
{
    m_cents += a_amountToAdd->m_cents;
}

void banking::Money::subtract(const Money *a_amountToSubtract)
{
    m_cents -= a_amountToSubtract->m_cents;
}

bool banking::Money::lessEqual(const Money *a_compareTo) const
{
    return m_cents <= a_compareTo->m_cents;
}

QString banking::Money::toString() const
{
 return "$" + QString::number(m_cents/100) + (m_cents %100 >= 10  ? "." + QString::number(m_cents % 100) : ".0" + QString::number(m_cents % 100));
}

void banking::Money::setMoney(int a_dollars, int a_cents)
{
    m_cents = (100 * a_dollars) + a_cents;

}

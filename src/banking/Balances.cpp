#include <QDebug>
#include "Balances.h"

banking::Balances::Balances()
{

}


banking::Balances::~Balances()
{

}

void banking::Balances::setBalances(Money *ap_total, Money *ap_available)
{
    mp_total = ap_total;
    mp_available = ap_available;
}


banking::Money* banking::Balances::getTotal() const
{
    return mp_total;
}

banking::Money* banking::Balances::getAvailable() const
{
    return mp_available;
}




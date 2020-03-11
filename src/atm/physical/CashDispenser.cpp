#include <QDebug>
#include "CashDispenser.h"
#include "Money.h"

atm::physical::CashDispenser::CashDispenser()
{

}
atm::physical::CashDispenser::CashDispenser(Log *ap_log)
{
    mp_log = ap_log;
    mp_cashOnATM = new banking::Money(0);

}

atm::physical::CashDispenser::~CashDispenser()
{
    delete mp_cashOnATM;
    mp_cashOnATM = nullptr;

}

void atm::physical::CashDispenser::setInitialCashOnATM(const banking::Money a_initialCash)
{
    *mp_cashOnATM = a_initialCash;

}

bool atm::physical::CashDispenser::checkCashOnATM(const banking::Money *ap_amount)
{
    return ap_amount->lessEqual(mp_cashOnATM);

}

void atm::physical::CashDispenser::dispenseCash(const banking::Money *ap_amount)
{
    mp_cashOnATM->subtract(ap_amount);
    //Simulation.getInstance().dispenseCash(amount);
    // Log cash having been dispensed
    mp_log->logCashDispensed(ap_amount);

}

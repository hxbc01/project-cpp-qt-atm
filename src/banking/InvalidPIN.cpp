#include <QDebug>
#include "InvalidPIN.h"


banking::InvalidPIN::InvalidPIN() : StatusFailure("Invalid PIN")
{

}

banking::InvalidPIN::~InvalidPIN()
{

}

bool banking::InvalidPIN::isInvalidPIN()
{
    return true;
}




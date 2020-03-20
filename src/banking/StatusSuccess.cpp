#include <QDebug>
#include "StatusSuccess.h"

banking::StatusSuccess::StatusSuccess()
{

}


banking::StatusSuccess::~StatusSuccess()
{

}

bool banking::StatusSuccess::isSuccess()
{
    return true;
}

bool banking::StatusSuccess::isInvalidPIN()
{
    return false;
}

QString banking::StatusSuccess::getMessage()
{
    return "";
}





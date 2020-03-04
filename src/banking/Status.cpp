#include <QDebug>
#include "Status.h"

banking::Status::Status()
{

}

banking::Status::~Status()
{

}

QString banking::Status::toString()
{
    if (isSuccess())
        return "SUCCESS";
    else if (isInvalidPIN())
        return "INVALID PIN";
    else
        return "FAILURE " + getMessage();
}







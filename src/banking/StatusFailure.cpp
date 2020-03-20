#include <QDebug>
#include "StatusFailure.h"

banking::StatusFailure::StatusFailure()
{

}
banking::StatusFailure::StatusFailure(QString message) : m_message(message)
{


}

banking::StatusFailure::~StatusFailure()
{

}

bool banking::StatusFailure::isSuccess()
{
    return false;
}

bool banking::StatusFailure::isInvalidPIN()
{
    return false;
}

QString banking::StatusFailure::getMessage()
{
    return m_message;
}



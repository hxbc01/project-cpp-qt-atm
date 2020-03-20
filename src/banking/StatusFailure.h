/**
 * @file StatusFailure.h
 * @brief Header file of the StatusFailure class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef STATUSFAILURE_H
#define STATUSFAILURE_H
#include <QString>
#include "Status.h"
/** Representation for status of a transaction that failed (for reason other than
 *  invalid PIN)
 */
namespace banking
{
class StatusFailure : public Status
{

public:
    /** Default Constructor
     */
    StatusFailure();
    /** Constructor
     *
     *  @param message description of the failure
     */
    StatusFailure(QString message);

    /** Destructor
     */
    ~StatusFailure();
    /** status represents failure so return false
     */
    bool isSuccess();
    /** failure not due to invalid PIN
     */
    bool isInvalidPIN();
    /** return failure message
     */
    QString getMessage();

protected:


private:
    /** failure message
     */
    QString m_message;

};
}

#endif // STATUSFAILURE_H


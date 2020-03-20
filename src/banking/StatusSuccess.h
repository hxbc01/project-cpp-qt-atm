/**
 * @file StatusSuccess.h
 * @brief Header file of the StatusSuccess class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef STATUSSUCCESS_H
#define STATUSSUCCESS_H
#include "Status.h"
/** Representation for status of a transaction that succeeded
 */
namespace banking
{
class StatusSuccess : public Status
{

public:
    /** Default Constructor
     */
    StatusSuccess();
    /** Destructor
     */
    ~StatusSuccess();
    /** return true since status represents sccess
     */
    bool isSuccess();
    /** return false valid PIN
     */
    bool isInvalidPIN();
    /** return null for success message
     */
    QString getMessage();

protected:


private:


};
}

#endif // STATUSSUCCESS_H


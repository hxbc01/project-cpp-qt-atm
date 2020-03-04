/**
 * @file Status.h
 * @brief Header file of the Status class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef STATUS_H
#define STATUS_H
#include <QString>
/** Abstract base class for representation of various status codes returned
 *  by bank for a transaction.  The bank will create appropriate subclasses.
 */
namespace banking
{
class Status
{

public:
    /** Default Constructor
     */
    Status();
    /** Destructor
     */
    virtual ~Status();
    /** See if this status represents success
     *
     *  @return true if this status represents success
     */
    virtual bool isSuccess() = 0;

    /** See if this status represents an invalid PIN
     *
     *  @return true if this status represents an invalid PIN
     */
    virtual bool isInvalidPIN() = 0;

    /** Accessor for message describing this status (used if status is
     *  not success)
     *
     *  @return description of the problem
     */
    virtual QString getMessage() = 0;
    /** Create a printable string representing this status
     *
     *  @return string representation
     */
    QString toString();

protected:


private:


};
}

#endif // STATUS_H


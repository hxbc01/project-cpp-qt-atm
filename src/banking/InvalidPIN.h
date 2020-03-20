/**
 * @file InvalidPIN.h
 * @brief Header file of the InvalidPIN class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef INVALIDPIN_H
#define INVALIDPIN_H
#include "StatusFailure.h"
/** Representation for status of a transaction that failed due to an invalid PIN
 */
namespace banking
{
class InvalidPIN : public StatusFailure
{

public:
    /** Default Constructor
     */
    InvalidPIN();

    /** Destructor
     */
    ~InvalidPIN();
    /** Accessor for number
      *
      *  @return the number of the card
      */
    bool isInvalidPIN();

protected:


private:
    /** Card number encoded on the card
     */
    int m_number;

};
}

#endif // INVALIDPIN_H


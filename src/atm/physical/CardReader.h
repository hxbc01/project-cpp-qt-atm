/**
 * @file CardReader.h
 * @brief Header file of the CardReader class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef CARDREADER_H
#define CARDREADER_H


//#include "Card.h"
/** Manager for the ATM's card reader.  In a real ATM, this would
 *  manage a physical device; in this simulation, it uses classes
 *  in package simulation to simulate the device.
 */
// forward declared dependencies
//class Message;
//class Status;
class ATM;
class Card;


namespace atm
{
namespace physical
{
class CardReader
{

public:
    /** Default Constructor
     */
    CardReader();
    /** Constructor
     *
     *  @param atm the ATM that owns this card reader
     */
    CardReader(ATM *ap_atm);
    /** Destructor
     */
    ~CardReader();
    // In a real ATM, code would be needed to sense insertion of a card into the
    // slot and notify the ATM - simulated in this case by a button in the GUI

    /** Read a card that has been partially inserted into the reader
     *
     *  @return Card object representing information on the card if read
     *          successfully, null if not read successfully
     */
    Card readCard();
    /** Eject the card that is currently inside the reader.
     */
    void ejectCard();
    /** Retain the card that is currently inside the reader for action by the
     *  bank.
     */
    void retainCard();

protected:


private:
    ATM *mp_atm=nullptr;

};
}
}

#endif // CARDREADER_H

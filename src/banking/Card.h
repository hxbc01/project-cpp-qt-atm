/**
 * @file Card.h
 * @brief Header file of the Card class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef CARD_H
#define CARD_H
/** Representation for customer's ATM card
 */
namespace banking
{
class Card
{

public:
    /** Default Constructor
     */
    Card();
    /** Constructor
     *
     *  @param number the card number
     */
    explicit Card(int a_number);

    /** Destructor
     */
    ~Card();
    /** Accessor for number
      *
      *  @return the number of the card
      */
    int getNumber() const;

protected:


private:
    /** Card number encoded on the card
     */
    int m_number;

};
}

#endif // CARD_H


/**
 * @file Money.h
 * @brief Header file of the Money class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef MONEY_H
#define MONEY_H
#include <QString>
/**
 * @brief Representation for money amounts
 */
namespace banking
{
class Money
{

public:
    /** Default Constructor
     */
    Money();
    /** Constructor
     *
     *  @param dollars whole dollar amount
     */
    explicit Money(int a_dollars);
    /** Constructor
     *
     *  @param dollars dollar part of amount
     *  @param cents cents part of amount
     */
    explicit Money(int a_dollars, int a_cents);
    /** Copy constructor
     *
     *  @param toCopy the Money object to copy
     */
    Money(const Money & a_toCopy);
    /** Destructor
     */
    ~Money();
    /** Create a string representation of this amount
     *
     *  @return string representation of this amount
     */
    QString toString() const;
    /** Add an amount of money to this
     *
     *  @param amountToAdd the amount to add
     */
    void add(const Money *a_amountToAdd);
    /** Subtract an amount of money from this
     *
     *  @param amountToSubtract the amount to subtract
     *
     *  Precondition: amount must be <= this amount
     */
    void subtract(const Money *a_amountToSubtract);
    /** Compare this to another amount
     *
     *  @param compareTo the amount to compare to
     *  @return true if this amount is <= compareTo amount
     */
    bool lessEqual(const Money *a_compareTo) const;
    /** set Money amount
     *
     */
    void setMoney(int a_dollars=0, int a_cents=0);

protected:


private:
    /** Instance variable: this amount represented as a number of cents
      */
    int m_cents;

};
}

#endif // MONEY_H

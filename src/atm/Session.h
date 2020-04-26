/**
 * @file Session.h
 * @brief Header file of the Session class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef SESSION_H
#define SESSION_H
#include <QObject>
#include <mutex>
#include <condition_variable>
/** Representation for one ATM
 * session serving a single customer. */
namespace banking
{
class Card;
}
namespace atm
{
class ATM;
}
namespace atm
{
class Session : public QObject
{
    Q_OBJECT

public:
    /** Constructor
     *
     *  @param atm the ATM on which the session is performed
     */
    Session(ATM *ap_atm);

    /** Destructor
     */
    ~Session();
    /** Perform the Session Use Case
     */
    void performSession();
    /** Change the pin recorded for the customer (if invalid pin extension
      *  was performed by a transaction
      *
      *  @param pin the newly entered pin
      */
    void setPIN(int a_pin);


protected:

signals:
    void readCardSignal();
    void customerConsoleDisplaySignal(const QString&);
    void readPINSignal(const QString&);


private:
    // Instance variables


    /** The ATM on which the session is performed
     */
    ATM *mp_atm=nullptr;

    /** The PIN entered (or re-entered) by the customer
     */
    int m_pin;

    /** The current state of the session
     */
    int m_state;

    // Possible values for state

    /** Reading the customer's card
     */
    static const int READING_CARD_STATE = 1;

    /** Asking the customer to enter a PIN
     */
    static const int READING_PIN_STATE = 2;

    /** Asking the customer to choose a transaction type
     */
    static const int CHOOSING_TRANSACTION_STATE = 3;

    /** Peforming a transaction
     */
    static const int PERFORMING_TRANSACTION_STATE = 4;

    /** Ejecting the customer's card
     */
    static const int EJECTING_CARD_STATE = 5;

    /** Session finished
     */
    static const int FINAL_STATE = 6;


};
}

#endif // SESSION_H


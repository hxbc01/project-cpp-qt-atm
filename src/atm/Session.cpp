#include <QDebug>
#include <QString>
#include "Session.h"
#include "Card.h"
#include "Transaction.h"
#include "ATM.h"
#include "CardReader.h"
#include "CustomerConsole.h"

atm::Session::Session()
{

}
atm::Session::Session(ATM *ap_atm)
{
    mp_atm=ap_atm;
    m_state=READING_CARD_STATE;

}

atm::Session::~Session()
{

}

void atm::Session::performSession()
{
//    banking::Card *l_card = nullptr;
//    transaction::Transaction l_currentTransaction;
//    while (m_state != FINAL_STATE) {
//        switch (m_state) {
//            case READING_CARD_STATE :
//                l_card = mp_atm->getCardReader()->readCard();
//                if (l_card != nullptr){
//                    m_state = READING_PIN_STATE;
//                }
//                else {
//                    mp_atm->getCustomerConsole()->display("Unable to read card");
//                    m_state = EJECTING_CARD_STATE;
//                }
//                break;
//            case READING_PIN_STATE :
//                try {
//                    m_pin = mp_atm->getCustomerConsole()->readPIN(QString("Please enter your PIN\n") + QString("Then press ENTER"));

//                } catch (...) {

//                    m_state = EJECTING_CARD_STATE;
//                }
//                break;
//            case CHOOSING_TRANSACTION_STATE :
//                try {
//                        l_currentTransaction =

//                } catch (...) {
//                }

//            case PERFORMING_TRANSACTION_STATE :
//            case EJECTING_CARD_STATE :

//        }

//    }


}

void atm::Session::setPIN(int a_pin)
{
    m_pin=a_pin;

}

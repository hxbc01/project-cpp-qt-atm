#include <QDebug>
#include <QString>
#include "Session.h"
#include "Card.h"
#include "Transaction.h"
#include "ATM.h"
#include "CardReader.h"
#include "CustomerConsole.h"

atm::Session::Session(ATM *ap_atm)
{
    mp_atm=ap_atm;
    m_state=READING_CARD_STATE;
    connect(this, SIGNAL(readCardSignal()),
                   mp_atm, SLOT(readCard()),Qt::BlockingQueuedConnection);
    connect(this, SIGNAL(customerConsoleDisplaySignal(const QString&)),
                   mp_atm, SLOT(customerConsoleDisplay(const QString&)),Qt::BlockingQueuedConnection);
    connect(this, SIGNAL(readPINSignal(const QString&)),
                   mp_atm, SLOT(readPIN(const QString&)),Qt::BlockingQueuedConnection);



}

atm::Session::~Session()
{
qDebug()<< "Destructor Session";
}

void atm::Session::performSession()
{
    qDebug()<< "performSession()";
    banking::Card *lp_card = nullptr;
    int l_pin=-1;
    transaction::Transaction *lp_currentTransaction= nullptr;;
    while ((m_state != FINAL_STATE) && (mp_atm->isATMThreadRunning())) {
        switch (m_state) {
            case READING_CARD_STATE :
            {
                emit readCardSignal();
                lp_card = mp_atm->getCard();
                if (lp_card != nullptr){
                    m_state = READING_PIN_STATE;
                }
                else {

                    emit customerConsoleDisplaySignal("Unable to read card");
                    m_state = EJECTING_CARD_STATE;
                }
                break;
             }
             case READING_PIN_STATE :
             {
                qDebug()<< "READING_PIN_STATE";                
                emit readPINSignal(QString("Please enter your PIN\n") + QString("Then press ENTER"));

                if(ATM::p_cancelled != nullptr)
                {
                    try {
                        std::rethrow_exception(ATM::p_cancelled);

                    } catch (const std::exception &) {
                        qDebug()<< "PIN input Cancelled by Customer";
                        m_state = EJECTING_CARD_STATE;
                    }
                } else {
                    l_pin = mp_atm->getPin();
                    qDebug()<< "l_pin"<<l_pin;
                    m_state = CHOOSING_TRANSACTION_STATE;
                }
              break;
              }
              case CHOOSING_TRANSACTION_STATE :
              {
                try
                {
                    //lp_currentTransaction = transaction::Transaction.makeTransaction(atm, this, card, pin);
                    m_state = PERFORMING_TRANSACTION_STATE;
                }
                catch(...)
                {
                    m_state = EJECTING_CARD_STATE;
                }
                break;
                }
//                case PERFORMING_TRANSACTION_STATE :
//                {
//                    try
//                    {
//                        bool doAgain = currentTransaction.performTransaction();
//                        if (doAgain)
//                        {
//                            m_state = CHOOSING_TRANSACTION_STATE;
//                        }
//                        else
//                        {
//                            m_state = EJECTING_CARD_STATE;
//                        }

//                    }
//                    catch(...)
//                    {
//                        m_state = FINAL_STATE;
//                    }
//                    break;

//                }
//                case EJECTING_CARD_STATE :
//                {
//                    atm.getCardReader().ejectCard();
//                    m_state = FINAL_STATE;
//                    break;

//                }

        }
        //qDebug() << "session loop running";

    }


}

void atm::Session::setPIN(int a_pin)
{
    m_pin=a_pin;

}






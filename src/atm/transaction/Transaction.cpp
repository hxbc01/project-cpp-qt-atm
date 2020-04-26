#include <QDebug>
#include "Transaction.h"
#include "Balances.h"
#include "Withdrawal.h"
#include "Deposit.h"
#include "Transfer.h"
#include "Inquiry.h"
#include "ATM.h"
#include "CustomerConsole.h"
#include "Receipt.h"
#include "Status.h"
#include "NetworkToBank.h"
#include "ReceiptPrinter.h"
#include "Message.h"
#include "Session.h"

const QStringList atm::transaction::Transaction::TRANSACTION_TYPES_MENU = {"Withdrawal", "Deposit", "Transfer", "Balance Inquiry"};
int atm::transaction::Transaction::m_nextSerialNumber = 1;
atm::transaction::Transaction::Transaction()
{

}

atm::transaction::Transaction::Transaction(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin)
{
    mp_atm = ap_atm;
    mp_session = ap_session;
    mp_card = ap_card;
    m_pin = a_pin;
    m_serialNumber = m_nextSerialNumber ++;
    mp_balances = new banking::Balances();
    
    m_state = GETTING_SPECIFICS_STATE;

}


atm::transaction::Transaction::~Transaction()
{
    delete mp_balances;
    mp_balances = nullptr;

}

atm::transaction::Transaction* atm::transaction::Transaction::makeTransaction(ATM *ap_atm, Session *ap_session, banking::Card *ap_card, int a_pin)
{
    int choice = ap_atm->getCustomerConsole()->readMenuChoice("Please choose transaction type", TRANSACTION_TYPES_MENU);

        switch(choice)
        {
            case 0:
            {

                return new Withdrawal(ap_atm, ap_session, ap_card, a_pin);
            }
            case 1:
            {
                return new Deposit(ap_atm, ap_session, ap_card, a_pin);
            }
            case 2:
            {
                return new Transfer(ap_atm, ap_session, ap_card, a_pin);
            }
            case 3:
            {
                return new Inquiry(ap_atm, ap_session, ap_card, a_pin);
            }
            default:
            {
                return nullptr;
            }
        }


}

int atm::transaction::Transaction::getSerialNumber() const
{
    return m_serialNumber;

}

bool atm::transaction::Transaction::performTransaction()
{
    QString doAnotherMessage = "";
    banking::Status *lp_status = nullptr;
    banking::Receipt *lp_receipt = nullptr;

    while (true)    // Terminates by return in ASKING_DO_ANOTHER_STATE or exception
    {
        switch(m_state)
        {
            case GETTING_SPECIFICS_STATE:
            {
                try
                {
                    mp_message = getSpecificsFromCustomer();
                    mp_atm->getCustomerConsole()->display("");
                    m_state = SENDING_TO_BANK_STATE;
                }
                catch(atm::physical::CustomerConsole::Cancelled &e)
                {
                    qDebug()<< "Transaction e.what()"<<e.what();
                    doAnotherMessage = "Last transaction was cancelled";
                    m_state = ASKING_DO_ANOTHER_STATE;
                }

                break;
            }
        case SENDING_TO_BANK_STATE:
        {

            lp_status = mp_atm->getNetworkToBank()->sendMessage(mp_message, mp_balances);

            if (lp_status->isInvalidPIN())
                m_state = INVALID_PIN_STATE;
            else if (lp_status->isSuccess())
                m_state = COMPLETING_TRANSACTION_STATE;
            else
            {
                doAnotherMessage = lp_status->getMessage();
                m_state = ASKING_DO_ANOTHER_STATE;
            }

            break;
        }
        case INVALID_PIN_STATE:
        {

            try
            {
                lp_status = performInvalidPINExtension();

                // If customer repeatedly enters invalid PIN's, a
                // CardRetained exception is thrown, and this method
                // terminates

                    if (lp_status->isSuccess())
                    {
                        m_state = COMPLETING_TRANSACTION_STATE;
                    }
                    else
                    {
                        doAnotherMessage = lp_status->getMessage();
                        m_state = ASKING_DO_ANOTHER_STATE;
                    }
                }
                catch(atm::physical::CustomerConsole::Cancelled &e)
                {
                    qDebug()<< "Transaction e.what()"<<e.what();
                    doAnotherMessage = "Last transaction was cancelled";
                    m_state = ASKING_DO_ANOTHER_STATE;
                }

                break;
            }
            case COMPLETING_TRANSACTION_STATE:
            {

                try
                {
                    lp_receipt = completeTransaction();
                    m_state = PRINTING_RECEIPT_STATE;
                }
                catch(atm::physical::CustomerConsole::Cancelled &e)
                {
                    qDebug()<< "Transaction e.what()"<<e.what();
                    doAnotherMessage = "Last transaction was cancelled";
                    m_state = ASKING_DO_ANOTHER_STATE;
                }

                break;
            }
            case PRINTING_RECEIPT_STATE:
            {
                mp_atm->getReceiptPrinter()->printReceipt(lp_receipt);
                m_state = ASKING_DO_ANOTHER_STATE;
                break;
            }
            case ASKING_DO_ANOTHER_STATE:
            {
                if (doAnotherMessage.length() > 0)
                {
                    doAnotherMessage += "\n";
                }

                try
                {
                    QStringList yesNoMenu = { "Yes", "No" };

                    bool doAgain = mp_atm->getCustomerConsole()->readMenuChoice(
                    doAnotherMessage +
                    "Would you like to do another transaction?",
                    yesNoMenu) == 0;
                    return doAgain;
                }
                catch(atm::physical::CustomerConsole::Cancelled &e)
                {
                    return false;
                }
            }

        }
    }
}


banking::Status* atm::transaction::Transaction::performInvalidPINExtension()
{
    banking::Status *lp_status = nullptr;

    for (int i = 0; i < 3; i ++)
    {
        m_pin = mp_atm->getCustomerConsole()->readPIN(
            "PIN was incorrect\nPlease re-enter your PIN\n" +
            "Then press ENTER");
        mp_atm->getCustomerConsole()->display("");

        mp_message->setPIN(m_pin);
        lp_status = mp_atm->getNetworkToBank()->sendMessage(mp_message, mp_balances);
        if (! lp_status->isInvalidPIN())
        {
            mp_session->setPIN(pin);
            return status;
        }
    }


}

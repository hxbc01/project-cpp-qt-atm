#include "Message.h"
#include "Card.h"
#include "Money.h"

banking::Message::Message()
{

}

banking::Message::Message(int a_messageCode, Card *ap_card, int a_pin,
                          int a_serialNumber, int a_fromAccount,
                          int a_toAccount, Money *ap_amount)
{
    m_messageCode = a_messageCode;
    mp_card = ap_card;
    m_pin = a_pin;
    m_serialNumber = a_serialNumber;
    m_fromAccount = a_fromAccount;
    m_toAccount = a_toAccount;
    mp_amount = ap_amount;

}

banking::Message::~Message()
{

}

void banking::Message::setPIN(int a_pin)
{
    m_pin = a_pin;
}

int banking::Message::getMessageCode()
{
    return m_messageCode;
}

banking::Card* banking::Message::getCard() const
{
    return mp_card;
}

int banking::Message::getPIN() const
{
    return m_pin;
}

int banking::Message::getSerialNumber() const
{
    return m_serialNumber;
}

int banking::Message::getFromAccount() const
{
    return m_fromAccount;
}

int banking::Message::getToAccount() const
{
    return m_toAccount;
}

banking::Money* banking::Message::getAmount() const
{
    return mp_amount;
}


QString banking::Message::toString()
{
    QString result ="";
    switch (m_messageCode)
    {
        case WITHDRAWAL:

            result += "WITHDRAW";
            break;

        case INITIATE_DEPOSIT:

            result += "INIT_DEP";
            break;

        case COMPLETE_DEPOSIT:

            result += "COMP_DEP";
            break;

        case TRANSFER:

            result += "TRANSFER";
            break;

        case INQUIRY:

            result += "INQUIRY ";
            break;
    }

    result += " CARD# " + QString::number(mp_card->getNumber());
    result += " TRANS# " + QString::number(m_serialNumber);
    if (m_fromAccount >= 0)
        result += " FROM  " + QString::number(m_fromAccount);
    else
        result += " NO FROM";
    if (m_toAccount >= 0)
        result += " TO  " + QString::number(m_toAccount);
    else
        result += " NO TO";
    if (! mp_amount->lessEqual(new Money(0)))
        result += " " + mp_amount->toString();
    else
        result += " NO AMOUNT";

    return result;
}

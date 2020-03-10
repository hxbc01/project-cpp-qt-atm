#include <QDebug>
#include "NetworkToBank.h"

atm::physical::NetworkToBank::NetworkToBank()
{

}
atm::physical::NetworkToBank::NetworkToBank(Log *ap_log, QString a_bankAddress)
{
    mp_log = ap_log;
    m_bankAddress = a_bankAddress;

}

atm::physical::NetworkToBank::~NetworkToBank()
{

}

void atm::physical::NetworkToBank::openConnection()
{
    qDebug()<< "Open connection to Bank";

}

void atm::physical::NetworkToBank::closeConnection()
{
    qDebug()<< "Close connection to Bank";

}

banking::Status* atm::physical::NetworkToBank::sendMessage(banking::Message *ap_message, banking::Balances *ap_balances)
{
            // Log sending of the message
            mp_log->logSend(ap_message);
            //*******************++++++++++++
            // Simulate the sending of the message - here is where the real code
            // to actually send the message over the network would go
            //*******************++++++++++++
            mp_log->logResponse();
}

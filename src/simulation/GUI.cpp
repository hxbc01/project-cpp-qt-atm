#include <QDebug>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "GUI.h"
#include "ATMPanel.h"
#include "LogPanel.h"
#include "CardPanel.h"
#include "BillsPanel.h"
#include "Card.h"
#include "Money.h"
#include "SimOperatorPanel.h"
#include "SimCardReader.h"
#include "SimDisplay.h"
#include "SimKeyboard.h"
#include "SimCashDispenser.h"
#include "SimEnvelopeAcceptor.h"
#include "SimReceiptPrinter.h"


simulation::GUI::GUI()
{

}

simulation::GUI::GUI(SimOperatorPanel *ap_operatorPanel,
                     SimCardReader *ap_cardReader,
                     SimDisplay *ap_display,
                     SimKeyboard *ap_keyboard,
                     SimCashDispenser *ap_cashDispenser,
                     SimEnvelopeAcceptor *ap_envelopeAcceptor,
                     SimReceiptPrinter *ap_receiptPrinter)
{
    // create a Card object
    mp_card = new banking::Card();
    // create a Money object for initial cash
    mp_money = new banking::Money();
    // overall ATM GUI
    mp_atmGUI = new QStackedWidget();
    // ATM panel
    mp_atmPanel = new ATMPanel(this,
                               ap_operatorPanel,
                               ap_cardReader,
                               ap_display,
                               ap_keyboard,
                               ap_cashDispenser,
                               ap_envelopeAcceptor,
                               ap_receiptPrinter);
    // Log panel
    mp_logPanel = new LogPanel(this);

    // Card panel
    mp_cardPanel = new CardPanel();

    // Bills panel
    mp_billsPanel = new BillsPanel();

    // create a the GUI layout
    mp_GUIVLayout = new QVBoxLayout(this);
    // add ATMPanel widget
    mp_atmGUI->addWidget(mp_atmPanel);
    // add LogPanel widget
    mp_atmGUI->addWidget(mp_logPanel);
    // add BillsPanel widget
    mp_atmGUI->addWidget(mp_billsPanel);

    mp_GUIVLayout->addWidget(mp_atmGUI);
    mp_GUIVLayout->setAlignment(mp_atmGUI,Qt::AlignCenter);

    // Set layout to current Widget
    setLayout(mp_GUIVLayout);
}



simulation::GUI::~GUI()
{
//    qDebug()<< "Destructor GUI";
//    delete mp_atmGUI;
//    mp_atmGUI = nullptr;

}


QStackedWidget* simulation::GUI::getStackedWidget() const
{
    return mp_atmGUI;

}

simulation::LogPanel* simulation::GUI::getLogPanel() const
{
    return mp_logPanel;

}

simulation::ATMPanel* simulation::GUI::getATMPanel() const
{
    return mp_atmPanel;

}

banking::Card* simulation::GUI::readCard()
{
    mp_cardPanel->show();
    mp_cardPanel->m_loop.exec();
    int cardNumber = mp_cardPanel->readCardNumber();   
    mp_atmGUI->setCurrentWidget(mp_atmPanel);

    if (cardNumber > 0){
        mp_card->setNumber(cardNumber);
        return mp_card;
    }
    else
        return mp_card;
}

banking::Money* simulation::GUI::getInitialCash()
{
    mp_atmGUI->setCurrentWidget(mp_billsPanel);
    mp_billsPanel->m_loop.exec();
    int numberOfBills = mp_billsPanel->readBills();
    mp_atmGUI->setCurrentWidget(mp_atmPanel);
//    mp_money->setMoney(20*numberOfBills);

    return mp_money;
}

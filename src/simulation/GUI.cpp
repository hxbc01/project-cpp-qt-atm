#include <QDebug>
#include <QStackedWidget>
#include "GUI.h"
#include "ATMPanel.h"
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
    mp_atmGUI = new QStackedWidget();
    mp_atmPanel = new ATMPanel(this,
                               ap_operatorPanel,
                               ap_cardReader,
                               ap_display,
                               ap_keyboard,
                               ap_cashDispenser,
                               ap_envelopeAcceptor,
                               ap_receiptPrinter);
    mp_atmGUI->addWidget(mp_atmPanel);
}



simulation::GUI::~GUI()
{

}




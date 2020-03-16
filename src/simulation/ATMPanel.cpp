#include <QDebug>
#include "ATMPanel.h"
#include <QVBoxLayout>
#include <QLabel>
#include "SimOperatorPanel.h"

simulation::ATMPanel::ATMPanel()
{

}

simulation::ATMPanel::ATMPanel(const GUI *ap_gui,
                               SimOperatorPanel *ap_operatorPanel,
                               SimCardReader *ap_cardReader,
                               SimDisplay *ap_display,
                               SimKeyboard *ap_keyboard,
                               SimCashDispenser *ap_cashDispenser,
                               SimEnvelopeAcceptor *ap_envelopeAcceptor,
                               SimReceiptPrinter *ap_receiptPrinter)
{


    // Label for the ATM GUI
    mp_ATMLabel = new QLabel("ATM");
    // create a the ATM GUI layout
    mp_ATMLayout = new QVBoxLayout(this);
    // Add the ATM label
    mp_ATMLayout->addWidget(mp_ATMLabel);
    // Add the operator panel
    mp_ATMLayout->addWidget(ap_operatorPanel);

}

simulation::ATMPanel::~ATMPanel()
{

}





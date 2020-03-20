#include <QDebug>
#include "ATMPanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>
#include "SimOperatorPanel.h"
#include "SimDisplay.h"
#include "SimCardReader.h"
#include "SimEnvelopeAcceptor.h"
#include "SimKeyboard.h"
#include "SimReceiptPrinter.h"
#include "SimCashDispenser.h"
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
    mp_ATMLabel->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    mp_ATMLabel->setFont(QFont("Verdana",24,75));

    // create a the ATM GUI layout
    mp_ATMVLayout = new QVBoxLayout();
    // Add the ATM label
    mp_ATMVLayout->addWidget(mp_ATMLabel);
    mp_ATMVLayout->setAlignment(mp_ATMLabel,Qt::AlignCenter);
    // add the display
    mp_ATMVLayout->addWidget(ap_display);
    mp_ATMVLayout->setAlignment(ap_display,Qt::AlignCenter);
    // add card reader and envelope acceptor
    mp_CEHLayout = new QHBoxLayout();
    // add card reader
    mp_CEHLayout->addWidget(ap_cardReader);
    // add envelope acceptor
    mp_CEHLayout->addWidget(ap_envelopeAcceptor);
    mp_ATMVLayout->addLayout(mp_CEHLayout);
    // add cash dispenser and receipt printer
    mp_CRHLayout = new QVBoxLayout();
    // add cash dispenser
    mp_CRHLayout->addWidget(ap_cashDispenser);
    // add receipt printer
    mp_CRHLayout->addWidget(ap_receiptPrinter);

    // add keyboard, cash dispenser and receipt printer
    mp_KCRHLayout = new QHBoxLayout();
    // add keybord
    mp_KCRHLayout->addWidget(ap_keyboard);
    mp_KCRHLayout->addLayout(mp_CRHLayout);
    mp_ATMVLayout->addLayout(mp_KCRHLayout);

    // Add the operator panel
    mp_ATMVLayout->addWidget(ap_operatorPanel);
    mp_ATMVLayout->setAlignment(ap_operatorPanel,Qt::AlignCenter);

    // Set layout to current Widget
    setLayout(mp_ATMVLayout);


}

simulation::ATMPanel::~ATMPanel()
{

}





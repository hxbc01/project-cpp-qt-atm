#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QString>
#include "CardPanel.h"

simulation::CardPanel::CardPanel()
{
    mp_infoLabel = new QLabel("Hallo");
    mp_cardNumberField = new QLineEdit();
    mp_cardNumberField->setPlaceholderText("Card number");
    mp_cardNumberField->setFocus();
    // validate input cash : between 0 dollar to 20*10000 dollars
    mp_cardNumberField->setValidator(new QIntValidator(0,10000,mp_cardNumberField));

    connect(mp_cardNumberField,SIGNAL(textEdited(QString)),this,SLOT(validateText()));

    connect(mp_cardNumberField,SIGNAL(returnPressed()), &m_loop,SLOT(quit()));

    mp_cardPanelVLayout = new QVBoxLayout();
    mp_cardPanelVLayout->addWidget(mp_infoLabel);
    mp_cardPanelVLayout->addWidget(mp_cardNumberField);
    setLayout(mp_cardPanelVLayout);

    m_cardNumber = 0;

}


simulation::CardPanel::~CardPanel()
{

}

void simulation::CardPanel::validateText()
{
    if (!mp_cardNumberField->hasAcceptableInput()){
        mp_cardNumberField->undo();
        mp_cardNumberField->setText("Must be a valid integer >= 0");
        mp_cardNumberField->selectAll();
    }
    else {

        return;
    }
}

int simulation::CardPanel::readCardNumber()
{

    m_cardNumber = mp_cardNumberField->text().toInt();
    mp_cardNumberField->clear();
    return m_cardNumber;
}




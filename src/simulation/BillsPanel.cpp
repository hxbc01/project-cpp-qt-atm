#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QIntValidator>

#include "BillsPanel.h"

simulation::BillsPanel::BillsPanel()
{
    // information text
    mp_infoLabel = new QLabel("Hallo");

    // enter number initial cash
    mp_billsNumberField = new QLineEdit();
    mp_billsNumberField->setPlaceholderText("Number of bills");
    mp_billsNumberField->setFocus();
    // validate input cash : between 0 dollar to 20*10000 dollars
    mp_billsNumberField->setValidator(new QIntValidator(0,10000,mp_billsNumberField));


    // connect clicked signal to slot
    connect(mp_billsNumberField,SIGNAL(textEdited(QString)),this,SLOT(validateText()));
    connect(mp_billsNumberField,SIGNAL(returnPressed()), &m_loop,SLOT(quit()));


    mp_billsPanelVLayout = new QVBoxLayout();
    mp_billsPanelVLayout->addWidget(mp_infoLabel);
    mp_billsPanelVLayout->addWidget(mp_billsNumberField);
    setLayout(mp_billsPanelVLayout);

    m_billsNumber = 0;


}

simulation::BillsPanel::~BillsPanel()
{

}

void simulation::BillsPanel::validateText()
{
    if (!mp_billsNumberField->hasAcceptableInput()){
        mp_billsNumberField->undo();
        mp_billsNumberField->setText("Must be a valid integer >= 0");
        mp_billsNumberField->selectAll();
    }
    else {

        return;
    }
}

int simulation::BillsPanel::readBills()
{
    m_billsNumber = mp_billsNumberField->text().toInt();
    mp_billsNumberField->clear();

    return m_billsNumber;
}





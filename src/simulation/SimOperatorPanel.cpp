#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include "SimOperatorPanel.h"
#include "Simulation.h"
#include "GUI.h"
#include "LogPanel.h"



simulation::SimOperatorPanel::SimOperatorPanel()
{

}

simulation::SimOperatorPanel::SimOperatorPanel(const Simulation *ap_simulation)
{
    // simulation object
    mp_simulation = ap_simulation;

    mp_infoLabel = new QLabel("Turn ATM ON");
    // center align  text
    mp_infoLabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);


    mp_buttonONOFF = new QPushButton("ON");
    // enable toggle property
    mp_buttonONOFF->setCheckable(true);
    // connect clicked signal to slot
    connect(mp_buttonONOFF,SIGNAL(clicked()),this,SLOT(pushATMButton()));

    mp_showLogButton = new QPushButton("Show Log");
    // connect clicked signal to slot
    connect(mp_showLogButton,SIGNAL(clicked()),this,SLOT(pushShowLogButton()));



    mp_buttonONOFFVLayout = new QVBoxLayout();

    // set spacing between child widgets
    mp_buttonONOFFVLayout->setSpacing(0);
    mp_buttonONOFFVLayout->addWidget(mp_infoLabel);
    mp_buttonONOFFVLayout->setAlignment(mp_infoLabel,Qt::AlignCenter);
    mp_buttonONOFFVLayout->addWidget(mp_buttonONOFF);
    mp_buttonONOFFVLayout->setAlignment(mp_buttonONOFF,Qt::AlignCenter);

    mp_operatorHLayout = new QHBoxLayout();
    mp_operatorHLayout->addWidget(mp_showLogButton);
    mp_operatorHLayout->setAlignment(mp_showLogButton,Qt::AlignBottom);
    mp_operatorHLayout->addLayout(mp_buttonONOFFVLayout);

    setLayout(mp_operatorHLayout);
    //setStyleSheet("background-color:rgb(192,192,0);");




}

simulation::SimOperatorPanel::~SimOperatorPanel()
{

}

void simulation::SimOperatorPanel::pushATMButton()
{
    if (mp_buttonONOFF->isChecked()){ // ATM is currently on
        mp_buttonONOFF->setText("OFF");
        mp_infoLabel->setText("Turn ATM OFF");
        mp_simulation->switchChanged(true);

    } else { // ATM is currently off
        mp_buttonONOFF->setText("ON");
        mp_infoLabel->setText("Turn ATM ON");
        mp_simulation->switchChanged(false);

    }
}

void simulation::SimOperatorPanel::pushShowLogButton()
{
    mp_simulation->getGUI()->getStackedWidget()->setCurrentWidget(mp_simulation->getGUI()->getLogPanel());

}


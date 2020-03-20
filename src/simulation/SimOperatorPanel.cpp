#include <QDebug>
#include "SimOperatorPanel.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


simulation::SimOperatorPanel::SimOperatorPanel()
{

}

simulation::SimOperatorPanel::SimOperatorPanel(const Simulation *ap_simulation)
{
    mp_infoLabel = new QLabel("Turn ATM ON");
    // center align  text
    mp_infoLabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);


    mp_buttonONOFF = new QPushButton("ON");
    mp_showLogButton = new QPushButton("Show Log");
    // enable toggle property
    mp_buttonONOFF->setCheckable(true);


    mp_buttonONOFFVLayout = new QVBoxLayout();

    // set spacing between child widgets
    mp_buttonONOFFVLayout->setSpacing(0);
    mp_buttonONOFFVLayout->addWidget(mp_infoLabel);
    mp_buttonONOFFVLayout->setAlignment(mp_infoLabel,Qt::AlignCenter);
    mp_buttonONOFFVLayout->addWidget(mp_buttonONOFF);
    mp_buttonONOFFVLayout->setAlignment(mp_buttonONOFF,Qt::AlignCenter);

    connect(mp_buttonONOFF,SIGNAL(clicked()),this,SLOT(pushATMButton()));
    mp_operatorHLayout = new QHBoxLayout();
    mp_operatorHLayout->addWidget(mp_showLogButton);
    mp_operatorHLayout->addLayout(mp_buttonONOFFVLayout);

    setLayout(mp_operatorHLayout);
    //setStyleSheet("background-color:rgb(192,192,0);");




}

simulation::SimOperatorPanel::~SimOperatorPanel()
{

}

void simulation::SimOperatorPanel::pushATMButton()
{
    if (mp_buttonONOFF->isChecked()){
        mp_buttonONOFF->setText("OFF");
        mp_infoLabel->setText("Turn ATM OFF");
        //simulation.switchChanged(true);

    } else {
        mp_buttonONOFF->setText("ON");
        mp_infoLabel->setText("Turn ATM ON");
        //simulation.switchChanged(false);

    }


}





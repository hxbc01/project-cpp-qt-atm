#include <QDebug>
#include "SimOperatorPanel.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>


simulation::SimOperatorPanel::SimOperatorPanel()
{

}

simulation::SimOperatorPanel::SimOperatorPanel(const Simulation *ap_simulation)
{
    mp_infoLabel = new QLabel("Turn ATM ON");
    mp_buttonONOFF = new QPushButton("&ON");
    mp_buttonONOFF->setCheckable(true);
    mp_operatorLayout = new QVBoxLayout();
    mp_operatorLayout->addWidget(mp_infoLabel);
    mp_operatorLayout->addWidget(mp_buttonONOFF);

    connect(mp_buttonONOFF,SIGNAL(clicked()),this,SLOT(pushATMButton()));

    setStyleSheet("background-color:rgb(128,128,255);");
    setLayout(mp_operatorLayout);



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





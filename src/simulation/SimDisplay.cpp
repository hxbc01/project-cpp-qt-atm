#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "SimDisplay.h"

simulation::SimDisplay::SimDisplay()
{
    mp_buttonLeftVLayout = new QVBoxLayout();
    mp_buttonRightVLayout = new QVBoxLayout();
    mp_displayHLayout = new QHBoxLayout();
    mp_display = new QLabel("Hello");
    mp_display->setBackgroundRole(QPalette::Base);
    mp_display->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mp_display->setSizeIncrement(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mp_display->setScaledContents(true);
    mp_display->setFixedSize(ATM_DISPLAY_WIDTH,ATM_DISPLAY_HEIGHT);
    for (int i=0;i<m_numLeftButtons;++i)
    {
        mp_leftButtons[i] = new QPushButton();
        mp_buttonLeftVLayout->addWidget(mp_leftButtons[i]);
    }
    for (int i=0;i<m_numRightButtons;++i)
    {
        mp_rightButtons[i] = new QPushButton();
        mp_buttonRightVLayout->addWidget(mp_rightButtons[i]);
    }
    mp_displayHLayout->addLayout(mp_buttonLeftVLayout);
    mp_displayHLayout->addWidget(mp_display);
    mp_displayHLayout->addLayout(mp_buttonRightVLayout);
    setLayout(mp_displayHLayout);



}


simulation::SimDisplay::~SimDisplay()
{

}




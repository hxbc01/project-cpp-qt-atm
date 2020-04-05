#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "SimDisplay.h"

simulation::SimDisplay::SimDisplay()
{
    mp_buttonLeftVLayout = new QVBoxLayout();
    mp_buttonRightVLayout = new QVBoxLayout();
    mp_displayHLayout = new QHBoxLayout();
    mp_mainDisplay = new QTextEdit("Hello\nggggg\nzzzz");
    mp_mainDisplay->setBackgroundRole(QPalette::Base);
    mp_mainDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mp_mainDisplay->setSizeIncrement(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mp_mainDisplay->setFixedSize(ATM_MAIN_DISPLAY_WIDTH,ATM_MAIN_DISPLAY_HEIGHT);
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
    mp_displayHLayout->addWidget(mp_mainDisplay);
    mp_displayHLayout->addLayout(mp_buttonRightVLayout);
    setLayout(mp_displayHLayout);



}


simulation::SimDisplay::~SimDisplay()
{

}




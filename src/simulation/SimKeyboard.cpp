#include <QDebug>
#include "SimKeyboard.h"
#include "SimDisplay.h"
#include "SimEnvelopeAcceptor.h"
#include <QGridLayout>
#include <QPushButton>
simulation::SimKeyboard::SimKeyboard(SimDisplay *ap_display, SimEnvelopeAcceptor *ap_envelopeAcceptor)
{
    mp_keyboardGridLayout = new QGridLayout();
    for (int i=0;i<m_buttons;++i)
    {
        mp_button[i] = new QPushButton(m_buttonsLabels.at(i));
        int column = i % (m_buttons/4);
        int row = i / (m_buttons/4);
        mp_keyboardGridLayout->addWidget(mp_button[i], row, column);
    }
    setLayout(mp_keyboardGridLayout);

}

simulation::SimKeyboard::~SimKeyboard()
{

}





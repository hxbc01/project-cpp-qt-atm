#include <QDebug>
#include "SimKeyboard.h"
#include "SimDisplay.h"
#include "SimEnvelopeAcceptor.h"
#include <QGridLayout>
#include <QPushButton>
simulation::SimKeyboard::SimKeyboard(SimDisplay *ap_display, SimEnvelopeAcceptor *ap_envelopeAcceptor)
{
    mp_display = ap_display;
    mp_envelopeAcceptor = ap_envelopeAcceptor;
    mp_keyboardGridLayout = new QGridLayout();
    for (int i=0;i<m_buttons;++i)
    {
        mp_button[i] = new QPushButton(m_buttonsLabels.at(i));
        int column = i % (m_buttons/4);
        int row = i / (m_buttons/4);
        mp_keyboardGridLayout->addWidget(mp_button[i], row, column);
        // check if the pressed digit key is an integer {0,1,2,3,4,5,6,7,8,9}
        bool l_isDigit;
        //m_buttonsLabels.at(i).toInt(&l_isDigit);
        mp_button[i]->text().toInt(&l_isDigit);
        if (l_isDigit){

            mp_button[i]->setShortcut((0x30 + mp_button[i]->text().toInt()));
            mp_button[i]->setToolTip(mp_button[i]->text());

            connect(mp_button[i], &QPushButton::clicked,
                     [=]() { digitKeyPressed(m_buttonsLabels.at(i).toInt()); });
        } else {
            switch (i)
            {
                case 3: // Cancel Key
                {
                    mp_button[i]->setShortcut(Qt::Key_Escape);
                    mp_button[i]->setToolTip(mp_button[i]->text());
                    break;
                }
                case 7: // Clear Key
                {
                    mp_button[i]->setShortcut(Qt::Key_Delete);
                    mp_button[i]->setToolTip(mp_button[i]->text());
                    break;
                }
                case 11: // Enter Key
                {
                    mp_button[i]->setShortcut(Qt::Key_Enter);
                    mp_button[i]->setToolTip(mp_button[i]->text());
                    break;
                }
            }
        }
    }

    // Enter key
    connect(mp_button[11],SIGNAL(clicked()), this,SLOT(enterKeyPressed()));

    // quit event loop when Enter key clicked
    //connect(mp_button[11],SIGNAL(clicked()), &m_eventLoop,SLOT(quit()));

    // Cancel Key
    connect(mp_button[3],SIGNAL(clicked()), this,SLOT(cancelKeyPressed()));

    // Clear Key
    connect(mp_button[7],SIGNAL(clicked()), this,SLOT(clearKeyPressed()));


    setLayout(mp_keyboardGridLayout);

    m_mode = IDLE_MODE;

}

simulation::SimKeyboard::~SimKeyboard()
{
    if (m_eventLoop.isRunning()){
        m_eventLoop.quit();
    }

}




void simulation::SimKeyboard::setEcho(const QString &a_echo)
{
    mp_display->setEcho(a_echo);
}

QString* simulation::SimKeyboard::readInput(const int &a_mode, const int &a_maxValue)
{
    m_mode = a_mode;
    m_maxValue = a_maxValue;
    m_currentInput.clear();
    m_cancelled = false;
    if (m_mode == AMOUNT_MODE)
    {
        setEcho("0.00");
    }
    else
    {
        setEcho("");
    }   

    // set focus to keyboard
    setFocus();

    // wait()
    m_eventLoop.exec();
    // ------

    m_mode = IDLE_MODE;
    qDebug()<< "m_currentInput = "<<m_currentInput;
    qDebug()<< "m_cancelled = "<<m_cancelled;
    qDebug()<< "IDLE_MODE";


    if (m_cancelled)
        return nullptr;
    else
        return &m_currentInput;


}

void simulation::SimKeyboard::digitKeyPressed(int digit)
{

    switch (m_mode)
    {
        case IDLE_MODE:
        {
            qDebug()<< "IDLE_MODE";
            break;
        }
        case PIN_MODE:
        {
            qDebug()<< "digitKeyPressed";
            m_currentInput.append(QString::number(digit));
            setEcho(QString("*"));
            break;
        }

//        case AMOUNT_MODE:
//        {
//            m_currentInput.append(digit);
//            QString l_input = m_currentInput;
//            if (l_input.length() == 1)
//                setEcho("0.0" + l_input);
//            else if (l_input.length() == 2)
//                setEcho("0." + l_input);
//            else
//                setEcho(input.substring(0, input.length() - 2) + "." +
//                    input.substring(input.length() - 2));
//            break;
//        }

        case MENU_MODE:
        {
            if (digit > 0 && digit <= m_maxValue)
            {
                m_currentInput.append(QString::number(digit));
            }
            else {
                qDebug()<< "beep";
            }
            break;
        }
    }

}

void simulation::SimKeyboard::enterKeyPressed()
{
    switch(m_mode)
    {
        case IDLE_MODE:
        {
            break;
        }
        case PIN_MODE:
        {
            if (m_currentInput.length() > 0){
                m_eventLoop.quit();
            }
            else {
                qDebug()<< "beep";
            }
            break;
        }
        case AMOUNT_MODE:
        {
            if (m_currentInput.length() > 0){

                m_eventLoop.quit();
            }
            else {
                qDebug()<< "beep";
            }
            break;
        }
        case MENU_MODE:
        {
            qDebug()<< "beep";
            break;
        }
    }

}

void simulation::SimKeyboard::clearKeyPressed()
{
    switch(m_mode)
    {
        case IDLE_MODE:
        {
            break;
        }
        case PIN_MODE:
        {
            m_currentInput.clear();
            setEcho("");
            break;
        }
        case AMOUNT_MODE:
        {

            m_currentInput.clear();
            setEcho("0.00");
            break;
        }
        case MENU_MODE:
        {
            qDebug()<< "beep";
            break;
        }
    }

}

void simulation::SimKeyboard::cancelKeyPressed()
{
    switch(m_mode)
    {
        case IDLE_MODE:
        {
            // It is possible to press the cancel key when requested
            // to insert an envelope - so notify the envelope acceptor
            // of this fact (notification is ignored if acceptor is
            // not waiting for an envelope)

//            synchronized(envelopeAcceptor)
//            {
//                envelopeAcceptor.notify();
//            }
            m_cancelled = true;
            m_eventLoop.quit();
            break;

        }
        case PIN_MODE:
        {
            m_cancelled = true;
            m_eventLoop.quit();
            qDebug()<< "Cancel PIN_MODE";

            break;
        }
        case AMOUNT_MODE:
        {
            m_cancelled = true;
            m_eventLoop.quit();
            break;
        }
        case MENU_MODE:
        {
            m_cancelled = true;
            m_eventLoop.quit();
            break;
        }

    }

}


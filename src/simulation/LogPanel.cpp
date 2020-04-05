#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QTextEdit>
#include "LogPanel.h"
#include "ATMPanel.h"
#include "GUI.h"

simulation::LogPanel::LogPanel(const GUI *ap_GUI)
{
    mp_gui = ap_GUI;
    mp_logPanelVLayout = new QVBoxLayout();
    mp_logPanelButtonsHLayout = new QHBoxLayout();
    mp_logDisplay = new QTextEdit("Hello\nggggg\nzzzz");
    mp_logDisplay->setBackgroundRole(QPalette::Base);
    mp_logDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mp_logLabel = new QLabel("Log");
    mp_logLabel->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    mp_logLabel->setFont(QFont("Verdana",24,75));
    mp_logLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    mp_clearLogButton = new QPushButton("Clear Log");
    // connect clicked signal to slot
    connect(mp_clearLogButton,SIGNAL(clicked()),this,SLOT(pushClearLogButton()));
    mp_hideLogButton = new QPushButton("Hide Log");
    // connect clicked signal to slot
    connect(mp_hideLogButton,SIGNAL(clicked()),this,SLOT(pushHideLogButton()));
    // build GUI
    // bottom GUI
    mp_logPanelButtonsHLayout->addWidget(mp_clearLogButton);
    mp_logPanelButtonsHLayout->addWidget(mp_hideLogButton);
    // Overall GUI
    mp_logPanelVLayout->addWidget(mp_logLabel);
    mp_logPanelVLayout->addWidget(mp_logDisplay);
    mp_logPanelVLayout->addLayout(mp_logPanelButtonsHLayout);
    setLayout(mp_logPanelVLayout);



}

simulation::LogPanel::~LogPanel()
{

}

void simulation::LogPanel::pushHideLogButton()
{
    mp_gui->getStackedWidget()->setCurrentWidget(mp_gui->getATMPanel());

}

void simulation::LogPanel::pushClearLogButton()
{
    mp_logDisplay->clear();
}




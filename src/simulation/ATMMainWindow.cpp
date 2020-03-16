#include "ATMMainWindow.h"
#include "Simulation.h"
#include "GUI.h"
#include <QDebug>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QLineEdit>
#include <QPalette>

ATMMainWindow::ATMMainWindow(simulation::Simulation *ap_theSimulation)
{

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setWindowTitle(tr("ATM Simulation"));


    mp_mainWidget = new QWidget;
    mp_mainWidget->setStyleSheet("background-color:Grey;");
    setCentralWidget(ap_theSimulation->getGUI());
    // creat the file menu in menu bar
    // define menu action
    mp_exitAction = new QAction(tr("E&xit"),this);
    mp_exitAction->setShortcuts(QKeySequence::Quit);
    mp_exitAction->setStatusTip(tr("Exit the application"));

    // add menu bar
    // add a file menu
    mp_fileMenu = menuBar()->addMenu(tr("&File"));
    // define action icon
    const QIcon l_exitIcon = QIcon::fromTheme("application-exit");
    // add action to file menu
    mp_fileMenu->addAction(l_exitIcon, tr("E&xit"), this, &QWidget::close);

    // create a the GUI layout
    //mp_mainLayout = new QGridLayout(this);
    // place display on the layout

    //addWidget(nullptr, 0, 0, 1, 6);


    // build the ATM GUI window

}

ATMMainWindow::~ATMMainWindow()
{
    delete mp_mainLayout;
    mp_mainLayout = nullptr;

    delete mp_exitAction;
    mp_exitAction = nullptr;

}

QSize ATMMainWindow::sizeHint() const
{
    QSize size(0,0);
    size.setHeight(ATM_GUI_HEIGHT);
    size.setWidth(ATM_GUI_WIDTH);

    return size;
}

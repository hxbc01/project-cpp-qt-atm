#include "ATMMainWindow.h"
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>

ATMMainWindow::ATMMainWindow(simulation::Simulation *ap_theSimulation)
{
    mp_mainLayout = new QGridLayout(this);

    // creat the file menu in menu bar
    // define menu action
    mp_exitAction = new QAction(tr("E&xit"),this);
    mp_exitAction->setShortcuts(QKeySequence::Quit);
    mp_exitAction->setStatusTip(tr("Exit the application"));

    // add a file menu
    mp_fileMenu = menuBar()->addMenu(tr("&File"));
    // define action icon
    const QIcon l_exitIcon = QIcon::fromTheme("application-exit");
    // add action to file menu
    mp_fileMenu->addAction(l_exitIcon, tr("E&xit"), this, &QWidget::close);

    // build the ATM GUI window
    setLayout(mp_mainLayout);
    setWindowTitle(tr("ATM Simulation"));

}

ATMMainWindow::~ATMMainWindow()
{
    delete mp_mainLayout;
    mp_mainLayout = nullptr;

    delete mp_exitAction;
    mp_exitAction = nullptr;

}

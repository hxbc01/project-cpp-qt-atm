#include "ATMMainWindow.h"
#include "Simulation.h"
#include "GUI.h"
#include <QDebug>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QLineEdit>
#include <QPalette>

ATMMainWindow::ATMMainWindow(simulation::Simulation *ap_simulation)
{
    // get pointer to simulation object
    mp_simulation = ap_simulation;
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setWindowTitle(tr("ATM Simulation"));


    mp_simulation->getGUI()->setStyleSheet("background-color:Grey;");
    // creat the file menu in menu bar
    // define menu action
    mp_exitAction = new QAction(tr("E&xit"),this);
    mp_exitAction->setShortcuts(QKeySequence::Quit);
    mp_exitAction->setStatusTip(tr("Exit the application"));

    // add menu bar
    mp_menuBar = new QMenuBar();
    // add a file menu
    mp_fileMenu = new QMenu(tr("&File"));
    mp_menuBar->addMenu(mp_fileMenu);
    // define action icon
    const QIcon l_exitIcon = QIcon::fromTheme("application-exit");
    // add action to file menu
    mp_fileMenu->addAction(l_exitIcon, tr("E&xit"), this, &QWidget::close);

    // create a the GUI layout
    mp_mainVLayout = new QVBoxLayout();
    // set menu Bar
    mp_mainVLayout->setMenuBar(mp_menuBar);
    // add ATM GUI
    mp_mainVLayout->addWidget(mp_simulation->getGUI());
    // set layout to current widget
    setLayout(mp_mainVLayout);
    // set fixed size main window
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

}

ATMMainWindow::~ATMMainWindow()
{
    //qDebug()<< "Destructor ATMMainWindow";
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

void ATMMainWindow::closeEvent(QCloseEvent *event)
{

    qDebug()<< "ATMMainWindow closed";
    mp_simulation->mainWindowClosed();

}

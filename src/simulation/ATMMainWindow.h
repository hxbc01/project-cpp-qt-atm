#ifndef ATMMAINWINDOW_H
#define ATMMAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QMenu;
class QGridLayout;
QT_END_NAMESPACE
namespace simulation
{
class Simulation;
}

class ATMMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ATMMainWindow(simulation::Simulation *ap_theSimulation);
    ~ATMMainWindow();
private slots:

protected:
private:
    // main layout for th ATM GUI Window
    QGridLayout *mp_mainLayout =nullptr;
    // main menu for th ATM GUI Window
    QMenu *mp_fileMenu =nullptr;
    // exit action in main menu for th ATM GUI Window
    QAction *mp_exitAction =nullptr;
};

#endif // ATMMAINWINDOW_H

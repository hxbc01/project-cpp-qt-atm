#ifndef ATMMAINWINDOW_H
#define ATMMAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QMenu;
class QGridLayout;
class QWidget;
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
    ~ATMMainWindow() override;
    QSize sizeHint() const override;
private slots:

protected:
private:
    // main widget for the ATM GUI Window
    QWidget *mp_mainWidget =nullptr;
    // main layout for the ATM GUI Window
    QGridLayout *mp_mainLayout =nullptr;
    // menu bar for the ATM GUI Window
    QMenu *mp_fileMenu =nullptr;
    // exit action in main menu for the ATM GUI Window
    QAction *mp_exitAction =nullptr;

    // The following are used only for doing the layout
    const int ATM_GUI_WIDTH = 500;
    const int ATM_GUI_HEIGHT = 720;
};

#endif // ATMMAINWINDOW_H

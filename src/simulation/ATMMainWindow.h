#ifndef ATMMAINWINDOW_H
#define ATMMAINWINDOW_H
#include <QWidget>

QT_BEGIN_NAMESPACE
class QMenu;
class QVBoxLayout;
class QWidget;
class QMenuBar;
QT_END_NAMESPACE
namespace simulation
{
class Simulation;
}

class ATMMainWindow : public QWidget
{
    Q_OBJECT

public:
    ATMMainWindow(simulation::Simulation *ap_theSimulation);
    ~ATMMainWindow() override;
    QSize sizeHint() const override;
    void closeEvent(QCloseEvent *event) override;
private slots:

protected:
private:
    // simulation object
    simulation::Simulation *mp_simulation = nullptr;
    // main layout for the ATM GUI Window
    QVBoxLayout *mp_mainVLayout =nullptr;
    // menu bar for the ATM GUI Window
    QMenu *mp_fileMenu =nullptr;
    // menu bar for the ATM GUI Window
    QMenuBar *mp_menuBar =nullptr;
    // exit action in main menu for the ATM GUI Window
    QAction *mp_exitAction =nullptr;

    // The following are used only for setting the ATM GUI size
    const int ATM_GUI_WIDTH = 500;
    const int ATM_GUI_HEIGHT = 720;
};

#endif // ATMMAINWINDOW_H

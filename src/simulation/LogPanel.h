/**
 * @file LogPanel.h
 * @brief Header file of the LogPanel class
 * @author Farid Oubbati
 * @date 08-july-2019
 * @version 1.0
 */
#ifndef LOGPANEL_H
#define LOGPANEL_H
#include <QWidget>
/** The GUI panel that displays the ATM's internal log
 */
QT_BEGIN_NAMESPACE
class QLabel;
class QVBoxLayout;
class QPushButton;
class QHBoxLayout;
class QTextEdit;
QT_END_NAMESPACE
namespace simulation
{
class GUI;
}
namespace simulation
{
class LogPanel : public QWidget
{
    Q_OBJECT

private slots:
    /**
     * hide log button clicked
     */
    void pushHideLogButton();
    /**
     * clear log button clicked
     */
    void pushClearLogButton();

public:
    /** Constructor
     *
     *  @param gui the the overall GUI
     */

    LogPanel(const GUI *ap_GUI);
    /** Destructor
     */
    ~LogPanel();

protected:


private:
    // vertical layout for the Log panel
    QVBoxLayout *mp_logPanelVLayout=nullptr;
    // Horizontal layout for the Log buttons
    QHBoxLayout *mp_logPanelButtonsHLayout=nullptr;
    // display screen
    QTextEdit *mp_logDisplay=nullptr;
    // top label for the Log panel
    QLabel *mp_logLabel=nullptr;
    // clear log button
    QPushButton *mp_clearLogButton=nullptr;
    // hide log button
    QPushButton *mp_hideLogButton=nullptr;
    /** Panel containing the GUI that simulates the ATM
     */
    const GUI *mp_gui=nullptr;


};
}

#endif // LOGPANEL_H


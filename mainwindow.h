#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "storage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const QString actionName_noAction = "No action";
const QString actionName_script = "User script";
const QString actionName_hardOn = "Turn on";
const QString actionName_hardOff = "Turn off";
const QString actionName_hardReset = "Hard reset";
const QString actionName_softOff = "Cmd 'poweroff'";
const QString actionName_softReset = "Cmd 'reboot'";

const QString eventName_empty = "Disabled";
const QString eventName_once = "Single";
const QString eventName_daily = "Every day";
const QString eventName_xHours = "Every X hours";
const QString eventName_xMinutes = "Every X minutes";

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_pushButton_buttons_apply_clicked();
        void on_checkBox_clock_stateChanged(int arg1);
        void on_pushButton_clock_sync_from_RTC_clicked();
        void on_pushButton_clock_sync_from_system_clicked();
        void on_pushButton_clock_manually_clicked();
        void on_comboBox_buttons_power_short_currentIndexChanged(const QString &arg1);
        void on_comboBox_buttons_reset_short_currentIndexChanged(const QString &arg1);

private:
        void initUiElements();
        Ui::MainWindow *ui;
        Storage storage;
};
#endif // MAINWINDOW_H

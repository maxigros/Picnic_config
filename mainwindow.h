#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "storage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        /**********   Tab BUTTONS    *********/
        void on_comboBox_buttons_power_short_currentIndexChanged(int index);
        void on_comboBox_buttons_power_long_currentIndexChanged(int index);
        void on_comboBox_buttons_reset_short_currentIndexChanged(int index);
        void on_pushButton_buttons_apply_clicked();
        /***********   Tab CLOCK    **********/
        void on_checkBox_clock_stateChanged(int arg1);
        void on_pushButton_clock_sync_from_RTC_clicked();
        void on_pushButton_clock_sync_from_system_clicked();
        void on_pushButton_clock_manually_clicked();
        /***********   Tab ALARM    **********/
        void on_comboBox_alarm_type_0_currentIndexChanged(int index);
        void on_comboBox_alarm_type_1_currentIndexChanged(int index);
        void on_comboBox_alarm_type_2_currentIndexChanged(int index);
        void on_comboBox_alarm_type_3_currentIndexChanged(int index);
        void on_comboBox_alarm_type_4_currentIndexChanged(int index);
        void on_comboBox_alarm_type_5_currentIndexChanged(int index);
        void on_comboBox_alarm_action_0_currentIndexChanged(int index);
        void on_comboBox_alarm_action_1_currentIndexChanged(int index);
        void on_comboBox_alarm_action_2_currentIndexChanged(int index);
        void on_comboBox_alarm_action_3_currentIndexChanged(int index);
        void on_comboBox_alarm_action_4_currentIndexChanged(int index);
        void on_comboBox_alarm_action_5_currentIndexChanged(int index);
        void on_pushButton_alarm_apply_clicked();
        /************   Tab IR    ************/
        void on_comboBox_ir_action_0_currentIndexChanged(int index);
        void on_comboBox_ir_action_1_currentIndexChanged(int index);
        void on_comboBox_ir_action_2_currentIndexChanged(int index);
        void on_comboBox_ir_action_3_currentIndexChanged(int index);
        void on_comboBox_ir_action_4_currentIndexChanged(int index);
        void on_comboBox_ir_action_5_currentIndexChanged(int index);
        void on_pushButton_ir_apply_clicked();
        void on_lineEdit_ir_parameter_0_returnPressed();
        /*****   Tab POWER MANAGEMENT    *****/
        void on_comboBox_pm_type_0_currentIndexChanged(int index);
        void on_comboBox_pm_type_1_currentIndexChanged(int index);
        void on_comboBox_pm_type_2_currentIndexChanged(int index);
        void on_comboBox_pm_action_0_currentIndexChanged(int index);
        void on_comboBox_pm_action_1_currentIndexChanged(int index);
        void on_comboBox_pm_action_2_currentIndexChanged(int index);
        void on_pushButton_pm_apply_clicked();

private:
        void initUiElements();
        Ui::MainWindow *ui;
        Storage storage;
};
#endif // MAINWINDOW_H

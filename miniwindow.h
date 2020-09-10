#ifndef MINIWINDOW_H
#define MINIWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MiniWindow;
}

class MiniWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiniWindow(QWidget *parent = nullptr);
    ~MiniWindow();

private slots:
    void on_comboBox_ext_pow_app_currentIndexChanged(int index);
    void on_comboBox_ext_pow_disapp_currentIndexChanged(int index);
    void on_comboBox_low_bat_currentIndexChanged(int index);
    void on_pushButton_apply_clicked();
    void timerUpdate();

private:
    Ui::MiniWindow *ui;
    QTimer* tim;

    QString scriptExtPowApp = "./../Picnic_config/extPowAppeared.sh";
    QString scriptExtPowDisapp = "./../Picnic_config/extPowDisappeared.sh";
    QString scriptLowBat = "./../Picnic_config/lowBattery.sh";
};

#endif // MINIWINDOW_H

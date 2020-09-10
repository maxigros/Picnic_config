#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initUiElements();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_buttons_power_short_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_buttons_power->setEnabled(arg1 == actionName_script ? true : false);
}

void MainWindow::on_comboBox_buttons_reset_short_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_buttons_reset->setEnabled(arg1 == actionName_script ? true : false);
}

void MainWindow::on_pushButton_buttons_apply_clicked()
{
    strcpy(     this->storage.dataScripts[SCRIPT_BUTTONS_POWER].str,
                ui->lineEdit_buttons_power->text().toLocal8Bit().data()
    );
    strcpy(     this->storage.dataScripts[SCRIPT_BUTTONS_RESET].str,
                ui->lineEdit_buttons_reset->text().toLocal8Bit().data()
    );
    this->storage.writeFullFile();
}

void MainWindow::on_checkBox_clock_stateChanged(int arg1)
{

}

void MainWindow::on_pushButton_clock_sync_from_RTC_clicked()
{

}

void MainWindow::on_pushButton_clock_sync_from_system_clicked()
{

}

void MainWindow::on_pushButton_clock_manually_clicked()
{

}

void MainWindow::initUiElements()
{
    /*************************      BUTTONS        ****************************/
    /* POWER short */
    ui->comboBox_buttons_power_short->addItem(actionName_noAction);
    ui->comboBox_buttons_power_short->addItem(actionName_softOff);
    ui->comboBox_buttons_power_short->addItem(actionName_script);
    ui->comboBox_buttons_power_short->addItem(actionName_hardOff);
    /* POWER long */
    ui->comboBox_buttons_power_long->addItem(actionName_noAction);
    ui->comboBox_buttons_power_long->addItem(actionName_hardOff);
    /* RESET short */
    ui->comboBox_buttons_reset_short->addItem(actionName_noAction);
    ui->comboBox_buttons_reset_short->addItem(actionName_softReset);
    ui->comboBox_buttons_reset_short->addItem(actionName_script);
    ui->comboBox_buttons_reset_short->addItem(actionName_hardReset);
    /* Scripts */
    ui->lineEdit_buttons_power->setText(this->storage.dataScripts[SCRIPT_BUTTONS_POWER].str);
    ui->lineEdit_buttons_reset->setText(this->storage.dataScripts[SCRIPT_BUTTONS_RESET].str);
}


#include "miniwindow.h"
#include "ui_miniwindow.h"

MiniWindow::MiniWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MiniWindow)
{
    ui->setupUi(this);

    ui->comboBox_ext_pow_app->setCurrentIndex(0);
    ui->comboBox_ext_pow_disapp->setCurrentIndex(1);
    ui->comboBox_low_bat->setCurrentIndex(1);

    ui->lineEdit_ext_pow_app->setText(this->scriptExtPowApp);
    ui->lineEdit_ext_pow_disapp->setText(this->scriptExtPowDisapp);
    ui->lineEdit_low_bat->setText(this->scriptLowBat);

    this->tim = new QTimer(this);
    connect(this->tim, SIGNAL(timeout()), this, SLOT(timerUpdate()));
//    this->tim->start(1000);
}

MiniWindow::~MiniWindow()
{
    delete this->tim;
    delete ui;
}

void MiniWindow::timerUpdate()
{
    system(this->scriptExtPowApp.toLocal8Bit().data());
}

void MiniWindow::on_comboBox_ext_pow_app_currentIndexChanged(int index)
{
    /* Set script line active or not */
    if (index) {
        ui->lineEdit_ext_pow_app->setEnabled(false);
    } else {
        ui->lineEdit_ext_pow_app->setEnabled(true);
    }
}

void MiniWindow::on_comboBox_ext_pow_disapp_currentIndexChanged(int index)
{
    /* Set script line active or not */
    if (index) {
        ui->lineEdit_ext_pow_disapp->setEnabled(false);
    } else {
        ui->lineEdit_ext_pow_disapp->setEnabled(true);
    }
}

void MiniWindow::on_comboBox_low_bat_currentIndexChanged(int index)
{
    /* Set script line active or not */
    if (index) {
        ui->lineEdit_low_bat->setEnabled(false);
    } else {
        ui->lineEdit_low_bat->setEnabled(true);
    }
}

void MiniWindow::on_pushButton_apply_clicked()
{
    if (ui->lineEdit_ext_pow_app->isEnabled()) {
        this->scriptExtPowApp = ui->lineEdit_ext_pow_app->text();
    }

    if (ui->lineEdit_ext_pow_disapp->isEnabled()) {
        this->scriptExtPowDisapp = ui->lineEdit_ext_pow_disapp->text();
    }

    if (ui->lineEdit_low_bat->isEnabled()) {
        this->scriptLowBat = ui->lineEdit_low_bat->text();
    }
}

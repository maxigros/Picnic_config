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

void MainWindow::initUiElements()
{
    QStringList t;

    /*************************      BUTTONS        ****************************/
    /* POWER short */
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_POW_S);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_buttons_power_short->addItem(t[i]);
    }
    t = this->storage.getTabData(TABID_BUTTONS, 0);
    ui->comboBox_buttons_power_short->setCurrentIndex(t[2].toInt());
    ui->lineEdit_buttons_power->setText(t[3]);
    /* POWER long */
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_POW_L);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_buttons_power_long->addItem(t[i]);
    }
    t = this->storage.getTabData(TABID_BUTTONS, 1);
    ui->comboBox_buttons_power_long->setCurrentIndex(t[2].toInt());
    /* RESET short */
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_RES_S);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_buttons_reset_short->addItem(t[i]);
    }
    t = this->storage.getTabData(TABID_BUTTONS, 2);
    ui->comboBox_buttons_reset_short->setCurrentIndex(t[2].toInt());
    ui->lineEdit_buttons_reset->setText(t[3]);

    /**************************      CLOCK        *****************************/
    /* CheckBox */
    t = this->storage.getTabData(TABID_CLOCK, 0);
    ui->checkBox_clock->setChecked(t[2].toInt());
    /* Current time and date */
    ui->dateTimeEdit_clock->setDateTime(QDateTime::currentDateTime());

    /**************************      ALARM        *****************************/
    /* Actions */       // !!! actions before events !!!
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_ALARM_ACTION);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_alarm_action_0->addItem(t[i]);
        ui->comboBox_alarm_action_1->addItem(t[i]);
        ui->comboBox_alarm_action_2->addItem(t[i]);
        ui->comboBox_alarm_action_3->addItem(t[i]);
        ui->comboBox_alarm_action_4->addItem(t[i]);
        ui->comboBox_alarm_action_5->addItem(t[i]);
    }
    /* Events */
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_ALARM_EVENT);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_alarm_type_0->addItem(t[i]);
        ui->comboBox_alarm_type_1->addItem(t[i]);
        ui->comboBox_alarm_type_2->addItem(t[i]);
        ui->comboBox_alarm_type_3->addItem(t[i]);
        ui->comboBox_alarm_type_4->addItem(t[i]);
        ui->comboBox_alarm_type_5->addItem(t[i]);
    }
    /* Data */
    t = this->storage.getTabData(TABID_ALARM, 0);           //   <=== SLOT0
    ui->comboBox_alarm_type_0->setCurrentIndex(t[1].toInt());
    ui->lineEdit_alarm_parameter_0->setText(t[2]);
    ui->comboBox_alarm_action_0->setCurrentIndex(t[3].toInt());
    ui->lineEdit_alarm_script_0->setText(t[4]);
    ui->timeEdit_alarm_0->setTime(QTime(t[5].toInt(), t[6].toInt()));

    t = this->storage.getTabData(TABID_ALARM, 1);           //   <=== SLOT1
    ui->comboBox_alarm_type_1->setCurrentIndex(t[1].toInt());
    ui->lineEdit_alarm_parameter_1->setText(t[2]);
    ui->comboBox_alarm_action_1->setCurrentIndex(t[3].toInt());
    ui->lineEdit_alarm_script_1->setText(t[4]);
    ui->timeEdit_alarm_1->setTime(QTime(t[5].toInt(), t[6].toInt()));

    t = this->storage.getTabData(TABID_ALARM, 2);           //   <=== SLOT2
    ui->comboBox_alarm_type_2->setCurrentIndex(t[1].toInt());
    ui->lineEdit_alarm_parameter_2->setText(t[2]);
    ui->comboBox_alarm_action_2->setCurrentIndex(t[3].toInt());
    ui->lineEdit_alarm_script_2->setText(t[4]);
    ui->timeEdit_alarm_2->setTime(QTime(t[5].toInt(), t[6].toInt()));

    t = this->storage.getTabData(TABID_ALARM, 3);           //   <=== SLOT3
    ui->comboBox_alarm_type_3->setCurrentIndex(t[1].toInt());
    ui->lineEdit_alarm_parameter_3->setText(t[2]);
    ui->comboBox_alarm_action_3->setCurrentIndex(t[3].toInt());
    ui->lineEdit_alarm_script_3->setText(t[4]);
    ui->timeEdit_alarm_3->setTime(QTime(t[5].toInt(), t[6].toInt()));

    t = this->storage.getTabData(TABID_ALARM, 4);           //   <=== SLOT4
    ui->comboBox_alarm_type_4->setCurrentIndex(t[1].toInt());
    ui->lineEdit_alarm_parameter_4->setText(t[2]);
    ui->comboBox_alarm_action_4->setCurrentIndex(t[3].toInt());
    ui->lineEdit_alarm_script_4->setText(t[4]);
    ui->timeEdit_alarm_4->setTime(QTime(t[5].toInt(), t[6].toInt()));

    t = this->storage.getTabData(TABID_ALARM, 5);           //   <=== SLOT5
    ui->comboBox_alarm_type_5->setCurrentIndex(t[1].toInt());
    ui->lineEdit_alarm_parameter_5->setText(t[2]);
    ui->comboBox_alarm_action_5->setCurrentIndex(t[3].toInt());
    ui->lineEdit_alarm_script_5->setText(t[4]);
    ui->timeEdit_alarm_5->setTime(QTime(t[5].toInt(), t[6].toInt()));

    /****************************      IR        ******************************/
    /* Actions */
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_IR_ACTION);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_ir_action_0->addItem(t[i]);
        ui->comboBox_ir_action_1->addItem(t[i]);
        ui->comboBox_ir_action_2->addItem(t[i]);
        ui->comboBox_ir_action_3->addItem(t[i]);
        ui->comboBox_ir_action_4->addItem(t[i]);
        ui->comboBox_ir_action_5->addItem(t[i]);
    }
    /* Data */
    t = this->storage.getTabData(TABID_IR, 0);           /*   <=== SLOT0 */
    ui->lineEdit_ir_parameter_0->setText(t[1]);
    ui->comboBox_ir_action_0->setCurrentIndex(t[2].toInt());
    ui->lineEdit_ir_script_0->setText(t[3]);

    t = this->storage.getTabData(TABID_IR, 1);           /*   <=== SLOT1 */
    ui->lineEdit_ir_parameter_1->setText(t[1]);
    ui->comboBox_ir_action_1->setCurrentIndex(t[2].toInt());
    ui->lineEdit_ir_script_1->setText(t[3]);

    t = this->storage.getTabData(TABID_IR, 2);           /*   <=== SLOT2 */
    ui->lineEdit_ir_parameter_2->setText(t[1]);
    ui->comboBox_ir_action_2->setCurrentIndex(t[2].toInt());
    ui->lineEdit_ir_script_2->setText(t[3]);

    t = this->storage.getTabData(TABID_IR, 3);           /*   <=== SLOT3 */
    ui->lineEdit_ir_parameter_3->setText(t[1]);
    ui->comboBox_ir_action_3->setCurrentIndex(t[2].toInt());
    ui->lineEdit_ir_script_3->setText(t[3]);

    t = this->storage.getTabData(TABID_IR, 4);           /*   <=== SLOT4 */
    ui->lineEdit_ir_parameter_4->setText(t[1]);
    ui->comboBox_ir_action_4->setCurrentIndex(t[2].toInt());
    ui->lineEdit_ir_script_4->setText(t[3]);

    t = this->storage.getTabData(TABID_IR, 5);           /*   <=== SLOT5 */
    ui->lineEdit_ir_parameter_5->setText(t[1]);
    ui->comboBox_ir_action_5->setCurrentIndex(t[2].toInt());
    ui->lineEdit_ir_script_5->setText(t[3]);

    /*********************      POWER MANAGEMENT        ***********************/
    /* Actions */       // !!! actions before events !!!
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_PM_ACTION);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_pm_action_0->addItem(t[i]);
        ui->comboBox_pm_action_1->addItem(t[i]);
        ui->comboBox_pm_action_2->addItem(t[i]);
    }
    /* Events */
    t = this->storage.getComboBoxVariants(BOXSUITTYPE_PM_EVENT);
    for (int i = 0; i < t.size(); ++i) {
        ui->comboBox_pm_type_0->addItem(t[i]);
        ui->comboBox_pm_type_1->addItem(t[i]);
        ui->comboBox_pm_type_2->addItem(t[i]);
    }
    /* Data */
    t = this->storage.getTabData(TABID_PM, 0);           /*   <=== SLOT0 */
    ui->comboBox_pm_type_0->setCurrentIndex(t[1].toInt());
    ui->comboBox_pm_action_0->setCurrentIndex(t[2].toInt());
    ui->lineEdit_pm_script_0->setText(t[3]);

    t = this->storage.getTabData(TABID_PM, 1);           /*   <=== SLOT1 */
    ui->comboBox_pm_type_1->setCurrentIndex(t[1].toInt());
    ui->comboBox_pm_action_1->setCurrentIndex(t[2].toInt());
    ui->lineEdit_pm_script_1->setText(t[3]);

    t = this->storage.getTabData(TABID_PM, 2);           /*   <=== SLOT2 */
    ui->comboBox_pm_type_2->setCurrentIndex(t[1].toInt());
    ui->comboBox_pm_action_2->setCurrentIndex(t[2].toInt());
    ui->lineEdit_pm_script_2->setText(t[3]);
}

/******************************************************************************
 **********************    TAB BUTTONS HANDLING    ****************************
 ******************************************************************************/

void MainWindow::on_comboBox_buttons_power_short_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_POW_S, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_buttons_power->setEnabled(isActive);
}

void MainWindow::on_comboBox_buttons_power_long_currentIndexChanged(int index){
    Q_UNUSED(index);
}

void MainWindow::on_comboBox_buttons_reset_short_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_RES_S, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_buttons_reset->setEnabled(isActive);
}

void MainWindow::on_pushButton_buttons_apply_clicked()
{
    QStringList t;
    /* POWER short */
    t.append(QString("%1").arg(ui->comboBox_buttons_power_short->currentIndex()));
    t.append(ui->lineEdit_buttons_power->text());
    this->storage.setTabData(TABID_BUTTONS, 0, t);
    t.clear();
    /* POWER long */
    t.append(QString("%1").arg(ui->comboBox_buttons_power_long->currentIndex()));
    this->storage.setTabData(TABID_BUTTONS, 1, t);
    t.clear();
    /* RESET short */
    t.append(QString("%1").arg(ui->comboBox_buttons_reset_short->currentIndex()));
    t.append(ui->lineEdit_buttons_reset->text());
    this->storage.setTabData(TABID_BUTTONS, 2, t);
    t.clear();
}

/******************************************************************************
 ***********************    TAB CLOCK HANDLING    *****************************
 ******************************************************************************/

void MainWindow::on_checkBox_clock_stateChanged(int arg1)
{
    QStringList t;
    t.append(QString("%1").arg(arg1));
    this->storage.setTabData(TABID_CLOCK, 0, t);
}

void MainWindow::on_pushButton_clock_sync_from_RTC_clicked()
{

}

void MainWindow::on_pushButton_clock_sync_from_system_clicked()
{

}

void MainWindow::on_pushButton_clock_manually_clicked()
{
    QString month_s, day_s;
    int year = ui->dateTimeEdit_clock->date().year();
    int month = ui->dateTimeEdit_clock->date().month();
    if (month > 9) {
        month_s = QString("%1").arg(month);
    } else {
        month_s = QString("0%1").arg(month);
    }
    int day = ui->dateTimeEdit_clock->date().day();
    if (day > 9) {
        day_s = QString("%1").arg(day);
    } else {
        day_s = QString("0%1").arg(day);
    }
    int hour = ui->dateTimeEdit_clock->time().hour();
    int minute = ui->dateTimeEdit_clock->time().minute();
    QString str = QString("sudo date --set='%1%2%3 %4:%5:00'")
        .arg(year)
        .arg(month_s)
        .arg(day_s)
        .arg(hour)
        .arg(minute);
//    qDebug() << str;
    system(str.toLocal8Bit().data());
}

/******************************************************************************
 ***********************    TAB ALARM HANDLING    *****************************
 ******************************************************************************/

void MainWindow::on_comboBox_alarm_type_0_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->lineEdit_alarm_parameter_0->setEnabled(rowActive);
    ui->comboBox_alarm_action_0->setEnabled(rowActive);
    ui->timeEdit_alarm_0->setEnabled(rowActive);
    /* If row active, select used argument field */
    if (rowActive) {
        bool useX = t[3].toInt() ? true : false;
        ui->lineEdit_alarm_parameter_0->setEnabled(useX);
        ui->timeEdit_alarm_0->setEnabled(!useX);
    }
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_alarm_action_0->currentIndexChanged(ui->comboBox_alarm_action_0->currentIndex());
}

void MainWindow::on_comboBox_alarm_type_1_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->lineEdit_alarm_parameter_1->setEnabled(rowActive);
    ui->comboBox_alarm_action_1->setEnabled(rowActive);
    ui->timeEdit_alarm_1->setEnabled(rowActive);
    /* If row active, select used argument field */
    if (rowActive) {
        bool useX = t[3].toInt() ? true : false;
        ui->lineEdit_alarm_parameter_1->setEnabled(useX);
        ui->timeEdit_alarm_1->setEnabled(!useX);
    }
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_alarm_action_1->currentIndexChanged(ui->comboBox_alarm_action_1->currentIndex());
}

void MainWindow::on_comboBox_alarm_type_2_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->lineEdit_alarm_parameter_2->setEnabled(rowActive);
    ui->comboBox_alarm_action_2->setEnabled(rowActive);
    ui->timeEdit_alarm_2->setEnabled(rowActive);
    /* If row active, select used argument field */
    if (rowActive) {
        bool useX = t[3].toInt() ? true : false;
        ui->lineEdit_alarm_parameter_2->setEnabled(useX);
        ui->timeEdit_alarm_2->setEnabled(!useX);
    }
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_alarm_action_2->currentIndexChanged(ui->comboBox_alarm_action_2->currentIndex());
}

void MainWindow::on_comboBox_alarm_type_3_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->lineEdit_alarm_parameter_3->setEnabled(rowActive);
    ui->comboBox_alarm_action_3->setEnabled(rowActive);
    ui->timeEdit_alarm_3->setEnabled(rowActive);
    /* If row active, select used argument field */
    if (rowActive) {
        bool useX = t[3].toInt() ? true : false;
        ui->lineEdit_alarm_parameter_3->setEnabled(useX);
        ui->timeEdit_alarm_3->setEnabled(!useX);
    }
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_alarm_action_3->currentIndexChanged(ui->comboBox_alarm_action_3->currentIndex());
}

void MainWindow::on_comboBox_alarm_type_4_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->lineEdit_alarm_parameter_4->setEnabled(rowActive);
    ui->comboBox_alarm_action_4->setEnabled(rowActive);
    ui->timeEdit_alarm_4->setEnabled(rowActive);
    /* If row active, select used argument field */
    if (rowActive) {
        bool useX = t[3].toInt() ? true : false;
        ui->lineEdit_alarm_parameter_4->setEnabled(useX);
        ui->timeEdit_alarm_4->setEnabled(!useX);
    }
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_alarm_action_4->currentIndexChanged(ui->comboBox_alarm_action_4->currentIndex());
}

void MainWindow::on_comboBox_alarm_type_5_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->lineEdit_alarm_parameter_5->setEnabled(rowActive);
    ui->comboBox_alarm_action_5->setEnabled(rowActive);
    ui->timeEdit_alarm_5->setEnabled(rowActive);
    /* If row active, select used argument field */
    if (rowActive) {
        bool useX = t[3].toInt() ? true : false;
        ui->lineEdit_alarm_parameter_5->setEnabled(useX);
        ui->timeEdit_alarm_5->setEnabled(!useX);
    }
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_alarm_action_5->currentIndexChanged(ui->comboBox_alarm_action_5->currentIndex());
}

void MainWindow::on_comboBox_alarm_action_0_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_alarm_action_0->isEnabled()) {
        ui->lineEdit_alarm_script_0->setEnabled(scriptActive);
    } else {
        ui->lineEdit_alarm_script_0->setEnabled(false);
    }
}

void MainWindow::on_comboBox_alarm_action_1_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_alarm_action_1->isEnabled()) {
        ui->lineEdit_alarm_script_1->setEnabled(scriptActive);
    } else {
        ui->lineEdit_alarm_script_1->setEnabled(false);
    }
}

void MainWindow::on_comboBox_alarm_action_2_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_alarm_action_2->isEnabled()) {
        ui->lineEdit_alarm_script_2->setEnabled(scriptActive);
    } else {
        ui->lineEdit_alarm_script_2->setEnabled(false);
    }
}

void MainWindow::on_comboBox_alarm_action_3_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_alarm_action_3->isEnabled()) {
        ui->lineEdit_alarm_script_3->setEnabled(scriptActive);
    } else {
        ui->lineEdit_alarm_script_3->setEnabled(false);
    }
}

void MainWindow::on_comboBox_alarm_action_4_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_alarm_action_4->isEnabled()) {
        ui->lineEdit_alarm_script_4->setEnabled(scriptActive);
    } else {
        ui->lineEdit_alarm_script_4->setEnabled(false);
    }
}

void MainWindow::on_comboBox_alarm_action_5_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_ALARM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_alarm_action_5->isEnabled()) {
        ui->lineEdit_alarm_script_5->setEnabled(scriptActive);
    } else {
        ui->lineEdit_alarm_script_5->setEnabled(false);
    }
}

void MainWindow::on_pushButton_alarm_apply_clicked()
{
    QStringList t;

    t.append(QString("%1").arg(ui->comboBox_alarm_type_0->currentIndex()));
    t.append(ui->lineEdit_alarm_parameter_0->text());
    t.append(QString("%1").arg(ui->comboBox_alarm_action_0->currentIndex()));
    t.append(ui->lineEdit_alarm_script_0->text());
    t.append(QString("%1").arg(ui->timeEdit_alarm_0->time().hour()));
    t.append(QString("%1").arg(ui->timeEdit_alarm_0->time().minute()));
    this->storage.setTabData(TABID_ALARM, 0, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_alarm_type_1->currentIndex()));
    t.append(ui->lineEdit_alarm_parameter_1->text());
    t.append(QString("%1").arg(ui->comboBox_alarm_action_1->currentIndex()));
    t.append(ui->lineEdit_alarm_script_1->text());
    t.append(QString("%1").arg(ui->timeEdit_alarm_1->time().hour()));
    t.append(QString("%1").arg(ui->timeEdit_alarm_1->time().minute()));
    this->storage.setTabData(TABID_ALARM, 1, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_alarm_type_2->currentIndex()));
    t.append(ui->lineEdit_alarm_parameter_2->text());
    t.append(QString("%1").arg(ui->comboBox_alarm_action_2->currentIndex()));
    t.append(ui->lineEdit_alarm_script_2->text());
    t.append(QString("%1").arg(ui->timeEdit_alarm_2->time().hour()));
    t.append(QString("%1").arg(ui->timeEdit_alarm_2->time().minute()));
    this->storage.setTabData(TABID_ALARM, 2, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_alarm_type_3->currentIndex()));
    t.append(ui->lineEdit_alarm_parameter_3->text());
    t.append(QString("%1").arg(ui->comboBox_alarm_action_3->currentIndex()));
    t.append(ui->lineEdit_alarm_script_3->text());
    t.append(QString("%1").arg(ui->timeEdit_alarm_3->time().hour()));
    t.append(QString("%1").arg(ui->timeEdit_alarm_3->time().minute()));
    this->storage.setTabData(TABID_ALARM, 3, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_alarm_type_4->currentIndex()));
    t.append(ui->lineEdit_alarm_parameter_4->text());
    t.append(QString("%1").arg(ui->comboBox_alarm_action_4->currentIndex()));
    t.append(ui->lineEdit_alarm_script_4->text());
    t.append(QString("%1").arg(ui->timeEdit_alarm_4->time().hour()));
    t.append(QString("%1").arg(ui->timeEdit_alarm_4->time().minute()));
    this->storage.setTabData(TABID_ALARM, 4, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_alarm_type_5->currentIndex()));
    t.append(ui->lineEdit_alarm_parameter_5->text());
    t.append(QString("%1").arg(ui->comboBox_alarm_action_5->currentIndex()));
    t.append(ui->lineEdit_alarm_script_5->text());
    t.append(QString("%1").arg(ui->timeEdit_alarm_5->time().hour()));
    t.append(QString("%1").arg(ui->timeEdit_alarm_5->time().minute()));
    this->storage.setTabData(TABID_ALARM, 5, t);
    t.clear();
}

/******************************************************************************
 *************************    TAB IR HANDLING    ******************************
 ******************************************************************************/

void MainWindow::on_comboBox_ir_action_0_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_IR_ACTION, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_ir_script_0->setEnabled(isActive);
}

void MainWindow::on_comboBox_ir_action_1_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_IR_ACTION, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_ir_script_1->setEnabled(isActive);
}

void MainWindow::on_comboBox_ir_action_2_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_IR_ACTION, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_ir_script_2->setEnabled(isActive);
}

void MainWindow::on_comboBox_ir_action_3_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_IR_ACTION, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_ir_script_3->setEnabled(isActive);
}

void MainWindow::on_comboBox_ir_action_4_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_IR_ACTION, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_ir_script_4->setEnabled(isActive);
}

void MainWindow::on_comboBox_ir_action_5_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_IR_ACTION, index);
    bool isActive = t[2].toInt() ? true : false;
    ui->lineEdit_ir_script_5->setEnabled(isActive);
}

void MainWindow::on_pushButton_ir_apply_clicked()
{
    QStringList t;

    t.append(ui->lineEdit_ir_parameter_0->text());
    t.append(QString("%1").arg(ui->comboBox_ir_action_0->currentIndex()));
    t.append(ui->lineEdit_ir_script_0->text());
    this->storage.setTabData(TABID_IR, 0, t);
    t.clear();

    t.append(ui->lineEdit_ir_parameter_1->text());
    t.append(QString("%1").arg(ui->comboBox_ir_action_1->currentIndex()));
    t.append(ui->lineEdit_ir_script_1->text());
    this->storage.setTabData(TABID_IR, 1, t);
    t.clear();

    t.append(ui->lineEdit_ir_parameter_2->text());
    t.append(QString("%1").arg(ui->comboBox_ir_action_2->currentIndex()));
    t.append(ui->lineEdit_ir_script_2->text());
    this->storage.setTabData(TABID_IR, 2, t);
    t.clear();

    t.append(ui->lineEdit_ir_parameter_3->text());
    t.append(QString("%1").arg(ui->comboBox_ir_action_3->currentIndex()));
    t.append(ui->lineEdit_ir_script_3->text());
    this->storage.setTabData(TABID_IR, 3, t);
    t.clear();

    t.append(ui->lineEdit_ir_parameter_4->text());
    t.append(QString("%1").arg(ui->comboBox_ir_action_4->currentIndex()));
    t.append(ui->lineEdit_ir_script_4->text());
    this->storage.setTabData(TABID_IR, 4, t);
    t.clear();

    t.append(ui->lineEdit_ir_parameter_5->text());
    t.append(QString("%1").arg(ui->comboBox_ir_action_5->currentIndex()));
    t.append(ui->lineEdit_ir_script_5->text());
    this->storage.setTabData(TABID_IR, 5, t);
    t.clear();
}

void MainWindow::on_lineEdit_ir_parameter_0_returnPressed()
{

}

/******************************************************************************
 *****************    TAB POWER MANAGEMENT HANDLING    ************************
 ******************************************************************************/

void MainWindow::on_comboBox_pm_type_0_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_PM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->comboBox_pm_action_0->setEnabled(rowActive);
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_pm_action_0->currentIndexChanged(ui->comboBox_pm_action_0->currentIndex());
}

void MainWindow::on_comboBox_pm_type_1_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_PM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->comboBox_pm_action_1->setEnabled(rowActive);
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_pm_action_1->currentIndexChanged(ui->comboBox_pm_action_1->currentIndex());
}

void MainWindow::on_comboBox_pm_type_2_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_PM_EVENT, index);
    bool rowActive = t[2].toInt() ? true : false;
    ui->comboBox_pm_action_2->setEnabled(rowActive);
    /* script field depends on value of action comboBox, go to another slot */
    ui->comboBox_pm_action_2->currentIndexChanged(ui->comboBox_pm_action_2->currentIndex());
}

void MainWindow::on_comboBox_pm_action_0_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_PM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_pm_action_0->isEnabled()) {
        ui->lineEdit_pm_script_0->setEnabled(scriptActive);
    } else {
        ui->lineEdit_pm_script_0->setEnabled(false);
    }
}

void MainWindow::on_comboBox_pm_action_1_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_PM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_pm_action_1->isEnabled()) {
        ui->lineEdit_pm_script_1->setEnabled(scriptActive);
    } else {
        ui->lineEdit_pm_script_1->setEnabled(false);
    }
}

void MainWindow::on_comboBox_pm_action_2_currentIndexChanged(int index)
{
    QStringList t = this->storage.getComboBoxVariantData(BOXSUITTYPE_PM_ACTION, index);
    bool scriptActive = t[2].toInt() ? true : false;
    /* If slot is called manually from event comboBox handler, need one more check */
    if (ui->comboBox_pm_action_2->isEnabled()) {
        ui->lineEdit_pm_script_2->setEnabled(scriptActive);
    } else {
        ui->lineEdit_pm_script_2->setEnabled(false);
    }
}

void MainWindow::on_pushButton_pm_apply_clicked()
{
    QStringList t;

    t.append(QString("%1").arg(ui->comboBox_pm_type_0->currentIndex()));
    t.append(QString("%1").arg(ui->comboBox_pm_action_0->currentIndex()));
    t.append(ui->lineEdit_pm_script_0->text());
    this->storage.setTabData(TABID_PM, 0, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_pm_type_1->currentIndex()));
    t.append(QString("%1").arg(ui->comboBox_pm_action_1->currentIndex()));
    t.append(ui->lineEdit_pm_script_1->text());
    this->storage.setTabData(TABID_PM, 1, t);
    t.clear();

    t.append(QString("%1").arg(ui->comboBox_pm_type_2->currentIndex()));
    t.append(QString("%1").arg(ui->comboBox_pm_action_2->currentIndex()));
    t.append(ui->lineEdit_pm_script_2->text());
    this->storage.setTabData(TABID_PM, 2, t);
    t.clear();
}



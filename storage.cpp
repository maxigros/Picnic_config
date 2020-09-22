#include "storage.h"

Storage::Storage()
{
    /******************      DB file operations     ***************************/

    QString currentDir = QCoreApplication::applicationDirPath();
    QString mainDbName = currentDir;
    mainDbName.append("/");
    mainDbName.append(this->dbFileName);
    /* Check existing main DB */
    if (!QFileInfo(mainDbName).exists()) {
        /* Not found, use default copy */
        QString defaultDbName = currentDir;
        defaultDbName.append("/");
        defaultDbName.append(this->dbFileNameDefault);
        /* Check if default DB exists */
        if (QFileInfo(defaultDbName).exists()) {
            /* Copy default --> main */
            if (!QFile::copy(defaultDbName, mainDbName)) {
                /* Cannot copy file */
                exit(ERROR_DB_FILE);
            }
        } else {
            /* Don't have main nor default copy of DB, shit */
            exit(ERROR_DB_FILE);
        }
    }
    this->dbPath = mainDbName;

    /*********************      DB routines     *******************************/

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(this->dbPath);

}

Storage::~Storage()
{

}

QStringList Storage::getComboBoxVariants(uint8_t type)
{
    QStringList result;
    QString queryText = "SELECT text FROM ";
    switch (type) {
        case BOXSUITTYPE_POW_S:
            queryText.append("buttonsActionsPowerShort");
            break;
        case BOXSUITTYPE_POW_L:
            queryText.append("buttonsActionsPowerLong");
            break;
        case BOXSUITTYPE_RES_S:
            queryText.append("buttonsActionsResetShort");
            break;
        case BOXSUITTYPE_ALARM_EVENT:
            queryText.append("alarmEvents");
            break;
        case BOXSUITTYPE_ALARM_ACTION:
            queryText.append("alarmActions");
            break;
        case BOXSUITTYPE_IR_ACTION:
            queryText.append("irActions");
            break;
        case BOXSUITTYPE_PM_EVENT:
            queryText.append("pmEvents");
            break;
        case BOXSUITTYPE_PM_ACTION:
            queryText.append("pmActions");
            break;
        default:
            break;
    }

#ifdef DEBUG_DB_MSG
    qDebug() << queryText;
#endif

    if (!this->db.open()) {
        exit(ERROR_DB_OPEN);
    }
    QSqlQuery query;
    query.exec(queryText);
    while(query.next()) {
        result.append(query.value(0).toString());
    }
    this->db.close();

    return result;
}

QStringList Storage::getComboBoxVariantData(uint8_t type, uint8_t id)
{
    QString arg1, arg2;
    switch (type) {
        case BOXSUITTYPE_ALARM_EVENT:
            arg1 = "rowid, text, row_active, use_X";
            arg2 = "alarmEvents";
            break;
        case BOXSUITTYPE_ALARM_ACTION:
            arg1 = "rowid, text, script_active";
            arg2 = "alarmActions";
            break;
        case BOXSUITTYPE_POW_S:
            arg1 = "rowid, text, script_active";
            arg2 = "buttonsActionsPowerShort";
            break;
        case BOXSUITTYPE_POW_L:
            arg1 = "rowid, text";
            arg2 = "buttonsActionsPowerLong";
            break;
        case BOXSUITTYPE_RES_S:
            arg1 = "rowid, text, script_active";
            arg2 = "buttonsActionsResetShort";
            break;
        case BOXSUITTYPE_IR_ACTION:
            arg1 = "rowid, text, script_active";
            arg2 = "irActions";
            break;
        case BOXSUITTYPE_PM_EVENT:
            arg1 = "rowid, text, row_active";
            arg2 = "pmEvents";
            break;
        case BOXSUITTYPE_PM_ACTION:
            arg1 = "rowid, text, script_active";
            arg2 = "pmActions";
            break;
        default:
            break;
    }

    QString queryText = QString("SELECT %1 FROM %2 WHERE rowid=%3").arg(arg1).arg(arg2).arg(id + 1);

#ifdef DEBUG_DB_MSG
    qDebug() << queryText;
#endif

    if (!this->db.open()) {
        exit(ERROR_DB_OPEN);
    }
    QSqlQuery query;
    QStringList result;
    query.exec(queryText);
    while(query.next()) {
        for (uint8_t i = 0; i < query.record().count(); ++i) {
            result.append(query.value(i).toString());
        }
    }
    this->db.close();
    return result;
}

QStringList Storage::getTabData(uint8_t tabId, uint8_t row)
{
    QString arg1, arg2;
    switch (tabId) {
        case TABID_BUTTONS:
            arg1 = "rowid, name, id_currentAction, script";
            arg2 = "tabButtons";
            break;
        case TABID_CLOCK:
            arg1 = "rowid, name, value";
            arg2 = "tabClock";
            break;
        case TABID_ALARM:
            arg1 = "rowid, id_currentEvent, parameter, id_currentAction, script, hours, minutes";
            arg2 = "tabAlarm";
            break;
        case TABID_IR:
            arg1 = "rowid, parameter, id_currentAction, script";
            arg2 = "tabIr";
            break;
        case TABID_PM:
            arg1 = "rowid, id_currentEvent, id_currentAction, script";
            arg2 = "tabPm";
            break;
        default:
            break;
    }

    QString queryText = QString("SELECT %1 FROM %2 WHERE rowid=%3").arg(arg1).arg(arg2).arg(row + 1);

#ifdef DEBUG_DB_MSG
    qDebug() << queryText;
#endif

    if (!this->db.open()) {
        exit(ERROR_DB_OPEN);
    }
    QSqlQuery query;
    QStringList result;
    query.exec(queryText);
    while(query.next()) {
        for (uint8_t i = 0; i < query.record().count(); ++i) {
            result.append(query.value(i).toString());
        }
    }
    this->db.close();
    return result;
}

void Storage::setTabData(uint8_t tabId, uint8_t row, QStringList data)
{
    QString arg1, arg2;
    switch (tabId) {
        case TABID_BUTTONS:
            arg1 = "tabButtons";
            switch (row) {
                case 0:
                case 2:
                    arg2 = QString("id_currentAction = %1, script = '%2'")
                            .arg(data[0].toInt())
                            .arg(data[1]);
                    break;
                case 1:
                    arg2 = QString("id_currentAction = %1")
                            .arg(data[0].toInt());
                    break;
            }
            break;
        case TABID_CLOCK:
            arg1 = "tabClock";
            arg2 = QString("value = %1").arg(data[0].toInt());
            break;
        case TABID_ALARM:
            arg1 = "tabAlarm";
            arg2 = QString("id_currentEvent = %1, parameter = %2, id_currentAction = %3, script = '%4', hours = %5, minutes = %6")
                    .arg(data[0].toInt())
                    .arg(data[1].toInt())
                    .arg(data[2].toInt())
                    .arg(data[3])
                    .arg(data[4].toInt())
                    .arg(data[5].toInt());
            break;
        case TABID_IR:
            arg1 = "tabIr";
            arg2 = QString("parameter = %1, id_currentAction = %2, script = '%3'")
                    .arg(data[0].toInt())
                    .arg(data[1].toInt())
                    .arg(data[2]);
            break;
        case TABID_PM:
            arg1 = "tabPm";
            arg2 = QString("id_currentEvent = %1, id_currentAction = %2, script = '%3'")
                    .arg(data[0].toInt())
                    .arg(data[1].toInt())
                    .arg(data[2]);
            break;
        default:
            break;
    }

    QString queryText = QString("UPDATE %1 SET %2 WHERE rowid = %3").arg(arg1).arg(arg2).arg(row + 1);

#ifdef DEBUG_DB_MSG
    qDebug() << queryText;
#endif

    if (!this->db.open()) {
        exit(ERROR_DB_OPEN);
    }
    QSqlQuery query;
    query.exec(queryText);
    this->db.close();
}

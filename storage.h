#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>
#include <QDebug>


enum errors {
    ERROR_DB_FILE = -1,
    ERROR_DB_OPEN = -2,
};

enum boxSuitType {
    BOXSUITTYPE_POW_S,
    BOXSUITTYPE_POW_L,
    BOXSUITTYPE_RES_S,
    BOXSUITTYPE_ALARM_EVENT,
    BOXSUITTYPE_ALARM_ACTION,
    BOXSUITTYPE_IR_ACTION,
    BOXSUITTYPE_PM_EVENT,
    BOXSUITTYPE_PM_ACTION
};

enum tabIDs {
    TABID_BUTTONS,
    TABID_CLOCK,
    TABID_ALARM,
    TABID_IR,
    TABID_PM
};


class Storage
{
    public:
        Storage();
        ~Storage();
        QStringList getComboBoxVariants(uint8_t type);
        QStringList getComboBoxVariantData(uint8_t type, uint8_t id);
        QStringList getTabData(uint8_t tabId, uint8_t row);
        void setTabData(uint8_t tabId, uint8_t row, QStringList data);

    private:
        const QString dbFileName = "database.sqlite";
        const QString dbFileNameDefault = "database_default.sqlite";
        QString dbPath;
        QSqlDatabase db;
};

#endif // STORAGE_H

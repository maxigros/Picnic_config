#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <fstream>
#include <cstdint>  /* For uint*_t types */
#include <experimental/filesystem>
#include <QCoreApplication>
#include <QFileInfo>

using namespace std;
namespace fs = std::experimental::filesystem;

#define VALID_SEQUENCE  0xdeadbeef
#define MAX_PATH_SIZE   80

/* Struct for storing string in file */
typedef struct {
    uint8_t size = 0;
    char str[MAX_PATH_SIZE] = {0};
} stringInStorage_t;

enum Events {
    EVENT_EMPTY,
    EVENT_ONCE,
    EVENT_DAILY,
    EVENT_X_HOURS,
    EVENT_X_MINUTES
};

enum Actions {
    ACTION_EMPTY,
    ACTION_SCRIPT,
    ACTION_HARD_ON,
    ACTION_HARD_OFF,
    ACTION_HARD_RESET,
    ACTION_SOFT_OFF,
    ACTION_SOFT_RESET
};

enum Watchdog {
    WATCHDOG_ON,
    WATCHDOG_OFF
};

typedef struct {
    uint32_t validSequence;

    uint32_t buttonsActionPowerShort:4;     /* <==== BUTTONS */
    uint32_t buttonsActionPowerLong:4;
    uint32_t buttonsActionResetShort:4;
    uint32_t clockWatchdog:4;               /* <==== CLOCK */
    uint32_t alarmEvent0:4;                 /* <==== ALARM */
    uint32_t alarmEvent1:4;
    uint32_t alarmEvent2:4;
    uint32_t alarmEvent3:4;

    uint32_t alarmEvent4:4;
    uint32_t alarmEvent5:4;
    uint32_t alarmAction0:4;
    uint32_t alarmAction1:4;
    uint32_t alarmAction2:4;
    uint32_t alarmAction3:4;
    uint32_t alarmAction4:4;
    uint32_t alarmAction5:4;

    uint32_t irAction0:4;                   /* <==== IR */
    uint32_t irAction1:4;
    uint32_t irAction2:4;
    uint32_t irAction3:4;
    uint32_t irAction4:4;
    uint32_t irAction5:4;
    uint32_t pmActionOn:4;                  /* <==== POWER MANAGEMENT */
    uint32_t pmActionOff:4;

    uint32_t pmActionLow:4;
    uint32_t rsvd:28;

    uint32_t irCode0;                       /* <==== IR */
    uint32_t irCode1;
    uint32_t irCode2;
    uint32_t irCode3;
    uint32_t irCode4;
    uint32_t irCode5;

    uint32_t alarmParam0:16;                   /* <==== ALARM */
    uint32_t alarmParam1:16;

    uint32_t alarmParam2:16;
    uint32_t alarmParam3:16;

    uint32_t alarmParam4:16;
    uint32_t alarmParam5:16;
} optionStorageFields_t;

enum Scripts {
    SCRIPT_BUTTONS_POWER,
    SCRIPT_BUTTONS_RESET,
    SCRIPT_ALARM_0,
    SCRIPT_ALARM_1,
    SCRIPT_ALARM_2,
    SCRIPT_ALARM_3,
    SCRIPT_ALARM_4,
    SCRIPT_ALARM_5,
    SCRIPT_IR_0,
    SCRIPT_IR_1,
    SCRIPT_IR_2,
    SCRIPT_IR_3,
    SCRIPT_IR_4,
    SCRIPT_IR_5,
    SCRIPT_PM_ON,
    SCRIPT_PM_OFF,
    SCRIPT_PM_LOW
};

// typedef struct {
//     stringInStorage_t buttonsPower;
//     stringInStorage_t buttonsReset;
//     stringInStorage_t alarm0;
//     stringInStorage_t alarm1;
//     stringInStorage_t alarm2;
//     stringInStorage_t alarm3;
//     stringInStorage_t alarm4;
//     stringInStorage_t alarm5;
//     stringInStorage_t ir0;
//     stringInStorage_t ir1;
//     stringInStorage_t ir2;
//     stringInStorage_t ir3;
//     stringInStorage_t ir4;
//     stringInStorage_t ir5;
//     stringInStorage_t pmOn;
//     stringInStorage_t pmOff;
//     stringInStorage_t pmLow;
// } scriptStorageFields_t;

#define OPTIONS_UINT32_SIZE     14
union optionStorage_t {
    optionStorageFields_t fields;
    uint32_t data[OPTIONS_UINT32_SIZE];
};

#define SCRIPTS_NUM     17
// union scriptStorage_t {
//     scriptStorageFields_t fields;
//     stringInStorage_t data[SCRIPTS_NUM];
// };

class Storage
{
    public:
        Storage();
        ~Storage() {}
        void readFullFile();
        void writeFullFile();

        optionStorage_t dataOptions;
        // scriptStorage_t dataScripts;
        stringInStorage_t dataScripts[SCRIPTS_NUM];

    private:
        void createNewDataFile();
        uint32_t readValidSequence();

        string dataFileName = "data.bin";
        uint32_t validSequence = VALID_SEQUENCE;
};

#endif // STORAGE_H

#include "storage.h"

Storage::Storage()
{
    QString path = QCoreApplication::applicationDirPath();
    path.append(QString::fromStdString(this->dataFileName));

    /* Check existing data file */
    if (!QFileInfo(path).exists()) {
        /* Not found, need to create and init */
        cout << "need new file\n\r";
        this->createNewDataFile();
    }
    cout << "file found\n\r";
    /* Check valid sequence */
    uint32_t t = this->readValidSequence();
    if (t != this->validSequence) {
        /* Valid sequence error, re-create file */
        cout << "need re-create new file\n\r";
        QFile::remove(path);
        this->createNewDataFile();
    }
    /* One more check valid sequence */
    t = this->readValidSequence();
    if (t != this->validSequence) {
        /* Undefined file error, exit */
        exit(-1);
    }
    cout << "file OK\n\r";
    /* File OK, read it and fill dataStruct */
    this->readFullFile();
}

void Storage::createNewDataFile()
{
    cout << "new file\n\r";
    // TODO: fill from STM, not manually

    /* Fill dataStrucr with default values */
    this->dataOptions.fields.validSequence = this->validSequence;

    /* Write to empty file */
    this->writeFullFile();
}

void Storage::readFullFile()
{
    ifstream file_in(this->dataFileName.c_str(), std::ios::in | std::ios::binary);
    if (!file_in) {
        cout << "open in file failed\n\r";
        return;
    }

    for (uint8_t i = 0; i < OPTIONS_UINT32_SIZE; ++i) {
        file_in.read(reinterpret_cast<char*>(&(this->dataOptions.data[i])), sizeof(uint32_t));
    }

    for (uint8_t i = 0; i < SCRIPTS_NUM; ++i) {
        file_in.read(reinterpret_cast<char*>(&(this->dataScripts[i].size)), sizeof(uint8_t));
        file_in.read(this->dataScripts[i].str, this->dataScripts[i].size);
    }
    file_in.close();
}

void Storage::writeFullFile()
{
    ofstream file_out(this->dataFileName.c_str(), std::ios::out | std::ios::binary);
    if (!file_out) {
        cout << "open out file failed\n\r";
        return;
    }

    for (uint8_t i = 0; i < OPTIONS_UINT32_SIZE; ++i) {
        file_out.write(reinterpret_cast<char*>(&(this->dataOptions.data[i])), sizeof(uint32_t));
    }

    for (uint8_t i = 0; i < SCRIPTS_NUM; ++i) {
        file_out.write(reinterpret_cast<char*>(&(this->dataScripts[i].size)), sizeof(uint8_t));
        file_out.write(this->dataScripts[i].str, this->dataScripts[i].size);
    }

    file_out.flush();
    file_out.close();
}

uint32_t Storage::readValidSequence()
{
    ifstream file_in(this->dataFileName.c_str(), std::ios::in | std::ios::binary);
    if (!file_in) {
        cout << "open in file failed\n\r";
        return 0;
    }

    uint32_t temp = 0;

    file_in.read(reinterpret_cast<char*>(&(temp)), sizeof(uint32_t));
    file_in.close();

    return temp;
}


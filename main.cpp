#include "mainwindow.h"
#include "miniwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* TODO: check I2C ID, set window type */

   MainWindow w;    /* Full window */
   w.show();

    // MiniWindow mini;
    // mini.show();

    return a.exec();
}

#include <QApplication>
#include "../include/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);

    // app settings etc
    aa.setApplicationName("SigWatch");
    aa.setApplicationDisplayName("sykaya - Spectrum Analyzer");
    aa.setOrganizationName("sykaya");

    MainWindow www;
    www.show();

    return aa.exec();
}

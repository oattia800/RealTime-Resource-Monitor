#include <QCoreApplication>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include <QProcess>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include "cpu.h"
#include "disk.h"
#include "ram.h"
#include "network.h"
#include "gpu.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow w;
    w.show();  // This displays the GUI

    return app.exec();  // Starts the event loop
}

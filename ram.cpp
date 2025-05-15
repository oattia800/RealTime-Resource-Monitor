#include "ram.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include <cstdlib>

double Ram::extractMemoryValue(const QString &line)
{
    int colonPos = line.indexOf(":");
    if (colonPos != -1) {
        QString valueString = line.mid(colonPos + 1).trimmed().split(" ").first();
        bool ok;
        double valueInKB = valueString.toDouble(&ok);
        if (ok) {
            return valueInKB / 1024.0 / 1024.0;
        }
    }
    return 0.0;
}
double Ram::getMemtotal(){
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 0;
    }

    QTextStream in(&file);
    QString line;
    double memtotal=0;
    while (in.readLineInto(&line)) {
        if (line.contains("MemTotal")) {
            memtotal=extractMemoryValue(line);
        }
    }
    file.close();

    return memtotal;
}

double Ram:: getfreeMem(){
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 0;
    }

    QTextStream in(&file);
    QString line;
    double freemem=0;
    while (in.readLineInto(&line)) {
        if (line.contains("MemFree")) {
            freemem=extractMemoryValue(line);
        }
    }
    file.close();

    return freemem;
}

double Ram::getMemAvailable(){
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 0;
    }

    QTextStream in(&file);
    QString line;
    double MemAvailable=0;
    while (in.readLineInto(&line)) {
        if (line.contains("MemAvailable")) {
            MemAvailable=extractMemoryValue(line);
        }
    }
    file.close();

    return MemAvailable;
}

double Ram::getCached(){
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 0;
    }

    QTextStream in(&file);
    QString line;
    double cached=0;
    while (in.readLineInto(&line)) {
        if (line.contains("Cached")) {
            cached=extractMemoryValue(line);
        }
    }
    file.close();

    return cached;
}

void Ram::printMemoryInfo()
{
    qDebug() << "\nTotal Memory: " << getMemtotal() << "GB";
    qDebug() << "Free Memory: " << getfreeMem() << "GB";
    qDebug() << "Available Memory: " << getMemAvailable() << "GB";
    //qDebug() << "Model Name: " << getRamModel();
}

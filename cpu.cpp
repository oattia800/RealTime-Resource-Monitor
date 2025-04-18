#include "cpu.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <iomanip>

cpu::cpu() {}

void cpu::getCoreCount() {
    long cores = sysconf(_SC_NPROCESSORS_ONLN);
    std::cout << "CPU Cores: " << cores << std::endl;
}

std::string cpu::getCpuModel() {
    std::ifstream file("/proc/cpuinfo");
    std::string line;

    while (getline(file, line)) {
        if (line.find("model name") != std::string::npos) {
            file.close();
            return line.substr(line.find(":") + 2); // Extract CPU name after ": "
        }
    }
    file.close();
    return "Unknown CPU";
}

QString cpu::getCpuClockSpeeds() {
    QFile file("/proc/cpuinfo");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open /proc/cpuinfo";
        return "Unknown Clock Speed";
    }

    QTextStream in(&file);
    QString line;
    while (in.readLineInto(&line)) {
        if (line.contains("cpu MHz")) {
            file.close();
            return line.split(":").last().trimmed(); // Extract clock speed value
        }
    }
    file.close();
    return "Unknown Clock Speed"; // Default if no match
}

float cpu::getCpuUsage() {
    std::ifstream file("/proc/stat");
    std::string line;
    getline(file, line);
    file.close();

    long user, nice, system, idle;
    sscanf(line.c_str(), "cpu %ld %ld %ld %ld", &user, &nice, &system, &idle);
    return 100.0 * (user + nice + system) / (user + nice + system + idle);
}

void cpu::startMonitoring() {
    while (true) {
        float usage = getCpuUsage();
        std::cout << "\rCPU Usage: " << std::fixed << std::setprecision(2) << usage << " %" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


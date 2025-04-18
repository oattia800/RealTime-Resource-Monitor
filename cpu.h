#ifndef CPU_H
#define CPU_H

#include <string>
#include <QString>

class cpu {
public:
    cpu();
    void getCoreCount();
    std::string getCpuModel();
    QString getCpuClockSpeeds();
    float getCpuUsage();
    void startMonitoring();  // Real-time loop
};

#endif // CPU_H

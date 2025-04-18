#ifndef GPU_H
#define GPU_H

#include <QString>

class Gpu
{
public:
    Gpu();

    QString getGpuName() const;
    QString getGpuClockSpeed() const;
    QString getGpuMemory() const;

private:
    QString gpuName;
    QString gpuClockSpeed;
    QString gpuMemory;

    void fetchGpuInfo();
};

#endif // GPU_H

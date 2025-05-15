#include "gpu.h"
#include <QProcess>
#include <QRegularExpression>
#include <QDebug>

Gpu::Gpu() {
    fetchGpuInfo();
}

QString Gpu::getGpuName() const {
    return gpuName;
}

QString Gpu::getGpuClockSpeed() const {
    return gpuClockSpeed;
}

QString Gpu::getGpuMemory() const {
    return gpuMemory;
}

void Gpu::fetchGpuInfo() {
    static const QRegularExpression nameRegex("product: ([^\n]+)");
    static const QRegularExpression clockRegex("clock: (\\d+MHz)");
    static const QRegularExpression memoryRegex("size: ([^\n]+)");

    QProcess process;
    process.start("lshw", QStringList() << "-C" << "display");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();

    if (output.isEmpty()) {
        gpuName = "Unavailable";
        gpuClockSpeed = "Unavailable";
        gpuMemory = "Unavailable";
        return;
    }

    QRegularExpressionMatch nameMatch = nameRegex.match(output);
    if (nameMatch.hasMatch()) {
        gpuName = nameMatch.captured(1).trimmed();
    } else {
        gpuName = "Unknown Integrated GPU";
    }

    QRegularExpressionMatch clockMatch = clockRegex.match(output);
    if (clockMatch.hasMatch()) {
        gpuClockSpeed = clockMatch.captured(1).trimmed();
    } else {
        gpuClockSpeed = "Not Reported";
    }

    QRegularExpressionMatch memoryMatch = memoryRegex.match(output);
    if (memoryMatch.hasMatch()) {
        gpuMemory = memoryMatch.captured(1).trimmed();
    } else {
        gpuMemory = "Shared/System RAM";
    }
}

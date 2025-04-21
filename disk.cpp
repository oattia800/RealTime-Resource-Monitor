#include "disk.h"
#include <iostream>
#include <fstream>
#include <sys/statvfs.h>
#include <string>
#include <chrono>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <thread>

Disk::Disk() {}

std::string Disk::getDiskModel(const std::string& diskName) {
    std::string path = "/sys/block/" + diskName + "/device/model";
    std::ifstream file(path);
    std::string modelName;

    if (file.is_open()) {
        getline(file, modelName);
        file.close();
    } else {
        return "Unknown Disk Model";
    }

    return modelName;
}

long long Disk::getReadBytes(const std::string& diskName) {
    std::ifstream file("/proc/diskstats");
    std::string line;

    while (getline(file, line)) {
        if (line.find(diskName) != std::string::npos) {
            std::istringstream iss(line);
            std::string ignore;
            long long reads = 0;
            iss >> ignore >> ignore >> ignore; // major, minor, device name
            iss >> reads;
            return reads * 512; // sectors to bytes
        }
    }
    return 0;
}

long long Disk::getWriteBytes(const std::string& diskName) {
    std::ifstream file("/proc/diskstats");
    std::string line;

    while (getline(file, line)) {
        if (line.find(diskName) != std::string::npos) {
            std::istringstream iss(line);
            std::string ignore;
            long long dummy, writes = 0;
            iss >> ignore >> ignore >> ignore; // skip header
            for (int i = 0; i < 4; ++i) iss >> dummy; // skip read fields
            iss >> writes;
            return writes * 512;
        }
    }
    return 0;
}

void Disk::monitorDiskIO(const std::string& diskName) {
    while (true) {
        long long currRead = getReadBytes(diskName);
        long long currWrite = getWriteBytes(diskName);

        double readSpeedMBps = (currRead - prevReadBytes) / (1024.0 * 1024.0 * 0.5);
        double writeSpeedMBps = (currWrite - prevWriteBytes) / (1024.0 * 1024.0 * 0.5);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\rDisk Read: " << readSpeedMBps << " MB/s | "
                  << "Write: " << writeSpeedMBps << " MB/s" << std::flush;

        prevReadBytes = currRead;
        prevWriteBytes = currWrite;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

DiskSpaceInfo Disk::getDiskSpace(const std::string& path) {
    struct statvfs stat;
    DiskSpaceInfo info{};

    if (statvfs(path.c_str(), &stat) != 0) {
        std::cerr << "Error: Cannot retrieve disk information for " << path << std::endl;
        return info;
    }

    info.total = stat.f_blocks * stat.f_frsize;
    info.free = stat.f_bfree * stat.f_frsize;
    info.used = info.total - info.free;

    return info;
}


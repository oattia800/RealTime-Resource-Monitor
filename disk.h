#ifndef DISK_H
#define DISK_H

#include <string>

class Disk {
public:
    Disk();
    void getDiskSpace(const std::string& path);  // Get total, used, and free disk space
    std::string getDiskModel(const std::string& diskName);  // Get disk model name
    long long getReadBytes(const std::string& diskName);
    long long getWriteBytes(const std::string& diskName);
    void monitorDiskIO(const std::string& diskName);

private:
    long long prevReadBytes = 0;
    long long prevWriteBytes = 0;
};

#endif // DISK_H

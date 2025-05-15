#include "network.h"
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <sys/stat.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

Network::Network(const std::string& iface)
    : interface(iface), lastRxBytes(0), lastTxBytes(0), downloadSpeed(0.0), uploadSpeed(0.0) {
    lastRxBytes = getRxBytes();
    lastTxBytes = getTxBytes();
}

long long Network::getRxBytes() {
    std::ifstream file("/proc/net/dev");
    std::string line;
    while (getline(file, line)) {
        if (line.find(interface) != std::string::npos) {
            std::istringstream iss(line);
            std::string iface;
            long long rxBytes = 0;
            iss >> iface;
            iss >> rxBytes;
            return rxBytes;
        }
    }
    return 0;
}

long long Network::getTxBytes() {
    std::ifstream file("/proc/net/dev");
    std::string line;
    while (getline(file, line)) {
        if (line.find(interface) != std::string::npos) {
            std::istringstream iss(line);
            std::string iface;
            long long dummy, txBytes;
            iss >> iface;
            for (int i = 0; i < 8; ++i) iss >> dummy; // skip 8 fields
            iss >> txBytes;
            return txBytes;
        }
    }
    return 0;
}

void Network::updateStats() {
    using namespace std::chrono;

    long long currentRx = getRxBytes();
    long long currentTx = getTxBytes();

    std::this_thread::sleep_for(milliseconds(500));

    long long newRx = getRxBytes();
    long long newTx = getTxBytes();

    downloadSpeed = (newRx - currentRx) / (1024.0 * 1024.0 * 0.5);
    uploadSpeed = (newTx - currentTx) / (1024.0 * 1024.0 * 0.5);

    lastRxBytes = newRx;
    lastTxBytes = newTx;
}

std::string Network::getIPv4Address() const {
    struct ifaddrs* ifaddr;
    std::string ipv4 = "Not available";

    if (getifaddrs(&ifaddr) == -1) return ipv4;

    for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr || interface != ifa->ifa_name) continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            char addr[INET_ADDRSTRLEN];
            void* ptr = &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, ptr, addr, INET_ADDRSTRLEN);
            ipv4 = addr;
            break;
        }
    }

    freeifaddrs(ifaddr);
    return ipv4;
}

std::string Network::getIPv6Address() const {
    struct ifaddrs* ifaddr;
    std::string ipv6 = "Not available";

    if (getifaddrs(&ifaddr) == -1) return ipv6;

    for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr || interface != ifa->ifa_name) continue;

        if (ifa->ifa_addr->sa_family == AF_INET6) {
            char addr[INET6_ADDRSTRLEN];
            void* ptr = &((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr;
            inet_ntop(AF_INET6, ptr, addr, INET6_ADDRSTRLEN);
            ipv6 = addr;
            break;
        }
    }

    freeifaddrs(ifaddr);
    return ipv6;
}

bool Network::isWireless() const {
    std::string path = "/sys/class/net/" + interface + "/wireless";
    struct stat info;
    return stat(path.c_str(), &info) == 0 && S_ISDIR(info.st_mode);
}

double Network::getDownloadSpeed() {
    return downloadSpeed;
}

double Network::getUploadSpeed() {
    return uploadSpeed;
}

std::string Network::getInterface() const {
    return interface;
}

std::string Network::getInterfaceName() const {
    return interface;
}

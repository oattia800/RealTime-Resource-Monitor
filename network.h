#ifndef NETWORK_H
#define NETWORK_H

#include <string>

class Network {
public:
    Network(const std::string& interface = "eth0");  // default to eth0
    void updateStats();
    double getDownloadSpeed(); // MB/s
    double getUploadSpeed();   // MB/s
    std::string getInterface() const;
    long long getRxBytes();
    long long getTxBytes();
    bool isWireless() const;
    std::string getInterfaceName() const;
    std::string getIPv4Address() const;
    std::string getIPv6Address() const;



private:
    std::string interface;
    long long lastRxBytes;
    long long lastTxBytes;
    double downloadSpeed;
    double uploadSpeed;
    std::string interfaceName;
};

#endif // NETWORK_H

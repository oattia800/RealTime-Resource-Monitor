#ifndef RAM_H
#define RAM_H
#include <QString>
class Ram
{
public:
    Ram() {}

    void printMemoryInfo();
    double extractMemoryValue(const QString &line);
    double  getMemtotal();
    double getfreeMem();
    double getMemAvailable();
    double getCached();
    //QString getRamModel();

};

#endif // RAM_H

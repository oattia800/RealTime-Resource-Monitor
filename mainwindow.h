#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cpu.h"
#include "ram.h"
#include "disk.h"
#include "gpu.h"
#include "network.h"
#include <QTimer>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    cpu cpuInfo;
    Ram ramInfo;
    Disk diskInfo;
    Gpu gpuInfo;
    Network netInfo{"ens33"}; // or "wlan0" depending on your system

    QTimer *updateTimer;
    void updateStats();
    void applyTheme();
    void updateTabVisibility();

};
#endif // MAINWINDOW_H

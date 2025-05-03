
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtConcurrent>
#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList bgColors = { "#1e1e1e", "#000000", "#2b2b2b", "#ffffff", "#f0f0f0" };
    QStringList fontColors = { "#00ffff", "#ffffff", "#00ff00", "#ff0000", "#000000" };

    for (const QString &color : bgColors) {
        QPixmap pixmap(50, 20);
        pixmap.fill(QColor(color));
        ui->comboBox_2->addItem(QIcon(pixmap), color, color);  // display icon, store color
    }

    for (const QString &color : fontColors) {
        QPixmap pixmap(50, 20);
        pixmap.fill(QColor(color));
        ui->comboBox_3->addItem(QIcon(pixmap), color, color);
    }


    // Font sizes
    ui->comboBox_4->addItems({"12px", "14px", "16px", "18px", "20px"});
    ui->tabWidget->setCurrentIndex(0);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::applyTheme);
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::applyTheme);
    connect(ui->comboBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::applyTheme);
    connect(ui->comboBox_4, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::applyTheme);


    connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::updateTabVisibility);
    connect(ui->checkBox_2, &QCheckBox::toggled, this, &MainWindow::updateTabVisibility);
    connect(ui->checkBox_3, &QCheckBox::toggled, this, &MainWindow::updateTabVisibility);
    connect(ui->checkBox_4, &QCheckBox::toggled, this, &MainWindow::updateTabVisibility);
    connect(ui->checkBox_5, &QCheckBox::toggled, this, &MainWindow::updateTabVisibility);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateStats);
    updateTimer->start(1000); // Reduced to 1 second

    updateStats();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStats()
{
    //CPU
    static QElapsedTimer heavyTimer;
    if (!heavyTimer.isValid()) heavyTimer.start();

    QtConcurrent::run([=]() {
        float usage = cpuInfo.getCpuUsage();
        QString usageText = QString("Usage: %1%").arg(usage, 0, 'f', 2);

        QMetaObject::invokeMethod(this, [=]() {
            static QString lastUsage;
            if (lastUsage != usageText) {
                ui->labelCpuUsage->setText(usageText);
                lastUsage = usageText;
            }
        });
    });

    QtConcurrent::run([=]() {
        QString model = QString::fromStdString(cpuInfo.getCpuModel());
        QString clock = cpuInfo.getCpuClockSpeeds() + " MHz";
        QString arch = "Architecture: " + QSysInfo::currentCpuArchitecture();

        QMetaObject::invokeMethod(this, [=]() {
            ui->labelCpuModel->setText(model);
            ui->labelCpuClock->setText(clock);
            ui->labelCpuArch->setText(arch);
        });
    });

    //GPU
    QtConcurrent::run([=]() {
        QString name = "Name: " + gpuInfo.getGpuName();
        QString clock = "Clock: " + gpuInfo.getGpuClockSpeed();
        QString mem = "Memory: " + gpuInfo.getGpuMemory();

        QMetaObject::invokeMethod(this, [=]() {
            ui->labelGpuName->setText(name);
            ui->labelGpuClockSpeed->setText(clock);
            ui->labelGpuMemory->setText(mem);
        });
    });

    //RAM
    QtConcurrent::run([=]() {
        QString total = QString("Total: %1 GB").arg(ramInfo.getMemtotal(), 0, 'f', 2);
        QString free = QString("Free: %1 GB").arg(ramInfo.getfreeMem(), 0, 'f', 2);
        QString available = QString("Available: %1 GB").arg(ramInfo.getMemAvailable(), 0, 'f', 2);
        QString cached = QString("Cached: %1 GB").arg(ramInfo.getCached(), 0, 'f', 2);

        QMetaObject::invokeMethod(this, [=]() {
            ui->labelRamTotal->setText(total);
            ui->labelRamFree->setText(free);
            ui->labelRamAvailable->setText(available);
            ui->labelRamCached->setText(cached);
        });
    });

    //DISK

    if (heavyTimer.elapsed() > 3000) {
        heavyTimer.restart();

        QtConcurrent::run([=]() {
            DiskSpaceInfo spaceInfo = diskInfo.getDiskSpace("/home");
            std::string diskModel = diskInfo.getDiskModel("sda");

            QString totalDisk = QString("Total Disk Space: %1 GB").arg(spaceInfo.total / (1024.0 * 1024 * 1024), 0, 'f', 0);
            QString usedDisk = QString("Used Disk Space: %1 GB").arg(spaceInfo.used / (1024.0 * 1024 * 1024), 0, 'f', 0);
            QString freeDisk = QString("Free Disk Space: %1 GB").arg(spaceInfo.free / (1024.0 * 1024 * 1024), 0, 'f', 0);

            QMetaObject::invokeMethod(this, [=]() {
                ui->labelDiskModel->setText(QString::fromStdString(diskModel));
                ui->labelDiskTotal->setText(totalDisk);
                ui->labelDiskUsed->setText(usedDisk);
                ui->labelDiskFree->setText(freeDisk);
            });
        });
    }

    static long long prevRead = diskInfo.getReadBytes("sda");
    static long long prevWrite = diskInfo.getWriteBytes("sda");

    long long currRead = diskInfo.getReadBytes("sda");
    long long currWrite = diskInfo.getWriteBytes("sda");

    double readSpeed = (currRead - prevRead) / (1024.0 * 1024.0);
    double writeSpeed = (currWrite - prevWrite) / (1024.0 * 1024.0);

    QString ioText = QString("Read: %1 MB/s | Write: %2 MB/s")
                         .arg((currRead - prevRead) / (1024.0 * 1024.0), 0, 'f', 2)
                         .arg((currWrite - prevWrite) / (1024.0 * 1024.0), 0, 'f', 2);

    static QString lastDiskText;
    if (lastDiskText != ioText) {
        ui->labelDiskSpeed->setText(ioText);
        lastDiskText = ioText;
    }


    //NETWORK
    QtConcurrent::run([=]() {
        netInfo.updateStats();
        QString netSpeed = QString("Down: %1 MB/s | Up: %2 MB/s")
                               .arg(netInfo.getDownloadSpeed(), 0, 'f', 2)
                               .arg(netInfo.getUploadSpeed(), 0, 'f', 2);
        QString ipv4 = "IPv4: " + QString::fromStdString(netInfo.getIPv4Address());
        QString ipv6 = "IPv6: " + QString::fromStdString(netInfo.getIPv6Address());
        QString type = QString("Type: %1").arg(netInfo.isWireless() ? "Wi-Fi" : "Ethernet");

        QMetaObject::invokeMethod(this, [=]() {
            ui->labelNetworkSpeed->setText(netSpeed);
            ui->labelNetworkIP->setText(ipv4);
            ui->labelNetworkIPv6->setText(ipv6);
            ui->labelNetworkType->setText(type);
        });
    });
}

void MainWindow::applyTheme() {
    QString choice = ui->comboBox->currentText();

    if (choice == "Darkmode") {
        qApp->setStyleSheet(R"(
            QWidget {
                background-color: #2b2b2b;
                color: #ffffff;
            }
            QGroupBox {
                border: 1px solid #555;
                margin-top: 10px;
            }
            QLabel {
                color: #ffffff;
            }
            QComboBox, QCheckBox {
                background-color: #3c3f41;
                color: #ffffff;
                border: 1px solid #555;
            }
        )");
    } else if (choice == "Default") {
        qApp->setStyleSheet("");
    } else if (choice == "Custom") {
        QString bgColor = ui->comboBox_2->currentData().toString();
        QString fontColor = ui->comboBox_3->currentData().toString();
        QString fontSize = ui->comboBox_4->currentText();

        QString style = QString(R"(
            QWidget {
                background-color: %1;
                color: %2;
                font-size: %3;
            }
            QGroupBox {
                border: 1px solid %2;
                margin-top: 10px;
            }
            QComboBox, QCheckBox {
                background-color: %1;
                color: %2;
                border: 1px solid %2;
            }
        )").arg(bgColor, fontColor, fontSize);

        qApp->setStyleSheet(style);
    }
}

void MainWindow::updateTabVisibility() {
    // Original tab order
    QList<QWidget*> tabOrder = {
        ui->General,
        ui->CPU,
        ui->GPU,
        ui->RAM,
        ui->DISK,
        ui->NETWORK
    };
    QStringList tabLabels = {
        "Overview",
        "CPU",
        "GPU",
        "RAM",
        "DISK",
        "NETWORK"
    };
    QList<QCheckBox*> checkBoxes = {
        nullptr,            // No checkbox for Overview
        ui->checkBox,
        ui->checkBox_2,
        ui->checkBox_3,
        ui->checkBox_4,
        ui->checkBox_5
    };

    for (int i = 1; i < tabOrder.size(); ++i) {
        QWidget* tab = tabOrder[i];
        QString label = tabLabels[i];
        QCheckBox* box = checkBoxes[i];

        int currentIndex = ui->tabWidget->indexOf(tab);
        bool shouldBeVisible = !box->isChecked();

        if (shouldBeVisible && currentIndex == -1) {
            // Reinsert tab at correct index (after counting how many visible tabs should come before it)
            int insertIndex = 0;
            for (int j = 0; j < i; ++j) {
                if (j == 0 || (checkBoxes[j] && !checkBoxes[j]->isChecked())) {
                    ++insertIndex;
                }
            }
            ui->tabWidget->insertTab(insertIndex, tab, label);
        } else if (!shouldBeVisible && currentIndex != -1) {
            ui->tabWidget->removeTab(currentIndex);
        }
    }
}

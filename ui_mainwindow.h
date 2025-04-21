/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *General;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QComboBox *comboBox;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QWidget *CPU;
    QFormLayout *formLayout;
    QLabel *labelCpuModel;
    QLabel *labelCpuClock;
    QLabel *labelCpuArch;
    QLabel *labelCpuUsage;
    QWidget *RAM;
    QFormLayout *formLayout_2;
    QLabel *labelRamTotal;
    QLabel *labelRamFree;
    QLabel *labelRamAvailable;
    QLabel *labelRamCached;
    QWidget *GPU;
    QFormLayout *formLayout_3;
    QLabel *labelGpuClockSpeed;
    QLabel *labelGpuName;
    QLabel *labelGpuMemory;
    QWidget *DISK;
    QFormLayout *formLayout_4;
    QLabel *labelDiskModel;
    QLabel *labelDiskSpeed;
    QLabel *labelDiskTotal;
    QLabel *labelDiskUsed;
    QLabel *labelDiskFree;
    QWidget *NETWORK;
    QFormLayout *formLayout_5;
    QLabel *labelNetworkSpeed;
    QLabel *labelNetworkIP;
    QLabel *labelNetworkIPv6;
    QLabel *labelNetworkType;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->resize(918, 608);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::TabPosition::West);
        tabWidget->setTabShape(QTabWidget::TabShape::Triangular);
        General = new QWidget();
        General->setObjectName(QString::fromUtf8("General"));
        scrollArea = new QScrollArea(General);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(220, 0, 641, 531));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 625, 529));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 611, 221));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 220, 611, 211));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 430, 611, 211));
        scrollArea->setWidget(scrollAreaWidgetContents);
        comboBox = new QComboBox(General);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 200, 86, 26));
        label_2 = new QLabel(General);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 180, 66, 18));
        groupBox_4 = new QGroupBox(General);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 260, 141, 191));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 121, 18));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 101, 18));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 66, 18));
        comboBox_2 = new QComboBox(groupBox_4);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 50, 121, 26));
        comboBox_3 = new QComboBox(groupBox_4);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(10, 100, 121, 26));
        comboBox_4 = new QComboBox(groupBox_4);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(10, 150, 121, 26));
        groupBox_5 = new QGroupBox(General);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(30, 20, 120, 131));
        checkBox = new QCheckBox(groupBox_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 20, 92, 24));
        checkBox_2 = new QCheckBox(groupBox_5);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 40, 92, 24));
        checkBox_3 = new QCheckBox(groupBox_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 60, 92, 24));
        checkBox_4 = new QCheckBox(groupBox_5);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 80, 92, 24));
        checkBox_5 = new QCheckBox(groupBox_5);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(10, 100, 92, 24));
        tabWidget->addTab(General, QString());
        CPU = new QWidget();
        CPU->setObjectName(QString::fromUtf8("CPU"));
        formLayout = new QFormLayout(CPU);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelCpuModel = new QLabel(CPU);
        labelCpuModel->setObjectName(QString::fromUtf8("labelCpuModel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelCpuModel);

        labelCpuClock = new QLabel(CPU);
        labelCpuClock->setObjectName(QString::fromUtf8("labelCpuClock"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelCpuClock);

        labelCpuArch = new QLabel(CPU);
        labelCpuArch->setObjectName(QString::fromUtf8("labelCpuArch"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelCpuArch);

        labelCpuUsage = new QLabel(CPU);
        labelCpuUsage->setObjectName(QString::fromUtf8("labelCpuUsage"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelCpuUsage);

        tabWidget->addTab(CPU, QString());
        RAM = new QWidget();
        RAM->setObjectName(QString::fromUtf8("RAM"));
        formLayout_2 = new QFormLayout(RAM);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelRamTotal = new QLabel(RAM);
        labelRamTotal->setObjectName(QString::fromUtf8("labelRamTotal"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelRamTotal);

        labelRamFree = new QLabel(RAM);
        labelRamFree->setObjectName(QString::fromUtf8("labelRamFree"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelRamFree);

        labelRamAvailable = new QLabel(RAM);
        labelRamAvailable->setObjectName(QString::fromUtf8("labelRamAvailable"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelRamAvailable);

        labelRamCached = new QLabel(RAM);
        labelRamCached->setObjectName(QString::fromUtf8("labelRamCached"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelRamCached);

        tabWidget->addTab(RAM, QString());
        GPU = new QWidget();
        GPU->setObjectName(QString::fromUtf8("GPU"));
        formLayout_3 = new QFormLayout(GPU);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelGpuClockSpeed = new QLabel(GPU);
        labelGpuClockSpeed->setObjectName(QString::fromUtf8("labelGpuClockSpeed"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelGpuClockSpeed);

        labelGpuName = new QLabel(GPU);
        labelGpuName->setObjectName(QString::fromUtf8("labelGpuName"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelGpuName);

        labelGpuMemory = new QLabel(GPU);
        labelGpuMemory->setObjectName(QString::fromUtf8("labelGpuMemory"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelGpuMemory);

        tabWidget->addTab(GPU, QString());
        DISK = new QWidget();
        DISK->setObjectName(QString::fromUtf8("DISK"));
        formLayout_4 = new QFormLayout(DISK);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        labelDiskModel = new QLabel(DISK);
        labelDiskModel->setObjectName(QString::fromUtf8("labelDiskModel"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelDiskModel);

        labelDiskSpeed = new QLabel(DISK);
        labelDiskSpeed->setObjectName(QString::fromUtf8("labelDiskSpeed"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelDiskSpeed);

        labelDiskTotal = new QLabel(DISK);
        labelDiskTotal->setObjectName(QString::fromUtf8("labelDiskTotal"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelDiskTotal);

        labelDiskUsed = new QLabel(DISK);
        labelDiskUsed->setObjectName(QString::fromUtf8("labelDiskUsed"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, labelDiskUsed);

        labelDiskFree = new QLabel(DISK);
        labelDiskFree->setObjectName(QString::fromUtf8("labelDiskFree"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, labelDiskFree);

        tabWidget->addTab(DISK, QString());
        NETWORK = new QWidget();
        NETWORK->setObjectName(QString::fromUtf8("NETWORK"));
        formLayout_5 = new QFormLayout(NETWORK);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        labelNetworkSpeed = new QLabel(NETWORK);
        labelNetworkSpeed->setObjectName(QString::fromUtf8("labelNetworkSpeed"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelNetworkSpeed);

        labelNetworkIP = new QLabel(NETWORK);
        labelNetworkIP->setObjectName(QString::fromUtf8("labelNetworkIP"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, labelNetworkIP);

        labelNetworkIPv6 = new QLabel(NETWORK);
        labelNetworkIPv6->setObjectName(QString::fromUtf8("labelNetworkIPv6"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, labelNetworkIPv6);

        labelNetworkType = new QLabel(NETWORK);
        labelNetworkType->setObjectName(QString::fromUtf8("labelNetworkType"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, labelNetworkType);

        tabWidget->addTab(NETWORK, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 918, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "System Monitor", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GPU", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "RAM", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Default", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Darkmode", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Custom", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Theme:", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Custom theme:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Font color", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Font size", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Hide:", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "GPU", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "RAM", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "DISK", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "NETWORK", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(General), QCoreApplication::translate("MainWindow", "Overview", nullptr));
        labelCpuModel->setText(QCoreApplication::translate("MainWindow", "Model:", nullptr));
        labelCpuClock->setText(QCoreApplication::translate("MainWindow", "Clock Speed:", nullptr));
        labelCpuArch->setText(QCoreApplication::translate("MainWindow", "Architecture:", nullptr));
        labelCpuUsage->setText(QCoreApplication::translate("MainWindow", "CPU Usage:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CPU), QCoreApplication::translate("MainWindow", "CPU", nullptr));
        labelRamTotal->setText(QCoreApplication::translate("MainWindow", "Total Memory:", nullptr));
        labelRamFree->setText(QCoreApplication::translate("MainWindow", "Free Memory:", nullptr));
        labelRamAvailable->setText(QCoreApplication::translate("MainWindow", "Available Memory:", nullptr));
        labelRamCached->setText(QCoreApplication::translate("MainWindow", "Cached Memory:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RAM), QCoreApplication::translate("MainWindow", "RAM", nullptr));
        labelGpuClockSpeed->setText(QCoreApplication::translate("MainWindow", "GPU Clock Speed", nullptr));
        labelGpuName->setText(QCoreApplication::translate("MainWindow", "GPU Name:", nullptr));
        labelGpuMemory->setText(QCoreApplication::translate("MainWindow", "GPU Memory:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(GPU), QCoreApplication::translate("MainWindow", "GPU", nullptr));
        labelDiskModel->setText(QCoreApplication::translate("MainWindow", "Disk Model:", nullptr));
        labelDiskSpeed->setText(QCoreApplication::translate("MainWindow", "Disk Speeds:", nullptr));
        labelDiskTotal->setText(QCoreApplication::translate("MainWindow", "Total Disk Space:", nullptr));
        labelDiskUsed->setText(QCoreApplication::translate("MainWindow", "Used Disk Space:", nullptr));
        labelDiskFree->setText(QCoreApplication::translate("MainWindow", "Free Disk Space:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DISK), QCoreApplication::translate("MainWindow", "DISK", nullptr));
        labelNetworkSpeed->setText(QCoreApplication::translate("MainWindow", "Download:", nullptr));
        labelNetworkIP->setText(QCoreApplication::translate("MainWindow", "IPv4:", nullptr));
        labelNetworkIPv6->setText(QCoreApplication::translate("MainWindow", "IPv6:", nullptr));
        labelNetworkType->setText(QCoreApplication::translate("MainWindow", "Netowrk Type: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(NETWORK), QCoreApplication::translate("MainWindow", "NETWORK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

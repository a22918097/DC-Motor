/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_velocity;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_distance;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_angle;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_front;
    QPushButton *pushButton_back;
    QPushButton *pushButton_trun_right;
    QPushButton *pushButton_turn_left;
    QPushButton *pushButton_turn_one_left;
    QPushButton *pushButton_trun_one_right;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_baudrate_right;
    QComboBox *comboBox_COMport_right;
    QPushButton *pushButton_right;
    QLabel *label_4;
    QPushButton *pushButton_stop;
    QGroupBox *groupBox;
    QComboBox *comboBox_baudrate_left;
    QComboBox *comboBox_COMport_left;
    QPushButton *pushButton_left;
    QPushButton *pushButton_clearlog;
    QPushButton *pushButton_initial;
    QPushButton *pushButton_D;
    QPushButton *pushButton_R;
    QPushButton *pushButton_read;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1050);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(520, 320, 131, 311));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        doubleSpinBox_velocity = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_velocity->setObjectName(QStringLiteral("doubleSpinBox_velocity"));
        doubleSpinBox_velocity->setMinimum(-5000);
        doubleSpinBox_velocity->setMaximum(5000);
        doubleSpinBox_velocity->setValue(500);

        verticalLayout->addWidget(doubleSpinBox_velocity);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        doubleSpinBox_distance = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_distance->setObjectName(QStringLiteral("doubleSpinBox_distance"));
        doubleSpinBox_distance->setValue(2);

        verticalLayout->addWidget(doubleSpinBox_distance);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        doubleSpinBox_angle = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_angle->setObjectName(QStringLiteral("doubleSpinBox_angle"));
        doubleSpinBox_angle->setMinimum(-90);
        doubleSpinBox_angle->setMaximum(90);
        doubleSpinBox_angle->setSingleStep(0.5);

        verticalLayout->addWidget(doubleSpinBox_angle);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 330, 451, 301));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(690, 320, 421, 311));
        pushButton_front = new QPushButton(groupBox_3);
        pushButton_front->setObjectName(QStringLiteral("pushButton_front"));
        pushButton_front->setGeometry(QRect(160, 50, 101, 101));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(48);
        pushButton_front->setFont(font);
        pushButton_back = new QPushButton(groupBox_3);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(160, 190, 101, 101));
        pushButton_back->setFont(font);
        pushButton_trun_right = new QPushButton(groupBox_3);
        pushButton_trun_right->setObjectName(QStringLiteral("pushButton_trun_right"));
        pushButton_trun_right->setGeometry(QRect(310, 190, 101, 101));
        pushButton_trun_right->setFont(font);
        pushButton_turn_left = new QPushButton(groupBox_3);
        pushButton_turn_left->setObjectName(QStringLiteral("pushButton_turn_left"));
        pushButton_turn_left->setGeometry(QRect(10, 190, 101, 101));
        pushButton_turn_left->setFont(font);
        pushButton_turn_one_left = new QPushButton(groupBox_3);
        pushButton_turn_one_left->setObjectName(QStringLiteral("pushButton_turn_one_left"));
        pushButton_turn_one_left->setGeometry(QRect(10, 50, 101, 101));
        pushButton_turn_one_left->setFont(font);
        pushButton_trun_one_right = new QPushButton(groupBox_3);
        pushButton_trun_one_right->setObjectName(QStringLiteral("pushButton_trun_one_right"));
        pushButton_trun_one_right->setGeometry(QRect(310, 50, 101, 101));
        pushButton_trun_one_right->setFont(font);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 0, 310, 230));
        comboBox_baudrate_right = new QComboBox(groupBox_2);
        comboBox_baudrate_right->setObjectName(QStringLiteral("comboBox_baudrate_right"));
        comboBox_baudrate_right->setGeometry(QRect(20, 160, 110, 30));
        comboBox_COMport_right = new QComboBox(groupBox_2);
        comboBox_COMport_right->setObjectName(QStringLiteral("comboBox_COMport_right"));
        comboBox_COMport_right->setGeometry(QRect(20, 60, 110, 30));
        pushButton_right = new QPushButton(groupBox_2);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));
        pushButton_right->setGeometry(QRect(190, 100, 101, 51));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 302, 131, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(16);
        label_4->setFont(font1);
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(980, 160, 131, 131));
        pushButton_stop->setFont(font);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 310, 230));
        comboBox_baudrate_left = new QComboBox(groupBox);
        comboBox_baudrate_left->setObjectName(QStringLiteral("comboBox_baudrate_left"));
        comboBox_baudrate_left->setGeometry(QRect(20, 160, 110, 30));
        comboBox_COMport_left = new QComboBox(groupBox);
        comboBox_COMport_left->setObjectName(QStringLiteral("comboBox_COMport_left"));
        comboBox_COMport_left->setGeometry(QRect(20, 60, 110, 30));
        pushButton_left = new QPushButton(groupBox);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));
        pushButton_left->setGeometry(QRect(180, 100, 101, 51));
        pushButton_clearlog = new QPushButton(centralWidget);
        pushButton_clearlog->setObjectName(QStringLiteral("pushButton_clearlog"));
        pushButton_clearlog->setGeometry(QRect(330, 290, 131, 31));
        pushButton_initial = new QPushButton(centralWidget);
        pushButton_initial->setObjectName(QStringLiteral("pushButton_initial"));
        pushButton_initial->setGeometry(QRect(690, 180, 231, 101));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(48);
        pushButton_initial->setFont(font2);
        pushButton_D = new QPushButton(centralWidget);
        pushButton_D->setObjectName(QStringLiteral("pushButton_D"));
        pushButton_D->setGeometry(QRect(980, 0, 131, 131));
        pushButton_D->setFont(font);
        pushButton_R = new QPushButton(centralWidget);
        pushButton_R->setObjectName(QStringLiteral("pushButton_R"));
        pushButton_R->setGeometry(QRect(790, 0, 131, 131));
        pushButton_R->setFont(font);
        pushButton_read = new QPushButton(centralWidget);
        pushButton_read->setObjectName(QStringLiteral("pushButton_read"));
        pushButton_read->setGeometry(QRect(680, 30, 91, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Algerian"));
        font3.setPointSize(16);
        pushButton_read->setFont(font3);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 240, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox_baudrate_right->setCurrentIndex(3);
        comboBox_COMport_right->setCurrentIndex(3);
        comboBox_baudrate_left->setCurrentIndex(3);
        comboBox_COMport_left->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Setting", 0));
        label->setText(QApplication::translate("MainWindow", "Velocity(rpm):", 0));
        label_2->setText(QApplication::translate("MainWindow", "Distance(m):", 0));
        label_3->setText(QApplication::translate("MainWindow", "Angle(degree):", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Direction", 0));
        pushButton_front->setText(QApplication::translate("MainWindow", "\342\206\221", 0));
        pushButton_front->setShortcut(QApplication::translate("MainWindow", "Up", 0));
        pushButton_back->setText(QApplication::translate("MainWindow", "\342\206\223", 0));
        pushButton_back->setShortcut(QApplication::translate("MainWindow", "Down", 0));
        pushButton_trun_right->setText(QApplication::translate("MainWindow", "\342\206\222", 0));
        pushButton_trun_right->setShortcut(QApplication::translate("MainWindow", "Right", 0));
        pushButton_turn_left->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        pushButton_turn_left->setShortcut(QApplication::translate("MainWindow", "Left", 0));
        pushButton_turn_one_left->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        pushButton_turn_one_left->setShortcut(QApplication::translate("MainWindow", "Ctrl+Left", 0));
        pushButton_trun_one_right->setText(QApplication::translate("MainWindow", "\342\206\222", 0));
        pushButton_trun_one_right->setShortcut(QApplication::translate("MainWindow", "Ctrl+Right", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Right DC Motor", 0));
        comboBox_baudrate_right->clear();
        comboBox_baudrate_right->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "115200", 0)
        );
        comboBox_COMport_right->clear();
        comboBox_COMport_right->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "COM1", 0)
         << QApplication::translate("MainWindow", "COM2", 0)
         << QApplication::translate("MainWindow", "COM3", 0)
         << QApplication::translate("MainWindow", "COM4", 0)
         << QApplication::translate("MainWindow", "COM5", 0)
         << QApplication::translate("MainWindow", "COM6", 0)
         << QApplication::translate("MainWindow", "COM7", 0)
         << QApplication::translate("MainWindow", "COM8", 0)
         << QApplication::translate("MainWindow", "COM9", 0)
         << QApplication::translate("MainWindow", "COM10", 0)
         << QApplication::translate("MainWindow", "COM11", 0)
         << QApplication::translate("MainWindow", "COM12", 0)
        );
        pushButton_right->setText(QApplication::translate("MainWindow", "OPEN", 0));
        label_4->setText(QApplication::translate("MainWindow", "log", 0));
        pushButton_stop->setText(QApplication::translate("MainWindow", "\342\226\240", 0));
        pushButton_stop->setShortcut(QApplication::translate("MainWindow", "S, Esc", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Left DC Motor", 0));
        comboBox_baudrate_left->clear();
        comboBox_baudrate_left->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "115200", 0)
        );
        comboBox_COMport_left->clear();
        comboBox_COMport_left->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "COM1", 0)
         << QApplication::translate("MainWindow", "COM2", 0)
         << QApplication::translate("MainWindow", "COM3", 0)
         << QApplication::translate("MainWindow", "COM4", 0)
         << QApplication::translate("MainWindow", "COM5", 0)
         << QApplication::translate("MainWindow", "COM6", 0)
         << QApplication::translate("MainWindow", "COM7", 0)
         << QApplication::translate("MainWindow", "COM8", 0)
         << QApplication::translate("MainWindow", "COM9", 0)
         << QApplication::translate("MainWindow", "COM10", 0)
         << QApplication::translate("MainWindow", "COM11", 0)
         << QApplication::translate("MainWindow", "COM12", 0)
        );
        pushButton_left->setText(QApplication::translate("MainWindow", "OPEN", 0));
        pushButton_clearlog->setText(QApplication::translate("MainWindow", "Clear Log", 0));
        pushButton_initial->setText(QApplication::translate("MainWindow", "Initial", 0));
        pushButton_D->setText(QApplication::translate("MainWindow", "D", 0));
        pushButton_D->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        pushButton_R->setText(QApplication::translate("MainWindow", "R", 0));
        pushButton_R->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        pushButton_read->setText(QApplication::translate("MainWindow", "Read", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

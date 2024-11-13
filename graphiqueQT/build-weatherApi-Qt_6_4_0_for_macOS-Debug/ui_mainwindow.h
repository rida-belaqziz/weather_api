/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_titre;
    QLabel *label_ville;
    QComboBox *comboBox_ville;
    QLabel *label_source;
    QPushButton *pushButton_valider;
    QLCDNumber *lcdNumber_temp;
    QLCDNumber *lcdNumber_vent;
    QLCDNumber *lcdNumber_hum;
    QLabel *label_temp;
    QLabel *label_vent;
    QLabel *label_hum;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_titre = new QLabel(centralwidget);
        label_titre->setObjectName("label_titre");
        label_titre->setGeometry(QRect(330, 0, 201, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_titre->sizePolicy().hasHeightForWidth());
        label_titre->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        label_titre->setFont(font);
        label_ville = new QLabel(centralwidget);
        label_ville->setObjectName("label_ville");
        label_ville->setGeometry(QRect(70, 140, 171, 16));
        comboBox_ville = new QComboBox(centralwidget);
        comboBox_ville->setObjectName("comboBox_ville");
        comboBox_ville->setGeometry(QRect(230, 130, 221, 32));
        label_source = new QLabel(centralwidget);
        label_source->setObjectName("label_source");
        label_source->setGeometry(QRect(590, 520, 151, 16));
        pushButton_valider = new QPushButton(centralwidget);
        pushButton_valider->setObjectName("pushButton_valider");
        pushButton_valider->setGeometry(QRect(480, 130, 100, 32));
        lcdNumber_temp = new QLCDNumber(centralwidget);
        lcdNumber_temp->setObjectName("lcdNumber_temp");
        lcdNumber_temp->setGeometry(QRect(280, 250, 121, 31));
        lcdNumber_vent = new QLCDNumber(centralwidget);
        lcdNumber_vent->setObjectName("lcdNumber_vent");
        lcdNumber_vent->setGeometry(QRect(280, 310, 121, 31));
        lcdNumber_hum = new QLCDNumber(centralwidget);
        lcdNumber_hum->setObjectName("lcdNumber_hum");
        lcdNumber_hum->setGeometry(QRect(280, 370, 121, 31));
        label_temp = new QLabel(centralwidget);
        label_temp->setObjectName("label_temp");
        label_temp->setGeometry(QRect(120, 260, 101, 16));
        label_vent = new QLabel(centralwidget);
        label_vent->setObjectName("label_vent");
        label_vent->setGeometry(QRect(120, 320, 58, 16));
        label_hum = new QLabel(centralwidget);
        label_hum->setObjectName("label_hum");
        label_hum->setGeometry(QRect(120, 380, 91, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_titre->setText(QCoreApplication::translate("MainWindow", ":::::::::::: METEO ::::::::::::", nullptr));
        label_ville->setText(QCoreApplication::translate("MainWindow", "Selectioner une ville : ", nullptr));
        label_source->setText(QCoreApplication::translate("MainWindow", "Source: Openweather", nullptr));
        pushButton_valider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        label_temp->setText(QCoreApplication::translate("MainWindow", "Temperature: ", nullptr));
        label_vent->setText(QCoreApplication::translate("MainWindow", "Vent :", nullptr));
        label_hum->setText(QCoreApplication::translate("MainWindow", "Humidit\303\251:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

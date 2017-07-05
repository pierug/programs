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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *connGroupBox;
    QGridLayout *gridLayout;
    QComboBox *comboDriver;
    QLabel *textLabel4;
    QLabel *textLabel2;
    QLineEdit *editDatabase;
    QSpinBox *portSpinBox;
    QLabel *textLabel3;
    QLineEdit *editPassword;
    QLineEdit *editUsername;
    QLineEdit *editHostname1;
    QLabel *textLabel5;
    QLabel *textLabel5_2;
    QLabel *textLabel4_2;
    QWidget *layoutWidget;
    QHBoxLayout *_2;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(604, 749);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow#MainWindow{\n"
"	background: white;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        connGroupBox = new QGroupBox(centralWidget);
        connGroupBox->setObjectName(QStringLiteral("connGroupBox"));
        connGroupBox->setGeometry(QRect(40, 50, 521, 541));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(16);
        connGroupBox->setFont(font);
        connGroupBox->setStyleSheet(QLatin1String("QGroupBox#connGroupBox{\n"
"	background: white;\n"
"border: black;\n"
"}"));
        gridLayout = new QGridLayout(connGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(8, 8, 8, 8);
        comboDriver = new QComboBox(connGroupBox);
        comboDriver->setObjectName(QStringLiteral("comboDriver"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        comboDriver->setFont(font1);
        comboDriver->setStyleSheet(QLatin1String("QComboBox#comboDriver{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));
        comboDriver->setInsertPolicy(QComboBox::InsertBeforeCurrent);
        comboDriver->setFrame(true);

        gridLayout->addWidget(comboDriver, 0, 1, 1, 1);

        textLabel4 = new QLabel(connGroupBox);
        textLabel4->setObjectName(QStringLiteral("textLabel4"));
        textLabel4->setFont(font1);

        gridLayout->addWidget(textLabel4, 2, 0, 1, 1);

        textLabel2 = new QLabel(connGroupBox);
        textLabel2->setObjectName(QStringLiteral("textLabel2"));
        textLabel2->setFont(font1);

        gridLayout->addWidget(textLabel2, 0, 0, 1, 1);

        editDatabase = new QLineEdit(connGroupBox);
        editDatabase->setObjectName(QStringLiteral("editDatabase"));
        editDatabase->setFont(font1);
        editDatabase->setStyleSheet(QLatin1String("QLineEdit#editDatabase{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));

        gridLayout->addWidget(editDatabase, 1, 1, 1, 1);

        portSpinBox = new QSpinBox(connGroupBox);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setFont(font1);
        portSpinBox->setStyleSheet(QLatin1String("QSpinBox#portSpinBox{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));
        portSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        portSpinBox->setMinimum(-1);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(-1);

        gridLayout->addWidget(portSpinBox, 5, 1, 1, 1);

        textLabel3 = new QLabel(connGroupBox);
        textLabel3->setObjectName(QStringLiteral("textLabel3"));
        textLabel3->setFont(font1);

        gridLayout->addWidget(textLabel3, 1, 0, 1, 1);

        editPassword = new QLineEdit(connGroupBox);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        editPassword->setFont(font1);
        editPassword->setStyleSheet(QLatin1String("QLineEdit#editPassword{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));
        editPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editPassword, 3, 1, 1, 1);

        editUsername = new QLineEdit(connGroupBox);
        editUsername->setObjectName(QStringLiteral("editUsername"));
        editUsername->setFont(font1);
        editUsername->setStyleSheet(QLatin1String("QLineEdit#editUsername{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));

        gridLayout->addWidget(editUsername, 2, 1, 1, 1);

        editHostname1 = new QLineEdit(connGroupBox);
        editHostname1->setObjectName(QStringLiteral("editHostname1"));
        editHostname1->setFont(font1);
        editHostname1->setStyleSheet(QLatin1String("QLineEdit#editHostname{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));

        gridLayout->addWidget(editHostname1, 4, 1, 1, 1);

        textLabel5 = new QLabel(connGroupBox);
        textLabel5->setObjectName(QStringLiteral("textLabel5"));
        textLabel5->setFont(font1);

        gridLayout->addWidget(textLabel5, 4, 0, 1, 1);

        textLabel5_2 = new QLabel(connGroupBox);
        textLabel5_2->setObjectName(QStringLiteral("textLabel5_2"));
        textLabel5_2->setFont(font1);

        gridLayout->addWidget(textLabel5_2, 5, 0, 1, 1);

        textLabel4_2 = new QLabel(connGroupBox);
        textLabel4_2->setObjectName(QStringLiteral("textLabel4_2"));
        textLabel4_2->setFont(font1);

        gridLayout->addWidget(textLabel4_2, 3, 0, 1, 1);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(23, 630, 561, 51));
        layoutWidget->setFont(font1);
        _2 = new QHBoxLayout(layoutWidget);
        _2->setSpacing(6);
        _2->setContentsMargins(11, 11, 11, 11);
        _2->setObjectName(QStringLiteral("_2"));
        _2->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setFont(font1);
        okButton->setAutoFillBackground(false);
        okButton->setStyleSheet(QLatin1String("QPushButton#okButton {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"    padding: 6px;\n"
"\n"
"}\n"
"\n"
"QPushButton#okButton:pressed {\n"
"    background-color:rgb(200, 200, 200);\n"
"    border-style: inset;\n"
"}"));

        _2->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font1);
        cancelButton->setStyleSheet(QLatin1String("QPushButton#cancelButton {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"  padding: 6px;\n"
"\n"
"}\n"
"\n"
"QPushButton#cancelButton:pressed {\n"
"    background-color:rgb(200, 200, 200);\n"
"    border-style: inset;\n"
"}"));

        _2->addWidget(cancelButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 604, 20));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        textLabel4->setBuddy(editUsername);
        textLabel2->setBuddy(comboDriver);
        textLabel3->setBuddy(editDatabase);
        textLabel5->setBuddy(editHostname1);
        textLabel5_2->setBuddy(portSpinBox);
        textLabel4_2->setBuddy(editPassword);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EasyHospital", 0));
        connGroupBox->setTitle(QApplication::translate("MainWindow", "Connection settings", 0));
        textLabel4->setText(QApplication::translate("MainWindow", "Username:", 0));
        textLabel2->setText(QApplication::translate("MainWindow", "Driver", 0));
        portSpinBox->setSpecialValueText(QApplication::translate("MainWindow", "Default", 0));
        textLabel3->setText(QApplication::translate("MainWindow", "Database Name:", 0));
        textLabel5->setText(QApplication::translate("MainWindow", "Hostname:", 0));
        textLabel5_2->setText(QApplication::translate("MainWindow", "Port:", 0));
        textLabel4_2->setText(QApplication::translate("MainWindow", "Password:", 0));
        okButton->setText(QApplication::translate("MainWindow", "&OK", 0));
        cancelButton->setText(QApplication::translate("MainWindow", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

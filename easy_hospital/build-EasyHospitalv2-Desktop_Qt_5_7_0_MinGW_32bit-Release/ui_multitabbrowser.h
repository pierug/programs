/********************************************************************************
** Form generated from reading UI file 'multitabbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTITABBROWSER_H
#define UI_MULTITABBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiTabBrowser
{
public:
    QWidget *call;
    QWidget *controlPump;
    QLabel *label;
    QLineEdit *substanceEdit;
    QLineEdit *velocityEdit;
    QLineEdit *timeEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTableWidget *controlTable;
    QWidget *pateintTemperature;

    void setupUi(QTabWidget *multiTabBrowser)
    {
        if (multiTabBrowser->objectName().isEmpty())
            multiTabBrowser->setObjectName(QStringLiteral("multiTabBrowser"));
        multiTabBrowser->resize(800, 800);
        multiTabBrowser->setStyleSheet(QLatin1String("QTabWidget#multiTabBrowser {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"  padding: 6px;\n"
"\n"
"}\n"
""));
        call = new QWidget();
        call->setObjectName(QStringLiteral("call"));
        multiTabBrowser->addTab(call, QString());
        controlPump = new QWidget();
        controlPump->setObjectName(QStringLiteral("controlPump"));
        label = new QLabel(controlPump);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 0, 200, 200));
        label->setPixmap(QPixmap(QString::fromUtf8("../symbols/syringe.png")));
        substanceEdit = new QLineEdit(controlPump);
        substanceEdit->setObjectName(QStringLiteral("substanceEdit"));
        substanceEdit->setGeometry(QRect(600, 240, 200, 40));
        substanceEdit->setStyleSheet(QLatin1String("QLineEdit#substanceEdit{\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"  padding: 6px;\n"
"\n"
"}"));
        velocityEdit = new QLineEdit(controlPump);
        velocityEdit->setObjectName(QStringLiteral("velocityEdit"));
        velocityEdit->setGeometry(QRect(600, 300, 200, 40));
        velocityEdit->setStyleSheet(QLatin1String("QLineEdit#velocityEdit {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"  padding: 6px;\n"
"\n"
"}"));
        timeEdit = new QLineEdit(controlPump);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(600, 360, 200, 40));
        timeEdit->setStyleSheet(QLatin1String("QLineEdit#timeEdit {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"  padding: 6px;\n"
"\n"
"}"));
        label_2 = new QLabel(controlPump);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 220, 61, 16));
        label_3 = new QLabel(controlPump);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(600, 280, 61, 16));
        label_4 = new QLabel(controlPump);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(600, 340, 61, 16));
        okButton = new QPushButton(controlPump);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(600, 440, 200, 40));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        okButton->setFont(font);
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
        cancelButton = new QPushButton(controlPump);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(600, 520, 200, 40));
        cancelButton->setFont(font);
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
        controlTable = new QTableWidget(controlPump);
        controlTable->setObjectName(QStringLiteral("controlTable"));
        controlTable->setGeometry(QRect(0, 0, 600, 400));
        controlTable->setStyleSheet(QLatin1String("QTableWidgetn#controlTable {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"    font color: white;\n"
"    min-width:5em;\n"
"  padding: 6px;\n"
"\n"
"}\n"
""));
        multiTabBrowser->addTab(controlPump, QString());
        pateintTemperature = new QWidget();
        pateintTemperature->setObjectName(QStringLiteral("pateintTemperature"));
        multiTabBrowser->addTab(pateintTemperature, QString());

        retranslateUi(multiTabBrowser);

        multiTabBrowser->setCurrentIndex(1);
        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(multiTabBrowser);
    } // setupUi

    void retranslateUi(QTabWidget *multiTabBrowser)
    {
        multiTabBrowser->setWindowTitle(QApplication::translate("multiTabBrowser", "MultiBrowser", 0));
        multiTabBrowser->setTabText(multiTabBrowser->indexOf(call), QApplication::translate("multiTabBrowser", "Call", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("multiTabBrowser", "Substance:", 0));
        label_3->setText(QApplication::translate("multiTabBrowser", "Velocity:", 0));
        label_4->setText(QApplication::translate("multiTabBrowser", "When:", 0));
        okButton->setText(QApplication::translate("multiTabBrowser", "&OK", 0));
        cancelButton->setText(QApplication::translate("multiTabBrowser", "&Cancel", 0));
        multiTabBrowser->setTabText(multiTabBrowser->indexOf(controlPump), QApplication::translate("multiTabBrowser", "Control Pump", 0));
        multiTabBrowser->setTabText(multiTabBrowser->indexOf(pateintTemperature), QApplication::translate("multiTabBrowser", "Patient Temperature", 0));
    } // retranslateUi

};

namespace Ui {
    class multiTabBrowser: public Ui_multiTabBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTITABBROWSER_H

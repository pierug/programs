/********************************************************************************
** Form generated from reading UI file 'multibrowserpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIBROWSERPATIENT_H
#define UI_MULTIBROWSERPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiBrowser
{
public:
    QWidget *controlPump;
    QPushButton *pushButton;
    QWidget *calls;
    QWidget *patientTemperature;

    void setupUi(QTabWidget *MultiBrowser)
    {
        if (MultiBrowser->objectName().isEmpty())
            MultiBrowser->setObjectName(QStringLiteral("MultiBrowser"));
        MultiBrowser->resize(900, 900);
        controlPump = new QWidget();
        controlPump->setObjectName(QStringLiteral("controlPump"));
        pushButton = new QPushButton(controlPump);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 230, 80, 21));
        MultiBrowser->addTab(controlPump, QString());
        calls = new QWidget();
        calls->setObjectName(QStringLiteral("calls"));
        MultiBrowser->addTab(calls, QString());
        patientTemperature = new QWidget();
        patientTemperature->setObjectName(QStringLiteral("patientTemperature"));
        patientTemperature->setEnabled(true);
        MultiBrowser->addTab(patientTemperature, QString());

        retranslateUi(MultiBrowser);

        MultiBrowser->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MultiBrowser);
    } // setupUi

    void retranslateUi(QTabWidget *MultiBrowser)
    {
        MultiBrowser->setWindowTitle(QApplication::translate("MultiBrowser", "TabWidget", 0));
        pushButton->setText(QApplication::translate("MultiBrowser", "PushButton", 0));
        MultiBrowser->setTabText(MultiBrowser->indexOf(controlPump), QApplication::translate("MultiBrowser", "Control Pump", 0));
        MultiBrowser->setTabText(MultiBrowser->indexOf(calls), QApplication::translate("MultiBrowser", "Calls", 0));
        MultiBrowser->setTabText(MultiBrowser->indexOf(patientTemperature), QApplication::translate("MultiBrowser", "Patient Temperature", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiBrowser: public Ui_MultiBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIBROWSERPATIENT_H

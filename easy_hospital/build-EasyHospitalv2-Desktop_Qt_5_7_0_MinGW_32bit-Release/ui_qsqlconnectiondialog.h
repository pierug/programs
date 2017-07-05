/********************************************************************************
** Form generated from reading UI file 'qsqlconnectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSQLCONNECTIONDIALOG_H
#define UI_QSQLCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_QSqlConnectionDialog
{
public:
    QGroupBox *connGroupBox;
    QGridLayout *gridLayout;
    QLabel *textLabel4_2;
    QLineEdit *editPassword;
    QSpinBox *portSpinBox;
    QLineEdit *editUsername;
    QLabel *textLabel3;
    QLabel *textLabel5;
    QLineEdit *editHostname;
    QLabel *textLabel5_2;
    QComboBox *comboDriver;
    QLabel *textLabel4;
    QLabel *textLabel2;
    QLineEdit *editDatabase;
    QLabel *label;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QCheckBox *dbCheckBox;

    void setupUi(QDialog *QSqlConnectionDialog)
    {
        if (QSqlConnectionDialog->objectName().isEmpty())
            QSqlConnectionDialog->setObjectName(QStringLiteral("QSqlConnectionDialog"));
        QSqlConnectionDialog->setEnabled(true);
        QSqlConnectionDialog->resize(600, 550);
        QSqlConnectionDialog->setStyleSheet(QLatin1String("QDialog#QSqlConnectionDialog{\n"
"	background: white;\n"
"}"));
        connGroupBox = new QGroupBox(QSqlConnectionDialog);
        connGroupBox->setObjectName(QStringLiteral("connGroupBox"));
        connGroupBox->setGeometry(QRect(0, 0, 390, 590));
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
        textLabel4_2 = new QLabel(connGroupBox);
        textLabel4_2->setObjectName(QStringLiteral("textLabel4_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        textLabel4_2->setFont(font1);

        gridLayout->addWidget(textLabel4_2, 3, 0, 1, 1);

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

        textLabel3 = new QLabel(connGroupBox);
        textLabel3->setObjectName(QStringLiteral("textLabel3"));
        textLabel3->setFont(font1);

        gridLayout->addWidget(textLabel3, 1, 0, 1, 1);

        textLabel5 = new QLabel(connGroupBox);
        textLabel5->setObjectName(QStringLiteral("textLabel5"));
        textLabel5->setFont(font1);

        gridLayout->addWidget(textLabel5, 4, 0, 1, 1);

        editHostname = new QLineEdit(connGroupBox);
        editHostname->setObjectName(QStringLiteral("editHostname"));
        editHostname->setFont(font1);
        editHostname->setStyleSheet(QLatin1String("QLineEdit#editHostname{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));

        gridLayout->addWidget(editHostname, 4, 1, 1, 1);

        textLabel5_2 = new QLabel(connGroupBox);
        textLabel5_2->setObjectName(QStringLiteral("textLabel5_2"));
        textLabel5_2->setFont(font1);

        gridLayout->addWidget(textLabel5_2, 5, 0, 1, 1);

        comboDriver = new QComboBox(connGroupBox);
        comboDriver->setObjectName(QStringLiteral("comboDriver"));
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

        label = new QLabel(QSqlConnectionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 0, 200, 200));
        label->setPixmap(QPixmap(QString::fromUtf8("../symbols/db.png")));
        okButton = new QPushButton(QSqlConnectionDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(395, 270, 200, 40));
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
        cancelButton = new QPushButton(QSqlConnectionDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(395, 330, 200, 40));
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
        dbCheckBox = new QCheckBox(QSqlConnectionDialog);
        dbCheckBox->setObjectName(QStringLiteral("dbCheckBox"));
        dbCheckBox->setGeometry(QRect(395, 390, 200, 40));
        dbCheckBox->setStyleSheet(QLatin1String("QCheckBox#dbCheckBox {\n"
"    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"\n"
"\n"
"}"));
#ifndef QT_NO_SHORTCUT
        textLabel4_2->setBuddy(editPassword);
        textLabel3->setBuddy(editDatabase);
        textLabel5->setBuddy(editHostname);
        textLabel5_2->setBuddy(portSpinBox);
        textLabel4->setBuddy(editUsername);
        textLabel2->setBuddy(comboDriver);
#endif // QT_NO_SHORTCUT

        retranslateUi(QSqlConnectionDialog);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(QSqlConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *QSqlConnectionDialog)
    {
        QSqlConnectionDialog->setWindowTitle(QApplication::translate("QSqlConnectionDialog", "QSqlConnectionDialog", 0));
        connGroupBox->setTitle(QApplication::translate("QSqlConnectionDialog", "Connection settings", 0));
        textLabel4_2->setText(QApplication::translate("QSqlConnectionDialog", "Password:", 0));
        portSpinBox->setSpecialValueText(QApplication::translate("QSqlConnectionDialog", "Default", 0));
        textLabel3->setText(QApplication::translate("QSqlConnectionDialog", "Database Name:", 0));
        textLabel5->setText(QApplication::translate("QSqlConnectionDialog", "Hostname:", 0));
        textLabel5_2->setText(QApplication::translate("QSqlConnectionDialog", "Port:", 0));
        textLabel4->setText(QApplication::translate("QSqlConnectionDialog", "Username:", 0));
        textLabel2->setText(QApplication::translate("QSqlConnectionDialog", "Driver", 0));
        label->setText(QString());
        okButton->setText(QApplication::translate("QSqlConnectionDialog", "&OK", 0));
        cancelButton->setText(QApplication::translate("QSqlConnectionDialog", "&Cancel", 0));
        dbCheckBox->setText(QApplication::translate("QSqlConnectionDialog", "Us&e predefined in-memory database", 0));
    } // retranslateUi

};

namespace Ui {
    class QSqlConnectionDialog: public Ui_QSqlConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSQLCONNECTIONDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'patientbrowse.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTBROWSE_H
#define UI_PATIENTBROWSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "connectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QTableView *table;
    ConnectionWidget *connectionWidget;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    QTextEdit *sqlEdit;
    QLabel *label;
    QPushButton *submitButton;
    QPushButton *clearButton;

    void setupUi(QWidget *Browser)
    {
        if (Browser->objectName().isEmpty())
            Browser->setObjectName(QStringLiteral("Browser"));
        Browser->resize(700, 800);
        Browser->setStyleSheet(QLatin1String("QWidget#Browser{\n"
"	background: white;\n"
"}"));
        table = new QTableView(Browser);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(0, 0, 500, 530));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy);
        table->setContextMenuPolicy(Qt::ActionsContextMenu);
        table->setStyleSheet(QLatin1String("QTableView#table{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        connectionWidget = new ConnectionWidget(Browser);
        connectionWidget->setObjectName(QStringLiteral("connectionWidget"));
        connectionWidget->setGeometry(QRect(500, 200, 200, 330));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectionWidget->sizePolicy().hasHeightForWidth());
        connectionWidget->setSizePolicy(sizePolicy1);
        connectionWidget->setStyleSheet(QLatin1String("ConnectionWidget#connectionWidget{\n"
"	background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}\n"
""));
        groupBox = new QGroupBox(Browser);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-4, 547, 701, 180));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMaximumSize(QSize(16777215, 180));
        vboxLayout = new QVBoxLayout(groupBox);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(9, 9, 9, 9);
        sqlEdit = new QTextEdit(groupBox);
        sqlEdit->setObjectName(QStringLiteral("sqlEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sqlEdit->sizePolicy().hasHeightForWidth());
        sqlEdit->setSizePolicy(sizePolicy3);
        sqlEdit->setMinimumSize(QSize(0, 18));
        sqlEdit->setBaseSize(QSize(0, 120));
        sqlEdit->setStyleSheet(QLatin1String("QTextEdit#sqlEdit{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));

        vboxLayout->addWidget(sqlEdit);

        label = new QLabel(Browser);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 0, 200, 200));
        label->setPixmap(QPixmap(QString::fromUtf8("../symbols/PATIENT.png")));
        submitButton = new QPushButton(Browser);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(260, 750, 200, 40));
        submitButton->setStyleSheet(QLatin1String("QPushButton#submitButton {\n"
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
        clearButton = new QPushButton(Browser);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(480, 750, 200, 40));
        clearButton->setStyleSheet(QLatin1String("QPushButton#clearButton {\n"
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

        retranslateUi(Browser);

        QMetaObject::connectSlotsByName(Browser);
    } // setupUi

    void retranslateUi(QWidget *Browser)
    {
        Browser->setWindowTitle(QApplication::translate("Browser", "Patient Browser", 0));
        groupBox->setTitle(QApplication::translate("Browser", "SQL Query", 0));
        label->setText(QString());
        submitButton->setText(QApplication::translate("Browser", "&Submit", 0));
        clearButton->setText(QApplication::translate("Browser", "&Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class Browser: public Ui_Browser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTBROWSE_H

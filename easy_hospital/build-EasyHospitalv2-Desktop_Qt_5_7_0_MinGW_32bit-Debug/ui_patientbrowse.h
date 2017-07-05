/********************************************************************************
** Form generated from reading UI file 'patientbrowse.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTBROWSE_H
#define UI_PATIENTBROWSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "connectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QAction *insertRowAction;
    QAction *deleteRowAction;
    QAction *fieldStrategyAction;
    QAction *rowStrategyAction;
    QAction *manualStrategyAction;
    QAction *submitAction;
    QAction *revertAction;
    QAction *selectAction;

    QTableView *table;
    ConnectionWidget *connectionWidget;
    QLabel *label;
    QPushButton *submitButton;
    QPushButton *clearButton;
    QTextEdit *sqlEdit;
    QListView *patientsList;

    void setupUi(QWidget *Browser)
    {
        if (Browser->objectName().isEmpty())
            Browser->setObjectName(QStringLiteral("Browser"));
        Browser->resize(700, 800);
        Browser->setStyleSheet(QLatin1String("QWidget#Browser{\n"
"	background: white;\n"
"}"));

        insertRowAction = new QAction(Browser);
        insertRowAction->setObjectName(QStringLiteral("insertRowAction"));
        insertRowAction->setEnabled(false);
        deleteRowAction = new QAction(Browser);
        deleteRowAction->setObjectName(QStringLiteral("deleteRowAction"));
        deleteRowAction->setEnabled(false);
        fieldStrategyAction = new QAction(Browser);
        fieldStrategyAction->setObjectName(QStringLiteral("fieldStrategyAction"));
        fieldStrategyAction->setCheckable(true);
        rowStrategyAction = new QAction(Browser);
        rowStrategyAction->setObjectName(QStringLiteral("rowStrategyAction"));
        rowStrategyAction->setCheckable(true);
        manualStrategyAction = new QAction(Browser);
        manualStrategyAction->setObjectName(QStringLiteral("manualStrategyAction"));
        manualStrategyAction->setCheckable(true);
        submitAction = new QAction(Browser);
        submitAction->setObjectName(QStringLiteral("submitAction"));
        revertAction = new QAction(Browser);
        revertAction->setObjectName(QStringLiteral("revertAction"));
        selectAction = new QAction(Browser);
        selectAction->setObjectName(QStringLiteral("selectAction"));

        table = new QTableView(Browser);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(0, 199, 701, 331));
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
        connectionWidget->setGeometry(QRect(10, 549, 681, 181));
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
        sqlEdit = new QTextEdit(Browser);
        sqlEdit->setObjectName(QStringLiteral("sqlEdit"));
        sqlEdit->setGeometry(QRect(220, 0, 281, 201));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sqlEdit->sizePolicy().hasHeightForWidth());
        sqlEdit->setSizePolicy(sizePolicy2);
        sqlEdit->setMinimumSize(QSize(0, 18));
        sqlEdit->setBaseSize(QSize(0, 120));
        sqlEdit->setStyleSheet(QLatin1String("QTextEdit#sqlEdit{\n"
"	    background-color:white;\n"
"  	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-color: black;\n"
"}"));
        patientsList = new QListView(Browser);
        patientsList->setObjectName(QStringLiteral("patientsList"));
        patientsList->setGeometry(QRect(0, 0, 220, 200));

        retranslateUi(Browser);

        QMetaObject::connectSlotsByName(Browser);
    } // setupUi

    void retranslateUi(QWidget *Browser)
    {
        Browser->setWindowTitle(QApplication::translate("Browser", "Patient Browser", 0));
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

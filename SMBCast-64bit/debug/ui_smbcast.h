/********************************************************************************
** Form generated from reading UI file 'smbcast.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMBCAST_H
#define UI_SMBCAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SMBCast
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SMBCast)
    {
        if (SMBCast->objectName().isEmpty())
            SMBCast->setObjectName(QStringLiteral("SMBCast"));
        SMBCast->resize(400, 300);
        menuBar = new QMenuBar(SMBCast);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SMBCast->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SMBCast);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SMBCast->addToolBar(mainToolBar);
        centralWidget = new QWidget(SMBCast);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SMBCast->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SMBCast);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SMBCast->setStatusBar(statusBar);

        retranslateUi(SMBCast);

        QMetaObject::connectSlotsByName(SMBCast);
    } // setupUi

    void retranslateUi(QMainWindow *SMBCast)
    {
        SMBCast->setWindowTitle(QApplication::translate("SMBCast", "SMBCast", 0));
    } // retranslateUi

};

namespace Ui {
    class SMBCast: public Ui_SMBCast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMBCAST_H

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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SMBCast
{
public:
    QAction *actionManually_open_file;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SMBCast)
    {
        if (SMBCast->objectName().isEmpty())
            SMBCast->setObjectName(QStringLiteral("SMBCast"));
        SMBCast->resize(627, 480);
        actionManually_open_file = new QAction(SMBCast);
        actionManually_open_file->setObjectName(QStringLiteral("actionManually_open_file"));
        centralWidget = new QWidget(SMBCast);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        SMBCast->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SMBCast);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 25));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        SMBCast->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SMBCast);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SMBCast->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SMBCast);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SMBCast->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionManually_open_file);

        retranslateUi(SMBCast);

        QMetaObject::connectSlotsByName(SMBCast);
    } // setupUi

    void retranslateUi(QMainWindow *SMBCast)
    {
        SMBCast->setWindowTitle(QApplication::translate("SMBCast", "SMBCast", 0));
        actionManually_open_file->setText(QApplication::translate("SMBCast", "Manually open file", 0));
        menuOptions->setTitle(QApplication::translate("SMBCast", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class SMBCast: public Ui_SMBCast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMBCAST_H

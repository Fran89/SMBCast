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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SMBCast
{
public:
    QAction *actionManually_open_file;
    QAction *actionToggle_Debug;
    QAction *actionE_Mail_Settings;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SMBCast)
    {
        if (SMBCast->objectName().isEmpty())
            SMBCast->setObjectName(QStringLiteral("SMBCast"));
        SMBCast->resize(950, 482);
        actionManually_open_file = new QAction(SMBCast);
        actionManually_open_file->setObjectName(QStringLiteral("actionManually_open_file"));
        actionToggle_Debug = new QAction(SMBCast);
        actionToggle_Debug->setObjectName(QStringLiteral("actionToggle_Debug"));
        actionE_Mail_Settings = new QAction(SMBCast);
        actionE_Mail_Settings->setObjectName(QStringLiteral("actionE_Mail_Settings"));
        centralWidget = new QWidget(SMBCast);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(0, 0));
        textBrowser->setMaximumSize(QSize(16777215, 80));

        verticalLayout->addWidget(textBrowser);

        SMBCast->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SMBCast);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 25));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SMBCast->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SMBCast);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SMBCast->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SMBCast);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SMBCast->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOptions->addAction(actionE_Mail_Settings);
        menuOptions->addAction(actionManually_open_file);
        menuHelp->addAction(actionToggle_Debug);

        retranslateUi(SMBCast);

        QMetaObject::connectSlotsByName(SMBCast);
    } // setupUi

    void retranslateUi(QMainWindow *SMBCast)
    {
        SMBCast->setWindowTitle(QApplication::translate("SMBCast", "SMBCast", 0));
        actionManually_open_file->setText(QApplication::translate("SMBCast", "Manually open file", 0));
        actionToggle_Debug->setText(QApplication::translate("SMBCast", "Toggle Debug", 0));
        actionE_Mail_Settings->setText(QApplication::translate("SMBCast", "E-Mail Settings", 0));
        menuOptions->setTitle(QApplication::translate("SMBCast", "Options", 0));
        menuHelp->setTitle(QApplication::translate("SMBCast", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SMBCast: public Ui_SMBCast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMBCAST_H

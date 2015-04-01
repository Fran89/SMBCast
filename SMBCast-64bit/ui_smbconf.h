/********************************************************************************
** Form generated from reading UI file 'smbconf.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMBCONF_H
#define UI_SMBCONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SMBConf
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *EmailIS;
    QPushButton *InsEmail;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QPushButton *InsSMS;
    QLineEdit *SMSIS;
    QComboBox *CarSel;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListView *EmailList;
    QPushButton *RemoveEmail;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QListView *SMSList;
    QPushButton *RemoveSMS;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QFrame *SMBConf)
    {
        if (SMBConf->objectName().isEmpty())
            SMBConf->setObjectName(QStringLiteral("SMBConf"));
        SMBConf->resize(564, 464);
        SMBConf->setFrameShape(QFrame::StyledPanel);
        SMBConf->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(SMBConf);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SMBConf);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        EmailIS = new QLineEdit(SMBConf);
        EmailIS->setObjectName(QStringLiteral("EmailIS"));

        verticalLayout->addWidget(EmailIS);

        InsEmail = new QPushButton(SMBConf);
        InsEmail->setObjectName(QStringLiteral("InsEmail"));

        verticalLayout->addWidget(InsEmail);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        line = new QFrame(SMBConf);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(SMBConf);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        InsSMS = new QPushButton(SMBConf);
        InsSMS->setObjectName(QStringLiteral("InsSMS"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, InsSMS);

        SMSIS = new QLineEdit(SMBConf);
        SMSIS->setObjectName(QStringLiteral("SMSIS"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, SMSIS);

        CarSel = new QComboBox(SMBConf);
        CarSel->setObjectName(QStringLiteral("CarSel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, CarSel);


        verticalLayout->addLayout(formLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(SMBConf);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        EmailList = new QListView(SMBConf);
        EmailList->setObjectName(QStringLiteral("EmailList"));

        verticalLayout_2->addWidget(EmailList);

        RemoveEmail = new QPushButton(SMBConf);
        RemoveEmail->setObjectName(QStringLiteral("RemoveEmail"));

        verticalLayout_2->addWidget(RemoveEmail);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(SMBConf);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        SMSList = new QListView(SMBConf);
        SMSList->setObjectName(QStringLiteral("SMSList"));

        verticalLayout_3->addWidget(SMSList);

        RemoveSMS = new QPushButton(SMBConf);
        RemoveSMS->setObjectName(QStringLiteral("RemoveSMS"));

        verticalLayout_3->addWidget(RemoveSMS);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(SMBConf);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(SMBConf);

        QMetaObject::connectSlotsByName(SMBConf);
    } // setupUi

    void retranslateUi(QFrame *SMBConf)
    {
        SMBConf->setWindowTitle(QApplication::translate("SMBConf", "Frame", 0));
        label->setText(QApplication::translate("SMBConf", "E-Mail Addresses", 0));
        InsEmail->setText(QApplication::translate("SMBConf", "Insert", 0));
        label_2->setText(QApplication::translate("SMBConf", "SMS Phone Number", 0));
        InsSMS->setText(QApplication::translate("SMBConf", "Insert", 0));
        label_3->setText(QApplication::translate("SMBConf", "Subscribed Emails", 0));
        RemoveEmail->setText(QApplication::translate("SMBConf", "Remove", 0));
        label_4->setText(QApplication::translate("SMBConf", "Subscribed SMS", 0));
        RemoveSMS->setText(QApplication::translate("SMBConf", "Remove", 0));
        pushButton->setText(QApplication::translate("SMBConf", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class SMBConf: public Ui_SMBConf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMBCONF_H

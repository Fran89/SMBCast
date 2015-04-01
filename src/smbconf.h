#ifndef SMBCONF_H
#define SMBCONF_H

#include <QFrame>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QCloseEvent>
#include <QStringListModel>

class Carriers {
public:
    Carriers();
    void addCarrier(QString Line);
    qint32 size();
    QString getDomain(QString Nam);
    QString getName(qint32 Idx);

private:
    QList<QString> Name;
    QList<QString> Value;
};

namespace Ui {
class SMBConf;
}

class SMBConf : public QFrame
{
    Q_OBJECT

public:
    explicit SMBConf(QWidget *parent = 0);
    void setCarriers(QFile *Car);
    void ReadFiles();
    ~SMBConf();

private slots:
    void on_InsSMS_clicked();

    void on_InsEmail_clicked();

    void on_RemoveEmail_clicked();

    void on_RemoveSMS_clicked();

    void on_pushButton_clicked();

private:
    QFile EmaF;
    QFile SMSF;
    Carriers ListCar;
    QStringList Emails;
    QStringList SMS;
    QStringListModel EmailsMod;
    QStringListModel SMSMod;
    Ui::SMBConf *ui;
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void WriteFiles();
    void setEmail();
    void setSMS();
};

#endif // SMBCONF_H

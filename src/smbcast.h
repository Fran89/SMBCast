#ifndef SMBCAST_H
#define SMBCAST_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDomDocument>
#include <QMessageBox>
#include <QTextTable>
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <tclap/CmdLine.h>
#include <smclass.h>
#include <smbconf.h>

namespace Ui {
class SMBCast;
}

class SMBCast : public QMainWindow
{
    Q_OBJECT
    bool Debug;
    SMClass Stas;

public:
    explicit SMBCast(QWidget *parent = 0);
    void parse_shakemapSend(QString fileName);
    void setEvtID(int ID);
    ~SMBCast();

private slots:
    void on_actionManually_open_file_triggered();

    void on_actionToggle_Debug_triggered();

    void on_actionE_Mail_Settings_triggered();

    void on_SendEmail_clicked();

private:
    Ui::SMBCast *ui;
    void parse_shakemap(QString fileName);
    void DrawTableSend();
    void SendEmail();
    void DrawTable();
    SMBConf Config;
    QFile Email;
    QFile SMS;
    QFile Carrier;
    int EvtID;
};

#endif // SMBCAST_H

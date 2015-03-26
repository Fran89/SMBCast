#ifndef SMBCAST_H
#define SMBCAST_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDomDocument>
#include <QTextTable>
#include <QDir>
#include <smclass.h>

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
    ~SMBCast();

private slots:
    void on_actionManually_open_file_triggered();

    void on_actionToggle_Debug_triggered();

private:
    Ui::SMBCast *ui;
    void parse_shakemap(QString fileName);
    void DrawTable();
};

#endif // SMBCAST_H

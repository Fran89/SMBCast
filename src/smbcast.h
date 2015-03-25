#ifndef SMBCAST_H
#define SMBCAST_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class SMBCast;
}

class SMBCast : public QMainWindow
{
    Q_OBJECT
    bool Debug;

public:
    explicit SMBCast(QWidget *parent = 0);
    ~SMBCast();

private slots:
    void on_actionManually_open_file_triggered();

private:
    Ui::SMBCast *ui;
};

#endif // SMBCAST_H

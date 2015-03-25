#ifndef SMBCAST_H
#define SMBCAST_H

#include <QMainWindow>

namespace Ui {
class SMBCast;
}

class SMBCast : public QMainWindow
{
    Q_OBJECT

public:
    explicit SMBCast(QWidget *parent = 0);
    ~SMBCast();

private:
    Ui::SMBCast *ui;
};

#endif // SMBCAST_H

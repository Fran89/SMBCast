#include "smbcast.h"
#include "ui_smbcast.h"

SMBCast::SMBCast(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SMBCast)
{
    ui->setupUi(this);
}

SMBCast::~SMBCast()
{
    delete ui;
}

#include "smbcast.h"
#include "ui_smbcast.h"

SMBCast::SMBCast(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SMBCast)
{
    ui->setupUi(this);
    Debug = true;
}

SMBCast::~SMBCast()
{
    delete ui;
}

void SMBCast::on_actionManually_open_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName (this, "Open CSV file",
                                                     QDir::currentPath(), "Shakemap XML(*.xml)");
    if (Debug)
        ui->textBrowser->append("Reading File...");

}

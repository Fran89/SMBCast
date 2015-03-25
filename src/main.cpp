#include "smbcast.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SMBCast w;
    w.show();

    return a.exec();
}

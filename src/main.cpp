#include "smbcast.h"
#include <QApplication>

// It begins
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SMBCast w;
    w.show();

    return a.exec();
}

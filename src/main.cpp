#include "smbcast.h"
#include <QApplication>

// It begins
int main(int argc, char *argv[]) {
    bool GUI = false;
    int Evt = 0;
    QString Filename;
    try{
        TCLAP::CmdLine cmd("SMBCast- A ShakeMap BroadCaster", ' ', "0.1");
        TCLAP::SwitchArg GuiSwitch("n","no-gui","Suppress the Graphical User Interface",cmd,false);
        TCLAP::ValueArg<std::string> nameArg("f","smFile","Shakemap XML File", false,"event_dat.xml","string",cmd);
        TCLAP::ValueArg<int> IdArg("I","evtID","Event ID", false, 0, "integer",cmd);

        cmd.parse( argc, argv );

        Evt = IdArg.getValue();
        GUI = GuiSwitch.getValue();
        Filename = nameArg.getValue().data();

    } catch (TCLAP::ArgException &e) {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }

    QApplication a(argc, argv);
    SMBCast w;
    if(!GUI){
        w.show();
    } else {
        qDebug() << "Filename: " << Filename;
        w.setEvtID(Evt);
        w.parse_shakemapSend(Filename);
        qDebug() << "Exit Program";
        return 0;
    }

    return a.exec();
}

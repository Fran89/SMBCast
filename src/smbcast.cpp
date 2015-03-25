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

void SMBCast::on_actionManually_open_file_triggered() {
    QString fileName = QFileDialog::getOpenFileName (this, "Open CSV file",
                                                     QDir::currentPath(), "Shakemap XML(*.xml)");
    if (Debug)
        ui->textBrowser->append("Reading File...");
    parse_shakemap(fileName);
}

void SMBCast::parse_shakemap(QString fileName){
    QDomDocument doc;
    QFile xmldoc(fileName);
    if (!xmldoc.open(QIODevice::ReadOnly) || !doc.setContent(&xmldoc)){
        ui->textBrowser->append("Error reading file.");
        return;
    }

    QDomNodeList stations = doc.elementsByTagName("station");
    for (int i = 0; i < stations.size(); i++) {
        QDomElement station =stations.at(i).toElement();
        QDomNode STA = stations.at(i);

        if (Debug) {
            ui->textBrowser->append("==========");
            ui->textBrowser->append("Station: " + station.attribute("code","ERROR"));
            ui->textBrowser->append("Latitude: " + station.attribute("lat","ERROR"));
            ui->textBrowser->append("Longitude: " + station.attribute("lon","ERROR"));
        }

        QDomNodeList comps = STA.childNodes();
        for (int j=0; j < comps.size(); j++){
            QDomElement comp = comps.at(j).toElement();
            QDomNode COM = comps.at(j);

            if (Debug) {
                ui->textBrowser->append("=====");
                ui->textBrowser->append("Component: " + comp.attribute("name","ERROR"));
            }

            QDomNodeList cinfs = COM.childNodes();
            for (int k=0; k < cinfs.size();k++){
                QDomElement cinf = cinfs.at(k).toElement();
                if (Debug) {
                    ui->textBrowser->append( cinf.tagName() + ": " + cinf.attribute("value","ERROR"));
                }
            }
        }
    }
}

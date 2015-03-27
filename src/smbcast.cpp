#include "smbcast.h"
#include "ui_smbcast.h"

SMBCast::SMBCast(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SMBCast)
{
    ui->setupUi(this);
    Debug = false;
    Email.setFileName("Email.cfg");
    SMS.setFileName("SMS.cfg");
    Carrier.setFileName("Carriers.cfg");
    Email.open(QIODevice::ReadWrite| QIODevice::Text);
    Carrier.open(QIODevice::ReadWrite| QIODevice::Text);
    SMS.open(QIODevice::ReadWrite| QIODevice::Text);
    Config.setCarriers(&Carrier);
    Email.close();
    SMS.close();
    ui->textBrowser->hide();
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
    Stas.clear();

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

        qint32 CurID;
        CurID = Stas.addStation(station.attribute("code","Err"),
                                station.attribute("lat","ERROR").toDouble(),
                                station.attribute("lon","ERROR").toDouble());

        QDomNodeList comps = STA.childNodes();
        for (int j=0; j < comps.size(); j++){
            QDomElement comp = comps.at(j).toElement();
            QDomNode COM = comps.at(j);

            if (Debug) {
                ui->textBrowser->append("=====");
                ui->textBrowser->append("Component: " + comp.attribute("name","ERROR"));
            }

            QString curcomp = comp.attribute("name","ERROR");
            CompInf Temp;

            QDomNodeList cinfs = COM.childNodes();
            for (int k=0; k < cinfs.size();k++){
                QDomElement cinf = cinfs.at(k).toElement();
                if (Debug) {
                    ui->textBrowser->append( cinf.tagName() + ": " + cinf.attribute("value","ERROR"));
                }

                if(cinf.tagName() == "acc")
                    Temp.pga = cinf.attribute("value","ERROR").toDouble();
                else if(cinf.tagName() == "vel")
                    Temp.pgv = cinf.attribute("value","ERROR").toDouble();
                else if(cinf.tagName() == "psa03")
                    Temp.psa03 = cinf.attribute("value","ERROR").toDouble();
                else if(cinf.tagName() == "psa10")
                    Temp.psa10 = cinf.attribute("value","ERROR").toDouble();
                else if(cinf.tagName() == "psa30")
                    Temp.psa30 = cinf.attribute("value","ERROR").toDouble();
            }

            if (curcomp == "HNN")
                Stas.addCmpNInfo(CurID,Temp.pga,Temp.pgv,Temp.psa03,Temp.psa10,Temp.psa30);
            else if (curcomp == "HNE")
                Stas.addCmpEInfo(CurID,Temp.pga,Temp.pgv,Temp.psa03,Temp.psa10,Temp.psa30);
            else if (curcomp == "HNZ")
                Stas.addCmpZInfo(CurID,Temp.pga,Temp.pgv,Temp.psa03,Temp.psa10,Temp.psa30);
        }

    }

    DrawTable();
}

void SMBCast::DrawTable(){

    // Set Up Table
    QTextCursor cursor(ui->textEdit->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QTextTableFormat SMTF;
    SMTF.setHeaderRowCount(2);
    SMTF.setAlignment(Qt::AlignHCenter);
    SMTF.setCellPadding(2);

    QTextTable *SMTable = cursor.insertTable(2,18);
    SMTable->setFormat(SMTF);
    cursor = SMTable->cellAt(0,0).firstCursorPosition();
    cursor.insertText("Station");
    SMTable->mergeCells(0,0,2,1);
    cursor = SMTable->cellAt(0,1).firstCursorPosition();
    cursor.insertText("Latitude");
    SMTable->mergeCells(0,1,2,1);
    cursor = SMTable->cellAt(0,2).firstCursorPosition();
    cursor.insertText("Longitude");
    SMTable->mergeCells(0,2,2,1);
    cursor = SMTable->cellAt(0,3).firstCursorPosition();
    cursor.insertText("PGA (%g)");
    SMTable->mergeCells(0,3,1,3);
    cursor = SMTable->cellAt(0,6).firstCursorPosition();
    cursor.insertText("PGV (cm/s)");
    SMTable->mergeCells(0,6,1,3);
    cursor = SMTable->cellAt(0,9).firstCursorPosition();
    cursor.insertText("PSA @ 0.3s (%g)");
    SMTable->mergeCells(0,9,1,3);
    cursor = SMTable->cellAt(0,12).firstCursorPosition();
    cursor.insertText("PSA @ 1.0s (%g)");
    SMTable->mergeCells(0,12,1,3);
    cursor = SMTable->cellAt(0,15).firstCursorPosition();
    cursor.insertText("PSA @ 3.0s (%g)");
    SMTable->mergeCells(0,15,1,3);

    int c = 3;
    int co;
    for (int i = 0; i < 5; i++){
        co = c + (i*3);
        for (int j = 0; j < 3; j++) {
            switch(j){
            case 0:
                cursor = SMTable->cellAt(1,co).firstCursorPosition();
                cursor.insertText("HNN");
                break;
            case 1:
                cursor = SMTable->cellAt(1,co).firstCursorPosition();
                cursor.insertText("HNE");
                break;
            case 2:
                cursor = SMTable->cellAt(1,co).firstCursorPosition();
                cursor.insertText("HNZ");
                break;
            default:
                break;
            }
            co++;
        }
    }
    // Finish Setup Table

    // Add Stations
    int numrow=1;

    for(int i=0; i < Stas.size(); i++){
        Station Temp;
        Temp = Stas.retSta(i);
        SMTable->appendRows(1);
        numrow++;
        for (int j=0; j < SMTable->columns(); j++){
            switch(j){
            case 0:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(Temp.Name);
                break;
            case 1:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Location.latitude()));
                break;
            case 2:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Location.longitude()));
                break;
            case 3:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.N.pga,'f',3));
                break;
            case 4:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.E.pga,'f',3));
                break;
            case 5:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Z.pga,'f',3));
                break;
            case 6:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.N.pgv,'f',3));
                break;
            case 7:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.E.pgv,'f',3));
                break;
            case 8:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Z.pgv,'f',3));
                break;
            case 9:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.N.psa03,'f',3));
                break;
            case 10:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.E.psa03,'f',3));
                break;
            case 11:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Z.psa03,'f',3));
                break;
            case 12:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.N.psa10,'f',3));
                break;
            case 13:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.E.psa10,'f',3));
                break;
            case 14:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Z.psa10,'f',3));
                break;
            case 15:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.N.psa30,'f',3));
                break;
            case 16:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.E.psa30,'f',3));
                break;
            case 17:
                cursor = SMTable->cellAt(numrow,j).firstCursorPosition();
                cursor.insertText(QString::number(Temp.Z.psa30,'f',3));
                break;
            }
        }
    }
}

void SMBCast::on_actionToggle_Debug_triggered()
{
    Debug = !Debug;
    if(Debug)
        ui->textBrowser->show();
    else
        ui->textBrowser->hide();
}

void SMBCast::on_actionE_Mail_Settings_triggered() {
    Config.show();
}


void SMBCast::on_SendEmail_clicked() {
    Email.open(QIODevice::ReadOnly);
    QTextStream in(&Email);
    QStringList Emails;
    while (!in.atEnd()) {
        QString line = in.readLine();
        Emails.append(line);
    }
    QProcess term;

    term.setReadChannel(QProcess::StandardOutput);
    term.setProcessChannelMode(QProcess::MergedChannels);

    term.start("which",QStringList() << "sendmail");
    term.waitForFinished(-1);
    QByteArray cmd = term.readAllStandardOutput();
    QString cmdl(cmd.data());
    cmdl = cmdl.trimmed();

    term.start("hostname");
    term.waitForFinished(-1);
    QByteArray hst = term.readAllStandardOutput();
    QString hstnm(hst.data());
    hstnm = hstnm.trimmed();

    if(Debug){
        ui->textBrowser->append(cmdl);
        ui->textBrowser->append(hstnm);
    }

    if(cmdl.contains("sendmail")){
        if (Debug){
            ui->textBrowser->append(QString::number(Emails.size()));
        }

        for (int i=0; i < Emails.size(); i++){
            QFile temp;
            temp.setFileName("Temp.html");
            temp.open(QIODevice::ReadWrite| QIODevice::Text);
            QTextStream Temp(&temp);

            if (Debug){
                ui->textBrowser->append(Emails.at(i));
            }
            Temp    << "From: SMBCast@" << hstnm << endl
                    << "To: " << Emails.at(i) << endl
                    << "Subject: Latest ShakeMap Table" << endl
                    << "Content-Type: text/html" << endl
                    << "MIME-Version: 1.0" << endl << endl
                    << ui->textEdit->toHtml() << endl;
            temp.close();
            term.start(cmdl+"-tv Temp.html");
            term.waitForFinished(-1);
            QByteArray dbg = term.readAllStandardOutput();
            temp.remove();
            if (Debug){
                ui->textBrowser->append(dbg.data());
            }

        }

    }
    Email.close();
}

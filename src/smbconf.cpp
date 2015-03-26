#include "smbconf.h"
#include "ui_smbconf.h"

Carriers::Carriers(){
}

void Carriers::addCarrier(QString Line){
    QStringList Temp;
    Temp = Line.split(":");
    Name.append(Temp.at(0));
    Value.append(Temp.at(1));
}

qint32 Carriers::size(){
    return Name.size();
}

QString Carriers::getName(qint32 Idx){
    return Name.at(Idx);
}

QString Carriers::getDomain(QString Nam){
    qint32 id = Name.indexOf(Nam);
    return Value.at(id);
}

SMBConf::SMBConf(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SMBConf)
{

    ui->setupUi(this);
    this->setWindowTitle("E-Mail Configuration");
    ui->EmailList->setModel(&EmailsMod);
    ui->SMSList->setModel(&SMSMod);
}

SMBConf::~SMBConf()
{
    delete ui;
}

void SMBConf::setCarriers(QFile *Car){

    QTextStream in(Car);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ListCar.addCarrier(line);
    }

    for (int i=0;i<ListCar.size();i++){
        ui->CarSel->addItem(ListCar.getName(i));

    }

}

void SMBConf::setEmail(){

    QTextStream in(&EmaF);
    Emails.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        Emails.append(line);
    }
    EmailsMod.setStringList(Emails);
}

void SMBConf::setSMS(){

    QTextStream in(&SMSF);
    SMS.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        SMS.append(line);
    }
    SMSMod.setStringList(SMS);
}

void SMBConf::on_InsSMS_clicked()
{
    QString sms;
    sms = ui->SMSIS->text() +'@' + ListCar.getDomain(ui->CarSel->currentText());
    SMS.append(sms);
    SMSMod.setStringList(SMS);
}

void SMBConf::on_InsEmail_clicked()
{
    QString email;
    email = ui->EmailIS->text();
    Emails.append(email);
    EmailsMod.setStringList(Emails);
}

void SMBConf::on_RemoveEmail_clicked()
{
    EmailsMod.removeRow(ui->EmailList->currentIndex().row());
    Emails = EmailsMod.stringList();
}

void SMBConf::on_RemoveSMS_clicked()
{
    SMSMod.removeRow(ui->SMSList->currentIndex().row());
    SMS = SMSMod.stringList();
}

void SMBConf::WriteFiles(){

    EmaF.resize(0);
    QTextStream EmailOut(&EmaF);
    for(int i=0; i<Emails.size(); i++){
        EmailOut << Emails.at(i) <<endl;
    }

    SMSF.resize(0);
    QTextStream SMSOut(&SMSF);
    for(int i=0; i<SMS.size(); i++){
        SMSOut << SMS.at(i) <<endl;
    }
}

void SMBConf::ReadFiles(){
    setEmail();
    setSMS();
}

void SMBConf::closeEvent(QCloseEvent *event){
    WriteFiles();
    SMSF.close();
    EmaF.close();
    event->accept();
}

void SMBConf::showEvent(QShowEvent *event){
    SMSF.setFileName("SMS.cfg");
    SMSF.open(QIODevice::ReadWrite| QIODevice::Text);
    EmaF.setFileName("Email.cfg");
    EmaF.open(QIODevice::ReadWrite| QIODevice::Text);
    ReadFiles();
    event->accept();
}

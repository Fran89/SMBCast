#include "smclass.h"

Station::Station() {
}

bool Station::operator ==(const Station &b){
    if (this->Name == b.Name)
        return true;
    else
        return false;
}

SMClass::SMClass() {
}

qint32 SMClass::addStation(QString name, qreal lat, qreal lon) {
    Station Temp;
    Temp.Name = name;
    Temp.Location.setLatitude(lat);
    Temp.Location.setLongitude(lon);
    Stations.append(Temp);
    return Stations.indexOf(Temp);
}

void SMClass::addCmpEInfo(qint32 idx, qreal pga, qreal pgv, qreal psa03, qreal psa10, qreal psa30) {
    Stations[idx].E.pga = pga;
    Stations[idx].E.pgv = pgv;
    Stations[idx].E.psa03 = psa03;
    Stations[idx].E.psa10 = psa10;
    Stations[idx].E.psa30 = psa30;
}

void SMClass::addCmpNInfo(qint32 idx, qreal pga, qreal pgv, qreal psa03, qreal psa10, qreal psa30) {
    Stations[idx].N.pga = pga;
    Stations[idx].N.pgv = pgv;
    Stations[idx].N.psa03 = psa03;
    Stations[idx].N.psa10 = psa10;
    Stations[idx].N.psa30 = psa30;
}

void SMClass::addCmpZInfo(qint32 idx, qreal pga, qreal pgv, qreal psa03, qreal psa10, qreal psa30) {
    Stations[idx].Z.pga = pga;
    Stations[idx].Z.pgv = pgv;
    Stations[idx].Z.psa03 = psa03;
    Stations[idx].Z.psa10 = psa10;
    Stations[idx].Z.psa30 = psa30;
}

qint32  SMClass::retIdx(QString name){
    Station temp;
    temp.Name = name;
    return Stations.indexOf(temp);
}

Station SMClass::retSta(qint32   idx) {
    Station temp;
    temp = Stations.at(idx);
    return temp;
}

Station SMClass::retSta(QString name) {
    Station A,B;
    A.Name = name;
    qint32 Temp;
    Temp = Stations.indexOf(A);
    B = Stations.at(Temp);
    return B;
}

void SMClass::clear() {
    Stations.clear();
}

int SMClass::size(){
    return Stations.length();
}

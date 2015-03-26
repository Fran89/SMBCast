#ifndef SMCLASS_H
#define SMCLASS_H

#include <QGeoCoordinate>
#include <QList>

struct CompInf {
    qreal pga;
    qreal pgv;
    qreal psa03;
    qreal psa10;
    qreal psa30;
};

class Station {

public:
    Station();
    bool operator==(const Station &b);
    QString Name;
    QGeoCoordinate Location;
    CompInf N, E, Z;

};

class SMClass {

public:
    SMClass();
    qint32 addStation(QString name, qreal lat, qreal lon);
    void addCmpNInfo(qint32 idx, qreal pga, qreal pgv, qreal psa03, qreal psa10, qreal psa30);
    void addCmpEInfo(qint32 idx, qreal pga, qreal pgv, qreal psa03, qreal psa10, qreal psa30);
    void addCmpZInfo(qint32 idx, qreal pga, qreal pgv, qreal psa03, qreal psa10, qreal psa30);
    qint32  retIdx(QString name);
    Station retSta(qint32   idx);
    Station retSta(QString name);
    int size();
    void clear();

private:
    QList<Station> Stations;

};

#endif // SMCLASS_H

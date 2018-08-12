#ifndef LAYER_H
#define LAYER_H
#include <QtGui>
#include <QtCore>
#include <iostream>
#include <vector>
#include "layeritem.h"



struct obstruction {
    QString name;
    QString type, position;
    int diff_value, layerLink;
    bool visited;

};
struct asset {
    int c, i, a;
    QString name;
};

class layer {
private:
    QString name;
    QVector<obstruction> entryPoints;
    asset as;
    QString levelOfAccess;
    dimensions dim;
public:
    void setName(QString name);
    QString getName();

    void setEntryPoints(obstruction o);
    QVector<obstruction> getEntryPoints();

    void setAssets(asset a);
    asset getAssets();

    void setAccess(QString access);
    QString getAccess();

    void setDimensions(int height, int width);
    dimensions getDimensions();
};
#endif // LAYER_H

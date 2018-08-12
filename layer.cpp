#include "layer.h"

void layer::setName(QString n)
{
  name = n;
}

QString layer::getName()
{
    return name;
}

void layer::setEntryPoints(obstruction o)
{
    entryPoints.push_back(o);
}

QVector<obstruction> layer::getEntryPoints()
{
    return entryPoints;
}

void layer::setAssets(asset a)
{
    as.name = a.name;
    as.c = a.c;
    as.i = a.i;
    as.a = a.a;
}

asset layer::getAssets()
{
    return as;
}

void layer::setAccess(QString access)
{
    levelOfAccess = access;
}

QString layer::getAccess()
{
    return levelOfAccess;
}

void layer::setDimensions(int height, int width)
{
    dim.height = height;
    dim.width = width;
}

dimensions layer::getDimensions()
{
    return dim;
}



#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "layer.h"
#include "attacker.h"

//route consisting of attacker info, entry points, layer names,
//asset, and the route difficulty
struct route {
    attacker *a = new attacker;
    asset *target = new asset;

    QVector<obstruction> obs_arr;
    QVector<QString> layerNames;

    int route_dif;
};

class algorithms
{
private:

public:

    route collectRoute(QVector<layer> environment, attacker a);




};

#endif // ALGORITHMS_H

#include "algorithms.h"

route algorithms::collectRoute(QVector<layer> environment, attacker a)
{
    route *r = new route;
    obstruction o;
    int d = 0;

    for(int i = 0; i < environment.size(); i++)
    {
        o = environment[i].getEntryPoints()[0];
        r->layerNames.push_back(environment[i].getName());


        for(int j = 1; j < environment[i].getEntryPoints().size(); j++)
        {
            if(a.getSkillLevel().technical >= environment[i].getEntryPoints()[j].diff_value && environment[i].getEntryPoints()[j].type == "Technical")
            {
                if(environment[i].getEntryPoints()[j].diff_value < o.diff_value)
                {
                    o = environment[i].getEntryPoints()[j];
                    d+=environment[i].getEntryPoints()[j].diff_value;
                }
            }
            else if( a.getSkillLevel().physical >= environment[i].getEntryPoints()[j].diff_value && environment[i].getEntryPoints()[j].type == "Physical")
            {
                if(environment[i].getEntryPoints()[j].diff_value < o.diff_value)
                {
                    o = environment[i].getEntryPoints()[j];
                    d+=environment[i].getEntryPoints()[j].diff_value;
                }
            }
        }

        d+=o.diff_value;

        if(o.layerLink > i+1)
        {
            i = o.layerLink - 1;
        }

        r->obs_arr.push_back(o);

        if(a.getTarget() == environment[i].getAssets().name)
        {
            *r->target = environment[i].getAssets();
        }
    }

    return *r;
}

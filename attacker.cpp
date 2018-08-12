#include "attacker.h"

void attacker::setSource(QString s)
{
    source = s;
}

void attacker::setActor(QString a)
{
    actor = a;
}

void attacker::setSkill(int p, int t)
{
    skill.physical=p;
    skill.technical=t;
}

void attacker::setTarget(QString t)
{
    target = t;
}

void attacker::setAccess(QString a)
{
    levelOfAccess = a;
}

QString attacker::getSource()
{
    return source;
}

QString attacker::getActor()
{
    return actor;
}

QString attacker::getTarget()
{
    return target;
}

QString attacker::getLevelOfAccess()
{
    return levelOfAccess;
}

skillLevel attacker::getSkillLevel()
{
    return skill;
}

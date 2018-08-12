#ifndef ATTACKER_H
#define ATTACKER_H
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>

struct skillLevel {
    int physical;
    int technical;
};

class attacker
{
private:
    QString source;
    QString actor;
    skillLevel skill;
    QString target;
//1 = perimeter access, 2 = building access, 3 = Technical Access, 4 = all access
    QString levelOfAccess;

public:
    void setSource(QString source);
    void setActor(QString actor);
    void setSkill(int physical, int technical);
    void setTarget(QString target);
    void setAccess(QString);

    QString getSource();
    QString getActor();
    QString getTarget();
    QString getLevelOfAccess();
    skillLevel getSkillLevel();

};

#endif // ATTACKER_H

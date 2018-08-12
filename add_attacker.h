#ifndef ADD_ATTACKER_H
#define ADD_ATTACKER_H

#include <QDialog>
#include "attacker.h"
#include "layer.h"

namespace Ui {
class add_attacker;
}

class add_attacker : public QDialog
{
    Q_OBJECT

private:
    Ui::add_attacker *ui;

    attacker *a = new attacker;


signals:

    void attackerSignal(attacker);

public:
    explicit add_attacker(QWidget *parent = nullptr);
    ~add_attacker();

    void setAttackerObj(QString source, QString actor, int physical, int technical, QString target, QString access);

    void setTargetComboBox(QVector<layer> l);

private slots:
    void on_attacker_create_btn_clicked();
};





#endif // ADD_ATTACKER_H

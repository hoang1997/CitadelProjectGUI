#include "add_attacker.h"
#include "ui_add_attacker.h"
#include "layer.h"

add_attacker::add_attacker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_attacker)
{
    ui->setupUi(this);
    QStringList list = (QStringList()<<"No Access" << "Perimeter Access"<< "Building Access"<<"Technical Access" << "All Access");
    ui->access->addItems(list);


}

add_attacker::~add_attacker()
{
    delete ui;
}

void add_attacker::setAttackerObj(QString source, QString actor, int physical, int technical, QString target, QString access)
{
    a->setAccess(access);
    a->setSource(source);
    a->setActor(actor);
    a->setSkill(physical, technical);
    a->setTarget(target);
}

void add_attacker::setTargetComboBox(QVector<layer> l)
{
    for(int i = 0; i < l.size();i++)
    {
        ui->targetAsset->addItem(l[i].getAssets().name);
    }
}

void add_attacker::on_attacker_create_btn_clicked()
{
    setAttackerObj(ui->source->text(), ui->type->text(), ui->physical_skill->value(), ui->technical_skill->value(), ui->targetAsset->currentText(), ui->access->currentText());
    emit attackerSignal(*a);
    this->close();

}

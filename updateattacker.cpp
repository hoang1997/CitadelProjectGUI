#include "updateattacker.h"
#include "ui_updateattacker.h"
#include "mainwindow.h"

updateAttacker::updateAttacker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateAttacker)
{
    ui->setupUi(this);
}

updateAttacker::~updateAttacker()
{
    delete ui;
}

void updateAttacker::setAttackerComboBox(QVector<attacker>a)
{
    for(int i = 0; i < a.size();i++)
    {
        ui->chosen_attacker->addItem(a[i].getActor());
    }
}

void updateAttacker::on_cancelBtn_clicked()
{
    this->close();
}

void updateAttacker::on_updateBtn_clicked()
{

}

#include "add_layer.h"
#include "ui_add_layer.h"
#include "add_obstruction.h"
#include "mainwindow.h"
#include "layer.h"
#include <QtCore>
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>
#include <QMessageBox>
//constructor//
add_layer::add_layer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_layer)
{

    ui->setupUi(this);
    this->setWindowTitle("Add Layer");
    QStringList list = (QStringList()<<"No Access" << "Perimeter Access"<< "Building Access"<<"Technical Access" << "All Access");
    ui->levelOfAccess->addItems(list);
    ui->layer_height->setRange(50, 1000);
    ui->layer_width->setRange(50, 1000);
    ui->treeWidget->setColumnCount(2);
}
//destructor//
add_layer::~add_layer()
{
    delete ui;
}

//public functions
void add_layer::setAss()
{
    asset *itm = new asset;

    itm->name = ui->asset_name->text();
    itm->c = ui->spinBox_assetc->value();
    itm->i = ui->spinBox_asseti->value();
    itm->a = ui->spinBox_asseta->value();

    lay->setAssets(*itm);

}

void add_layer::setLayer()
{
    lay->setName(ui->layerName->text());
    lay->setAccess(ui->levelOfAccess->currentText());
    lay->setDimensions(ui->layer_height->value(), ui->layer_width->value());
    setAss();
}

//signal slots----------
void add_layer::setObsTW(obstruction o)
{
    QTreeWidgetItem *obs_name = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(obs_name);
    obs_name->setText(0, o.name);

    QTreeWidgetItem *obs_type = new QTreeWidgetItem(obs_name);
    QTreeWidgetItem *obs_position = new QTreeWidgetItem(obs_name);
    QTreeWidgetItem *obs_diff = new QTreeWidgetItem(obs_name);
    QTreeWidgetItem *obs_layerLink = new QTreeWidgetItem(obs_name);

    obs_type->setText(0, "Type");
    obs_position->setText(0, "Position");
    obs_diff->setText(0, "Difficulty");
    obs_layerLink->setText(0, "Link");

    obs_type->setText(1, o.type);
    obs_position->setText(1, o.position);
    obs_diff->setText(1, QString::number(o.diff_value));
    obs_layerLink->setText(1, "Layer "+QString::number(o.layerLink));
}

void add_layer::setObs(obstruction o)
{
    lay->setEntryPoints(o);
}


//buttons---------
void add_layer::on_create_layer_btn_clicked()
{
    setLayer();


    if(lay->getEntryPoints().isEmpty())
    {
        QMessageBox::StandardButton warning;
        warning = QMessageBox::information(this, "Error:", "Obstructions Must Be Created Before You Procede");

    }
    else
    {
        emit layerSignal(*lay);
        this->close();
    }
}

void add_layer::on_create_obs_btn_clicked()
{

    connect(obs, SIGNAL(obsSignal(obstruction)),this, SLOT(setObsTW(obstruction)), Qt::UniqueConnection);
    connect(obs, SIGNAL(obsSignal(obstruction)), this, SLOT(setObs(obstruction)), Qt::UniqueConnection);

    obs->setModal(true);
    obs->show();
}

void add_layer::on_cancel_layer_btn_clicked()
{
    this->close();
}


void add_layer::on_deleteObs_clicked()
{
   targetObs = ui->obsToDelete->text();

   ui->treeWidget->clear();
   lay->getEntryPoints().clear();
}

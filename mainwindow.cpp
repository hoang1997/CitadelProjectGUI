#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  "add_layer.h"
#include  "add_attacker.h"
#include  "add_obstruction.h"
#include  "layer.h"
#include  "attacker.h"
#include  "layeritem.h"
#include  "savefile.h"
#include  "updatelayer.h"
#include  "updateattacker.h"
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>
#include <QGraphicsItem>
#include <QPaintEvent>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

    ua = new updateAttacker(this);
    connect(this, &MainWindow::attackerInfoSignal, ua , &updateAttacker::setAttackerComboBox);

    sf = new saveFile(this);
    connect(this, &MainWindow::savePreviewSignal, sf, &saveFile::setGraphicsPreview);


    aa = new add_attacker(this);
    connect(this, &MainWindow::setChooseTargetSignal, aa, &add_attacker::setTargetComboBox);
    QList<QGraphicsItem*> list;

    scene->createItemGroup(list);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//set routes tree widget view
void MainWindow::setRouteTW(QVector<layer> e, attacker a)
{
    *r = calc->collectRoute(e, a);
    routeCollection.push_back(*r);

    ui->treeWidget_3->setColumnCount(2);
    ui->treeWidget_3->setColumnWidth(0, 170);

    QTreeWidgetItem *route = new QTreeWidgetItem(ui->treeWidget_3);
    ui->treeWidget->addTopLevelItem(route);
    route->setText(0, "Attacker Based Route");

    if(r->obs_arr.isEmpty())
    {
        displayError("somethings wrong");
    }
    for(int i = 0; i < r->layerNames.size(); i++)
    {
        QTreeWidgetItem *layerName = new QTreeWidgetItem(route);
        layerName ->setText(0, r->layerNames[i]);


        QTreeWidgetItem *entry = new QTreeWidgetItem(layerName);
        entry->setText(0, r->obs_arr[i].name);
        entry->setText(1, QString::number(r->obs_arr[i].diff_value));

    }
}

//set graphical layers into the graphics view
void MainWindow::createLayerGraphicsItem(layer l)
{
   QBrush brush(Qt::blue);
   layerItem *rec = new layerItem();
   rec->setHeightWidth(l.getDimensions().height,l.getDimensions().width);
   rec->setName(l.getName());
   rec->setOpacity(0.3);

   int d = 0;

   for(int i = 0; i < l.getEntryPoints().size(); i++)
   {
       d += l.getEntryPoints()[i].diff_value;
   }

   d /= l.getEntryPoints().size();

   rec->setDiffValue(d);
   scene->addItem(rec);
   //layerItems.push_back(*rec);
}

//set layer tree widget and set layer object to use for route calculations
void MainWindow::setLayerTW(layer l)
{
   ui->treeWidget->setColumnCount(2);
   ui->treeWidget->setColumnWidth(0,170);
   QTreeWidgetItem *layer = new QTreeWidgetItem(ui->treeWidget);
   ui->treeWidget->addTopLevelItem(layer);
   layer->setText(0, l.getName());
   QTreeWidgetItem *obs = new QTreeWidgetItem(layer);
   obs->setText(0, "Obstructions");
   obs->setExpanded(true);
   for(int i = 0; i < l.getEntryPoints().size(); i++)
   {
       QTreeWidgetItem *obs_name = new QTreeWidgetItem(obs);
       QTreeWidgetItem *obs_type = new QTreeWidgetItem(obs_name);
       QTreeWidgetItem *obs_position = new QTreeWidgetItem(obs_name);
       QTreeWidgetItem *obs_diff = new QTreeWidgetItem(obs_name);
       QTreeWidgetItem *obs_link = new QTreeWidgetItem(obs_name);

       obs_name->setText(0, l.getEntryPoints()[i].name);
       obs_type->setText(0, "Type");
       obs_position->setText(0, "Position");
       obs_diff->setText(0, "Dificulty");
       obs_link->setText(0, "Link:");

       obs_type->setText(1, l.getEntryPoints()[i].type);
       obs_position->setText(1, l.getEntryPoints()[i].position);
       obs_diff->setText(1,QString::number(l.getEntryPoints()[i].diff_value));
       obs_link->setText(1, "Layer " + QString::number(l.getEntryPoints()[i].layerLink));

       obs_name -> setExpanded(true);
   }

   QTreeWidgetItem *assets = new QTreeWidgetItem(layer);
   assets->setText(0, "Assets");

       QTreeWidgetItem *asset_n = new QTreeWidgetItem(assets);
       QTreeWidgetItem *asset_c = new QTreeWidgetItem(asset_n);
       QTreeWidgetItem *asset_i = new QTreeWidgetItem(asset_n);
       QTreeWidgetItem *asset_a = new QTreeWidgetItem(asset_n);

   asset_n->setText(0, l.getAssets().name);
   asset_c->setText(0, "Confidentiality");
   asset_i->setText(0, "Integrity");
   asset_a->setText(0, "Availability");

   asset_n->setText(1, "Value");
   asset_c->setText(1, QString::number(l.getAssets().c));
   asset_i->setText(1, QString::number(l.getAssets().i));
   asset_a->setText(1, QString::number(l.getAssets().a));

   asset_n->setExpanded(true);

   QTreeWidgetItem *a = new QTreeWidgetItem(layer);
   a->setText(0, "Access");
   a->setText(1, l.getAccess());
}
void MainWindow::setLayerArray(layer l)
{
    layer_array.push_back(l);
}

//set attacker tree widget and set attacker object to use for calculations
void MainWindow::setAttackerTW(attacker a)
{
    ui->attacker_tw->setColumnCount(2);
    ui->attacker_tw->setColumnWidth(0, 170);
    QTreeWidgetItem *actor = new QTreeWidgetItem(ui->attacker_tw);
    ui->attacker_tw->addTopLevelItem(actor);
    actor->setText(0, a.getActor());


    QTreeWidgetItem *source = new QTreeWidgetItem(actor);
    QTreeWidgetItem *access = new QTreeWidgetItem(actor);
    QTreeWidgetItem *skill = new QTreeWidgetItem(actor);
    QTreeWidgetItem *pskill = new QTreeWidgetItem(skill);
    QTreeWidgetItem *tskill = new QTreeWidgetItem(skill);
    QTreeWidgetItem *target = new QTreeWidgetItem(actor);
    skill->setText(0, "Skill Level");
    source->setText(0, "Source");
    access->setText(0, "Access");
    pskill->setText(0, "Physical");
    tskill->setText(0, "Technical");
    target->setText(0, "Target Asset");

    source->setText(1, a.getSource());
    access->setText(1, a.getLevelOfAccess());
    pskill->setText(1, QString::number(a.getSkillLevel().physical));
    tskill->setText(1, QString::number(a.getSkillLevel().technical));
    target->setText(1, a.getTarget());

}
void MainWindow::setAttackerObj(attacker a)
{
    attackers.push_back(a);
}

//save graphics view image as whatever the format the user wants//                                    need work
void MainWindow::savef(QString fileName)
{
    QPixmap pixmap = ui->graphicsView->grab();
    QFile file(fileName);
    pixmap.save(&file, "JPG",0);
}

//display error message function
void MainWindow::displayError(QString errorMessage)
{
    QMessageBox::StandardButton error;

    error = QMessageBox::information(this,"ERROR:", errorMessage);

}
//button actions
void MainWindow::on_actionAdd_Attacker_triggered()
{

    connect(aa, SIGNAL(attackerSignal(attacker)),this,SLOT(setAttackerTW(attacker)),Qt::UniqueConnection);
    connect(aa, SIGNAL(attackerSignal(attacker)),this, SLOT(setAttackerObj(attacker)), Qt::UniqueConnection);

    emit setChooseTargetSignal(layer_array);
    aa->setModal(true);
    aa->show();
}

void MainWindow::on_actionAdd_Layer_triggered()
{

    add_layer *add_l = new add_layer;
    connect(add_l, SIGNAL(layerSignal(layer)),this,SLOT(setLayerTW(layer)),Qt::UniqueConnection);
    connect(add_l, SIGNAL(layerSignal(layer)),this,SLOT(setLayerArray(layer)),Qt::UniqueConnection);
    connect(add_l, SIGNAL(layerSignal(layer)),this, SLOT(createLayerGraphicsItem(layer)),Qt::UniqueConnection);
    add_l->setModal(true);
    add_l->show();
}

void MainWindow::on_actionSave_As_triggered()
{
    QPixmap *pixmap = new QPixmap;
    *pixmap = ui->graphicsView->grab();
    emit savePreviewSignal(*pixmap);
    sf->setModal(true);
    sf->show();
}

void MainWindow::on_pushButton_clicked()
{
    if(layer_array.isEmpty())
    {
        displayError("Layer Must Be Created Before You Delete");
    }
    else
    {
        ui->treeWidget->clear();
        scene->clear();
        layer_array.clear();
    }
}

void MainWindow::on_createCustomRoutBtn_clicked()
{
    if(layer_array.isEmpty() || attackers.isEmpty())
    {
        displayError("Environment and Attacker Must Be Created Before You Procede");
    }
}

void MainWindow::on_findCustomRoutesBtn_clicked()
{
    if(layer_array.isEmpty() || attackers.isEmpty())
    {
        displayError("Environment and Attacker Must Be Created Before You Procede");
    }
}

void MainWindow::on_findAllRoutesBtn_clicked()
{
    if( attackers.isEmpty() == true)
    {
       displayError("Environment and Attacker Must Be Created Before You Procede");
    }
    else
    {
        setRouteTW(layer_array, attackers[0]);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(attackers.isEmpty())
    {
        displayError("Attacker Must Be Created Before You Procede");
    }
    else
    {
        ui->attacker_tw->clear();
        attackers.clear();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(r->obs_arr.isEmpty())
    {
        displayError("Route Must Be Created Before You Procede");
    }
    else
    {
        ui->treeWidget_3->clear();
        routeCollection.clear();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(layer_array.isEmpty())
    {
        displayError("Layer Must Be Created Before You Edit");
    }
    else
    {
        updateLayer *u = new updateLayer;

        u->setModal(true);
        u->show();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(attackers.isEmpty())
    {
        displayError("Attacker Must Be Created Before You Edit");
    }
    else
    {
        emit attackerInfoSignal(attackers);
        ua->setModal(true);
        ua->show();
    }
}

void MainWindow::on_actionOpen_triggered()
{

}

void MainWindow::on_pushButton_6_clicked()
{
    QString p = QFileDialog::getOpenFileName(this, "Open Image File", QDir::currentPath());
    //QString pe = QFileDialog::getSaveFileName(this, "Open Image File", QDir::currentPath());

    if(!p.isEmpty())
    {
        QImage image(p);
        QImage img = image.scaled(800,600,Qt::KeepAspectRatio);

        if(image.isNull())
        {
            displayError("Error Displaying Image");
            return;
        }

        QGraphicsPixmapItem *itm = new QGraphicsPixmapItem(QPixmap::fromImage(img));


        scene->addItem(itm);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    scene->clear();
}



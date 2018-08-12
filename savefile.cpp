#include "savefile.h"
#include "ui_savefile.h"
#include "mainwindow.h"

#include <QFileDialog>

saveFile::saveFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveFile)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->previewGraphicsView->setScene(scene);
}

saveFile::~saveFile()
{
    delete ui;
}

void saveFile::setGraphicsPreview(QPixmap preview)
{
    scene->addPixmap(preview);

    scene->setSceneRect(scene->itemsBoundingRect());
    ui->previewGraphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void saveFile::on_save_btn_clicked()
{
    QString fileLocationName = QFileDialog::getSaveFileName(this, "Save As", QDir::currentPath());
    emit saveFileSignal(fileLocationName);
    this->close();
}

void saveFile::on_cancel_btn_clicked()
{
    this->close();
}


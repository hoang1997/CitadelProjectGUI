#include "updatelayer.h"
#include "ui_updatelayer.h"

updateLayer::updateLayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateLayer)
{
    ui->setupUi(this);
}

updateLayer::~updateLayer()
{
    delete ui;
}

void updateLayer::on_cancelBtn_clicked()
{
    this->close();
}

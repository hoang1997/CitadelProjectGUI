#ifndef ADD_LAYER_H
#define ADD_LAYER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>
#include "add_obstruction.h"
#include "mainwindow.h"
#include "layer.h"

namespace Ui {
class add_layer;
}

class add_layer : public QDialog
{
    Q_OBJECT
private:
    Ui::add_layer *ui;

    add_obstruction *obs = new add_obstruction;

    layer *lay = new layer;

    QString targetObs;

private slots:

    void setObsTW(obstruction o);
    void setObs(obstruction o);

    void on_create_layer_btn_clicked();

    void on_create_obs_btn_clicked();

    void on_cancel_layer_btn_clicked();

    void on_deleteObs_clicked();

signals:
    void layerSignal(layer l);




public:
    explicit add_layer(QWidget *parent = nullptr);
    ~add_layer();

    void setAss();

    void setLayer();
};

#endif // ADD_LAYER_H

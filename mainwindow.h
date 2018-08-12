#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QTreeWidget>
#include <QGraphicsSceneMouseEvent>


#include "layer.h"
#include "attacker.h"
#include "algorithms.h"
#include "updateattacker.h"
#include "savefile.h"
#include "add_attacker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    //graphcial view set up
    QGraphicsScene *scene;


    //objects for calculations
    layer *l = new layer;
    QVector<layer> layer_array;
    QVector<attacker> attackers;

    //algorithms object to calculate routes
    algorithms *calc = new algorithms;

    route *r = new route;

    QVector<route> routeCollection;

    updateAttacker *ua;
    saveFile *sf;
    add_attacker *aa;



private slots:

    void createLayerGraphicsItem(layer l);
    void setLayerTW(layer l);
    void setLayerArray (layer l);
    void setAttackerTW(attacker a);
    void setAttackerObj(attacker a);
    void savef(QString fileName);

    void on_actionAdd_Layer_triggered();
    void on_actionAdd_Attacker_triggered();
    void on_actionSave_As_triggered();
    void on_pushButton_clicked();
    void on_createCustomRoutBtn_clicked();
    void on_findCustomRoutesBtn_clicked();
    void on_findAllRoutesBtn_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_actionOpen_triggered();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

signals:
    void savePreviewSignal(QPixmap);

    void attackerInfoSignal(QVector<attacker>);

    void setChooseTargetSignal(QVector<layer>);


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setRouteTW(QVector<layer> e, attacker a);

    void displayError(QString errorMessage);



};




#endif // MAINWINDOW_H

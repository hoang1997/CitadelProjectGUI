#ifndef ADD_OBSTRUCTION_H
#define ADD_OBSTRUCTION_H

#include "layer.h"
#include <QDialog>

namespace Ui {
class add_obstruction;
}

class add_obstruction : public QDialog
{
    Q_OBJECT

public:
    explicit add_obstruction(QWidget *parent = nullptr);
    ~add_obstruction();

    void setObsObj(QString name, QString type, int diff, QString position, int ll);

    void checkName();

signals:
    void obsSignal(obstruction);

private slots:

    void on_create_obs_btn_clicked();

    void on_cancel_obs_btn_clicked();

private:
    Ui::add_obstruction *ui;
    obstruction obs;
    QVector<QString> obsNames;
    bool nameAlreadyExists = false;

};

#endif // ADD_OBSTRUCTION_H

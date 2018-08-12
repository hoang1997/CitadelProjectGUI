#ifndef UPDATEATTACKER_H
#define UPDATEATTACKER_H

#include <QDialog>
#include "attacker.h"

namespace Ui {
class updateAttacker;
}

class updateAttacker : public QDialog
{
    Q_OBJECT

public:
    explicit updateAttacker(QWidget *parent = nullptr);
    ~updateAttacker();


    void setAttackerComboBox(QVector<attacker>);

private slots:



    void on_cancelBtn_clicked();

    void on_updateBtn_clicked();

private:
    Ui::updateAttacker *ui;
};

#endif // UPDATEATTACKER_H

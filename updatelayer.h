#ifndef UPDATELAYER_H
#define UPDATELAYER_H

#include <QDialog>

namespace Ui {
class updateLayer;
}

class updateLayer : public QDialog
{
    Q_OBJECT

public:
    explicit updateLayer(QWidget *parent = nullptr);
    ~updateLayer();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::updateLayer *ui;
};

#endif // UPDATELAYER_H

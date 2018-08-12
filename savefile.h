#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>
#include <QGraphicsScene>


namespace Ui {
class saveFile;
}

class saveFile : public QDialog
{
    Q_OBJECT

public:
    explicit saveFile(QWidget *parent = nullptr);
    ~saveFile();

    void setGraphicsPreview(QPixmap preview);


signals:

    void saveFileSignal(QString fileName);



private slots:

    void on_save_btn_clicked();

    void on_cancel_btn_clicked();



private:
    Ui::saveFile *ui;
    QGraphicsScene *scene;


};



#endif // SAVEFILE_H

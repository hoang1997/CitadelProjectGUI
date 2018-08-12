#include "add_obstruction.h"
#include "ui_add_obstruction.h"
#include "add_layer.h"
#include "mainwindow.h"

add_obstruction::add_obstruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_obstruction)
{
    ui->setupUi(this);

    this->setWindowTitle("Add Obstruction");

    QStringList listOne = (QStringList()<<"Physical"<<"Technical");
    ui->comboBox_Type->addItems(listOne);

    QStringList listTwo = (QStringList()<<"Front"<<"Back"<<"Left"<<"Right"<<"Top"<<"Bottom");
    ui->comboBox_Position->addItems(listTwo);
}

add_obstruction::~add_obstruction()
{
    delete ui;
}

void add_obstruction::setObsObj(QString name, QString type, int diff, QString position, int ll)
{
    obs.name = name;
    obs.type = type;
    obs.diff_value = diff;
    obs.position= position;
    obs.layerLink= ll;
}

void add_obstruction::checkName()
{
    for(int i = 0; i < obsNames.size(); i++)
    {
        if(ui->obs_name->text() == obsNames[i])
        {
            nameAlreadyExists = true;
        }
        else
        {
            nameAlreadyExists = false;
        }
    }
}

void add_obstruction::on_create_obs_btn_clicked()
{
    checkName();

    if(nameAlreadyExists == true)
    {
        MainWindow mw;
        mw.displayError("Name Already Exists");
    }
    else
    {
        setObsObj(ui->obs_name->text(), ui->comboBox_Type->currentText(),ui->spinBox_Diff->value(),ui->comboBox_Position->currentText(),ui->spinBox_LayerLink->value());
        obsNames.push_back(ui->obs_name->text());
        emit obsSignal(obs);
        this->close();
    }

}

void add_obstruction::on_cancel_obs_btn_clicked()
{
    this->close();
}

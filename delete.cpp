#include "delete.h"
#include "ui_delete.h"

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_cancelButton_clicked()
{
    confirmDelete=0;
    close();
}

void Delete::on_confrimButton_clicked()
{
  confirmDelete=1;
  trash=new QSound(":/sounds/trash.wav");
  trash->play();
  close();
}

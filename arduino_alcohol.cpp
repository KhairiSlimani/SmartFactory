#include "arduino_alcohol.h"
#include "ui_arduino_alcohol.h"

arduino_alcohol::arduino_alcohol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduino_alcohol)
{
    ui->setupUi(this);
}

arduino_alcohol::~arduino_alcohol()
{
    delete ui;
}


void arduino_alcohol::on_pushButton_clicked()
{
    confirmAlert=1;
    close();
}


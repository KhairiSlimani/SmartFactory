#include "arduino_temperature.h"
#include "ui_arduino_temperature.h"

Arduino_temperature::Arduino_temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino_temperature)
{
    ui->setupUi(this);
}

Arduino_temperature::~Arduino_temperature()
{
    delete ui;
}

void Arduino_temperature::on_pushButton_clicked()
{
    confirmAlert=1;
        close();

}

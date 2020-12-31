#include "arduino_temperature.h"
#include "ui_arduino_temperature.h"

Arduino_Temperature::Arduino_Temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino_Temperature)
{
    ui->setupUi(this);
}

Arduino_Temperature::~Arduino_Temperature()
{
    delete ui;
}

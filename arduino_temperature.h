#ifndef ARDUINO_TEMPERATURE_H
#define ARDUINO_TEMPERATURE_H
#include"arduino.h"
#include <QDialog>

namespace Ui {
class Arduino_temperature;
}

class Arduino_temperature : public QDialog
{
    Q_OBJECT

public:
    explicit Arduino_temperature(QWidget *parent = nullptr);
    ~Arduino_temperature();
    int getAlert(){int i = confirmAlert; return i;}


private slots:
    void on_pushButton_clicked();

private:
    Ui::Arduino_temperature *ui;
    Arduino a;
        int confirmAlert;
};

#endif // ARDUINO_TEMPERATURE_H

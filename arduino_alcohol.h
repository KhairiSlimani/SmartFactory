#ifndef ARDUINO_ALCOHOL_H
#define ARDUINO_ALCOHOL_H

#include <QDialog>
#include "arduino.h"
namespace Ui {
class arduino_alcohol;
}

class arduino_alcohol : public QDialog
{
    Q_OBJECT

public:
    explicit arduino_alcohol(QWidget *parent = nullptr);
    ~arduino_alcohol();
    int getAlert(){int i = confirmAlert; return i;}

private slots:
    void on_pushButton_clicked();


private:
    Ui::arduino_alcohol *ui;
    Arduino A;
    int confirmAlert;
};

#endif // ARDUINO_ALCOHOL_H

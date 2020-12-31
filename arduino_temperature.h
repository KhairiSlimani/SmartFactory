#ifndef ARDUINO_TEMPERATURE_H
#define ARDUINO_TEMPERATURE_H

#include <QDialog>

namespace Ui {
class Arduino_Temperature;
}

class Arduino_Temperature : public QDialog
{
    Q_OBJECT

public:
    explicit Arduino_Temperature(QWidget *parent = nullptr);
    ~Arduino_Temperature();

private:
    Ui::Arduino_Temperature *ui;
};

#endif // ARDUINO_TEMPERATURE_H

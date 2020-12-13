#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getAlert(){int i = confirmAlert; return i;}

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Arduino A;
    int confirmAlert;
};

#endif // DIALOG_H

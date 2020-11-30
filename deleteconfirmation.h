#ifndef DELETECONFIRMATION_H
#define DELETECONFIRMATION_H


#include <QDialog>
#include <QListWidgetItem>
#include<QtMultimedia/QMediaPlayer>


namespace Ui {
class deleteconfirmation;
}

class deleteconfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit deleteconfirmation(QWidget *parent = nullptr);
    ~deleteconfirmation();
     int getConfirm(){int i = confirmDelete; return i;}

private slots:
     void on_confirmDelete_clicked();

     void on_CancelDelete_clicked();

private:
    Ui::deleteconfirmation *ui;
    //Ui::deleteconfirmation *ui;
    int confirmDelete;
    QMediaPlayer *trashSound;
};

#endif

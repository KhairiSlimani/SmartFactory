#ifndef DELETECONFIRMATION_H
#define DELETECONFIRMATION_H
#include<QtMultimedia/QMediaPlayer>
#include <QDialog>

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
    void on_pushButton_ConfirmDeleteCustomer_clicked();

    void on_pushButton_CancelDeleteCustomer_clicked();

private:
    Ui::deleteconfirmation *ui;
    int confirmDelete;
    QMediaPlayer *trashSound;


};

#endif // DELETECONFIRMATION_H

#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <QWidget>
#include <QMenu>
#include <QTimer>
#include <QDateTime>
#include "deleteconfirmation.h"
#include <QPropertyAnimation>
#include "client.h"


namespace Ui {
class Customers;
}

class Customers : public QWidget
{
    Q_OBJECT

public:
    explicit Customers(QWidget *parent = nullptr);
    ~Customers();

private:
    Ui::Customers *ui;
    QPropertyAnimation *animation;
    client Ctmp;
     QStringList  stringList;

signals:
    void HomeClicked();

private slots:
    void showTime();
    void showContextMenu(const QPoint &pos);
    void DeleteItem();
    void ViewItem();
    void EditItem();
    void SendEmailToItem();
    void on_pushButton_Return_clicked();
    void on_pushButton_CancelEditCustomer_clicked();
    void on_pushButton_CancelAddCustomer_clicked();
    void on_pushButton_return2_clicked();
    void on_pushButton_AddNewCustomer_clicked();
    void on_pushButton_SaveAddCustomer_clicked();
    void on_pushButton_SaveEditCustomer_clicked();

    void on_signOut_1_clicked();
    void on_signOut_2_clicked();
    void on_signOut_3_clicked();
    void on_signOut_4_clicked();
    void on_signOut_5_clicked();
    void on_LoadData_clicked();
};

#endif // CUSTOMERS_H

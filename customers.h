#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <QWidget>
#include <QMenu>
#include <QTimer>
#include <QDateTime>
#include "deleteconfirmation.h"
#include <QPropertyAnimation>
#include "client.h"
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>
#include "smtp.h"


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
    client C;//On ajoute un attribut a la classe Customers qui correspond a un objet de la classe client pour pouvoir faire appel aux methodes de la classe client
    QStringList  stringList;
    Smtp* smtp ;
    QString msg;
    QString mail;

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
    void on_pushButton_Print_clicked();
    void on_pushButton_Send_clicked();
    void on_pushButton_SortCustomers_clicked();
    void on_lineEdit_SearchCustomer_textChanged(const QString &arg1);
};

#endif // CUSTOMERS_H

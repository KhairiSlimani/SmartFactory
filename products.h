#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QWidget>
#include <QMenu>
#include <QTimer>
#include <QDateTime>
#include "deleteconfirmation.h"
#include <QPropertyAnimation>
#include "produit.h"
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>
#include "smtp.h"
namespace Ui {
class products;
}

class products : public QWidget
{
    Q_OBJECT

public:
    explicit products(QWidget *parent = nullptr);
    ~products();

private:
    Ui::products *ui;
    QPropertyAnimation *animation;
    produit P;//On ajoute un attribut a la classe Customers qui correspond a un objet de la classe client pour pouvoir faire appel aux methodes de la classe client
    QStringList  stringList;
    Smtp* smtp;
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
    void on_pushButton_CancelEditProduct_clicked();
    void on_pushButton_CancelAddProduct_clicked();
    void on_pushButton_return2_clicked();
    void on_pushButton_AddNewProduct_clicked();
    void on_pushButton_SaveAddProduct_clicked();
    void on_pushButton_SaveEditProduct_clicked();
    void on_signOut_1_clicked();
    void on_signOut_2_clicked();
    void on_signOut_3_clicked();
    void on_signOut_4_clicked();
    void on_signOut_5_clicked();
    void on_LoadData_clicked();
    void on_pushButton_Search_clicked();
    void on_pushButton_Print_clicked();
    void on_pushButton_clicked();
    void on_pushButton_SortProduct_clicked();
};

#endif // PRODUCTS_H






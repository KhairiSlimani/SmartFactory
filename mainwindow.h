#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cnx.h"
#include "bill.h"
#include "delete.h"
#include "order.h"
#include <QMainWindow>
#include <QString>
#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:


    void showTime();

    void showContextMenu(const QPoint&);

    void on_billButton_clicked();

    void on_order_clicked();

    void on_back_clicked();

    void on_back_2_clicked();

    void on_logout_clicked();

    void on_logout_2_clicked();

    void on_logOutButton_clicked();

    void deleteBill();
    void viewBill();
    void editBill();

    void deleteOrder();
    void viewOrder();
    void editOrder();

    void searchBill();

    void on_cancelButton_clicked();

    void on_addButton_clicked();

    void on_addOrder_clicked();

    void on_cancelButton_2_clicked();

    void on_addBill_clicked();

    void on_back_pressed();

    void on_return_1_clicked();




    int on_listView_doubleClicked(const QModelIndex &index);






    void on_addButton_3_clicked();

    void on_cancelButton_3_clicked();

    void on_return_3_clicked();

    void on_addButton_2_clicked();

    void on_editButton_clicked();

    void on_cancelButton_10_clicked();

    void on_sort_clicked();

private:
    Ui::MainWindow *ui;
    bill b;
    order o;


};
#endif // MAINWINDOW_H

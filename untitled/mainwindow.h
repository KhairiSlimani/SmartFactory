#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "products.h"
#include "warehouse.h"
#include <QPropertyAnimation>
#include "produit.h"


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
    void on_ProductsButton_clicked();

    void on_WarehouseButton_clicked();

    void moveHome();

    void on_signOut_clicked();


private:
    Ui::MainWindow *ui;
    products produit;
    warehouse depot;
    QPropertyAnimation *animation;

};
#endif // MAINWINDOW_H





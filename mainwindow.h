#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"suppliers.h"
#include"material.h"

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






    void on_pushButtonADD_clicked();


    void on_pushButton_ViewReturn_clicked();

    void on_pushButton_EditSave_clicked();

    void on_pushButton_Add_clicked();




    void on_pushButton_clicked();

    void on_pushButton_2_clicked();





    void on_pushButton_deletesupplier_clicked();



    void on_pushButton_AddMaterialAdd_clicked();

    void on_pushButton_DeleteMaterial_clicked();

    void on_pushButton_SortSupplier_clicked();

private:
    Ui::MainWindow *ui;
    Suppliers stmp;
    material mtmp;
};
#endif // MAINWINDOW_H

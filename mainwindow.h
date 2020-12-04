#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"suppliers.h"
#include"material.h"
#include <QDialog>
#include <QTimer>

#include <QDateTime>
#include <QListWidgetItem>

#include <QHeaderView>
#include <QMessageBox>
#include <QDebug>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"deleteconfirmation.h"
#include<QtCharts>


#include <qplaintextedit.h>
#include "smtp.h"


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
      //void showContextMenu(const QPoint&);
//      void deletematerial();
//      void viewmateriel();
//      void editmaterial();



      void mail(QString){};







    void on_pushButtonADD_clicked();


    void on_pushButton_ViewReturn_clicked();

    void on_pushButton_EditSave_clicked();

    void on_pushButton_Add_clicked();
    //void showContextMenu(const QPoint &pos);
    //void DeleteItem();
    //void EditItem();
    //void SendEmailToItem();




    void on_pushButton_clicked();

    void on_pushButton_2_clicked();





    void on_pushButton_deletesupplier_clicked();



    void on_pushButton_AddMaterialAdd_clicked();

    void on_pushButton_DeleteMaterial_clicked();



    //void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_menusupplier_clicked();

    void on_pushButton_menuMaterial_clicked();

    //void on_pushButton_12_clicked();

    //void on_pushButton_confirmSupplierEdit_clicked();

    void on_pushButton_confirmMaterialEdit_clicked();

    void on_pushButton_EditSaveSupplier_clicked();

    void on_pushButton_SearchMaterial_clicked();

    void on_pushButton_SortMaterial_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_statMateriel_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_matAddlist_clicked();

    void on_pushButton_matEditList_clicked();

    void on_pushButton_DeleteMatList_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_Addcancel_clicked();

    void on_pushButton_Editcancel_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_Home_clicked();

    void on_lineEdit_SearchMaterial_textChanged(const QString &arg1);
     //void loadData();


private:
    Ui::MainWindow *ui;
    QString msg;
    material m ;
    Suppliers s;
    Smtp* smtp;
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H

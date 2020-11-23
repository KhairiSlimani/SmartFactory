#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"suppliers.h"
#include"QString"
#include"QMessageBox"
#include<QtCore>
#include<QtGui>
#include<QTimer>
#include<QDateTime>
#include"QtSql/QSqlQueryModel"
#include"material.h"
#include"QtSql/qsqlerror.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewsupp->setModel(stmp.Viewsupplier());
   ui->tableViewMaterial->setModel(mtmp.ViewMaterial());
   // ui->stackedWidget
   // QTimer *timer=new QTimer(this);
    //connect(timer , SIGNAL(timeout ()),this,SLOT(showTime()));
   // timer->start();
    QDateTime datetime=QDateTime::currentDateTime();
    QString datetimetext=datetime.toString();
    ui->lineEdit_Date->setText(datetimetext);
    ui->lineEditDateAdd->setText(datetimetext);
    ui->lineEdit_DateEdit->setText(datetimetext);
    ui->lineEdit_DateView->setText(datetimetext);
    ui->lineEditdatedelete->setText(datetimetext);
    ui->lineEdit_ViewMatTime->setText(datetimetext);
    ui->lineEdit_ViewMatDate->setText(datetimetext);
    ui->lineEdit_ListMatDate->setText(datetimetext);
    ui->lineEdit_EditMatTime->setText(datetimetext);
    ui->lineEdit_ListMatTime->setText(datetimetext);
    ui->lineEdit_EditMatDate->setText(datetimetext);
    ui->lineEdit_DelMatTime->setText(datetimetext);
    ui->lineEdit_DelMatDate->setText(datetimetext);
    ui->lineEdit_AddMatDate->setText(datetimetext);
    ui->lineEdit_AddMatTime->setText(datetimetext);





   // QPixmap Logo("C:/Users/hp/Desktop/partie QT/Fournisseurs/floralloLogo.png");

 // ui->label_8->setPixmap(Logo);
     QPixmap pix(":/floralloLogo.png");
     ui->label_logo->setPixmap(pix);
     QPixmap sup(":/Supp photo.png");
     ui->label_9->setPixmap(sup);
     ui->label_10->setPixmap(sup);
     ui->label_11->setPixmap(sup);

   // for(int i=0;i<20;i++)

       // ui->listWidgetsupp->addItem("suppliers "+ QString ::number(i) );



   // for(int i=0;i<20;i++)

        //ui->listWidgetsupp->addItem("material"+ QString ::number(i));

    //ADD
    ui->stackedWidget->setCurrentIndex(0);
    //controle de saisie de fournisseurs de la modification
    ui->lineEdit_editSID->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_Addcontacttitle->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_editcontactName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_editCname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_EDitCIty->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_editCountry->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_editAdress->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_editPhone->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->lineEdit_editFAX->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->lineEdit_EditHomepage->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    //controle de saisie de l'ajout de fournisseurs
    ui->lineEditADDSID->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_Addcontacttitle->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddContName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddCompName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddCity->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddCountry->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddAdress->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_AddPhone->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->lineEditAddHomepage->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    //controle de saisie de l'ajout d'une matiére

     ui->lineEdit_AddSupplierIDMat->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEdit_AddcurrncyMatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEdit_AddQuantMatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEdit_AddMatpriceAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEdit_AddUnitMatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEdit_AddDesmatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->lineEdit_AddMatNameAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
       ui->lineEditADDMaterialID->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));

     // controle de saisie de la modification de la matiére
      ui->lineEdit_EditMatCurrency->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->lineEdit_EditMatSupID->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->lineEdit_EditMatQuant->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->lineEdit_EditMatPrice->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->lineEdit_EditMatName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->lineEdit_EditMatDes->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
       ui->lineEdit_EditMaterialID->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));

}

MainWindow::~MainWindow()
{
    delete ui;
}
  void MainWindow :: showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString(" hh : mm : ss ");
    ui->lineEditTime->setText(time_text);
    ui->lineEditTimeAdd->setText(time_text);
    ui->lineEditTimeEdit->setText(time_text);
    ui->lineEditTimeviw->setText(time_text);
    ui->lineEdittimedelete->setText(time_text);
    ui->lineEdit_AddMatTime->setText(time_text);
    ui->lineEdit_ViewMatTime->setText(time_text);
    ui->lineEdit_ListMatTime->setText(time_text);
    ui->lineEdit_EditMatTime->setText(time_text);
    ui->lineEdit_DelMatTime->setText(time_text);






}











  void MainWindow::on_pushButton_ViewReturn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_EditSave_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_Add_clicked()
{
    QString id=ui->lineEditADDSID->text();
    QString campName=ui->lineEdit_AddCompName->text();
            QString title=ui->lineEdit_Addcontacttitle->text();
             QString adress=ui->lineEdit_AddAdress->text();
             QString ville=ui->lineEdit_AddCity->text();
             QString pays=ui->lineEdit_AddCountry->text();
             QString telephone=ui->lineEdit_AddPhone->text();
             QString fax=ui->lineEditaddfax->text();
             QString pagacc=ui->lineEditAddHomepage->text();
  Suppliers S(id,campName,title,adress, ville,pays,telephone,fax, pagacc);
  bool test=S.Addsupplier();
  if(test)
  {
      //Mise a jour ou meme temps avec l'implémentation d'un fournisseurs
       ui->tableViewsupp->setModel(stmp.Viewsupplier());

      QMessageBox::information(nullptr, QObject::tr("Confirmation"),
                  QObject::tr("successful addition.\n"));
  }
  else

              QMessageBox::critical(nullptr, QObject::tr("failure"),
                          QObject::tr("add failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonADD_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}





void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}







void MainWindow::on_pushButton_deletesupplier_clicked()
{
    int id =ui->lineEdit_deleteID->text().toInt();
    bool test=stmp.deletesupplier(id);
    if(test)
    {
        //Mise a jour ou meme temps avec l'implémentation d'un fournisseurs
         ui->tableViewsupp->setModel(stmp.Viewsupplier());

        QMessageBox::information(nullptr, QObject::tr("Confirmation"),
                    QObject::tr("successful removal.\n"));
    }
    else

                QMessageBox::critical(nullptr, QObject::tr("failure"),
                            QObject::tr("deletion failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_AddMaterialAdd_clicked()
{
    QString Name=ui->lineEdit_AddMatNameAdd->text();
    QString description=ui->lineEdit_AddDesmatAdd->text();
    QString SupplierID=ui->lineEdit_AddSupplierIDMat->text();
    QString Quantity=ui->lineEdit_AddQuantMatAdd->text();
    QString Unit=ui->lineEdit_AddUnitMatAdd->text();
    QString price=ui->lineEdit_AddMatpriceAdd->text();
    QString Currency=ui->lineEdit_AddMatpriceAdd->text();
    QString Expiratdate=ui->dateEdit_addExpiratMat->text();
        QString id=ui->lineEditADDMaterialID->text();
    material m(id,Name,description,SupplierID,Quantity,Unit,price,Currency,Expiratdate);
    bool test=m.AddMaterial();
    if(test)
    {
        //Mise a jour ou meme temps avec l'implémentation d'une matiére
         ui->tableViewMaterial->setModel(mtmp.ViewMaterial());

        QMessageBox::information(nullptr, QObject::tr("Confirmation"),
                    QObject::tr("successful addition.\n"));
    }
    else

                QMessageBox::critical(nullptr, QObject::tr("failure"),
                            QObject::tr("add failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_DeleteMaterial_clicked()
{
    int id =ui->lineEdit_DeleteMatId->text().toInt();
    bool test=mtmp.deleteMaterial(id);
    if(test)
    {
        //Mise a jour ou meme temps avec l'implémentation d'un fournisseurs
         ui->tableViewMaterial->setModel(mtmp.ViewMaterial());

        QMessageBox::information(nullptr, QObject::tr("Confirmation"),
                    QObject::tr("successful removal.\n"));
    }
    else

                QMessageBox::critical(nullptr, QObject::tr("failure"),
                            QObject::tr("deletion failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_SortSupplier_clicked()
{
    QSqlQueryModel * myModel=new QSqlQueryModel(ui->tableViewsupp);
        QSqlQuery select;
        if (!select.exec("select * from supplier")) {
            QMessageBox::critical(this, tr("Error"), select.lastError().text());
        }
        else {
            myModel->setQuery(select);
            QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(myModel); // create proxy
            proxyModel->setSourceModel(myModel);
            ui->tableViewsupp->setSortingEnabled(true); // enable sortingEnabled
            ui->tableViewsupp->setModel(proxyModel);
        }
}

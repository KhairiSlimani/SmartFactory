#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"suppliers.h"
#include<QString>
#include<QMessageBox>
#include<QtCore>
#include<QtGui>
#include<QTimer>
#include<QDateTime>

#include"material.h"
#include"smtp.h"

#include"deleteconfirmation.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    //Material list
    ui->listViewMateriel->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listViewMateriel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    //Material List
    ui->listViewSupplier->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listViewSupplier, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));


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
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_Add_clicked()
{

    bool test=true;
    QString id;

    QString campName;
    QString title;
    QString adress;
    QString ville;
    QString pays;
    QString telephone;
    QString fax;
    QString pagacc;

    if(ui->lineEditADDSID->text().isEmpty())
    {
        ui->lineEditADDSID->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddPhone->text().isEmpty())
    {
        ui->lineEdit_AddPhone->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddAdress->text().isEmpty())
    {
        ui->lineEdit_AddAdress->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddCity->text().isEmpty())
    {
        ui->lineEdit_AddCity->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddCountry->text().isEmpty())
    {
        ui->lineEdit_AddCountry->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEditaddfax->text().isEmpty())
    {
        ui->lineEditaddfax->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEditAddHomepage->text().isEmpty())
    {
        ui->lineEditAddHomepage->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddCompName->text().isEmpty())
    {
        ui->lineEdit_AddCompName->setStyleSheet("border: 2px solid red;");
        test=false;
    }
    if(ui->lineEdit_AddContName->text().isEmpty())
    {
        ui->lineEdit_AddContName->setStyleSheet("border: 2px solid red;");
        test=false;
    }




    if(test)
    {
        id=ui->lineEditADDSID->text();
        campName=ui->lineEdit_AddCompName->text();
        title=ui->lineEdit_Addcontacttitle->text();
        adress=ui->lineEdit_AddAdress->text();
        ville=ui->lineEdit_AddCity->text();
        pays=ui->lineEdit_AddCountry->text();
        telephone=ui->lineEdit_AddPhone->text();
        fax=ui->lineEditaddfax->text();
        pagacc=ui->lineEditAddHomepage->text();
        Suppliers S(id,campName,title,adress, ville,pays,telephone,fax, pagacc);
        bool test2=S.Addsupplier();
        ui->listViewSupplier->setModel(s.afficherList2());//refresh list view




        if(test2)
        {
            QMessageBox :: information(nullptr, QObject :: tr("Add Supplier"),
                                       QObject::tr("Supplier Added"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox :: warning(nullptr, QObject :: tr("Add Supplier"),
                                   QObject::tr("Error,Supplier Not Added :("),QMessageBox::Cancel);

        }

    }
    else
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }
    ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_pushButtonADD_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}





void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}







void MainWindow::on_pushButton_deletesupplier_clicked()
{

    deleteconfirmation d;
    d.setModal(true);
    d.exec();

    QModelIndex index = ui->listViewSupplier->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    if(d.getConfirm()==1)
    {
        Suppliers s;

        bool test=s.deletesupplier(info);
        if(test)
    {
            ui->listViewSupplier->setModel(s.afficherList2());//refresh list view
        }

    }
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButton_AddMaterialAdd_clicked()
{

    bool test=true;
    QString id;
    QString Name;
    QString Description;
    QString SupplierID;
    QString Quantity ;
    QString Unit;
    QString price;
    QString Currency;
    QString Expiratdate;

    if(ui->lineEdit_AddMatNameAdd->text().isEmpty())
    {
        ui->lineEdit_AddMatNameAdd->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEditADDMaterialID->text().isEmpty())
    {
        ui->lineEditADDMaterialID->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddDesmatAdd->text().isEmpty())
    {
        ui->lineEdit_AddDesmatAdd->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddSupplierIDMat->text().isEmpty())
    {
        ui->lineEdit_AddSupplierIDMat->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddcurrncyMatAdd->text().isEmpty())
    {
        ui->lineEdit_AddcurrncyMatAdd->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddQuantMatAdd->text().isEmpty())
    {
        ui->lineEdit_AddQuantMatAdd->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddMatpriceAdd->text().isEmpty())
    {
        ui->lineEdit_AddMatpriceAdd->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddUnitMatAdd->text().isEmpty())
    {
        ui->lineEdit_AddUnitMatAdd->setStyleSheet("border: 2px solid red;");
        test=false;
    }





    if(test)
    {
        Name=ui->lineEdit_AddMatNameAdd->text();
        Description=ui->lineEdit_AddDesmatAdd->text();
        SupplierID=ui->lineEdit_AddSupplierIDMat->text();
        Quantity=ui->lineEdit_AddQuantMatAdd->text();
        Unit=ui->lineEdit_AddUnitMatAdd->text();
        price=ui->lineEdit_AddMatpriceAdd->text();
        Currency=ui->lineEdit_AddMatpriceAdd->text();
        id=ui->lineEditADDMaterialID->text();

        material m(id,Name,Description,SupplierID,Quantity,Unit,price,Currency);
        bool test2=m.AddMaterial();
        ui->listViewMateriel->setModel(m.afficherList());//refresh list view


        if(test2)
        {

            QMessageBox :: information(nullptr, QObject :: tr("Add Material"),
                                       QObject::tr("Material Added"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox :: warning(nullptr, QObject :: tr("Add Material"),
                                   QObject::tr("Error,Material Not Added :("),QMessageBox::Cancel);

        }

    }
    else
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }

     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_DeleteMaterial_clicked()
{
  /*  deleteconfirmation d;
    d.setModal(true);
    d.exec();

    QModelIndex index = ui->listViewMateriel->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    if(d.getConfirm()==1)
    {
        material m;
        bool test=m.deleteMaterial(info);

        if(test)
        {
           qDebug()<<"not done";
        }
    }
    */

}




void MainWindow::on_pushButton_menusupplier_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_menuMaterial_clicked()
{
    ui->listViewMateriel->setModel(m.afficherList());
    ui->stackedWidget->setCurrentIndex(7);
}



void MainWindow::on_pushButton_confirmMaterialEdit_clicked()
{
    QModelIndex index = ui->listViewMateriel->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    material m;
    view = m.ViewMaterial(info);

    while(view.next())
    {
        ui->lineEdit_EditMatDes->setText(view.value(0).toString());
        ui->lineEdit_EditMatCurrency->setText(view.value(1).toString());
        ui->lineEdit_EditMaterialID->setText(view.value(2).toString());
        ui->lineEdit_EditMatSupID->setText(view.value(3).toString());
        ui->lineEdit_EditMatQuant->setText(view.value(4).toString());
        ui->lineEdit_EditMatPrice->setText(view.value(5).toString());

    }

    ui->stackedWidget->setCurrentIndex(2);
}





void MainWindow::on_pushButton_EditSaveSupplier_clicked()
{
    QModelIndex index = ui->listViewSupplier->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Suppliers s;
    view=s.Viewsupplier(info);

    while(view.next())
    {
        ui->lineEdit_editSID->setText(view.value(0).toString());
        ui->lineEdit_editFAX->setText(view.value(1).toString());
        ui->lineEdit_EDitCIty->setText(view.value(2).toString());
        ui->lineEdit_editCname->setText(view.value(3).toString());
        ui->lineEdit_editPhone->setText(view.value(4).toString());
        ui->lineEdit_editAdress->setText(view.value(5).toString());

    }

    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_SearchMaterial_clicked()
{
    QString id =  ui->lineEdit_SearchMaterial->text();
    qDebug() << id;
    material m;
    bool test=m.searchMaterial(id);
    qDebug() << test;
    if(test == true)
    {
        QSqlQuery view=m.ViewMaterial(id);

        while(view.next())
        {
            ui->lineEdit_ViewMaterialID->setText(view.value(0).toString());
            ui->lineEdit_ViewMatQuantite->setText(view.value(1).toString());
            ui->lineEdit_ViewMatSuppID->setText(view.value(2).toString());
            ui->lineEdit_ViewMatPrice->setText(view.value(3).toString());
            ui->lineEdit_ViewMatUnit->setText(view.value(4).toString());
            ui->lineEdit_ViewMatDes->setText(view.value(5).toString());
            ui->lineEdit_ViewMatName->setText(view.value(6).toString());

        }



    }
    else
    {
        QMessageBox::warning(this, tr("Warning"),tr("Material Not Found!"), QMessageBox::Ok);
    }
}


void MainWindow::on_pushButton_SortMaterial_clicked()
{
    material m;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=m.sortmaterial();
    ui->listViewMateriel->setModel(model);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_statMateriel_clicked()
{
     material m;

      QPieSeries *series = new QPieSeries();

               QSqlQuery query;
                       query=m.statMat();
               while(query.next())
               {
                   series->append(query.value(0).toString(),query.value(3).toInt());
               }

               QChart * chart=new  QChart();
               chart->addSeries(series);
               chart->setTitle("Material stats");
               QChartView * chartView=new QChartView(chart);
               chartView ->setParent(ui->horizontalFrame);
               chartView->setFixedSize(ui->horizontalFrame->size());
               ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_pushButton_3_clicked()
{
    smtp = new Smtp("p.florallo@gmail.com" , "nesrine123", "smtp.gmail.com",465);

    connect(smtp, SIGNAL(status(QString)), this, SLOT(mail(QString)));

    msg=ui->plainTextEdit->toPlainText();

    smtp->sendMail("p.florallo@gmail.com","nesrine.zamni@esprit.tn",ui->lineEditmail->text(),msg);
}

void MainWindow::on_pushButton_matAddlist_clicked()
{
   ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_matEditList_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_DeleteMatList_clicked()
{
    deleteconfirmation d;
       d.setModal(true);
       d.exec();

       QModelIndex index = ui->listViewMateriel->currentIndex();
       QString info = index.data(Qt::DisplayRole).toString();
       if(d.getConfirm()==1)
       {
           material m;
           bool test=m.deleteMaterial(info);

           if(test)
           {
               ui->listViewMateriel->setModel(m.afficherList());//refresh list view
              qDebug()<<"not done";
           }
       }
   /* ui->stackedWidget->setCurrentIndex(10);*/
}

void MainWindow::on_pushButton_9_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_Addcancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Editcancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

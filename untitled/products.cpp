#include "products.h"
#include "ui_products.h"
#include "deleteconfirmation.h"
#include "produit.h"
#include <QMessageBox>
#include <QListWidget>
#include "connection.h"


products::products(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::products)
{
    ui->setupUi(this);
    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //Customer's list
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    //Place Holder for search product By code
    ui->lineEdit_SearchCustomer->setPlaceholderText("  Search...");

    //place Holder of add Product Inteface
    ui->lineEdit_ProductCodeInput->setPlaceholderText(" Enter Product Code");
    ui->lineEdit_ProductNameInput->setPlaceholderText("Enter Product Name");
    ui->lineEdit_QuantityInStockInput->setPlaceholderText("Enter The Quantity In Stock");
    ui->lineEdit_SellPriceInput->setPlaceholderText("Enter Sell Price /TND");


    //place Holder of edit Product Interface
    ui->lineEdit_ProductCodeInput_2->setPlaceholderText(" Enter Product Code");
    ui->lineEdit_ProductNameInput_2->setPlaceholderText("Enter Product Name");
    ui->lineEdit_QuantityInStockInput_2->setPlaceholderText("Enter The Quantity In Stock");
    ui->lineEdit_SellPriceInput_2->setPlaceholderText("Enter Sell Price /TND");

    //controle de saisie du searchProduct
    ui->lineEdit_SearchCustomer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    //controle de saisie des Inputs de AddProduct
    ui->lineEdit_ProductCodeInput->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_ProductNameInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));//input must be an alphabet uppercase or lowercase
    ui->lineEdit_QuantityInStockInput->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_SellPriceInput->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));



    //controle des Inputs de EditProduct
    ui->lineEdit_ProductCodeInput_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_ProductNameInput_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));//input must be an alphabet uppercase or lowercase
    ui->lineEdit_QuantityInStockInput_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_SellPriceInput_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));



}

products::~products()
{
    delete ui;
}

void products::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);
    ui->time2->setText(time_text);
    ui->time3->setText(time_text);
    ui->time4->setText(time_text);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date2->setText(datetimetext);
    ui->date3->setText(datetimetext);
    ui->date4->setText(datetimetext);
}

void products::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(ViewItem()));
    myMenu.addAction("Edit",  this, SLOT(EditItem()));
    myMenu.addAction("Delete", this, SLOT(DeleteItem()));
    myMenu.addAction("Send Email", this, SLOT(SendEmailToItem()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}


void products::DeleteItem()
{
    deleteconfirmation D;
    D.setModal(true);
    D.exec();

    //Recuperation de l'indice du curseur
    QModelIndex index = ui->listView->currentIndex();
    //Recuperation de l'id du client sur lequel mon curseur est positionné
    QString itemText = index.data(Qt::DisplayRole).toString();

    if(D.getConfirm()==1)
    {
        //supprimer l'objet C de la table client et on recupére la valeur de retour(query.exec()) dans la variable test
        bool test=P.Effacer(itemText);

        if(test)//if(test==true)->La requete est executée->QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Deletion of client is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView->setModel(P.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion of Client failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void products::ViewItem()
{
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    ui->tableView->setModel(P.Afficher(itemText));
    ui->stackedWidget->setCurrentIndex(1);
}

void products::EditItem()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void products::SendEmailToItem()
{
    QStringList list;
    QAbstractItemModel *model = ui->tableView->model();
    QModelIndex index0 = model->index(0,5);
    ui->lineEdit_Email->setText(index0.data().toString());
    ui->stackedWidget->setCurrentIndex(2);
}

void products::on_pushButton_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void products::on_pushButton_CancelEditProduct_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void products::on_pushButton_CancelAddProduct_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void products::on_pushButton_return2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void products::on_pushButton_AddNewProduct_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void products::on_pushButton_SaveAddProduct_clicked()

    {



        if(ui->lineEdit_ProductCodeInput->text().isEmpty())
        {
            ui->lineEdit_ProductCodeInput->setStyleSheet("border: 1px solid red");
        }
        else
        {
            ui->lineEdit_ProductCodeInput->setStyleSheet("border: 1px solid black");
        }

        if(ui->lineEdit_ProductNameInput->text().isEmpty())
        {
            ui->lineEdit_ProductNameInput->setStyleSheet("border: 1px solid red");
        }
        else
        {
           ui->lineEdit_ProductNameInput->setStyleSheet("border: 1px solid black");
        }

        if(ui->lineEdit_QuantityInStockInput->text().isEmpty())
        {
            ui->lineEdit_QuantityInStockInput->setStyleSheet("border: 1px solid red");
        }
        else
        {
            ui->lineEdit_QuantityInStockInput->setStyleSheet("border: 1px solid black");
        }

        if(ui->lineEdit_SellPriceInput->text().isEmpty())
        {
            ui->lineEdit_SellPriceInput->setStyleSheet("border: 1px solid red");
        }
        else
        {
            ui->lineEdit_SellPriceInput->setStyleSheet("border: 1px solid black");
        }

        if((ui->lineEdit_ProductCodeInput->text().isEmpty())||(ui->lineEdit_ProductNameInput->text().isEmpty())||(ui->lineEdit_QuantityInStockInput->text().isEmpty())||(ui->lineEdit_SellPriceInput->text().isEmpty()))
        {
            QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);

        }
        else
        {

                          QString productCode=ui->lineEdit_ProductCodeInput->text();
                          QString productName=ui->lineEdit_ProductNameInput->text();
                          int sellPrice=ui->lineEdit_SellPriceInput->text().toUInt();
                          int quantityInStock=ui->lineEdit_QuantityInStockInput->text().toUInt();

             produit p(productCode,productName,sellPrice,quantityInStock);
             bool test=p.ajouter();
             if(test)//if (test==true)->la requete est executÃ©e->QMessageBox::information
             {
                 QMessageBox::information(nullptr, QObject::tr("Ok"),
                                          QObject::tr("Addition of new PRODUCT is successful.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);

                 ui->listView->setModel(p.AfficherListe());
                 ui->stackedWidget->setCurrentIndex(0);
             }
             else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
             {
                 QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                       QObject::tr("Addition of new PRODUCT failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->stackedWidget->setCurrentIndex(0);
             }

        }

}

void products::on_pushButton_SaveEditProduct_clicked()
{
    if(ui->lineEdit_ProductCodeInput->text().isEmpty())
    {
        ui->lineEdit_ProductCodeInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_ProductCodeInput->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_ProductNameInput->text().isEmpty())
    {
        ui->lineEdit_ProductNameInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
       ui->lineEdit_ProductNameInput->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_QuantityInStockInput->text().isEmpty())
    {
        ui->lineEdit_QuantityInStockInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_QuantityInStockInput->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_SellPriceInput->text().isEmpty())
    {
        ui->lineEdit_SellPriceInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_SellPriceInput->setStyleSheet("border: 1px solid black");
    }






    if((ui->lineEdit_ProductCodeInput->text().isEmpty())||(ui->lineEdit_ProductNameInput->text().isEmpty())||(ui->lineEdit_QuantityInStockInput->text().isEmpty())||(ui->lineEdit_SellPriceInput->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),
        tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);

    }
    else
    {
        QString productCode=ui->lineEdit_ProductCodeInput->text();
        QString productName=ui->lineEdit_ProductNameInput->text();
        int sellPrice=ui->lineEdit_SellPriceInput->text().toUInt();
        int quantityInStock=ui->lineEdit_QuantityInStockInput->text().toUInt();

produit p(productCode,productName,sellPrice,quantityInStock);
bool test=p.Editer();

if(test)//if (test==true)->la requete est executÃ©e->QMessageBox::information
           {
               QMessageBox::information(nullptr, QObject::tr("Ok"),
                                        QObject::tr("Edit of PRODUCT is successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

               ui->listView->setModel(p.AfficherListe());
           }
           else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
           {
               QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                     QObject::tr("Edit of PRODUCT failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }

           ui->stackedWidget->setCurrentIndex(0);
       }


}

void products::on_signOut_1_clicked()
{
    emit(HomeClicked());
}

void products::on_signOut_2_clicked()
{
    emit(HomeClicked());
}

void products::on_signOut_3_clicked()
{
    emit(HomeClicked());
}

void products::on_signOut_4_clicked()
{
    emit(HomeClicked());
}

void products::on_signOut_5_clicked()
{
    emit(HomeClicked());
}
void products::on_LoadData_clicked()
{
    ui->listView->setModel(P.AfficherListe());
}

void products::on_pushButton_Search_clicked()
{
    QString itemText=ui->lineEdit_SearchCustomer->text();
    if(P.Chercher(itemText))
    {
        ui->tableView->setModel(P.Afficher(itemText));
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Client Not Found.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void products::on_pushButton_Print_clicked()
{
    QStringList list;
    QAbstractItemModel *model = ui->tableView->model();
    QModelIndex index0 = model->index(0,0);
    QModelIndex index1 = model->index(0,1);
    QModelIndex index2 = model->index(0,2);
    QModelIndex index3 = model->index(0,3);
    QModelIndex index4 = model->index(0,4);
    QModelIndex index5 = model->index(0,5);
    QModelIndex index6 = model->index(0,6);
    QModelIndex index7 = model->index(0,7);
    QModelIndex index8 = model->index(0,8);
    QModelIndex index9 = model->index(0,9);
    QModelIndex index10 = model->index(0,10);
    QModelIndex index11 = model->index(0,11);
    QModelIndex index12 = model->index(0,12);

    QPlainTextEdit text;
    text.appendPlainText("ID: "+index0.data().toString()+"");
    text.appendPlainText("First Name: "+index1.data().toString()+"");
    text.appendPlainText("Last Name: "+index2.data().toString()+"");
    text.appendPlainText("Company Name: "+index3.data().toString()+"");
    text.appendPlainText("Phone Number: "+index4.data().toString()+"");
    text.appendPlainText("Email: "+index5.data().toString()+"");
    text.appendPlainText("Website: "+index6.data().toString()+"");
    text.appendPlainText("Street: "+index7.data().toString()+"");
    text.appendPlainText("City: "+index8.data().toString()+"");
    text.appendPlainText("ZipCode: "+index9.data().toString()+"");
    text.appendPlainText("Country: "+index10.data().toString()+"");
    text.appendPlainText("Bank Account Number: "+index11.data().toString()+"");
    text.appendPlainText("Credit Limit: "+index12.data().toString()+"");

    QPrinter printer;
    printer.setPrinterName("Print");
    //printer.setOutputFormat(QPrinter::PdfFormat);
    //printer.setOutputFileName("Information Of Employee "+ui->viewID->text()+"");
    QPrintDialog dlg(&printer,this);
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }
    text.print(&printer);

}

void products::on_pushButton_clicked()
{
    smtp = new Smtp("rh.florallo@gmail.com" , "projetcpp", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->plainTextEdit->toPlainText();

    smtp->sendMail("rh.florallo@gmail.com",ui->lineEdit_Email->text(),ui->lineEdit_Subject->text(),msg);
}








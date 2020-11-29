#include "warehouse.h"
#include "ui_warehouse.h"
#include "depot.h"


warehouse::warehouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warehouse)
{
    ui->setupUi(this);
    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();


    //warehouse list
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    //Place Holder For Add New Warehouse
    ui->lineEdit_IDWarehouseInput->setPlaceholderText(" Enter Warehouse ID");
    ui->lineEdit_TypeOfProductInput->setPlaceholderText(" Enter The Type Of Product");
    ui->lineEdit_NameWarehouseManagerInput->setPlaceholderText(" Enter The Name Of Warehouse Manager");

    //Place Holder For Edit Warehouse
    ui->lineEdit_IDWarehouseInput->setPlaceholderText(" Enter Warehouse ID");
    ui->lineEdit_TypeOfProductInput->setPlaceholderText(" Enter The Type Of Product");
    ui->lineEdit_NameWarehouseManagerInput->setPlaceholderText(" Enter The Name Of Warehouse Manager");

    //Controle de saisie des Inputs de add Warehouse:
    ui->lineEdit_TypeOfProductInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_NameWarehouseManagerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDWarehouseInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    //Controle de saisie des Inputs de Edit Warehouse:
    ui->lineEdit_TypeOfProductInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_NameWarehouseManagerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDWarehouseInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

}

warehouse::~warehouse()
{
    delete ui;
}

void warehouse::showTime()
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

void warehouse::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(viewWarehouse()));
    myMenu.addAction("Edit",  this, SLOT(editWarehouse()));
    myMenu.addAction("Delete", this, SLOT(deleteWarehouse()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void warehouse::deleteWarehouse()
{
    deleteconfirmation D;
    D.setModal(true);
    D.exec();

    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    if(D.getConfirm()==1)
    {
        //supprimer l'objet P de la table projet et on recupére la valeur de retour(query.exec()) dans la variable test
        bool test=DEPOT.Effacer(itemText);

        if(test)//if(test==true)->La requete est executée->QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Deletion WAREHOUSE is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView->setModel(DEPOT.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion WAREHOUSE failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void warehouse::viewWarehouse()
{
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    ui->tableView->setModel(DEPOT.Afficher(itemText));
    ui->stackedWidget->setCurrentIndex(1);
}

void warehouse::editWarehouse()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void warehouse::on_pushButton_AddNewWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void warehouse::on_pushButton_SaveAddWarehouse_clicked()
{
    if(ui->lineEdit_IDWarehouseInput->text().isEmpty())
    {
        ui->lineEdit_IDWarehouseInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_IDWarehouseInput->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_TypeOfProductInput->text().isEmpty())
    {
        ui->lineEdit_TypeOfProductInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_TypeOfProductInput->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_NameWarehouseManagerInput->text().isEmpty())
    {
        ui->lineEdit_NameWarehouseManagerInput->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_NameWarehouseManagerInput->setStyleSheet("border: 1px solid black");
    }




    if((ui->lineEdit_IDWarehouseInput->text().isEmpty())||(ui->lineEdit_TypeOfProductInput->text().isEmpty())||(ui->lineEdit_NameWarehouseManagerInput->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }
    else
    {
        QString warehouseID=ui->lineEdit_IDWarehouseInput->text();
        QString typeOfProduct=ui->lineEdit_TypeOfProductInput->text();
        QString nameOfDepotManager=ui->lineEdit_NameWarehouseManagerInput->text();

depot d(warehouseID,typeOfProduct,nameOfDepotManager);
bool test=d.ajouter();
if(test)//if (test==true)->la requete est executÃ©e->QMessageBox::information
{
QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("Addition of new warehouse is successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

ui->listView->setModel(d.AfficherListe());
ui->stackedWidget->setCurrentIndex(0);
}
else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
{
QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                     QObject::tr("Addition of new warehouse failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
ui->stackedWidget->setCurrentIndex(3);
    }
}
}

void warehouse::on_pushButton_CancelAddWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void warehouse::on_pushButton_SaveEditWarehouse_clicked()
{
    if(ui->lineEdit_IDWarehouseInput_2->text().isEmpty())
    {
        ui->lineEdit_IDWarehouseInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_IDWarehouseInput_2->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_TypeOfProductInput_2->text().isEmpty())
    {
        ui->lineEdit_TypeOfProductInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_TypeOfProductInput_2->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_NameWarehouseManagerInput_2->text().isEmpty())
    {
        ui->lineEdit_NameWarehouseManagerInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_NameWarehouseManagerInput_2->setStyleSheet("border: 1px solid black");
    }





      if  ((ui->lineEdit_IDWarehouseInput_2->text().isEmpty())||(ui->lineEdit_TypeOfProductInput_2->text().isEmpty())||(ui->lineEdit_NameWarehouseManagerInput_2->text().isEmpty()))
       {
          QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
       }
    else
    {
          QString warehouseID=ui->lineEdit_IDWarehouseInput_2->text();
          QString typeOfProduct=ui->lineEdit_TypeOfProductInput_2->text();
          QString nameOfDepotManager=ui->lineEdit_NameWarehouseManagerInput_2->text();

  depot D(warehouseID,typeOfProduct,nameOfDepotManager);
  bool test=D.Editer();
  if(test)//if (test==true)->la requete est executÃ©e->QMessageBox::information
             {
                 QMessageBox::information(nullptr, QObject::tr("Ok"),
                                          QObject::tr("Edit of WAREHOUSE is successful.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);

                 ui->listView->setModel(D.AfficherListe());
             }
             else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
             {
                 QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                       QObject::tr("Edit of WAREHOUSE failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
             }

             ui->stackedWidget->setCurrentIndex(0);
         }
    }

void warehouse::on_pushButton_CancelEditWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void warehouse::on_pushButton_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void warehouse::on_signOut_8_clicked()
{
    emit(HomeClicked());
}

void warehouse::on_signOut_5_clicked()
{
    emit(HomeClicked());
}

void warehouse::on_signOut_6_clicked()
{
    emit(HomeClicked());
}

void warehouse::on_signOut_7_clicked()
{
    emit(HomeClicked());
}

void warehouse::on_LoadData_clicked()
{
    ui->listView->setModel(DEPOT.AfficherListe());
}





void warehouse::on_signOut_1_clicked()
{
    emit(HomeClicked());

}

void warehouse::on_signOut_2_clicked()
{
    emit(HomeClicked());

}

void warehouse::on_signOut_4_clicked()
{
    emit(HomeClicked());

}

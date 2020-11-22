#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //afficher
    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //BILL List
   ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    //ORDEER List
    ui->orderListView->setContextMenuPolicy(Qt::CustomContextMenu);
     connect(ui->orderListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);
    ui->time_2->setText(time_text);
    ui->time_3->setText(time_text);
    ui->time_4->setText(time_text);
    ui->time_5->setText(time_text);
     ui->time_6->setText(time_text);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date_2->setText(datetimetext);
    ui->date_3->setText(datetimetext);
    ui->date_4->setText(datetimetext);
    ui->date_5->setText(datetimetext);
    ui->date_6->setText(datetimetext);
}

void MainWindow::on_billButton_clicked()
{
    ui->listView->setModel(b.afficherList());
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_order_clicked()
{
    //refresh affichage
    order o ;
    ui->orderListView->setModel(o.afficherList());

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_logout_clicked()
{
    close();
}

void MainWindow::on_logout_2_clicked()
{
    close();
}

void MainWindow::on_logOutButton_clicked()
{
    close();
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->orderListView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;



    // Show context menu at handling position
  if(ui->stackedWidget->currentIndex()==2){
    myMenu.addAction("View", this, SLOT(viewBill()));
    myMenu.addAction("Edit",  this, SLOT(editBill()));
    myMenu.addAction("Delete", this, SLOT(deleteBill()));
    myMenu.exec(globalPos);
  }
  else if (ui->stackedWidget->currentIndex()==1) {
      myMenu.addAction("View", this, SLOT(viewOrder()));
      myMenu.addAction("Edit",  this, SLOT(editOrder()));
      myMenu.addAction("Delete", this, SLOT(deleteOrder()));
      myMenu.exec(globalPos);

  }
}

//Bill menu

void MainWindow::viewBill()
{
   int i = ui->listView->currentIndex().data().toInt();
    ui->billinfo->setModel(b.afficher(i));
   ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::editBill()
{

    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::deleteBill()
{
    Delete d;
    QMessageBox msg;

    //take the id of the element to delete

int i = ui->listView->currentIndex().data().toInt();

 d.exec();

if(d.getConfirmDelete()==1)
 { bool test= b.supprimer(i);

    //refresh affichage
    ui->listView->setModel(b.afficherList());

    if(test==true)
        {
        msg.setIcon(QMessageBox::Information);
         msg.setText("bill deleted ");
         msg.exec();
        }

}
else
{
    msg.setIcon(QMessageBox::Critical);
     msg.setText("error ");
     msg.exec();
}

}




void MainWindow::on_cancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_addButton_clicked()
{
      qDebug() << "bouton: « add bill » appuyé";
      qDebug() <<ui->dateEdit->text();
      QMessageBox msg;


        if((ui->shipperPhone->text().length()==0) || (ui->billNumber->text().length()==0) || (ui->customerID->text().length()==0) || (ui->orderID->text().length()==0)|| (ui->shipperName->text().length()==0)  )
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("no empty fields.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

        }
        else
        {
              bill b;
              b.setShipperName (ui->shipperName->text());
            b.setReleaseDate(ui->dateEdit->date());
             b.setBillNumber(ui->billNumber->text());
              b.setOrderID(ui->orderID->text());
             b.setPayMethod(ui->paymentMethod->currentText());
              b.setCustomerID(ui->customerID->text());
              b.setShipperNumber(ui->shipperPhone->text().toInt());
              b.setTotalAmount(ui->doubleSpinBox->text().toFloat());


           bool test= b.ajouter();
           //refresh affichage
             ui->listView->setModel(b.afficherList());


           if(test)
              { qDebug()<<"done";

               msg.setIcon(QMessageBox::Information);
                msg.setText("ajouter dans le tableau");
                   msg.exec();

                    //reintialisation the add interface
                   ui->shipperName->setText("");
                   QDate date = QDate::currentDate();
                   ui->dateEdit->setDate(date);
                   ui->billNumber->setText("");
                   ui->orderID->setText("");
                   ui->paymentMethod->setCurrentIndex(0);
                   ui->customerID->setText("");
                   ui->shipperPhone->setText(0);
                   ui->doubleSpinBox->setValue(0);

           }
           else
             { qDebug()<<"error";
                 msg.setIcon(QMessageBox::Critical);
               msg.setText("error ");
                  msg.exec();
           }




 ui->stackedWidget->setCurrentIndex(2);

        }



}

//Order menu

void MainWindow::viewOrder()
{
   int i = ui->orderListView->currentIndex().data().toInt();
    ui->orderinfo->setModel(o.afficher(i));
   ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::editOrder()
{

    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::deleteOrder()
{
    Delete d;
    QMessageBox msg;

    //take the id of the element to delete

int i = ui->orderListView->currentIndex().data().toInt();

 d.exec();

if(d.getConfirmDelete()==1)
 { bool test= o.supprimer(i);

    //refresh affichage
    ui->orderListView->setModel(o.afficherList());

    if(test==true)
        {
        msg.setIcon(QMessageBox::Information);
         msg.setText("order deleted ");
         msg.exec();
        }

}
else
{
    msg.setIcon(QMessageBox::Critical);
     msg.setText("error ");
     msg.exec();
}

}

void MainWindow::on_addOrder_clicked()
{

   ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_cancelButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addBill_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_back_pressed()
{

   ui->back->show();

    QPropertyAnimation animation(ui->back, "geometry");
    animation.setDuration(10000);
    animation.setStartValue(QRect(0, 0, 100, 30));
    animation.setEndValue(QRect(250, 250, 100, 30));
    animation.start();

}



void MainWindow::on_return_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




int MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    int id = ui->listView->currentIndex().data().toInt();
    ui->billinfo->setModel(b.afficher(id));
   ui->stackedWidget->setCurrentIndex(5);
  int i = index.data().toInt();
  //ui->billinfo->selectRow(find(i));

return i;
}



void MainWindow::on_addButton_3_clicked()
{
    //taking the billnumber selected in the listview
    int id = ui->listView->currentIndex().data().toInt();

    b.setShipperName (ui->shipperName_2->text());
    b.setReleaseDate(ui->dateEdit_2->date());
    b.setBillNumber(ui->billNumber_2->text());
    b.setOrderID(ui->orderID_2->text());
    b.setPayMethod(ui->paymentMethod_2->currentText());
    b.setCustomerID(ui->customerID_3->text());
    b.setShipperNumber(ui->shipperPhone_2->text().toInt());
    b.setTotalAmount(ui->doubleSpinBox_2->text().toFloat());
    //implementing edit function
    bool test =b.edit(id);
    QMessageBox msg ;
    if(test)
       { qDebug()<<"done";

        msg.setIcon(QMessageBox::Information);
         msg.setText("edited succesfully ");
            msg.exec();

             //reintialisation the add interface
            ui->shipperName_2->setText("");
            QDate date = QDate::currentDate();
            ui->dateEdit_2->setDate(date);
            ui->billNumber_2->setText("");
            ui->orderID_2->setText("");
            ui->paymentMethod_2->setCurrentIndex(0);
            ui->customerID_3->setText("");
            ui->shipperPhone_2->setText(0);
            ui->doubleSpinBox_2->setValue(0);

    }
    else
      { qDebug()<<"error";
          msg.setIcon(QMessageBox::Critical);
        msg.setText("error ");
           msg.exec();
    }

    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_cancelButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_return_3_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}

//add order button

void MainWindow::on_addButton_2_clicked()
{
    qDebug() << "bouton: « add order » appuyé";

    QMessageBox msg;


      if((ui->orderNumber->text().length()==0) || (ui->productCode->text().length()==0) || (ui->customerID_2->text().length()==0) || (ui->comments->text().length()==0)|| (ui->discount->text().length()==0)  )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else
      {


            o.setOrderNumber(ui->orderNumber->text());
            o.setProductCode(ui->productCode->text());
            o.setQuantityOrdered(ui->quantity->text().toInt());
            o.setStatus(ui->status->currentText());
            o.setOrderDate(ui->orderDate->date());
            o.setUnitPrice(ui->unitPrice->text().toDouble());
            o.setDiscount(ui->discount->text());
            o.setExtendedPrice(ui->extendedPrice->text().toDouble());
            o.setRequiredDate(ui->requiredDate->date());
            o.setCustomerID(ui->customerID_2->text());
            o.setComments(ui->comments->text());



         bool test= o.ajouter();
         //refresh affichage
           ui->orderListView->setModel(o.afficherList());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("ajouter dans le tableau");
                 msg.exec();

                  //reintialisation the add interface
                 ui->orderNumber->setText("");

                 QDate date = QDate::currentDate();
                 ui->orderDate->setDate(date);
                  ui->requiredDate->setDate(date);

                 ui->productCode->setText("");
                 ui->extendedPrice->setValue(0);
                 ui->status->setCurrentIndex(0);

                 ui->quantity->setValue(0);
                 ui->discount->setText("");
                 ui->comments->setText("");
                 ui->unitPrice->setValue(0);



         }
         else
           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();
         }




ui->stackedWidget->setCurrentIndex(1);
}
}

void MainWindow::on_editButton_clicked()
{
    qDebug() << "bouton: « add order » appuyé";

    QMessageBox msg;
     int id = ui->orderListView->currentIndex().data().toInt();

      if((ui->orderNumber_5->text().length()==0) || (ui->productCode_5->text().length()==0) || (ui->customerID_10->text().length()==0) || (ui->comments_5->text().length()==0)|| (ui->discount_5->text().length()==0)  )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else
      {


            o.setOrderNumber(ui->orderNumber_5->text());
            o.setProductCode(ui->productCode_5->text());
            o.setQuantityOrdered(ui->quantity_5->text().toInt());
            o.setStatus(ui->status_3->currentText());
            o.setOrderDate(ui->orderDate_5->date());
            o.setUnitPrice(ui->unitPrice_5->text().toDouble());
            o.setDiscount(ui->discount_5->text());
            o.setExtendedPrice(ui->extendedPrice_5->text().toDouble());
            o.setRequiredDate(ui->requiredDate_5->date());
            o.setCustomerID(ui->customerID_10->text());
            o.setComments(ui->comments_5->text());



         bool test= o.edit(id);
         //refresh affichage
           ui->orderListView->setModel(o.afficherList());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("edit dans le tableau");
                 msg.exec();

                  //reintialisation the add interface
                 ui->orderNumber->setText("");

                 QDate date = QDate::currentDate();
                 ui->orderDate_5->setDate(date);
                 ui->requiredDate_5->setDate(date);
                 ui->productCode_5->setText("");
                 ui->extendedPrice_5->setValue(0);
                 ui->status_3->setCurrentIndex(0);

                 ui->quantity_5->setValue(0);
                 ui->discount_5->setText("");
                 ui->comments_5->setText("");
                 ui->unitPrice_5->setValue(0);
                 ui->customerID_10->setText("");

         }
         else
           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();
         }




ui->stackedWidget->setCurrentIndex(1);
}
}

void MainWindow::on_cancelButton_10_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_sort_clicked()
{
    ui->listView->setModel(b.afficherOrderedList());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted");
    msg.exec();
}

void MainWindow:: searchBill()
{
  int s=ui->search->text().toInt();
   ui->listView->setModel(b.searchList(s));

}

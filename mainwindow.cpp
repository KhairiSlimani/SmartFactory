#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //affichage de mainwindow
    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);


    //Place Holder
    ui->search->setPlaceholderText("  Enter bill ID...");
    ui->searchLineEdit->setPlaceholderText("  Enter order ID...");

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

    statistique();

    //animation

    animation=new QPropertyAnimation(ui->billButton,"geometry");
    animation->setDuration(5000);
    animation->setStartValue(ui->billButton->geometry());
    animation->setEndValue(ui->order->geometry());
    animation->start();

    animation=new QPropertyAnimation(ui->order,"geometry");
    animation->setDuration(5000);
    animation->setStartValue(ui->order->geometry());
    animation->setEndValue(ui->billButton->geometry());
    animation->start();

    //sound ///

    coinSound=new QSound(":/sounds/coin.wav");

}

/// statistics ///

void MainWindow::statistique()
{
    //pie chart

    QChartView * chartView=new QChartView(o.stat());
    chartView ->setParent(ui->horizontalFrame);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//time function ///////////
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
    ui->time_7->setText(time_text);
    ui->time_8->setText(time_text);
    ui->time_9->setText(time_text);
    ui->time_10->setText(time_text);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date_1->setText(datetimetext);
    ui->date_2->setText(datetimetext);
    ui->date_3->setText(datetimetext);
    ui->date_4->setText(datetimetext);
    ui->date_5->setText(datetimetext);
    ui->date_6->setText(datetimetext);
    ui->date_7->setText(datetimetext);
    ui->date_8->setText(datetimetext);
    ui->date_9->setText(datetimetext);
}

//choose bill button from menu
void MainWindow::on_billButton_clicked()
{

    coinSound->play();

    ////////////////
    ui->listView->setModel(b.afficherList());
    ui->stackedWidget->setCurrentIndex(2);
}
//choose order button from menu
void MainWindow::on_order_clicked()
{
    //refresh affichage
    order o ;
    ui->orderListView->setModel(o.afficherList());
    ui->stackedWidget->setCurrentIndex(1);
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
      myMenu.addAction("sendMail", this, SLOT(sendMail()));
      myMenu.exec(globalPos);

  }
}

//Bill menu

void MainWindow::viewBill()
{
   int i = ui->listView->currentIndex().data().toInt();
    ui->billinfo_2->setModel(b.afficher(i));
   ui->tabWidget_3->setCurrentIndex(2);

}

void MainWindow::editBill()
{
       int i = ui->listView->currentIndex().data().toInt();
      ui->tabWidget_3->setCurrentIndex(3);

      b.editer(i);
      ui->billNumber_2->setText(b.getBillNumber());
      ui->orderID_2->setText(b.getOrderID());
      ui->paymentMethod_2->setCurrentText(b.getPayMethod());
      ui->dateEdit_2->setDate(b.getReleaseDate());
      ui->doubleSpinBox_2->setValue(b.getTotalAmount());
      ui->shipperName_2->setText(b.getShipperName());
      ui->shipperPhone_2->setText( QVariant(b.getShipperNumber()).toString());
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


//when u push add bill button
void MainWindow::on_addBill_clicked()
{
ui->tabWidget_3->setCurrentIndex(1);
}



int MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    int id = ui->listView->currentIndex().data().toInt();
    ui->billinfo_2->setModel(b.afficher(id));
    ui->tabWidget_3->setCurrentIndex(2);
  int i = index.data().toInt();

return i;
}

//add bill///

void MainWindow::on_addBill_2_clicked()
{

    qDebug() << "bouton: « add bill » appuyé";
    //qDebug() <<ui->dateEdit->text();
    QMessageBox msg;
    QIntValidator v(0,100000,this);
    int pos=0;
    QString shipperPhone=ui->shipperPhone->text(),billNumber=ui->billNumber->text(),orderID=ui->orderID->text(),shipperName=ui->shipperName->text();


    QRegularExpression regex("[A-Za-z]+");
    QValidator *validator = new QRegularExpressionValidator(regex, this);


      if((ui->shipperPhone->text().length()==0) || (ui->billNumber->text().length()==0)  || (ui->orderID->text().length()==0)|| (ui->shipperName->text().length()==0) || (ui->doubleSpinBox->value()==0)  )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(shipperPhone,pos)) || !(v.validate(billNumber,pos)) || !(v.validate(orderID,pos))  )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("shipperPhone,billNumber & orderID are numbers .");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
      else if (ui->shipperName->text().size()>20 || ui->shipperName->text().size()<5 )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("the size of the shipper Name is between 5 and 20 !");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
       else if (!(validator->validate(shipperName,pos)) )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("shipperName contain only letters !");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();

      }
      else
      {
            bill b;
            b.setShipperName (ui->shipperName->text());
            b.setReleaseDate(ui->dateEdit->date());
            b.setBillNumber(ui->billNumber->text());
            b.setOrderID(ui->orderID->text());
            b.setPayMethod(ui->paymentMethod->currentText());
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
                 ui->shipperPhone->setText(0);
                 ui->doubleSpinBox->setValue(0);

         }
         else
           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();
         }



ui->tabWidget_3->setCurrentIndex(0);

      }

}


//edit button bill

void MainWindow::on_addButton_3_clicked()
{


    qDebug() << "bouton: « edit bill » appuyé";

    QMessageBox msg;
    QIntValidator v(0,100000,this);
    int pos=0;
    QString shipperPhone=ui->shipperPhone_2->text(),billNumber=ui->billNumber_2->text(),orderID=ui->orderID_2->text(),shipperName=ui->shipperName_2->text();


    QRegularExpression regex("[A-Za-z]+");
    QValidator *validator = new QRegularExpressionValidator(regex, this);


      if((ui->shipperPhone_2->text().length()==0) || (ui->billNumber_2->text().length()==0)  || (ui->orderID_2->text().length()==0)|| (ui->shipperName_2->text().length()==0) || (ui->doubleSpinBox_2->value()==0)  )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(shipperPhone,pos)) || !(v.validate(billNumber,pos)) || !(v.validate(orderID,pos))  )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("shipperPhone,billNumber & orderID are numbers .");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
      else if (ui->shipperName_2->text().size()>20 || ui->shipperName_2->text().size()<5 )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("the size of the shipper Name is between 5 and 20 !");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
       else if (!(validator->validate(shipperName,pos)) )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("shipperName contain only letters !");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();

      }
    else
    {
    //taking the billnumber selected in the listview
    int id = ui->listView->currentIndex().data().toInt();

    b.setShipperName (ui->shipperName_2->text());
    b.setReleaseDate(ui->dateEdit_2->date());
    b.setBillNumber(ui->billNumber_2->text());
    b.setOrderID(ui->orderID_2->text());
    b.setPayMethod(ui->paymentMethod_2->currentText());
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
            ui->shipperPhone_2->setText(0);
            ui->doubleSpinBox_2->setValue(0);

    }
    else
      { qDebug()<<"error";
          msg.setIcon(QMessageBox::Critical);
        msg.setText("error ");
           msg.exec();
    }

      ui->tabWidget_3->setCurrentIndex(0);
    }

}

//sort bills
void MainWindow::on_sort_clicked()
{
    ui->listView->setModel(b.afficherOrderedList());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted");
    msg.exec();
}

//search bills


void MainWindow::on_search_textChanged(const QString &arg1)
{
    int s =arg1.toInt();
    ui->listView->setModel(b.searchList(s));
   if (arg1=="")
        ui->listView->setModel(b.afficherList());

}

//Order menu///

void MainWindow::viewOrder()
{
   int i = ui->orderListView->currentIndex().data().toInt();
    ui->orderinfo->setModel(o.afficher(i));
    ui->tabWidget_2->setCurrentIndex(2);

}

void MainWindow::editOrder()
{

     ui->tabWidget_2->setCurrentIndex(3);
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

void MainWindow::sendMail()
{

    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);

}


void MainWindow::on_addOrder_clicked()
{
  ui->tabWidget_2->setCurrentIndex(1);

}


//add order button////

void MainWindow::on_addButton_2_clicked()
{
    qDebug() << "bouton: « add order » appuyé";

    QMessageBox msg;
    QIntValidator v(0,100000,this);
    int pos=0;
    QString orderNumber=ui->orderNumber->text(),productCode=ui->productCode->text(),customerID=ui->customerID_2->text(),discount=ui->discount->text();

      if((ui->orderNumber->text().length()==0) || (ui->productCode->text().length()==0) || (ui->customerID_2->text().length()==0) || (ui->comments->text().length()==0)|| (ui->discount->text().length()==0)|| (ui->quantity->value()==0) ||  (ui->unitPrice->value()==0) ||  (ui->extendedPrice->value()==0) )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(orderNumber,pos)) || !(v.validate(productCode,pos)) || !(v.validate(customerID,pos)) || !(v.validate(discount,pos)) )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("orderNumber,productCode,customerID & discount are numbers .");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
      else if (ui->comments->text().size()>20 || ui->comments->text().size()<5 )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("the size of a comment is between 5 and 20 !");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
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



ui->tabWidget_2->setCurrentIndex(0);
}
}

//edit order
void MainWindow::on_edit_clicked()
{
    qDebug() << "bouton: « edit order » appuyé";
    QIntValidator v(0,100000,this);
    int pos=0;
    QString orderNumber=ui->orderNumber_10->text(),productCode=ui->productCode_10->text(),customerID=ui->customerID_10->text(),discount=ui->discount_10->text();
    QMessageBox msg;
     int id = ui->orderListView->currentIndex().data().toInt();

      if((ui->orderNumber_10->text().length()==0) || (ui->productCode_10->text().length()==0) || (ui->customerID_10->text().length()==0) || (ui->comments_10->text().length()==0)|| (ui->discount_10->text().length()==0) || (ui->quantity_10->value()==0) || (ui->unitPrice_10->value()==0) || (ui->extendedPrice_10->value()==0))
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(orderNumber,pos)) || !(v.validate(productCode,pos)) || !(v.validate(customerID,pos)) || !(v.validate(discount,pos)) )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("orderNumber,productCode,customerID & discount are numbers!");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }

      else if (ui->comments_10->text().size()>20 || ui->comments_10->text().size()<5 )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("the size of a comment is between 5 and 20 !");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }

      else
      {


            o.setOrderNumber(ui->orderNumber_10->text());
            o.setProductCode(ui->productCode_10->text());
            o.setQuantityOrdered(ui->quantity_10->text().toInt());
            o.setStatus(ui->status_10->currentText());
            o.setOrderDate(ui->orderDate_10->date());
            o.setUnitPrice(ui->unitPrice_10->text().toDouble());
            o.setDiscount(ui->discount_10->text());
            o.setExtendedPrice(ui->extendedPrice_10->text().toDouble());
            o.setRequiredDate(ui->requiredDate_10->date());
            o.setCustomerID(ui->customerID_10->text());
            o.setComments(ui->comments_10->text());



         bool test= o.edit(id);
         //refresh affichage
           ui->orderListView->setModel(o.afficherList());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("edit dans le tableau");
                 msg.exec();

                  //reintialisation the add interface
                 ui->orderNumber_10->setText("");

                 QDate date = QDate::currentDate();
                 ui->orderDate_10->setDate(date);
                 ui->requiredDate_10->setDate(date);
                 ui->productCode_10->setText("");
                 ui->extendedPrice_10->setValue(0);
                 ui->status_10->setCurrentIndex(0);

                 ui->quantity_10->setValue(0);
                 ui->discount_10->setText("");
                 ui->comments_10->setText("");
                 ui->unitPrice_10->setValue(0);
                 ui->customerID_10->setText("");

         }
         else
           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();
         }




  ui->tabWidget_2->setCurrentIndex(0);
}
}

//buttons


void MainWindow::on_return_9_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_logOutButton_21_clicked()
{
    close();
}

void MainWindow::on_logOutButton_19_clicked()
{
    close();
}

void MainWindow::on_cancelButton_2_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}




void MainWindow::on_cancelButton_22_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_return_11_clicked()
{
    ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_cancelButton_23_clicked()
{
   ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_cancelButton_3_clicked()
{
    ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_logOutButton_20_clicked()
{
    close();
}

void MainWindow::on_logOutButton_22_clicked()
{
    close();
}

void MainWindow::on_cancelButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_options_clicked()
{
    statistique();
    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(1);

}

//mail sending

void MainWindow::on_sendMailButton_clicked()
{
   smtp = new Smtp("recovery.mary2000@gmail.com" , "meriam.123", "smtp.gmail.com",465);
   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

   smtp->sendMail("recovery.mary2000@gmail.com","meriam.mhedhbi@esprit.tn",ui->subjectLineEdit->text(),ui->plainTextEdit->toPlainText());



   // reintialisation
   ui->subjectLineEdit->setText("");
   ui->plainTextEdit->setPlainText("");


   QMessageBox msg ;
   msg.setIcon(QMessageBox::Information);
    msg.setText("Mail sent");
       msg.exec();

       ui->stackedWidget->setCurrentIndex(1);
}




void MainWindow::on_cancelButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



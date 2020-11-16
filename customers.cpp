#include "customers.h"
#include "ui_customers.h"
#include "deleteconfirmation.h"
#include "client.h"
#include <QMessageBox>
#include <QListWidget>
#include "connection.h"


Customers::Customers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Customers)
{
    ui->setupUi(this);



    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //Customer's list
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    //Place Holder for search Customer By ID
    ui->lineEdit_SearchCustomer->setPlaceholderText("  Search...");

    //place Holder of add Customer Inteface
    ui->lineEdit_IDCustomerInput->setPlaceholderText(" Enter ID");
    ui->lineEdit_FirstNameCustomerInput->setPlaceholderText("Enter First Name");
    ui->lineEdit_LastNameCustomerInput->setPlaceholderText("Enter Last Name");
    ui->lineEdit_CompanyCustomerInput->setPlaceholderText("Enter Company Name");
    ui->lineEdit_PhoneNumberCustomerInput->setPlaceholderText("Enter Phone Number");
    ui->lineEdit_EmailCustomerInput->setPlaceholderText("Enter Email");
    ui->lineEdit_WebsiteCustomerInput->setPlaceholderText("Enter Website");
    ui->lineEdit_AdressCustomerInput->setPlaceholderText("Enter Adress");
    ui->lineEdit_CityCustomerInput->setPlaceholderText("Enter City");
    ui->lineEdit_ZipCodeCustomerInput->setPlaceholderText("Enter ZipCode");
    ui->lineEdit_CountryCustomerInput->setPlaceholderText("Enter Country");
    ui->lineEdit_BankAccountCustomerInput->setPlaceholderText("Enter Bank Account Number");
    ui->lineEdit_CreditLimitCustomerInput->setPlaceholderText("Enter Credit Limit");

    //place Holder of edit Customer Interface
    ui->lineEdit_IDCustomerEdit->setPlaceholderText(" Enter ID");
    ui->lineEdit_FirstNameCustomerEdit->setPlaceholderText("Enter First Name");
    ui->lineEdit_LastNameCustomerEdit->setPlaceholderText("Enter Last Name");
    ui->lineEdit_CompanyCustomerEdit->setPlaceholderText("Enter Company Name");
    ui->lineEdit_PhoneNumberCustomerEdit->setPlaceholderText("Enter Phone Number");
    ui->lineEdit_EmailCustomerEdit->setPlaceholderText("Enter Email");
    ui->lineEdit_WebsiteCustomerEdit->setPlaceholderText("Enter Website");
    ui->lineEdit_AdressCustomerEdit->setPlaceholderText("Enter Adress");
    ui->lineEdit_CityCustomerEdit->setPlaceholderText("Enter City");
    ui->lineEdit_ZipCodeCustomerEdit->setPlaceholderText("Enter ZipCode");
    ui->lineEdit_CountryCustomerEdit->setPlaceholderText("Enter Country");
    ui->lineEdit_BankAccountCustomerEdit->setPlaceholderText("Enter Bank Account Number");
    ui->lineEdit_CreditLimitCustomerEdit->setPlaceholderText("Enter Credit Limit");

    //controle de saisie du searchCustomer
    ui->lineEdit_SearchCustomer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    //controle de saisie des Inputs de AddCustomer
    ui->lineEdit_FirstNameCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));//input must be an alphabet uppercase or lowercase
    ui->lineEdit_LastNameCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_CityCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_CountryCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_PhoneNumberCustomerInput->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));//input must be from 7 to 15 dgits
    ui->lineEdit_BankAccountCustomerInput->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));//leading digit must be 1 to 9 (prevents leading zeroes)
    ui->lineEdit_CreditLimitCustomerInput->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));
    ui->lineEdit_IDCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));//input must be a code ascii character
    ui->lineEdit_CompanyCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_WebsiteCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_AdressCustomerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_ZipCodeCustomerInput->setValidator(new QRegExpValidator(QRegExp("[0-9]{6,12}")));


    //controle des Inputs de EditCustomer
    ui->lineEdit_FirstNameCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));//input must be an alphabet uppercase or lowercase
    ui->lineEdit_LastNameCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_CityCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_CountryCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_PhoneNumberCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));//input must be from 7 to 15 dgits
    ui->lineEdit_BankAccountCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));//leading digit must be 1 to 9 (prevents leading zeroes)
    ui->lineEdit_CreditLimitCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));
    ui->lineEdit_IDCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));//input must be a code ascii character
    ui->lineEdit_CompanyCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_WebsiteCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_AdressCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_ZipCodeCustomerEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{6,12}")));

    animation=new QPropertyAnimation(ui->label_2,"geometry");
    animation->setDuration(10000);
    animation->setLoopCount(4);
    animation->setStartValue(ui->label_2->geometry());
    animation->setEndValue(QRect(210,50,291,41));
    animation->start();

}

Customers::~Customers()
{
    delete ui;
}

void Customers::showTime()
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

void Customers::showContextMenu(const QPoint &pos)
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

void Customers::DeleteItem()
{
        deleteconfirmation D;
        D.setModal(true);
        D.exec();

        QModelIndex index = ui->listView->currentIndex();
        QString itemText = index.data(Qt::DisplayRole).toString();
        if(D.getConfirm()==1)
         {
        QSqlQuery query;
        bool test=Ctmp.Effacer(itemText);

        if(test)
        {
         QMessageBox::warning(this, tr("Client Edited"),tr("Done."), QMessageBox::Ok);
         QSqlQueryModel *modal=new QSqlQueryModel();
         QSqlQuery query=Ctmp.LoadData();
         query.exec();
         modal->setQuery(query);
         ui->listView->setModel(modal);
         qDebug()<<(modal->rowCount());
        }

        }
 }


void Customers::ViewItem()
{
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QSqlQuery query;
    query=Ctmp.Afficher(itemText);

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_CustomerIDOutPut->setText(query.value(0).toString());
            ui->lineEdit_FirstNameCustomerOutPut->setText(query.value(1).toString());
            ui->lineEdit_LastNameCustomerOutPut->setText(query.value(2).toString());
            ui->lineEdit_CompanyCustomerOutPut->setText(query.value(3).toString());
            ui->lineEdit_PhoneNumberCustomerOutPut->setText(query.value(4).toString());
            ui->lineEdit_EmailCustomerOutPut->setText(query.value(5).toString());
            ui->lineEdit_WebsiteCustomerOutPut->setText(query.value(6).toString());
            ui->lineEdit_AdressCustomerOutPut->setText(query.value(7).toString());
            ui->lineEdit_CityCustomerOutPut->setText(query.value(8).toString());
            ui->lineEdit_ZipCodeCustomerOutPut->setText(query.value(9).toString());
            ui->lineEdit_CountryCustomerOutPut->setText(query.value(10).toString());
            ui->lineEdit_BankAccountCustomerOutPut->setText(query.value(11).toString());
            ui->lineEdit_CreditLimitCustomerOutPut->setText(query.value(12).toString());

        }
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void Customers::EditItem()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Customers::SendEmailToItem()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void Customers::on_pushButton_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Customers::on_pushButton_CancelEditCustomer_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Customers::on_pushButton_CancelAddCustomer_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Customers::on_pushButton_return2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Customers::on_pushButton_AddNewCustomer_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Customers::on_pushButton_SaveAddCustomer_clicked()
{
        if(ui->lineEdit_IDCustomerInput->text().isEmpty())
            {
                ui->lineEdit_IDCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_IDCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_FirstNameCustomerInput->text().isEmpty())
            {
                ui->lineEdit_FirstNameCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
               ui->lineEdit_FirstNameCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_LastNameCustomerInput->text().isEmpty())
            {
                ui->lineEdit_LastNameCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_LastNameCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_CompanyCustomerInput->text().isEmpty())
            {
                ui->lineEdit_CompanyCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_CompanyCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_PhoneNumberCustomerInput->text().isEmpty())
            {
                ui->lineEdit_PhoneNumberCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_PhoneNumberCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_EmailCustomerInput->text().isEmpty())
            {
                ui->lineEdit_EmailCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                 ui->lineEdit_EmailCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_WebsiteCustomerInput->text().isEmpty())
            {
                ui->lineEdit_WebsiteCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                 ui->lineEdit_WebsiteCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_AdressCustomerInput->text().isEmpty())
            {
                ui->lineEdit_AdressCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                 ui->lineEdit_AdressCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_CityCustomerInput->text().isEmpty())
            {
                ui->lineEdit_CityCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
              ui->lineEdit_CityCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_ZipCodeCustomerInput->text().isEmpty())
            {
                ui->lineEdit_ZipCodeCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_ZipCodeCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_CountryCustomerInput->text().isEmpty())
            {
                ui->lineEdit_CountryCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_CountryCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_BankAccountCustomerInput->text().isEmpty())
            {
                ui->lineEdit_BankAccountCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_BankAccountCustomerInput->setStyleSheet("border: 1px solid black");
            }

            if(ui->lineEdit_CreditLimitCustomerInput->text().isEmpty())
            {
                ui->lineEdit_CreditLimitCustomerInput->setStyleSheet("border: 1px solid red");
            }
            else
            {
                ui->lineEdit_CreditLimitCustomerInput->setStyleSheet("border: 1px solid black");
            }


            if((ui->lineEdit_IDCustomerInput->text().isEmpty())||(ui->lineEdit_FirstNameCustomerInput->text().isEmpty())||(ui->lineEdit_LastNameCustomerInput->text().isEmpty())||(ui->lineEdit_CompanyCustomerInput->text().isEmpty())||(ui->lineEdit_PhoneNumberCustomerInput->text().isEmpty())||(ui->lineEdit_ZipCodeCustomerInput->text().isEmpty())||(ui->lineEdit_CountryCustomerInput->text().isEmpty())||(ui->lineEdit_BankAccountCustomerInput->text().isEmpty())||(ui->lineEdit_CreditLimitCustomerInput->text().isEmpty())||(ui->lineEdit_EmailCustomerInput->text().isEmpty())||(ui->lineEdit_CityCustomerInput->text().isEmpty()))
            {
                QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);

            }
            else
            {

            QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);ui->lineEdit_EmailCustomerInput->setValidator(new QRegularExpressionValidator(rx, this));
            if(!ui->lineEdit_EmailCustomerInput->hasAcceptableInput())
            {
                    ui->lineEdit_EmailCustomerInput->setStyleSheet("QLineEdit { color: red;}");
                    QMessageBox::warning(this, tr("Email verification"),tr("Email format is incorrect."), QMessageBox::Ok);
            }
            else
             {
        QString id=ui->lineEdit_IDCustomerInput->text();
        QString FirstName=ui->lineEdit_FirstNameCustomerInput->text();
        QString LastName=ui->lineEdit_LastNameCustomerInput->text();
        QString CompanyName=ui->lineEdit_CompanyCustomerInput->text();
        int PhoneNumber=ui->lineEdit_PhoneNumberCustomerInput->text().toInt();
        QString Email=ui->lineEdit_EmailCustomerInput->text();
        QString Website=ui->lineEdit_WebsiteCustomerInput->text();
        QString Street=ui->lineEdit_AdressCustomerInput->text();
        QString City=ui->lineEdit_CityCustomerInput->text();
        int ZipCode=ui->lineEdit_ZipCodeCustomerInput->text().toInt();
        QString Country=ui->lineEdit_CountryCustomerInput->text();
        int BankAccountNumber=ui->lineEdit_BankAccountCustomerInput->text().toInt();
        int CreditLimit=ui->lineEdit_CreditLimitCustomerInput->text().toInt();

        client c(id,FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);
        bool test=c.ajouter();
        if(test)
        {
            QMessageBox::warning(this, tr("Add New Client"),
                                         tr("Client Added.\n"
                                            "Click Cancel To Exit"), QMessageBox::Ok);

           QSqlQueryModel *modal=new QSqlQueryModel();
           QSqlQuery query=Ctmp.LoadData();
           query.exec();
           modal->setQuery(query);
           ui->listView->setModel(modal);
           qDebug()<<(modal->rowCount());

           ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::warning(this, tr("Add New Client"),
                                         tr("Client Not Added.\n"
                                            "ID Already Exists"), QMessageBox::Ok);
            ui->stackedWidget->setCurrentIndex(0);
        }

            }
            }
}

void Customers::on_pushButton_SaveEditCustomer_clicked()
{




}


void Customers::on_signOut_1_clicked()
{
    emit(HomeClicked());
}

void Customers::on_signOut_2_clicked()
{
    emit(HomeClicked());
}

void Customers::on_signOut_3_clicked()
{
    emit(HomeClicked());
}

void Customers::on_signOut_4_clicked()
{
    emit(HomeClicked());
}

void Customers::on_signOut_5_clicked()
{
    emit(HomeClicked());
}

void Customers::on_LoadData_clicked()
{
     QSqlQueryModel *modal=new QSqlQueryModel();
     QSqlQuery query=Ctmp.LoadData();
     query.exec();
     modal->setQuery(query);
     ui->listView->setModel(modal);
     qDebug()<<(modal->rowCount());
}

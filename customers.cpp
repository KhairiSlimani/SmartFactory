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
    ui->listView->setModel(C.AfficherListe());

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

    //Recuperation de l'indice du curseur
    QModelIndex index = ui->listView->currentIndex();
    //Recuperation de l'id du client sur lequel mon curseur est positionné
    QString itemText = index.data(Qt::DisplayRole).toString();

    if(D.getConfirm()==1)
    {
        //supprimer l'objet C de la table client et on recupére la valeur de retour(query.exec()) dans la variable test
        bool test=C.Effacer(itemText);

        if(test)//if(test==true)->La requete est executée->QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Deletion of client is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView->setModel(C.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion of Client failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}


void Customers::ViewItem()
{
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    ui->tableView->setModel(C.Afficher(itemText));
    ui->tableView->resizeColumnsToContents();
    ui->stackedWidget->setCurrentIndex(1);
}

void Customers::EditItem()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Customers::SendEmailToItem()
{
    QStringList list;
    QAbstractItemModel *model = ui->tableView->model();
    QModelIndex index0 = model->index(0,5);
    ui->lineEdit_Email->setText(index0.data().toString());
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

        QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
        ui->lineEdit_EmailCustomerInput->setValidator(new QRegularExpressionValidator(rx, this));
        if(!ui->lineEdit_EmailCustomerInput->hasAcceptableInput())
        {
            ui->lineEdit_EmailCustomerInput->setStyleSheet("QLineEdit { color: red;}");
            QMessageBox::warning(this, tr("Email verification"),tr("Email format is incorrect."), QMessageBox::Ok);
        }
        else
        {
            //récuperations des informations saisies dans les lineEdits
            QString id=ui->lineEdit_IDCustomerInput->text();
            QString FirstName=ui->lineEdit_FirstNameCustomerInput->text();
            QString LastName=ui->lineEdit_LastNameCustomerInput->text();
            QString CompanyName=ui->lineEdit_CompanyCustomerInput->text();
            int PhoneNumber=ui->lineEdit_PhoneNumberCustomerInput->text().toInt();//Conversion de la chaine saisie en un entier car PhoneNumber est de type int
            QString Email=ui->lineEdit_EmailCustomerInput->text();
            QString Website=ui->lineEdit_WebsiteCustomerInput->text();
            QString Street=ui->lineEdit_AdressCustomerInput->text();
            QString City=ui->lineEdit_CityCustomerInput->text();
            int ZipCode=ui->lineEdit_ZipCodeCustomerInput->text().toInt();
            QString Country=ui->lineEdit_CountryCustomerInput->text();
            int BankAccountNumber=ui->lineEdit_BankAccountCustomerInput->text().toInt();//Conversion de la chaine saisie en un entier car BankAccountNumber est de type int
            float CreditLimit=ui->lineEdit_CreditLimitCustomerInput->text().toFloat();//Conversion de la chaine saisie en un reel car CreditLimit est de type float


            //Instantiation d'un objet de type client en utilisant les informations saisies dans l'interface graphique
            client c(id,FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);

            //Inserer l'objet C dans la table client et recuperer la valeur de retour de query.exec() dans la variable test.
            bool test=c.ajouter();

            if(test)//if (test==true)->la requete est executée->QMessageBox::information
            {
                QMessageBox::information(nullptr, QObject::tr("Ok"),
                                         QObject::tr("Addition of new Client is successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

                ui->listView->setModel(C.AfficherListe());
                ui->stackedWidget->setCurrentIndex(0);
            }
            else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
            {
                QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                      QObject::tr("Addition of new Client failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                ui->stackedWidget->setCurrentIndex(0);
            }

        }
    }
}

void Customers::on_pushButton_SaveEditCustomer_clicked()
{
    if(ui->lineEdit_IDCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_IDCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_IDCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_FirstNameCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_FirstNameCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_FirstNameCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_LastNameCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_LastNameCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_LastNameCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_CompanyCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CompanyCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_CompanyCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_PhoneNumberCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_PhoneNumberCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_PhoneNumberCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_EmailCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_EmailCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_EmailCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_WebsiteCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_WebsiteCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_WebsiteCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_AdressCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_AdressCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_AdressCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_CityCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CityCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_CityCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_ZipCodeCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_ZipCodeCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_ZipCodeCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_CountryCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CountryCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_CountryCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_BankAccountCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_BankAccountCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_BankAccountCustomerEdit->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_CreditLimitCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CreditLimitCustomerEdit->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_CreditLimitCustomerEdit->setStyleSheet("border: 1px solid black");
    }


    if((ui->lineEdit_IDCustomerEdit->text().isEmpty())||(ui->lineEdit_FirstNameCustomerEdit->text().isEmpty())||(ui->lineEdit_LastNameCustomerEdit->text().isEmpty())||(ui->lineEdit_CompanyCustomerEdit->text().isEmpty())||(ui->lineEdit_PhoneNumberCustomerEdit->text().isEmpty())||(ui->lineEdit_ZipCodeCustomerEdit->text().isEmpty())||(ui->lineEdit_CountryCustomerEdit->text().isEmpty())||(ui->lineEdit_BankAccountCustomerEdit->text().isEmpty())||(ui->lineEdit_CreditLimitCustomerEdit->text().isEmpty())||(ui->lineEdit_EmailCustomerEdit->text().isEmpty())||(ui->lineEdit_CityCustomerEdit->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);

    }
    else
    {

        QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
        ui->lineEdit_EmailCustomerEdit->setValidator(new QRegularExpressionValidator(rx, this));
        if(!ui->lineEdit_EmailCustomerEdit->hasAcceptableInput())
        {
            ui->lineEdit_EmailCustomerEdit->setStyleSheet("QLineEdit { color: red;}");
            QMessageBox::warning(this, tr("Email verification"),
                                 tr("Email format is incorrect."), QMessageBox::Ok);
        }
        else
        {
            //récuperations des informations saisies dans les lineEdits
            QString id=ui->lineEdit_IDCustomerEdit->text();
            QString FirstName=ui->lineEdit_FirstNameCustomerEdit->text();
            QString LastName=ui->lineEdit_LastNameCustomerEdit->text();
            QString CompanyName=ui->lineEdit_CompanyCustomerEdit->text();
            int PhoneNumber=ui->lineEdit_PhoneNumberCustomerEdit->text().toInt();//Conversion de la chaine saisie en un entier car PhoneNumber est de type int
            QString Email=ui->lineEdit_EmailCustomerEdit->text();
            QString Website=ui->lineEdit_WebsiteCustomerEdit->text();
            QString Street=ui->lineEdit_AdressCustomerEdit->text();
            QString City=ui->lineEdit_CityCustomerEdit->text();
            int ZipCode=ui->lineEdit_ZipCodeCustomerEdit->text().toInt();
            QString Country=ui->lineEdit_CountryCustomerEdit->text();
            int BankAccountNumber=ui->lineEdit_BankAccountCustomerEdit->text().toInt();//Conversion de la chaine saisie en un entier car BankAccountNumber est de type int
            float CreditLimit=ui->lineEdit_CreditLimitCustomerEdit->text().toFloat();//Conversion de la chaine saisie en un reel car CreditLimit est de type float


            //Instantiation d'un objet de type client en utilisant les informations saisies dans l'interface graphique
            client C(id,FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);

            //Inserer l'objet C dans la table client et recuperer la valeur de retour de query.exec() dans la variable test.
            bool test=C.Editer();

            if(test)//if (test==true)->la requete est executée->QMessageBox::information
            {
                QMessageBox::information(nullptr, QObject::tr("Ok"),
                                         QObject::tr("Edit of Client is successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

                ui->listView->setModel(C.AfficherListe());
            }
            else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
            {
                QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                      QObject::tr("Edit of Client failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }

            ui->stackedWidget->setCurrentIndex(0);
        }
    }

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
    ui->listView->setModel(C.AfficherListe());
}

void Customers::on_pushButton_Search_clicked()
{
    QString itemText=ui->lineEdit_SearchCustomer->text();
    if(C.Chercher(itemText))
    {
        ui->tableView->setModel(C.Afficher(itemText));
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Client Not Found.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




void Customers::on_pushButton_Print_clicked()
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

void Customers::on_pushButton_clicked()
{
    smtp = new Smtp("rh.florallo@gmail.com" , "projetcpp", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->plainTextEdit->toPlainText();

    smtp->sendMail("rh.florallo@gmail.com",mail,ui->lineEdit_Email->text(),msg);
}

void Customers::on_pushButton_SortCustomers_clicked()
{
    ui->listView->setModel(C.Trier());
}

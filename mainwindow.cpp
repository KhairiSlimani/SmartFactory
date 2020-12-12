#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadData();
    //debut travail de yasmine
    ui->listView_3->setModel(C.AfficherListe());
    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //Customer's list
    ui->listView_3->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView_3, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuCustomers(QPoint)));

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

    ui->listView_4->setModel(P.AfficherListe());


    //Project's list
    ui->listView_4->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView_4, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuProject(QPoint)));



    //Place Holder For Add New Project
    ui->lineEdit_IDProjectInput->setPlaceholderText(" Enter ID");
    ui->lineEdit_NameProjectInput->setPlaceholderText(" Enter Name");
    ui->lineEdit_DescriptionProjectInput->setPlaceholderText(" Enter Description");
    ui->lineEdit_BudgetProjectInput->setPlaceholderText(" Enter Budget");
    ui->lineEdit_CustomerIDProjectInput->setPlaceholderText(" Enter Customer ID");

    //Place Holder For Edit Project
    ui->lineEdit_IDProjectEdit->setPlaceholderText(" Enter ID");
    ui->lineEdit_NameProjectEdit->setPlaceholderText(" Enter Name");
    ui->lineEdit_DescriptionProjectEdit->setPlaceholderText(" Enter Description");
    ui->lineEdit_BudgetProjectEdit->setPlaceholderText(" Enter Budget");
    ui->lineEdit_CustomerIDProjectEdit->setPlaceholderText(" Enter Customer ID");

    //Controle de saisie des Inputs de add project:
    ui->lineEdit_NameProjectInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_DescriptionProjectInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDProjectInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_CustomerIDProjectInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_BudgetProjectInput->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));

    //Controle de saisie des Inputs de Edit project:
    ui->lineEdit_NameProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_DescriptionProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_CustomerIDProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_BudgetProjectEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));

    animation=new QPropertyAnimation(ui->label_134,"geometry");
    animation->setDuration(10000);
    animation->setLoopCount(4);
    animation->setStartValue(ui->label_134->geometry());
    animation->setEndValue(QRect(210,50,251,51));
    animation->start();

    //khairi
    //Place Holder
    ui->idLineEdit->setPlaceholderText("  Enter ID");
    ui->passwordLineEdit->setPlaceholderText("  Enter Password");
    ui->idLineEdit_2->setPlaceholderText("  Enter ID");
    ui->passwordLineEdit_2->setPlaceholderText("  Enter Password");

    ui->idLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->idLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->passwordLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    ui->newPasswordLineEdit->setPlaceholderText("  New Password");
    ui->confirmPasswordLineEdit->setPlaceholderText("  Confirm Password");

    ui->lineEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setReadOnly(true);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);

    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
    connect(&client, SIGNAL(newMessage(QString,QString)),
            this, SLOT(appendMessage(QString,QString)));
    connect(&client, SIGNAL(newParticipant(QString)),
            this, SLOT(newParticipant(QString)));
    connect(&client, SIGNAL(participantLeft(QString)),
            this, SLOT(participantLeft(QString)));

    myNickName = client.nickName();
    newParticipant(myNickName);
    tableFormat.setBorder(0);
    QTimer::singleShot(10 * 1000, this, SLOT(showInformation()));

    //Animation
    animation=new QPropertyAnimation(ui->loginTitle,"geometry");
    animation->setDuration(2500);
    animation->setStartValue(ui->loginTitle->geometry());
    animation->setEndValue(QRect(340,90,291,61));
    animation->start();


    //Employees List
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    //Place Holder
    ui->searchLineEdit->setPlaceholderText("  Enter Employee ID...");
    ui->idLineEdit_3->setPlaceholderText("  Enter ID");
    ui->firstNameLineEdit->setPlaceholderText("  Enter First Name");
    ui->lastNameLineEdit->setPlaceholderText("  Enter Last Name");
    ui->phoneNumberLineEdit->setPlaceholderText("  Enter Phone Number");
    ui->adressLineEdit->setPlaceholderText("  Enter Adress");
    ui->salaryLineEdit->setPlaceholderText("  Enter Salary");
    ui->emailLineEdit->setPlaceholderText("  Enter Email");
    ui->subjectLineEdit->setPlaceholderText("Subject");

    //Controle De Saisie
    ui->idLineEdit_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->firstNameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lastNameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->phoneNumberLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->adressLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->salaryLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->idLineEdit_4->setValidator(new QRegExpValidator(QRegExp("[0-9]{7}")));
    ui->firstNameLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lastNameLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->phoneNumberLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->adressLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->salaryLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]")));

    ///meriam's work ///


    //affichage de mainwindow
    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);


    //Place Holder
    ui->search->setPlaceholderText("  Enter bill ID...");
    ui->searchLineEdit->setPlaceholderText("  Enter order ID...");


    //BILL List
   ui->billListView->setContextMenuPolicy(Qt::CustomContextMenu);
   connect(ui->billListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuBill(QPoint)));

    //ORDEER List
    ui->orderListView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->orderListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuOrder(QPoint)));

    statistique();


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
    ui->time_7->setText(time_text);
    ui->time_8->setText(time_text);
    ui->time_9->setText(time_text);
    ui->time_10->setText(time_text);
    ui->time_21->setText(time_text);
    ui->time_22->setText(time_text);
    ui->time_23->setText(time_text);
    ui->time_24->setText(time_text);
    ui->time_25->setText(time_text);
    ui->time2->setText(time_text);
    ui->time3->setText(time_text);
    ui->time4->setText(time_text);
    ui->time_11->setText(time_text);
    ui->time_12->setText(time_text);
    ui->time_13->setText(time_text);
    ui->time_14->setText(time_text);
    ui->time_15->setText(time_text);
    ui->time_16->setText(time_text);
    ui->time_17->setText(time_text);
    ui->time_18->setText(time_text);
    ui->time_19->setText(time_text);


    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date_2->setText(datetimetext);
    ui->date_3->setText(datetimetext);
    ui->date_4->setText(datetimetext);
    ui->date_5->setText(datetimetext);
    ui->date_6->setText(datetimetext);
    ui->date_7->setText(datetimetext);
    ui->date_19->setText(datetimetext);
    ui->date_20->setText(datetimetext);
    ui->date_21->setText(datetimetext);
    ui->date_22->setText(datetimetext);
    ui->date_23->setText(datetimetext);
    ui->date_24->setText(datetimetext);
    ui->date2->setText(datetimetext);
    ui->date3->setText(datetimetext);
    ui->date4->setText(datetimetext);
    ui->date_1->setText(datetimetext);
    ui->date_10->setText(datetimetext);
    ui->date_11->setText(datetimetext);
    ui->date_12->setText(datetimetext);
    ui->date_13->setText(datetimetext);
    ui->date_14->setText(datetimetext);
    ui->date_15->setText(datetimetext);
    ui->date_16->setText(datetimetext);
    ui->date_17->setText(datetimetext);



}

void MainWindow::showContextMenuCustomers(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView_3->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(ViewCustomer()));
    myMenu.addAction("Edit",  this, SLOT(EditCustomer()));
    myMenu.addAction("Delete", this, SLOT(DeleteCustomer()));
    myMenu.addAction("Send Email", this, SLOT(SendEmailToCustomer()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::DeleteCustomer()
{
    DeleteConfirmation D;
    D.setModal(true);
    D.exec();

    //Recuperation de l'indice du curseur
    QModelIndex index = ui->listView_3->currentIndex();
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
            ui->listView_3->setModel(C.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion of Client failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}


void MainWindow::ViewCustomer()
{
    QModelIndex index = ui->listView_3->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    view=C.Lire(itemText);

    while(view.next())
    {
          ui->lineEdit_IDCustomerOutput->setText(view.value(0).toString());
          ui->lineEdit_FirstNameCustomerOutput->setText(view.value(1).toString());
          ui->lineEdit_LastNameCustomerOutput->setText(view.value(2).toString());
          ui->lineEdit_CompanyNameCustomerOutput->setText(view.value(3).toString());
          ui->lineEdit_PhoneCustomerOutput->setText(view.value(4).toString());
          ui->lineEdit_EmailCustomerOutput->setText(view.value(5).toString());
          ui->lineEdit_WebsiteCustomerOutput->setText(view.value(6).toString());
          ui->lineEdit_StreetCustomerOutput->setText(view.value(7).toString());
          ui->lineEdit_CityCustomerOutput->setText(view.value(8).toString());
          ui->lineEdit_ZipCodeCustomerOutput->setText(view.value(9).toString());
          ui->lineEdit_CountryCustomerOutput->setText(view.value(10).toString());
          ui->lineEdit_BankAccountNumberOutput->setText(view.value(11).toString());
          ui->lineEdit_CreditLimitCustomerOutput->setText(view.value(12).toString());
    }

    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::EditCustomer()
{

    QModelIndex index = ui->listView_3->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    view=C.Lire(itemText);

    while(view.next())
    {
          ui->lineEdit_IDCustomerEdit->setText(view.value(0).toString());
          ui->lineEdit_FirstNameCustomerEdit->setText(view.value(1).toString());
          ui->lineEdit_LastNameCustomerEdit->setText(view.value(2).toString());
          ui->lineEdit_CompanyCustomerEdit->setText(view.value(3).toString());
          ui->lineEdit_PhoneNumberCustomerEdit->setText(view.value(4).toString());
          ui->lineEdit_EmailCustomerEdit->setText(view.value(5).toString());
          ui->lineEdit_WebsiteCustomerEdit->setText(view.value(6).toString());
          ui->lineEdit_AdressCustomerEdit->setText(view.value(7).toString());
          ui->lineEdit_CityCustomerEdit->setText(view.value(8).toString());
          ui->lineEdit_ZipCodeCustomerEdit->setText(view.value(9).toString());
          ui->lineEdit_CountryCustomerEdit->setText(view.value(10).toString());
          ui->lineEdit_BankAccountCustomerEdit->setText(view.value(11).toString());
          ui->lineEdit_CreditLimitCustomerEdit->setText(view.value(12).toString());
    }
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::SendEmailToCustomer()
{
    QModelIndex index = ui->listView_3->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    view=C.Lire(itemText);

    while(view.next())
    {
          ui->lineEdit_Email->setText(view.value(5).toString());
    }

    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_signInButton_clicked()
{
    bool test=true;
    bool test2;

    if(ui->idLineEdit->text().isEmpty())
    {
        ui->idLineEdit->setStyleSheet("border: 2px solid red; border-radius:20px;");
        test=false;
    }

    if(ui->passwordLineEdit->text().isEmpty())
    {
        ui->passwordLineEdit->setStyleSheet("border: 2px solid red; border-radius:20px;");
        test=false;
    }

    if(test == false)
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The Required Fields Marked In Red."), QMessageBox::Ok);
    }
    else
    {
        QString id = ui->idLineEdit->text();

        Profile P;
        test2=P.search(id);
        qDebug() << test2;
        if(test2 == true)
        {
            QSqlQuery view = P.read(id);
            if(view.value(1).toString() == ui->passwordLineEdit->text())
            {
                if(view.value(2).toString() == "HR Agent")
                {
                    ui->access1Button->setText("Employees");
                }
                else if(view.value(2).toString() == "Depot Employee")
                {
                    ui->access1Button->setText("Depots");
                }
                else if(view.value(2).toString() == "Project and Services Employee")
                {
                    ui->access1Button->setText("Project and Services");
                }
                else if(view.value(2).toString() == "Laboratory Employee")
                {
                    ui->access1Button->setText("Laboratories");
                }
                else if(view.value(2).toString() == "Stock Employee")
                {
                    ui->access1Button->setText("Stocks");
                }
                if(view.value(2).toString() == "HR Agent")
                {
                    ui->access1Button->setText("Employees");
                }
                else if(view.value(2).toString() == "Depot Employee")
                {
                    ui->access1Button->setText("Depots");
                }
                else if(view.value(2).toString() == "Project and Services Employee")
                {
                    ui->access1Button->setText("Project and Services");
                }
                else if(view.value(2).toString() == "Laboratory Employee")
                {
                    ui->access1Button->setText("Laboratories");
                }
                else if(view.value(2).toString() == "CEO")
                {
                    ui->access1Button->setText("Employees");
                }

                 ui->viewID->setText(view.value(0).toString());
                 ui->viewPassword->setText(view.value(1).toString());
                 ui->viewJobTitle->setText(view.value(2).toString());
                 ui->stackedWidget->setCurrentIndex(2);
                 ui->idLineEdit->clear();
                 ui->passwordLineEdit->clear();
            }
            else
            {
                QMessageBox::warning(this, tr("Warning"),tr("The password is wrong!"), QMessageBox::Ok);
            }

        }
        else if(test2 == false)
        {
            qDebug() << test2;
            QMessageBox::warning(this, tr("Warning"),tr("Account Not Found!"), QMessageBox::Ok);
        }

    }

}

void MainWindow::on_goToSignUpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_SignUpButton_clicked()
{
    bool test=true;

    QString id;
    QString password;
    QString jobTitle;

     if(ui->idLineEdit_2->text().isEmpty())
     {
         ui->idLineEdit_2->setStyleSheet("border: 2px solid red;");
         test=false;
     }

     if(ui->passwordLineEdit_2->text().isEmpty())
     {
         ui->passwordLineEdit_2->setStyleSheet("border: 2px solid red;");
         test=false;
     }

     if(test)
     {
         id = ui->idLineEdit_2->text();
         password = ui->passwordLineEdit_2->text();
         jobTitle = ui->jobTitleBox->currentText();

         Profile P(id,password,jobTitle);

         bool test_2 = P.searchIDSignUp(id);
         if(test_2)
         {
             bool test_3=P.searchJobTitleSignUp(id,jobTitle);
             if(test_3)
             {
                 bool test_4=P.search(id);
                 if(test_4)
                 {
                     QMessageBox :: warning(nullptr, QObject :: tr("Create Account"),
                                                QObject::tr("Error: This Account is Already Exist :("),QMessageBox::Cancel);

                 }
                 else
                 {
                     bool test_5 = P.create();
                     if(test_5)
                     {
                         QMessageBox :: information(nullptr, QObject :: tr("Create Account"),
                                                    QObject::tr("Account Created :)"),QMessageBox::Cancel);
                         ui->stackedWidget->setCurrentIndex(0);
                         ui->idLineEdit_2->clear();
                         ui->passwordLineEdit_2->clear();

                     }
                     else
                     {
                         QMessageBox :: warning(nullptr, QObject :: tr("Create Account"),
                                                    QObject::tr("Error: Something Is Wrong :("),QMessageBox::Cancel);

                     }
                 }

             }
             else
             {
                 QMessageBox :: warning(nullptr, QObject :: tr("Create Account"),
                                            QObject::tr("Error: Your Job Title Is Wrong :("),QMessageBox::Cancel);

             }

         }
         else
         {
             QMessageBox :: warning(nullptr, QObject :: tr("Create Account"),
                                        QObject::tr("Error: This ID Is Not Exist :("),QMessageBox::Cancel);

         }

     }
     else
     {
          QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
     }

}

void MainWindow::on_goToSignInButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_changeInformationButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_deleteAccountButton_clicked()
{

    QString info = ui->viewID->text();
    Profile P;
    bool test=P.Delete(info);

    if(test)
    {
         QMessageBox::information(this, tr("Delete Account"),tr("Account Deleted"), QMessageBox::Ok);
         ui->stackedWidget->setCurrentIndex(0);
    }

}

void MainWindow::on_logOutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_logOutButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_access1Button_clicked()
{
    if(ui->viewJobTitle->text() == "HR Agent")
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(ui->viewJobTitle->text() == "Depot Employee")
    {
        //ui->stackedWidget->setCurrentIndex("7ot lehna l'widget mte3k");
    }
    else if(ui->viewJobTitle->text() == "Project and Services Employee")
    {
        ui->stackedWidget->setCurrentIndex(11);

        //animation

        animation1=new QPropertyAnimation(ui->billButton,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->billButton->geometry());
        animation1->setEndValue(ui->orderButton->geometry());
        animation1->start();

        animation1=new QPropertyAnimation(ui->orderButton,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->orderButton->geometry());
        animation1->setEndValue(ui->billButton->geometry());
        animation1->start();
    }
    else if(ui->viewJobTitle->text() == "Laboratory Employee")
    {
        //ui->stackedWidget->setCurrentIndex("7ot lehna r9am l'widget mte3k");
    }
    else if(ui->viewJobTitle->text() == "Stock Employee")
    {
        //ui->stackedWidget->setCurrentIndex("7ot lehna r9am l'widget mte3k");
    }
    else if(ui->viewJobTitle->text() == "CEO")
    {
        ui->stackedWidget->setCurrentIndex(4);
    }


}

void MainWindow::on_access2Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_cancelButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->newPasswordLineEdit->clear();
    ui->confirmPasswordLineEdit->clear();
}

void MainWindow::on_saveButton_clicked()
{
    bool test=true;
    QString id;
    QString jobTitle;
    QString newPassword;
    QString confirmPassword;

    if(ui->newPasswordLineEdit->text().isEmpty())
    {
        ui->newPasswordLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->confirmPasswordLineEdit->text().isEmpty())
    {
        ui->confirmPasswordLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(test)
    {
        id = ui->viewID->text();
        jobTitle = ui->viewJobTitle->text();
        newPassword = ui->newPasswordLineEdit->text();
        confirmPassword = ui->confirmPasswordLineEdit->text();

        if(newPassword == confirmPassword)
        {
            Profile P(id,newPassword,jobTitle);

            bool test2 = P.Update();
            if(test2)
            {
                QMessageBox :: information(nullptr, QObject :: tr("Change Password"),
                                           QObject::tr("Password Updated :)"),QMessageBox::Cancel);

                QSqlQuery view = P.read(id);
                ui->viewID->setText(view.value(0).toString());
                ui->viewPassword->setText(view.value(1).toString());
                ui->viewJobTitle->setText(view.value(2).toString());
                ui->stackedWidget->setCurrentIndex(2);
                ui->newPasswordLineEdit->clear();
                ui->confirmPasswordLineEdit->clear();
            }
            else
            {
                QMessageBox :: warning(nullptr, QObject :: tr("Change password"),
                                           QObject::tr("Error: Password Not Updated :("),QMessageBox::Cancel);

            }

        }
        else
        {
            QMessageBox :: warning(nullptr, QObject :: tr("Change password"),
                                       QObject::tr("Error: Those passwords didn't match. Try again. :("),QMessageBox::Cancel);

        }


    }
    else
    {
         QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }

}

void MainWindow::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(ui->textEdit->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = ui->textEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}

void MainWindow::returnPressed()
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty())
        return;

    if (text.startsWith(QChar('/'))) {
        QColor color = ui->textEdit->textColor();
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(tr("! Unknown command: %1")
                         .arg(text.left(text.indexOf(' '))));
        ui->textEdit->setTextColor(color);
    } else {
        client.sendMessage(text);
        appendMessage(myNickName, text);
    }

    ui->lineEdit->clear();
}

void MainWindow::newParticipant(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QColor color = ui->textEdit->textColor();
    ui->textEdit->setTextColor(Qt::gray);
    ui->textEdit->append(tr("* %1 has joined").arg(nick));
    ui->textEdit->setTextColor(color);
    ui->listWidget->addItem(nick);
}

void MainWindow::participantLeft(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QList<QListWidgetItem *> items = ui->listWidget->findItems(nick,
                                                           Qt::MatchExactly);
    if (items.isEmpty())
        return;

    delete items.at(0);
    QColor color = ui->textEdit->textColor();
    ui->textEdit->setTextColor(Qt::gray);
    ui->textEdit->append(tr("* %1 has left").arg(nick));
    ui->textEdit->setTextColor(color);
}

void MainWindow::showInformation()
{
    if (ui->listWidget->count() == 1) {
        QMessageBox::information(this, tr("Chat"), tr("start chatting!"));
    }
}


void MainWindow::loadData()
{
    Employee E;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=E.loadData();
    ui->listView->setModel(model);

}


void MainWindow::on_addEmployeeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_sortButton_clicked()
{
    Employee E;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=E.sort();
    ui->listView->setModel(model);
}

void MainWindow::on_addButton_clicked()
{
    bool test=true;
    int phoneNumber;
    float salary;
    QString id;
    QString firstName;
    QString lastName;
    QString adresse;
    QString birthDate;
    QString hireDate;
    QString jobTitle;
    QString sex="";
    QString email;


    if(ui->idLineEdit_3->text().isEmpty())
    {
        ui->idLineEdit_3->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->phoneNumberLineEdit->text().isEmpty())
    {
        ui->phoneNumberLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->salaryLineEdit->text().isEmpty())
    {
        ui->salaryLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->firstNameLineEdit->text().isEmpty())
    {
        ui->firstNameLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lastNameLineEdit->text().isEmpty())
    {
        ui->lastNameLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->adressLineEdit->text().isEmpty())
    {
        ui->adressLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->emailLineEdit->text().isEmpty())
    {
        ui->emailLineEdit->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->maleRadioButton->isChecked())
    {
        sex="male";
    }

    if(ui->femaleRadioButton->isChecked())
    {
        sex="female";
    }

    if(sex == "")
    {
        ui->maleRadioButton->setStyleSheet("border: 2px solid red;");
        ui->femaleRadioButton->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(test)
    {
        Employee EE;
        bool testID = EE.searchID(ui->idLineEdit_3->text());

        if(testID == false)
        {
            phoneNumber = ui->phoneNumberLineEdit->text().toInt();
            salary = ui->salaryLineEdit->text().toFloat();
            id = ui->idLineEdit_3->text();
            firstName = ui->firstNameLineEdit->text();
            lastName = ui->lastNameLineEdit->text();
            adresse = ui->adressLineEdit->text();
            birthDate = ui->birthDateEdit->text();
            hireDate = ui->hireDateEdit->text();
            email = ui->emailLineEdit->text();
            jobTitle = ui->jobTitleBox_2->currentText();

            Employee E(phoneNumber,salary,id,firstName,lastName,sex,adresse,birthDate,hireDate,jobTitle,email);

            bool test2 = E.create();
            if(test2)
            {
                QMessageBox :: information(nullptr, QObject :: tr("Add Employee"),
                                           QObject::tr("Employee Added"),QMessageBox::Cancel);

                ui->stackedWidget->setCurrentIndex(4);
                ui->idLineEdit_3->clear();
                ui->firstNameLineEdit->clear();
                ui->lastNameLineEdit->clear();
                ui->adressLineEdit->clear();
                ui->phoneNumberLineEdit->clear();
                ui->salaryLineEdit->clear();
                ui->emailLineEdit->clear();
            }
            else
            {
                QMessageBox :: warning(nullptr, QObject :: tr("Add Employee"),
                                           QObject::tr("Error,Employee Not Added :("),QMessageBox::Cancel);

            }

        }
        else
        {
            QMessageBox::warning(this, tr("Warning"),tr("This ID is already exist!"), QMessageBox::Ok);
            ui->idLineEdit_3->setStyleSheet("border: 2px solid red;");
        }

    }
    else
    {
         QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }

}

void MainWindow::on_cancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    loadData();
    ui->idLineEdit_3->clear();
    ui->firstNameLineEdit->clear();
    ui->lastNameLineEdit->clear();
    ui->adressLineEdit->clear();
    ui->phoneNumberLineEdit->clear();
    ui->salaryLineEdit->clear();
    ui->emailLineEdit->clear();

}

void MainWindow::on_saveButton_2_clicked()
{
    bool test=true;
    int phoneNumber;
    float salary;
    QString id;
    QString firstName;
    QString lastName;
    QString adresse;
    QString birthDate;
    QString hireDate;
    QString jobTitle;
    QString sex;
    QString email;

    if(ui->idLineEdit_4->text().isEmpty())
    {
        ui->idLineEdit_4->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->phoneNumberLineEdit_2->text().isEmpty())
    {
        ui->phoneNumberLineEdit_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->salaryLineEdit_2->text().isEmpty())
    {
        ui->salaryLineEdit_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->firstNameLineEdit_2->text().isEmpty())
    {
        ui->firstNameLineEdit_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lastNameLineEdit_2->text().isEmpty())
    {
        ui->lastNameLineEdit_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->adressLineEdit_2->text().isEmpty())
    {
        ui->adressLineEdit_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->emailLineEdit_2->text().isEmpty())
    {
        ui->emailLineEdit_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->maleRadioButton_2->isChecked())
    {
        sex="male";
    }

    if(ui->femaleRadioButton_2->isChecked())
    {
        sex="female";
    }

    if(test)
    {
        phoneNumber = ui->phoneNumberLineEdit_2->text().toInt();
        salary = ui->salaryLineEdit_2->text().toFloat();
        id = ui->idLineEdit_4->text();
        firstName = ui->firstNameLineEdit_2->text();
        lastName = ui->lastNameLineEdit_2->text();
        adresse = ui->adressLineEdit_2->text();
        birthDate = ui->birthDateEdit_2->text();
        hireDate = ui->hireDateEdit_2->text();
        jobTitle = ui->jobTitleBox_3->currentText();
        email = ui->emailLineEdit_2->text();


        Employee E(phoneNumber,salary,id,firstName,lastName,sex,adresse,birthDate,hireDate,jobTitle,email);

        bool test2 = E.Update();
        if(test2)
        {
            QMessageBox :: information(nullptr, QObject :: tr("Update Employee"),
                                       QObject::tr("Employee Updated"),QMessageBox::Cancel);

            ui->idLineEdit_4->clear();
            ui->firstNameLineEdit_2->clear();
            ui->lastNameLineEdit_2->clear();
            ui->adressLineEdit_2->clear();
            ui->phoneNumberLineEdit_2->clear();
            ui->salaryLineEdit_2->clear();
            ui->emailLineEdit_2->clear();


        }
        else
        {
            QMessageBox :: warning(nullptr, QObject :: tr("Update Employee"),
                                       QObject::tr("Error,Employee Not Updated :("),QMessageBox::Cancel);

        }

    }
    else
    {
         QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }

}

void MainWindow::on_cancelButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    loadData();
    ui->idLineEdit_4->clear();
    ui->firstNameLineEdit_2->clear();
    ui->lastNameLineEdit_2->clear();
    ui->adressLineEdit_2->clear();
    ui->phoneNumberLineEdit_2->clear();
    ui->salaryLineEdit_2->clear();
    ui->emailLineEdit_2->clear();

}

void MainWindow::on_printButton_clicked()
{
    QPlainTextEdit text;
    text.setStyleSheet("QPlainTextEdit{color: #ffff00; background-color: #303030;");
    QTextDocument *doc = text.document();
    QFont font = doc->defaultFont();
    font.setBold(true);
    font.setFamily("Arial");
    font.setPixelSize(20);
    doc->setDefaultFont(font);
    text.appendPlainText("                                        Florallo Company");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("Print Time:"+ui->date->text()+"");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("Employee information:");
    text.appendPlainText("");
    text.appendPlainText("ID: "+ui->viewID_2->text()+"");
    text.appendPlainText("First Name: "+ui->viewFirstName->text()+"");
    text.appendPlainText("Last Name: "+ui->viewLastName->text()+"");
    text.appendPlainText("Birth Date: "+ui->viewBirthDate->text()+"");
    text.appendPlainText("Sex: "+ui->viewSex->text()+"");
    text.appendPlainText("Email: "+ui->viewEmail->text()+"");
    text.appendPlainText("Address: "+ui->viewAdress->text()+"");
    text.appendPlainText("Phone Number: "+ui->viewPhoneNumber->text()+"");
    text.appendPlainText("Salary: "+ui->viewSalary->text()+"");
    text.appendPlainText("Hire Date: "+ui->viewHireDate->text()+"");
    text.appendPlainText("Job Title: "+ui->viewJobTitle_2->text()+"");

    QPrinter printer;
    printer.setPrinterName("Print");
    QPrintDialog dlg(&printer,this);
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }
    text.print(&printer);

}

void MainWindow::on_returnButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::sendEmailToEmployee()
{
    QModelIndex index = ui->listView->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Employee E;
    view=E.read(info);

    mail=view.value(8).toString();

    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_sendMailButton_clicked()
{
    smtp = new Smtp("human.resources.florallo@gmail.com" , "khairiisthebest7", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->plainTextEdit->toPlainText();

    smtp->sendMail("human.resources.florallo@gmail.com",mail,ui->subjectLineEdit->text(),msg);

    //QMessageBox :: information(nullptr, QObject :: tr("Send Mail"),
                               //QObject::tr("Mail Sent"),QMessageBox::Cancel);

}

void MainWindow::on_cancelButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->subjectLineEdit->clear();
    ui->plainTextEdit->clear();

}


void MainWindow::on_profileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profileButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profileButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profileButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profileButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_searchLineEdit_textChanged(const QString &arg1)
{
    Employee E;
    QString info =arg1;
    QSortFilterProxyModel *proxy = new QSortFilterProxyModel;
    if(info!="")
    {
        proxy->setSourceModel(E.search(info));
        ui->listView->setModel(proxy);
    }
    else
    {
        loadData();
    }
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->listView->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(viewEmployee()));
    myMenu.addAction("Edit",  this, SLOT(editEmployee()));
    myMenu.addAction("Delete", this, SLOT(deleteEmployee()));
    myMenu.addAction("Send Email", this, SLOT(sendEmailToEmployee()));

    myMenu.exec(globalPos);
}

void MainWindow::deleteEmployee()
{

    QModelIndex index = ui->listView->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();

    Employee E;
    bool test=E.Delete(info);

    if(test)
    {
         loadData();
    }

}

void MainWindow::viewEmployee()
{
    QModelIndex index = ui->listView->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Employee E;
    view=E.read(info);

          ui->viewID_2->setText(view.value(0).toString());
          ui->viewFirstName->setText(view.value(1).toString());
          ui->viewLastName->setText(view.value(2).toString());
          ui->viewBirthDate->setText(view.value(5).toString());
          ui->viewSex->setText(view.value(3).toString());
          ui->viewAdress->setText(view.value(4).toString());
          ui->viewPhoneNumber->setText(view.value(9).toString());
          ui->viewSalary->setText(view.value(10).toString());
          ui->viewHireDate->setText(view.value(6).toString());
          ui->viewJobTitle_2->setText(view.value(7).toString());
          ui->viewEmail->setText(view.value(8).toString());


    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::editEmployee()
{
    QModelIndex index = ui->listView->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Employee E;
    view=E.read(info);

          ui->idLineEdit_4->setText(view.value(0).toString());
          ui->firstNameLineEdit_2->setText(view.value(1).toString());
          ui->lastNameLineEdit_2->setText(view.value(2).toString());
          ui->adressLineEdit_2->setText(view.value(4).toString());
          ui->phoneNumberLineEdit_2->setText(view.value(9).toString());
          ui->salaryLineEdit_2->setText(view.value(10).toString());
          ui->emailLineEdit_2->setText(view.value(8).toString());
          if(view.value(3).toString()=="male")
          {
              ui->maleRadioButton_2->setChecked(true);
          }
          else
          {
              ui->femaleRadioButton_2->setChecked(true);
          }


    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_profileButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_returnButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_returnButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_profileButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_SaveAddCustomer_clicked()
{
    if(ui->lineEdit_IDCustomerInput->text().isEmpty())
    {
        ui->lineEdit_IDCustomerInput->setStyleSheet("border: 2px solid red;"
                                                    "padding: 1px;"
                                                    "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_IDCustomerInput->setStyleSheet("border: 2px solid black;"
                                                    "padding: 1px;"
                                                    "border-radius: 10px;");
    }

    if(ui->lineEdit_FirstNameCustomerInput->text().isEmpty())
    {
        ui->lineEdit_FirstNameCustomerInput->setStyleSheet("border: 2px solid red;"
                                                           "padding: 1px;"
                                                           "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_FirstNameCustomerInput->setStyleSheet("border: 2px solid black;"
                                                           "padding: 1px;"
                                                           "border-radius: 10px;");
    }

    if(ui->lineEdit_LastNameCustomerInput->text().isEmpty())
    {
        ui->lineEdit_LastNameCustomerInput->setStyleSheet("border: 2px solid red;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_LastNameCustomerInput->setStyleSheet("border: 2px solid black;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }

    if(ui->lineEdit_CompanyCustomerInput->text().isEmpty())
    {
        ui->lineEdit_CompanyCustomerInput->setStyleSheet("border: 2px solid red;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CompanyCustomerInput->setStyleSheet("border: 2px solid black;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }

    if(ui->lineEdit_PhoneNumberCustomerInput->text().isEmpty())
    {
        ui->lineEdit_PhoneNumberCustomerInput->setStyleSheet("border: 2px solid red;"
                                                             "padding: 1px;"
                                                             "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_PhoneNumberCustomerInput->setStyleSheet("border: 2px solid black;"
                                                             "padding: 1px;"
                                                             "border-radius: 10px;");
    }

    if(ui->lineEdit_EmailCustomerInput->text().isEmpty())
    {
        ui->lineEdit_EmailCustomerInput->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_EmailCustomerInput->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }

    if(ui->lineEdit_WebsiteCustomerInput->text().isEmpty())
    {
        ui->lineEdit_WebsiteCustomerInput->setStyleSheet("border: 2px solid red;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_WebsiteCustomerInput->setStyleSheet("border: 2px solid black;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }

    if(ui->lineEdit_AdressCustomerInput->text().isEmpty())
    {
        ui->lineEdit_AdressCustomerInput->setStyleSheet("border: 2px solid red;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_AdressCustomerInput->setStyleSheet("border: 2px solid black;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }

    if(ui->lineEdit_CityCustomerInput->text().isEmpty())
    {
        ui->lineEdit_CityCustomerInput->setStyleSheet("border: 2px solid red;"
                                                      "padding: 1px;"
                                                      "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CityCustomerInput->setStyleSheet("border: 2px solid black;"
                                                      "padding: 1px;"
                                                      "border-radius: 10px;");
    }

    if(ui->lineEdit_ZipCodeCustomerInput->text().isEmpty())
    {
        ui->lineEdit_ZipCodeCustomerInput->setStyleSheet("border: 2px solid red;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_ZipCodeCustomerInput->setStyleSheet("border: 2px solid black;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }

    if(ui->lineEdit_CountryCustomerInput->text().isEmpty())
    {
        ui->lineEdit_CountryCustomerInput->setStyleSheet("border: 2px solid red;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CountryCustomerInput->setStyleSheet("border: 2px solid black;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }

    if(ui->lineEdit_BankAccountCustomerInput->text().isEmpty())
    {
        ui->lineEdit_BankAccountCustomerInput->setStyleSheet("border: 2px solid red;"
                                                             "padding: 1px;"
                                                             "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_BankAccountCustomerInput->setStyleSheet("border: 2px solid black;"
                                                             "padding: 1px;"
                                                             "border-radius: 10px;");
    }

    if(ui->lineEdit_CreditLimitCustomerInput->text().isEmpty())
    {
        ui->lineEdit_CreditLimitCustomerInput->setStyleSheet("border: 2px solid red;"
                                                             "padding: 1px;"
                                                             "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CreditLimitCustomerInput->setStyleSheet("border: 2px solid black;"
                                                             "padding: 1px;"
                                                             "border-radius: 10px;");
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
            Customer c(id,FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);

            //Inserer l'objet C dans la table client et recuperer la valeur de retour de query.exec() dans la variable test.
            bool test=c.ajouter();

            if(test)//if (test==true)->la requete est executée->QMessageBox::information
            {
                QMessageBox::information(nullptr, QObject::tr("Ok"),
                                         QObject::tr("Addition of new Client is successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

                ui->listView_3->setModel(C.AfficherListe());
            }
            else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
            {
                QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                      QObject::tr("Addition of new Client failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
              ui->stackedWidget->setCurrentIndex(12);
        }
    }
}


void MainWindow::on_pushButton_SaveEditCustomer_clicked()
{
    if(ui->lineEdit_IDCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_IDCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                   "padding: 1px;"
                                                   "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_IDCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;"
                                                   "border-radius: 10px;");
    }

    if(ui->lineEdit_FirstNameCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_FirstNameCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_FirstNameCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }

    if(ui->lineEdit_LastNameCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_LastNameCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_LastNameCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }

    if(ui->lineEdit_CompanyCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CompanyCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CompanyCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }

    if(ui->lineEdit_PhoneNumberCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_PhoneNumberCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_PhoneNumberCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }

    if(ui->lineEdit_EmailCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_EmailCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                      "padding: 1px;"
                                                      "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_EmailCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                      "padding: 1px;"
                                                      "border-radius: 10px;");
    }

    if(ui->lineEdit_WebsiteCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_WebsiteCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_WebsiteCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }

    if(ui->lineEdit_AdressCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_AdressCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_AdressCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }

    if(ui->lineEdit_CityCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CityCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                     "padding: 1px;"
                                                     "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CityCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                     "padding: 1px;"
                                                     "border-radius: 10px;");
    }

    if(ui->lineEdit_ZipCodeCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_ZipCodeCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_ZipCodeCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }

    if(ui->lineEdit_CountryCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CountryCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CountryCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }

    if(ui->lineEdit_BankAccountCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_BankAccountCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_BankAccountCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }

    if(ui->lineEdit_CreditLimitCustomerEdit->text().isEmpty())
    {
        ui->lineEdit_CreditLimitCustomerEdit->setStyleSheet("border: 2px solid red;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CreditLimitCustomerEdit->setStyleSheet("border: 2px solid black;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
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
            Customer C(id,FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);

            //Inserer l'objet C dans la table client et recuperer la valeur de retour de query.exec() dans la variable test.
            bool test=C.Editer();

            if(test)//if (test==true)->la requete est executée->QMessageBox::information
            {
                QMessageBox::information(nullptr, QObject::tr("Ok"),
                                         QObject::tr("Edit of Client is successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

                ui->listView_3->setModel(C.AfficherListe());
            }
            else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
            {
                QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                      QObject::tr("Edit of Client failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }

            ui->stackedWidget->setCurrentIndex(12);
        }
    }
}

void MainWindow::on_pushButton_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_CancelEditCustomer_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_CancelAddCustomer_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_return2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_signOut_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Print_clicked()
{

    QStringList list;

    QPlainTextEdit text;
    text.setStyleSheet("QPlainTextEdit{color: #ffff00; background-color: #303030;");
    QTextDocument *doc = text.document();
    QFont font = doc->defaultFont();
    font.setBold(true);
    font.setFamily("Arial");
    font.setPixelSize(20);
    doc->setDefaultFont(font);
    text.appendPlainText("                                              Date: "+ui->date->text()+"");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("Information of Customer:");
    text.appendPlainText("");
    text.appendPlainText("ID:  "+ui->lineEdit_IDCustomerOutput->text()+"");
    text.appendPlainText("First Name:  "+ui->lineEdit_FirstNameCustomerOutput->text()+"");
    text.appendPlainText("Last Name:  "+ui->lineEdit_LastNameCustomerOutput->text()+"");
    text.appendPlainText("Company Name:  "+ui->lineEdit_CompanyNameCustomerOutput->text()+"");
    text.appendPlainText("Phone Number:  "+ui->lineEdit_PhoneCustomerOutput->text()+"");
    text.appendPlainText("Email:  "+ui->lineEdit_EmailCustomerOutput->text()+"");
    text.appendPlainText("Website:  "+ui->lineEdit_WebsiteCustomerOutput->text()+"");
    text.appendPlainText("Street:  "+ui->lineEdit_StreetCustomerOutput->text()+"");
    text.appendPlainText("City:  "+ui->lineEdit_CityCustomerOutput->text()+"");
    text.appendPlainText("ZipCode:  "+ui->lineEdit_ZipCodeCustomerOutput->text()+"");
    text.appendPlainText("Country:  "+ui->lineEdit_CountryCustomerOutput->text()+"");
    text.appendPlainText("Bank Account Number:  "+ui->lineEdit_BankAccountNumberOutput->text()+"");
    text.appendPlainText("Credit Limit:  "+ui->lineEdit_CreditLimitCustomerOutput->text()+"");

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
    text.show();
}

void MainWindow::on_pushButton_Send_clicked()
{
    smtp = new Smtp("p.florallo@gmail.com","nesrine123","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    msg=ui->plainTextEdit->toPlainText();
    smtp->sendMail("p.florallo@gmail.com",ui->lineEdit_Email->text(),ui->lineEdit_Subject->text(),msg);
}

void MainWindow::on_pushButton_SortCustomers_clicked()
{
    ui->listView_3->setModel(C.Trier());

    QMessageBox::information(nullptr, QObject::tr("Ok"),
                             QObject::tr("Sort of list of clients successful.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_lineEdit_SearchCustomer_textChanged(const QString &arg1)
{
    QString information =arg1;
    ui->listView_3->setModel(C.chercher(information));
    if(ui->lineEdit_SearchCustomer->text()=="")
    {
        ui->listView_3->setModel(C.AfficherListe());
    }
}

void MainWindow::on_CustomersButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_AddNewCustomer_clicked()
{
   ui->stackedWidget->setCurrentIndex(15);
   ui->lineEdit_IDCustomerInput->clear();
   ui->lineEdit_FirstNameCustomerInput->clear();
   ui->lineEdit_LastNameCustomerInput->clear();
   ui->lineEdit_CompanyCustomerInput->clear();
   ui->lineEdit_PhoneNumberCustomerInput->clear();
   ui->lineEdit_EmailCustomerInput->clear();
   ui->lineEdit_WebsiteCustomerInput->clear();
   ui->lineEdit_AdressCustomerInput->clear();
   ui->lineEdit_CityCustomerInput->clear();
   ui->lineEdit_ZipCodeCustomerInput->clear();
   ui->lineEdit_CountryCustomerInput->clear();
   ui->lineEdit_BankAccountCustomerInput->clear();
   ui->lineEdit_CreditLimitCustomerInput->clear();
   ui->lineEdit_IDCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_IDCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_FirstNameCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_LastNameCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_CompanyCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_PhoneNumberCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_EmailCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_WebsiteCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_AdressCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_CityCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_ZipCodeCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_CountryCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_BankAccountCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
   ui->lineEdit_CreditLimitCustomerInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
}

void MainWindow::on_profile_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profile_1_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profile_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profile_4_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profile_5_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profile_6_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::showContextMenuProject(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView_4->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(viewProject()));
    myMenu.addAction("Edit",  this, SLOT(editProject()));
    myMenu.addAction("Delete", this, SLOT(deleteProject()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::deleteProject()
{
    DeleteConfirmation D;
    D.setModal(true);
    D.exec();

    QModelIndex index = ui->listView_4->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    if(D.getConfirm()==1)
    {
        //supprimer l'objet P de la table projet et on recupére la valeur de retour(query.exec()) dans la variable test
        bool test=P.Effacer(itemText);

        if(test)//if(test==true)->La requete est executée->QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Deletion Project is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView_4->setModel(P.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion Project failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void MainWindow::viewProject()
{
    QModelIndex index = ui->listView_4->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    view=P.Lire(itemText);

    while(view.next())
    {
          ui->lineEdit_IDProjectOutput->setText(view.value(0).toString());
          ui->lineEdit_NameProjectOutput->setText(view.value(1).toString());
          ui->lineEditlineEdit_DescriptionProjectOutput->setText(view.value(2).toString());
          ui->lineEditlineEdit_StartDateProjectOutput->setText(view.value(3).toString());
          ui->lineEdit_EndDateProjectOutput->setText(view.value(4).toString());
          ui->lineEdit_BudgetProjectOutput->setText(view.value(5).toString());
          ui->lineEdit_CustomerIDProjectOutput->setText(view.value(6).toString());
    }

    ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::editProject()
{
    QModelIndex index = ui->listView_4->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    view=P.Lire(itemText);

    while(view.next())
    {
          ui->lineEdit_IDProjectEdit->setText(view.value(0).toString());
          ui->lineEdit_NameProjectEdit->setText(view.value(1).toString());
          ui->lineEdit_DescriptionProjectEdit->setText(view.value(2).toString());
          ui->dateEdit_StartDateProjectEdit->setDate(view.value(3).toDate());
          ui->dateEdit_EndDateProjectEdit->setDate(view.value(4).toDate());
          ui->lineEdit_BudgetProjectEdit->setText(view.value(5).toString());
          ui->lineEdit_CustomerIDProjectEdit->setText(view.value(6).toString());
    }
   ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_AddNewProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
    ui->lineEdit_IDProjectInput->clear();
    ui->lineEdit_NameProjectInput->clear();
    ui->lineEdit_DescriptionProjectInput->clear();
    ui->lineEdit_BudgetProjectInput->clear();
    ui->lineEdit_CustomerIDProjectInput->clear();
    ui->lineEdit_IDProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_NameProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");

    ui->lineEdit_DescriptionProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_BudgetProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_CustomerIDProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->dateEdit_StartDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;");

    ui->dateEdit_EndDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;");
}


void MainWindow::on_pushButton_SaveAddProject_clicked()
{
    if(ui->lineEdit_IDProjectInput->text().isEmpty())
    {
        ui->lineEdit_IDProjectInput->setStyleSheet("border: 2px solid red;"
                                                   "padding: 1px;"
                                                   "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_IDProjectInput->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;"
                                                   "border-radius: 10px;");
    }

    if(ui->lineEdit_NameProjectInput->text().isEmpty())
    {
        ui->lineEdit_NameProjectInput->setStyleSheet("border: 2px solid red;"
                                                     "padding: 1px;"
                                                     "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_NameProjectInput->setStyleSheet("border: 2px solid black;"
                                                     "padding: 1px;"
                                                     "border-radius: 10px;");
    }

    if(ui->lineEdit_DescriptionProjectInput->text().isEmpty())
    {
        ui->lineEdit_DescriptionProjectInput->setStyleSheet("border: 2px solid red;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_DescriptionProjectInput->setStyleSheet("border: 2px solid black;"
                                                            "padding: 1px;"
                                                            "border-radius: 10px;");
    }

    if(ui->dateEdit_StartDateProjectInput->text().isEmpty())
    {
        ui->dateEdit_StartDateProjectInput->setStyleSheet("border: 2px solid red;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }
    else
    {
        ui->dateEdit_StartDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }

    if(ui->dateEdit_EndDateProjectInput->text().isEmpty())
    {
        ui->dateEdit_EndDateProjectInput->setStyleSheet("border: 2px solid red;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }
    else
    {
        ui->dateEdit_EndDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                        "padding: 1px;"
                                                        "border-radius: 10px;");
    }

    if(ui->lineEdit_BudgetProjectInput->text().isEmpty())
    {
        ui->lineEdit_BudgetProjectInput->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_BudgetProjectInput->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }

    if(ui->lineEdit_CustomerIDProjectInput->text().isEmpty())
    {
        ui->lineEdit_CustomerIDProjectInput->setStyleSheet("border: 2px solid red;"
                                                           "padding: 1px;"
                                                           "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CustomerIDProjectInput->setStyleSheet("border: 2px solid black;"
                                                           "padding: 1px;"
                                                           "border-radius: 10px;");
    }


    if((ui->lineEdit_IDProjectInput->text().isEmpty())||(ui->lineEdit_NameProjectInput->text().isEmpty())||(ui->lineEdit_DescriptionProjectInput->text().isEmpty())||(ui->dateEdit_StartDateProjectInput->text().isEmpty())||(ui->dateEdit_EndDateProjectInput->text().isEmpty())||(ui->lineEdit_BudgetProjectInput->text().isEmpty())||(ui->lineEdit_CustomerIDProjectInput->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }
    else
    {
        //récuperations des informations saisies dans les lineEdits
        QString ID=ui->lineEdit_IDProjectInput->text();
        QString Name=ui->lineEdit_NameProjectInput->text();
        QString Description=ui->lineEdit_DescriptionProjectInput->text();
        QString StartDate=ui->dateEdit_StartDateProjectInput->text();
        QString EndDate=ui->dateEdit_EndDateProjectInput->text();
        float Budget=ui->lineEdit_BudgetProjectInput->text().toFloat();//Conversion de la chaine saisie en un reel car Budget est de type float
        QString CustomerID=ui->lineEdit_CustomerIDProjectInput->text();


        //Instantiation d'un objet de type projet en utilisant les informations saisies dans l'interface graphique
        Project P(ID,Name,Description,StartDate,EndDate,Budget,CustomerID);

        //Inserer l'objet P dans la table projet et recuperer la valeur de retour de query.exec() dans la variable test.
        bool test=P.Ajouter();

        if(test)//Si la requete a ete executé convenablement
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Addition of new Project is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView_4->setModel(P.AfficherListe());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Addition of new Project failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->stackedWidget->setCurrentIndex(17);
    }
}

void MainWindow::on_pushButton_SaveEditProject_clicked()
{

    if(ui->lineEdit_IDProjectEdit->text().isEmpty())
    {
        ui->lineEdit_IDProjectEdit->setStyleSheet("border: 2px solid red;"
                                                  "padding: 1px;"
                                                  "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_IDProjectEdit->setStyleSheet("border: 2px solid black;"
                                                  "padding: 1px;"
                                                  "border-radius: 10px;");
    }

    if(ui->lineEdit_NameProjectEdit->text().isEmpty())
    {
        ui->lineEdit_NameProjectEdit->setStyleSheet("border: 2px solid red;"
                                                    "padding: 1px;"
                                                    "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_NameProjectEdit->setStyleSheet("border: 2px solid black;"
                                                    "padding: 1px;"
                                                    "border-radius: 10px;");
    }

    if(ui->lineEdit_DescriptionProjectEdit->text().isEmpty())
    {
        ui->lineEdit_DescriptionProjectEdit->setStyleSheet("border: 2px solid red;"
                                                           "padding: 1px;"
                                                           "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_DescriptionProjectEdit->setStyleSheet("border: 2px solid black;"
                                                           "padding: 1px;"
                                                           "border-radius: 10px;");
    }

    if(ui->dateEdit_StartDateProjectEdit->text().isEmpty())
    {
        ui->dateEdit_StartDateProjectEdit->setStyleSheet("border: 2px solid red;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }
    else
    {
        ui->dateEdit_StartDateProjectEdit->setStyleSheet("border: 2px solid black;"
                                                         "padding: 1px;"
                                                         "border-radius: 10px;");
    }

    if(ui->dateEdit_EndDateProjectEdit->text().isEmpty())
    {
        ui->dateEdit_EndDateProjectEdit->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }
    else
    {
        ui->dateEdit_EndDateProjectEdit->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;"
                                                       "border-radius: 10px;");
    }

    if(ui->lineEdit_BudgetProjectEdit->text().isEmpty())
    {
        ui->lineEdit_BudgetProjectEdit->setStyleSheet("border: 2px solid red;"
                                                      "padding: 1px;"
                                                      "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_BudgetProjectEdit->setStyleSheet("border: 2px solid black;"
                                                      "padding: 1px;"
                                                      "border-radius: 10px;");
    }

    if(ui->lineEdit_CustomerIDProjectEdit->text().isEmpty())
    {
        ui->lineEdit_CustomerIDProjectEdit->setStyleSheet("border: 2px solid red;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }
    else
    {
        ui->lineEdit_CustomerIDProjectEdit->setStyleSheet("border: 2px solid black;"
                                                          "padding: 1px;"
                                                          "border-radius: 10px;");
    }


    if(ui->dateEdit_StartDateProjectEdit->text()=="01/01/2000")
    {
        ui->dateEdit_StartDateProjectEdit->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;");
    }
    else
    {
        ui->dateEdit_EndDateProjectEdit->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;");

    }

    if(ui->dateEdit_EndDateProjectEdit->text()=="01/01/2000")
    {
        ui->dateEdit_EndDateProjectEdit->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;");
    }
    else
    {
        ui->dateEdit_EndDateProjectEdit->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;");

    }


    if((ui->lineEdit_IDProjectEdit->text().isEmpty())||(ui->lineEdit_NameProjectEdit->text().isEmpty())||(ui->lineEdit_DescriptionProjectEdit->text().isEmpty())||(ui->dateEdit_StartDateProjectEdit->text().isEmpty())||(ui->dateEdit_EndDateProjectEdit->text().isEmpty())||(ui->lineEdit_BudgetProjectEdit->text().isEmpty())||(ui->lineEdit_CustomerIDProjectEdit->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }
    else
    {
        //récuperations des informations saisies dans les lineEdits
        QString ID=ui->lineEdit_IDProjectEdit->text();
        QString Name=ui->lineEdit_NameProjectEdit->text();
        QString Description=ui->lineEdit_DescriptionProjectEdit->text();
        QString StartDate=ui->dateEdit_StartDateProjectEdit->text();
        QString EndDate=ui->dateEdit_EndDateProjectEdit->text();
        float Budget=ui->lineEdit_BudgetProjectEdit->text().toFloat();//Conversion de la chaine saisie en un reel car Budget est de type float
        QString CustomerID=ui->lineEdit_CustomerIDProjectEdit->text();

        //Instantiation d'un objet de type projet en utilisant les informations saisies dans l'interface graphique
        Project P(ID,Name,Description,StartDate,EndDate,Budget,CustomerID);

        //Inserer l'objet P dans la table projet et recuperer la valeur de retour de query.exec() dans la variable test.
        bool test=P.Editer();

        if(test)//Si la requete a ete executé convenablement
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Edit Project is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView_4->setModel(P.AfficherListe());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Edit Project failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->stackedWidget->setCurrentIndex(17);
    }
}

void MainWindow::on_pushButton_CancelAddProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_CancelEditProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_Return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_SortProject_clicked()
{
    ui->listView_4->setModel(P.Trier());
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                             QObject::tr("Sort of list of clients successful.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_SearchProject_textChanged(const QString &arg1)
{
    QString information =arg1;
    ui->listView_4->setModel(P.chercher(information));
    if(ui->lineEdit_SearchProject->text()=="")
    {
        ui->listView_4->setModel(P.AfficherListe());
    }
}

void MainWindow::on_pushButton_Print_2_clicked()
{
    QStringList list;
    QPlainTextEdit text;
    text.setStyleSheet("QPlainTextEdit{color: #ffff00; background-color: #303030;");
    QTextDocument *doc = text.document();
    QFont font = doc->defaultFont();
    font.setBold(true);
    font.setFamily("Arial");
    font.setPixelSize(20);
    doc->setDefaultFont(font);
    text.appendPlainText("                                              Date: "+ui->date->text()+"");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("Information of Customer:");
    text.appendPlainText("");
    text.appendPlainText("ID:  "+ui->lineEdit_IDProjectOutput->text()+"");
    text.appendPlainText("Name:  "+ui->lineEdit_NameProjectOutput->text()+"");
    text.appendPlainText("Description:  "+ui->lineEditlineEdit_DescriptionProjectOutput->text()+"");
    text.appendPlainText("Start Date:  "+ui->lineEditlineEdit_StartDateProjectOutput->text()+"");
    text.appendPlainText("End Date:  "+ui->lineEdit_EndDateProjectOutput->text()+"");
    text.appendPlainText("Budget:  "+ui->lineEdit_BudgetProjectOutput->text()+"");
    text.appendPlainText("Customer ID:  "+ui->lineEdit_CustomerIDProjectOutput->text()+"");

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
    text.show();
}

void MainWindow::on_signOut_8_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_10_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_12_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_14_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_9_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_11_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_13_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ProjectsButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(17);
}



///////Gestion facturation :: Meriam's work begin //////////


/// statistics ///

void MainWindow::statistique()
{
    //pie chart

    QChartView * chartView=new QChartView(o.stat());
    chartView ->setParent(ui->horizontalFrame);
}

//menu
void MainWindow::showContextMenuOrder(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos1 = ui->orderListView->mapToGlobal(pos);
    QPoint globalPos2 = ui->billListView->mapToGlobal(pos);
    // Create menu and insert some actions
    QMenu myMenu1;



    // Show context menu at handling position
  if(ui->stackedWidget->currentIndex()==22){
    myMenu1.addAction("View", this, SLOT(viewBill()));
    myMenu1.addAction("Edit",  this, SLOT(editBill()));
    myMenu1.addAction("Delete", this, SLOT(deleteBill()));
    myMenu1.exec(globalPos2);
  }
  else if (ui->stackedWidget->currentIndex()==21) {
      myMenu1.addAction("View", this, SLOT(viewOrder()));
      myMenu1.addAction("Edit",  this, SLOT(editOrder()));
      myMenu1.addAction("Delete", this, SLOT(deleteOrder()));
      myMenu1.addAction("sendMail", this, SLOT(sendMail()));
      myMenu1.exec(globalPos1);

  }
}

void MainWindow::showContextMenuBill(const QPoint &pos)
{

QPoint globalPos = ui->billListView->mapToGlobal(pos);
// Create menu and insert some actions
QMenu myMenu;



// Show context menu at handling position
if(ui->stackedWidget->currentIndex()==22)
{
myMenu.addAction("View", this, SLOT(viewBill()));
myMenu.addAction("Edit",  this, SLOT(editBill()));
myMenu.addAction("Delete", this, SLOT(deleteBill()));
myMenu.exec(globalPos);
}
}

/// refresh ///////////////
void MainWindow::initAddBill()
{
    ui->shipperName->setText("");
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
    ui->billNumber->setText("");
    ui->orderID->setText("");
    ui->paymentMethod->setCurrentIndex(0);
    ui->shipperPhone->setText(0);
    ui->doubleSpinBox->setValue(0);
}

void MainWindow::initEditBill()
{
    ui->shipperName_2->setText("");
    QDate date = QDate::currentDate();
    ui->dateEdit_2->setDate(date);
    ui->billNumber_2->setText("");
    ui->orderID_2->setText("");
    ui->paymentMethod_2->setCurrentIndex(0);
    ui->shipperPhone_2->setText(0);
    ui->doubleSpinBox_2->setValue(0);

}
void MainWindow::initEditOrder()
{

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

void MainWindow::initAddOrder()
{

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



//choose bill button from menu
void MainWindow::on_billButton_clicked()
{
    //sound ///

    coinSound=new QSound(":/sounds/sounds/coin.wav");
    coinSound->play();

    ////////////////
    ui->billListView->setModel(b.afficherList());
    ui->stackedWidget->setCurrentIndex(22);
}
//choose order button from menu
void MainWindow::on_orderButton_clicked()
{
    //refresh affichage
    order o ;
    ui->orderListView->setModel(o.afficherList());
    ui->stackedWidget->setCurrentIndex(21);
}

//Bill menu

void MainWindow::viewBill()
{
   int i = ui->billListView->currentIndex().data().toInt();

   ui->tabWidget_3->setCurrentIndex(2);

   b.loadData(i);
   ui->viewBillNumber->setText(b.getBillNumber());
   ui->viewOrderID->setText(b.getOrderID());
   ui->viewPaymentMethod->setText(b.getPayMethod());
   ui->viewreleaseDate->setText(QVariant(b.getReleaseDate()).toString());
   ui->viewTotalAmount->setText(QVariant(b.getTotalAmount()).toString());
   ui->viewShipperName->setText(b.getShipperName());
   ui->viewShipperPhone->setText( QVariant(b.getShipperNumber()).toString());

}

void MainWindow::editBill()
{
       int i = ui->billListView->currentIndex().data().toInt();
      ui->tabWidget_3->setCurrentIndex(3);

      b.loadData(i);
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
    DeleteConfirmation d;
    QMessageBox msg;

    //take the id of the element to delete

int i = ui->billListView->currentIndex().data().toInt();

 d.exec();

if(d.getConfirm()==1)
 { bool test= b.supprimer(i);

    //refresh affichage
    ui->billListView->setModel(b.afficherList());

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

///view with double click
int MainWindow::on_billListView_doubleClicked(const QModelIndex &index)
{

    ui->tabWidget_3->setCurrentIndex(2);
    int i = index.data().toInt();
    b.loadData(i);
    ui->viewBillNumber->setText(b.getBillNumber());
    ui->viewOrderID->setText(b.getOrderID());
    ui->viewPaymentMethod->setText(b.getPayMethod());
    ui->viewreleaseDate->setText(QVariant(b.getReleaseDate()).toString());
    ui->viewTotalAmount->setText(QVariant(b.getTotalAmount()).toString());
    ui->viewShipperName->setText(b.getShipperName());
    ui->viewShipperPhone->setText( QVariant(b.getShipperNumber()).toString());

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

            b.setShipperName (ui->shipperName->text());
            b.setReleaseDate(ui->dateEdit->date());
            b.setBillNumber(ui->billNumber->text());
            b.setOrderID(ui->orderID->text());
            b.setPayMethod(ui->paymentMethod->currentText());
            b.setShipperNumber(ui->shipperPhone->text().toInt());
            b.setTotalAmount(ui->doubleSpinBox->text().toFloat());


         bool test= b.ajouter();
         //refresh affichage
           ui->billListView->setModel(b.afficherList());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("ajouter dans le tableau");
                 msg.exec();

                  //reintialisation the add interface
                  initAddBill();

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

void MainWindow::on_editButton_clicked()
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
    int id = ui->billListView->currentIndex().data().toInt();

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

             //reintialisation the edit interface
             initEditBill();
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
    ui->billListView->setModel(b.afficherOrderedList());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted");
    msg.exec();
}

//search bills


void MainWindow::on_search_textChanged(const QString &arg1)
{
    int s =arg1.toInt();
    ui->billListView->setModel(b.searchList(s));
   if (arg1=="")
        ui->billListView->setModel(b.afficherList());

}

//Order menu///

void MainWindow::viewOrder()
{
   int i = ui->orderListView->currentIndex().data().toInt();
    o.loadData(i);
    ui->viewOrderNumber->setText(o.getOrderNumber());
    ui->viewProductCode->setText(o.getProductCode());
    ui->viewQuantityOrdered->setText(QVariant(o.getQuantityOrdered()).toString());
    ui->viewStatus->setText(o.getStatus());
    ui->viewOrderDate->setText(QVariant(o.getOrderDate()).toString());
    ui->viewUnitPrice->setText(QVariant(o.getUnitPrice()).toString());
    ui->viewDiscount->setText(o.getDiscount());
    ui->viewExtendedPrice->setText(QVariant(o.getExtendedPrice()).toString());
    ui->viewRequiredDate->setText(QVariant(o.getRequiredDate()).toString());
    ui->viewCustomerID->setText(o.getCustomerID());
    ui->viewComments->setText(o.getComments());

    ui->tabWidget_2->setCurrentIndex(2);

}

void MainWindow::editOrder()
{
    int i = ui->orderListView->currentIndex().data().toInt();
     o.loadData(i);
     ui->orderNumber_10->setText(o.getOrderNumber());
     ui->productCode_10->setText(o.getProductCode());
     ui->quantity_10->setValue (o.getQuantityOrdered());
     ui->status_10->setCurrentText(o.getStatus());
     ui->orderDate_10->setDate(o.getOrderDate());
     ui->unitPrice_10->setValue(o.getUnitPrice());
     ui->discount_10->setText(o.getDiscount());
     ui->extendedPrice_10->setValue(o.getExtendedPrice());
     ui->requiredDate_10->setDate(o.getRequiredDate());
     ui->customerID_10->setText(o.getCustomerID());
     ui->comments_10->setText(o.getComments());


     ui->tabWidget_2->setCurrentIndex(3);
}
///delete
void MainWindow::deleteOrder()
{
    DeleteConfirmation d;
    QMessageBox msg;

    //take the id of the element to delete

int i = ui->orderListView->currentIndex().data().toInt();

 d.exec();

if(d.getConfirm()==1)
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
     msg.setText("order wasn't deleted ");
     msg.exec();
}

}

void MainWindow::sendMail()
{

    ui->stackedWidget->setCurrentIndex(23);
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
                 initAddOrder();


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
                 initEditOrder();

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



void MainWindow::on_cancelButton_22_clicked()
{
    initEditOrder();
    ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}



void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_return_11_clicked()
{
    ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_cancelButton_23_clicked()
{

    initAddBill();
    ui->tabWidget_3->setCurrentIndex(0);
}


void MainWindow::on_options_clicked()
{
    statistique();
    ui->stackedWidget->setCurrentIndex(23);
    ui->tabWidget->setCurrentIndex(1);

}

//mail sending

void MainWindow::on_sendMailButton_2_clicked()
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

       ui->stackedWidget->setCurrentIndex(21);
}




void MainWindow::on_cancelButton_5_clicked()
{
    initAddOrder();
    ui->tabWidget_2->setCurrentIndex(0);
}


void MainWindow::on_cancelButton_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_cancelButton_6_clicked()
{
    initEditBill();
    ui->tabWidget_3->setCurrentIndex(0);
}



void MainWindow::on_signOut_16_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_22_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

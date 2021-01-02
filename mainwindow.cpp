#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLegend>

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
    //ui->lineEdit_IDCustomerInput->setPlaceholderText(" Enter ID");
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
    ui->lineEdit_NameProjectInput->setPlaceholderText(" Enter Name");
    ui->lineEdit_DescriptionProjectInput->setPlaceholderText(" Enter Description");
    ui->lineEdit_BudgetProjectInput->setPlaceholderText(" Enter Budget");

    //Place Holder For Edit Project
    ui->lineEdit_IDProjectEdit->setPlaceholderText(" Enter ID");
    ui->lineEdit_NameProjectEdit->setPlaceholderText(" Enter Name");
    ui->lineEdit_DescriptionProjectEdit->setPlaceholderText(" Enter Description");
    ui->lineEdit_BudgetProjectEdit->setPlaceholderText(" Enter Budget");

    //Controle de saisie des Inputs de add project:
    ui->lineEdit_NameProjectInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_DescriptionProjectInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_BudgetProjectInput->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));

    //Controle de saisie des Inputs de Edit project:
    ui->lineEdit_NameProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_DescriptionProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDProjectEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_BudgetProjectEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));

    animation=new QPropertyAnimation(ui->label_134,"geometry");
    animation->setDuration(10000);
    animation->setLoopCount(4);
    animation->setStartValue(ui->label_134->geometry());
    animation->setEndValue(QRect(210,50,251,51));
    animation->start();

    //************************************************************************************************************************


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
    ui->firstNameLineEdit->setPlaceholderText("  Enter First Name");
    ui->lastNameLineEdit->setPlaceholderText("  Enter Last Name");
    ui->phoneNumberLineEdit->setPlaceholderText("  Enter Phone Number");
    ui->adressLineEdit->setPlaceholderText("  Enter Adress");
    ui->salaryLineEdit->setPlaceholderText("  Enter Salary");
    ui->emailLineEdit->setPlaceholderText("  Enter Email");
    ui->subjectLineEdit->setPlaceholderText("Subject");

    //Controle De Saisie
    ui->firstNameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lastNameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->phoneNumberLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->adressLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->salaryLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->idLineEdit_4->setValidator(new QRegExpValidator(QRegExp("[0-9]{7}")));
    ui->firstNameLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lastNameLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->phoneNumberLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->adressLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->salaryLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    //************************************************************************************************************************
  //nersrine's work//
    //Supplier list
    ui->listViewSupplier->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listViewSupplier, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuSupplier(QPoint)));
     //Material List
     ui->listViewMateriel->setContextMenuPolicy(Qt::CustomContextMenu);
     connect(ui->listViewMateriel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuMaterial(QPoint)));

    ///meriam's work ///


    //affichage de mainwindow
    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);


    //BILL List
   ui->billListView->setContextMenuPolicy(Qt::CustomContextMenu);
   connect(ui->billListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuBill(QPoint)));

    //ORDEER List
    ui->orderListView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->orderListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuOrder(QPoint)));

    ui->lineEdit_CityCustomerInput->setPlaceholderText("Enter City");
    ui->search->setPlaceholderText("enter bill ID/totalAmount/orderNumber");
    ui->searchOrder->setPlaceholderText("enter order ID/status/ProductCode/customerCode");

    ui->sort_totalAmount->setVisible(false);
    ui->sort_shipperName->setVisible(false);
    ui->sort_releaseDate->setVisible(false);

    ui->sort_orderID->setVisible(false);
    ui->sort_orderDate->setVisible(false);
    ui->sort_discount->setVisible(false);

    statistique();

    //************************************************************************************************************************



    //chedi place holder + controle de saisie

    //products list
    ui->listView_5->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView_5, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuProduct(QPoint)));

    //Place Holder for search product By code
    ui->lineEdit_SearchCustomer->setPlaceholderText("  Search...");

    //place Holder of add Product Inteface
    ui->lineEdit_ProductCodeInput_2->setPlaceholderText(" Enter Product Code");
    ui->lineEdit_ProductNameInput_2->setPlaceholderText("Enter Product Name");
    ui->lineEdit_QuantityInStockInput_2->setPlaceholderText("Enter The Quantity In Stock");
    ui->lineEdit_SellPriceInput_2->setPlaceholderText("Enter Sell Price /TND");


    //place Holder of edit Product Interface
    ui->lineEdit_ProductCodeEdit_2->setPlaceholderText(" Enter Product Code");
    ui->lineEdit_ProductNameEdit_2->setPlaceholderText("Enter Product Name");
    ui->lineEdit_QuantityInStockEdit_2->setPlaceholderText("Enter The Quantity In Stock");
    ui->lineEdit_SellPriceEdit_2->setPlaceholderText("Enter Sell Price /TND");

    //controle de saisie du searchProduct
    ui->lineEdit_SearchCustomer_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    //controle de saisie des Inputs de AddProduct
    ui->lineEdit_ProductCodeInput_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_ProductNameInput_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));//input must be an alphabet uppercase or lowercase
    ui->lineEdit_QuantityInStockInput_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_SellPriceInput_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    //controle des Inputs de EditProduct
    ui->lineEdit_ProductCodeEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_ProductNameEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));//input must be an alphabet uppercase or lowercase
    ui->lineEdit_QuantityInStockEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_SellPriceEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    //warehouse list
    ui->listView_6->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView_6, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenuWarehouse(QPoint)));

    //Place Holder For Add New Warehouse
    ui->lineEdit_IDWarehouseInput->setPlaceholderText(" Enter Warehouse ID");
    ui->lineEdit_TypeOfProductInput->setPlaceholderText(" Enter The Type Of Product");
    ui->lineEdit_NameWarehouseManagerInput->setPlaceholderText(" Enter The Name Of Warehouse Manager");

    //Place Holder For Edit Warehouse
    ui->lineEdit_IDWarehouseInput_2->setPlaceholderText(" Enter Warehouse ID");
    ui->lineEdit_TypeOfProductInput_2->setPlaceholderText(" Enter The Type Of Product");
    ui->lineEdit_NameWarehouseManagerInput_2->setPlaceholderText(" Enter The Name Of Warehouse Manager");

    //Controle de saisie des Inputs de add Warehouse:
    ui->lineEdit_TypeOfProductInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_NameWarehouseManagerInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDWarehouseInput->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    //Controle de saisie des Inputs de Edit Warehouse:
    ui->lineEdit_TypeOfProductInput_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_NameWarehouseManagerInput_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_IDWarehouseInput_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));


    animation=new QPropertyAnimation(ui->CustomerRelationshipManagementButton,"geometry");
    animation->setDuration(4000);
    animation->setLoopCount(4);
    animation->setStartValue(ui->CustomerRelationshipManagementButton->geometry());
    animation->setEndValue(QRect(30,100,471,51));
    animation->start();

    ui->listView_5->setModel(P1.AfficherListe());
    ui->listView_6->setModel(DEPOT.AfficherListe());


    // travail de nesrine

    animation=new QPropertyAnimation(ui->pushButton_statMateriel,"geometry");
          animation->setDuration(5000);
          animation->setStartValue(ui->pushButton_statMateriel->geometry());
          animation->setEndValue(ui->pushButton_statMateriel->geometry());
          animation->start();

          animation=new QPropertyAnimation(ui->pushButton_statMateriel,"geometry");
          animation->setDuration(5000);
          animation->setStartValue(ui->pushButton_statMateriel->geometry());
          animation->setEndValue(ui->pushButton_statMateriel->geometry());
          animation->start();



    //controle de saisie de fournisseurs de la modification
    ui->lineEdit_editSID->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_Addcontacttitle->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    //ui->lineEdit_editcontactName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
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
    //ui->lineEdit_AddContName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddCompName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddCity->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddCountry->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddAdress->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->lineEdit_AddPhone->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    //ui->lineEditAddHomepage->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    //controle de saisie de l'ajout d'une matiére

    ui->lineEdit_AddSupplierIDMat->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddcurrncyMatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddQuantMatAdd->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->lineEdit_AddMatpriceAdd->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->lineEdit_AddUnitMatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddDesmatAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_AddMatNameAdd->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEditADDMaterialID->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));



    //arduino chedi+khairi

    /*int ret = A.connect_arduino();
    switch (ret)
    {
        case(0): qDebug()<<"arduino is avaible and connected to: "<<A.getArduino_port_name();
        break;

        case(1): qDebug()<<"arduino is avaible but not connected to: "<<A.getArduino_port_name();
        break;

        case(-1): qDebug()<<"arduino is not avaible";
        break;


    }

    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update()));

    ////
    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));*/
    //nesrine's Work
   /* switch (ret) {
    case (0): qDebug()<<"arduino is avaible and connected to :"<<a.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is not availble but not connect to :"<< a.getarduino_port_name();
        break;
    case(-1): qDebug()<<"arduino is not available  ";
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2()));*/



}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::update()
{
    data = A.read_from_arduino();

    if(data == "1")
    {
        ui->etat->setText("Warning there is a large amount of gas :(");
    }
    else
    {
        ui->etat->setText("No gas leak :)");
    }

    ui->etat->setText(data);


}

//meriam+yesmine arduino
void MainWindow::update_label()
{
    data1=A.read_from_arduino();
    bool ok;
    if(data1.toHex().toInt(&ok,16)==1)
    {
         D.setModal(true);
         D.exec();

         if(D.getAlert()==1)
         {
             A.write_to_arduino("1");
         }
    }
            else
    {
         D.hide();
    }
     qDebug() << "data" << data1;

}
/////
/// \brief MainWindow::showTime
///
//arduino nesrine
/*void MainWindow::update_label2()
{


        if( !data.contains('n') && !data.contains('r') )
{    data = A.read_from_arduino2();
    float nb = data.toFloat();
    bool ok;
    if(data.toHex().toInt(&ok,16)==1)// serialWrite("1")  condition
       {
            D.setModal(true);
            D.exec();
       }
               else
       {
            D.hide();
       }
    qDebug() << nb << endl;

}
   // qDebug() << data << endl;



}*/
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
    ui->time_26->setText(time_text);
    ui->time2_3->setText(time_text);
    ui->time3_3->setText(time_text);
    ui->time4_3->setText(time_text);
    ui->time_27->setText(time_text);
    ui->time2_4->setText(time_text);
    ui->time3_4->setText(time_text);
    ui->time4_4->setText(time_text);

    ui->time_20->setText(time_text);
    ui->time_28->setText(time_text);
    ui->time_29->setText(time_text);
    ui->time_30->setText(time_text);
    ui->time_31->setText(time_text);
    ui->time_32->setText(time_text);
    ui->time_33->setText(time_text);
    ui->time_34->setText(time_text);
    ui->time_35->setText(time_text);
    ui->time_36->setText(time_text);





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
    ui->date_8->setText(datetimetext);
    ui->date_1->setText(datetimetext);
    ui->date_10->setText(datetimetext);
    ui->date_11->setText(datetimetext);
    ui->date_12->setText(datetimetext);
    ui->date_13->setText(datetimetext);
    ui->date_14->setText(datetimetext);
    ui->date_15->setText(datetimetext);
    ui->date_16->setText(datetimetext);
    ui->date_17->setText(datetimetext);
    ui->date_25->setText(datetimetext);
    ui->date2_3->setText(datetimetext);
    ui->date3_3->setText(datetimetext);
    ui->date4_3->setText(datetimetext);
    ui->date_26->setText(datetimetext);
    ui->date3_4->setText(datetimetext);
    ui->date4_4->setText(datetimetext);

    ui->date_18->setText(datetimetext);
    ui->date_27->setText(datetimetext);
    ui->date_28->setText(datetimetext);
    ui->date_29->setText(datetimetext);
    ui->date_30->setText(datetimetext);
    ui->date_31->setText(datetimetext);
    ui->date_32->setText(datetimetext);
    ui->date_33->setText(datetimetext);
    ui->date_34->setText(datetimetext);
    ui->date_35->setText(datetimetext);

}
//nessrine
void MainWindow::showContextMenuMaterial(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listViewMateriel->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("Delete",  this, SLOT(deleteMaterial()));
    myMenu.addAction("View", this, SLOT(viewMaterial()));
    myMenu.addAction("Edit", this, SLOT(editMaterial()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}
void MainWindow::showContextMenuSupplier(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listViewSupplier->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("Delete",  this, SLOT(deleteSupplier()));
    myMenu.addAction("View", this, SLOT(viewSupplier()));
    myMenu.addAction("Edit", this, SLOT(editSupplier()));
    myMenu.addAction("Send Email", this, SLOT(SendMail()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
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

    ui->lineEdit_FirstNameCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_LastNameCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_CompanyCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_PhoneNumberCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_EmailCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_WebsiteCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_AdressCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_CityCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_ZipCodeCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_CountryCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_BankAccountCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");
    ui->lineEdit_CreditLimitCustomerEdit->setStyleSheet("padding: 1px;"
                                                "background: rgb(85,170,255);"
                                                "border-radius: 10px;");

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
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();

                }
                else if(view.value(2).toString() == "Depot Employee")
                {
                    ui->access1Button->setText("Depots");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "Project and Services Employee")
                {
                    ui->access1Button->setText("Project and Services");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "Laboratory Employee")
                {
                    ui->access1Button->setText("Laboratories");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "Stock Employee")
                {
                    ui->access1Button->setText("Stocks");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                if(view.value(2).toString() == "HR Agent")
                {
                    ui->access1Button->setText("Employees");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "Depot Employee")
                {
                    ui->access1Button->setText("Depots");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "Project and Services Employee")
                {
                    ui->access1Button->setText("Project and Services");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "Laboratory Employee")
                {
                    ui->access1Button->setText("Laboratories");
                    ui->accessButton_2->hide();
                    ui->accessButton_3->hide();
                    ui->accessButton_4->hide();
                }
                else if(view.value(2).toString() == "CEO")
                {
                    ui->access1Button->setText("Employees");
                    ui->accessButton_2->setText("Project and Services");
                    ui->accessButton_3->setText("Laboratories");
                    ui->accessButton_4->setText("Stock");
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
         jobTitle = ui->comboBox->currentText();

         Profile P(id,password,jobTitle);

         bool test_2 = P.searchIDSignUp(id);
         if(test_2)
         {
             qDebug()<<jobTitle;
             bool test_3=P.searchJobTitleSignUp(id,jobTitle);
             qDebug()<<test_3;
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
        ui->stackedWidget->setCurrentIndex(22);
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

        animation1=new QPropertyAnimation(ui->CustomersButton,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->CustomersButton->geometry());
        animation1->setEndValue(ui->ProjectsButton->geometry());
        animation1->start();

        animation1=new QPropertyAnimation(ui->ProjectsButton,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->ProjectsButton->geometry());
        animation1->setEndValue(ui->CustomersButton->geometry());
        animation1->start();
    }
    else if(ui->viewJobTitle->text() == "Laboratory Employee")
    {
        ui->stackedWidget->setCurrentIndex(37);

        animation1=new QPropertyAnimation(ui->pushButton_menusupplier,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->pushButton_menusupplier->geometry());
        animation1->setEndValue(ui->pushButton_menuMaterial->geometry());
        animation1->start();

        animation1=new QPropertyAnimation(ui->pushButton_menuMaterial,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->pushButton_menuMaterial->geometry());
        animation1->setEndValue(ui->pushButton_menusupplier->geometry());
        animation1->start();
    }
    else if(ui->viewJobTitle->text() == "Stock Employee")
    {
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if(ui->viewJobTitle->text() == "CEO")
    {
        ui->stackedWidget->setCurrentIndex(4);
    }


}

void MainWindow::on_accessButton_2_clicked()
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

    animation1=new QPropertyAnimation(ui->CustomersButton,"geometry");
    animation1->setDuration(5000);
    animation1->setStartValue(ui->CustomersButton->geometry());
    animation1->setEndValue(ui->ProjectsButton->geometry());
    animation1->start();

    animation1=new QPropertyAnimation(ui->ProjectsButton,"geometry");
    animation1->setDuration(5000);
    animation1->setStartValue(ui->ProjectsButton->geometry());
    animation1->setEndValue(ui->CustomersButton->geometry());
    animation1->start();

}

void MainWindow::on_accessButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);

    animation1=new QPropertyAnimation(ui->pushButton_menusupplier,"geometry");
    animation1->setDuration(5000);
    animation1->setStartValue(ui->pushButton_menusupplier->geometry());
    animation1->setEndValue(ui->pushButton_menuMaterial->geometry());
    animation1->start();

    animation1=new QPropertyAnimation(ui->pushButton_menuMaterial,"geometry");
    animation1->setDuration(5000);
    animation1->setStartValue(ui->pushButton_menuMaterial->geometry());
    animation1->setEndValue(ui->pushButton_menusupplier->geometry());
    animation1->start();

}

void MainWindow::on_accessButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
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

            phoneNumber = ui->phoneNumberLineEdit->text().toInt();
            salary = ui->salaryLineEdit->text().toFloat();
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

                loadData();
                ui->stackedWidget->setCurrentIndex(4);
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
         QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }

}

void MainWindow::on_cancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    loadData();
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

            loadData();
            ui->stackedWidget->setCurrentIndex(4);
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

    mail=view.value(10).toString();

    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_sendMailButton_clicked()
{
    smtp = new Smtp("human.resources.florallo@gmail.com" , "khairiisthebest7", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->plainTextEdit->toPlainText();
    qDebug()<<mail;
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
          ui->viewBirthDate->setText(view.value(4).toString());
          ui->viewSex->setText(view.value(3).toString());
          ui->viewAdress->setText(view.value(6).toString());
          ui->viewPhoneNumber->setText(view.value(7).toString());
          ui->viewSalary->setText(view.value(8).toString());
          ui->viewHireDate->setText(view.value(5).toString());
          ui->viewJobTitle_2->setText(view.value(9).toString());
          ui->viewEmail->setText(view.value(10).toString());


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
          ui->adressLineEdit_2->setText(view.value(6).toString());
          ui->phoneNumberLineEdit_2->setText(view.value(7).toString());
          ui->salaryLineEdit_2->setText(view.value(8).toString());
          ui->emailLineEdit_2->setText(view.value(10).toString());
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


    if((ui->lineEdit_FirstNameCustomerInput->text().isEmpty())||(ui->lineEdit_LastNameCustomerInput->text().isEmpty())||(ui->lineEdit_CompanyCustomerInput->text().isEmpty())||(ui->lineEdit_PhoneNumberCustomerInput->text().isEmpty())||(ui->lineEdit_ZipCodeCustomerInput->text().isEmpty())||(ui->lineEdit_CountryCustomerInput->text().isEmpty())||(ui->lineEdit_BankAccountCustomerInput->text().isEmpty())||(ui->lineEdit_CreditLimitCustomerInput->text().isEmpty())||(ui->lineEdit_EmailCustomerInput->text().isEmpty())||(ui->lineEdit_CityCustomerInput->text().isEmpty()))
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
            //QString id=ui->lineEdit_IDCustomerInput->text();
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
            Customer c(FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);

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
            QString ID=ui->lineEdit_IDCustomerEdit->text();
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
            Customer C(ID,FirstName,LastName,CompanyName,PhoneNumber,Email,Website,Street,City,ZipCode,Country,BankAccountNumber,CreditLimit);

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
void MainWindow::on_comboBoxSortCustomers_currentTextChanged(const QString &arg1)
{
     QString information =arg1;
    if(information=="ID")
    {

        ui->listView_3->setModel(C.Trier_ID());

        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Sort of list of clients by ID successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    if(information=="First Name")
    {

        ui->listView_3->setModel(C.Trier_FirstName());

        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Sort of list of clients by first name successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    if(information=="Credit Limit")
    {

        ui->listView_3->setModel(C.Trier_CreditLimit());

        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Sort of list of clients by credit limit successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }


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

    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::editProject()
{
    ui->lineEdit_NameProjectEdit->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_DescriptionProjectEdit->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_BudgetProjectEdit->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->dateEdit_StartDateProjectEdit->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;");

    ui->dateEdit_EndDateProjectEdit->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;");

    int i = ui->listView_4->currentIndex().data().toInt();
    P.loadData(i);

    ui->lineEdit_IDProjectEdit->setText(P.getID());
    ui->lineEdit_NameProjectEdit->setText(P.getName());
    ui->lineEdit_DescriptionProjectEdit->setText(P.getDescription());
    ui->dateEdit_StartDateProjectEdit->setDate(QDate::fromString(P.getStartDate(),"dd/MM/yyyy"));
    ui->dateEdit_EndDateProjectEdit->setDate(QDate::fromString(P.getEndDate(),"dd/MM/yyyy"));
    ui->lineEdit_BudgetProjectEdit->setText(QVariant(P.getBudget()).toString());
    ui->customerIDEdit->setModel(P.fillCustomerIDInProject());
    ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_pushButton_AddNewProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
    ui->lineEdit_NameProjectInput->clear();
    ui->lineEdit_DescriptionProjectInput->clear();
    ui->lineEdit_BudgetProjectInput->clear();
    ui->customerIDInput->setModel(P.fillCustomerIDInProject());

    ui->lineEdit_NameProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_DescriptionProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->lineEdit_BudgetProjectInput->setStyleSheet("padding: 1px;"
                                               "background: rgb(85,170,255);"
                                               "border-radius: 10px;");
    ui->dateEdit_StartDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;");
    ui->dateEdit_EndDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                   "padding: 1px;");
}


void MainWindow::on_pushButton_SaveAddProject_clicked()
{

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




    if((ui->lineEdit_NameProjectInput->text().isEmpty())||(ui->lineEdit_DescriptionProjectInput->text().isEmpty())||(ui->dateEdit_StartDateProjectInput->text().isEmpty())||(ui->dateEdit_EndDateProjectInput->text().isEmpty())||(ui->lineEdit_BudgetProjectInput->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }
    else
    {
        //récuperations des informations saisies dans les lineEdits
        QString Name=ui->lineEdit_NameProjectInput->text();
        QString Description=ui->lineEdit_DescriptionProjectInput->text();
        QString StartDate=ui->dateEdit_StartDateProjectInput->text();
        QString EndDate=ui->dateEdit_EndDateProjectInput->text();
        float Budget=ui->lineEdit_BudgetProjectInput->text().toFloat();//Conversion de la chaine saisie en un reel car Budget est de type float
        QString CustomerID=ui->customerIDInput->currentText();


        //Instantiation d'un objet de type projet en utilisant les informations saisies dans l'interface graphique
        Project P(Name,Description,StartDate,EndDate,Budget,CustomerID);

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

        ui->stackedWidget->setCurrentIndex(18);
    }
}

void MainWindow::on_pushButton_SaveEditProject_clicked()
{

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


    if((ui->lineEdit_IDProjectEdit->text().isEmpty())||(ui->lineEdit_NameProjectEdit->text().isEmpty())||(ui->lineEdit_DescriptionProjectEdit->text().isEmpty())||(ui->dateEdit_StartDateProjectEdit->text().isEmpty())||(ui->dateEdit_EndDateProjectEdit->text().isEmpty())||(ui->lineEdit_BudgetProjectEdit->text().isEmpty()))
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
        QString CustomerID=ui->customerIDEdit->currentText();

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

        ui->stackedWidget->setCurrentIndex(18);
    }
}

void MainWindow::on_comboBoxSortProject_currentTextChanged(const QString &arg1)
{
    QString information =arg1;
   if(information=="ID")
   {

       ui->listView_4->setModel(P.Trier_ID());

       QMessageBox::information(nullptr, QObject::tr("Ok"),
                                QObject::tr("Sort of list of Projects by ID successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
   }

   if(information=="Name")
   {

       ui->listView_4->setModel(P.Trier_Name());

       QMessageBox::information(nullptr, QObject::tr("Ok"),
                                QObject::tr("Sort of list of Projects by name successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
   }

   if(information=="Budget")
   {

       ui->listView_4->setModel(P.Trier_Budget());

       QMessageBox::information(nullptr, QObject::tr("Ok"),
                                QObject::tr("Sort of list of projects by budgets successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
   }

}

void MainWindow::on_pushButton_CancelAddProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_CancelEditProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_Return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
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
     ui->stackedWidget->setCurrentIndex(18);
}



///////Gestion facturation :: Meriam's work begin //////////


/// statistics ///

void MainWindow::statistique()
{
    //pie chart

    QChartView * chartView=new QChartView(o.stat());
    chartView ->setParent(ui->horizontalFrame);
    chartView->setFixedSize(ui->horizontalFrame->size());
}

//menu
void MainWindow::showContextMenuOrder(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos1 = ui->orderListView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu1;



    // Show context menu at handling position
 if (ui->stackedWidget->currentIndex()==34)
 {
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
if(ui->stackedWidget->currentIndex()==35)
{
myMenu.addAction("View", this, SLOT(viewBill()));
myMenu.addAction("Edit",  this, SLOT(editBill()));
myMenu.addAction("Delete", this, SLOT(deleteBill()));
myMenu.addAction("print", this, SLOT(PrintBill()));
myMenu.exec(globalPos);
}
}

/// refresh ///////////////
void MainWindow::initAddBill()
{
    ui->shipperName->setText("");
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
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
    ui->extendedPrice_10->setValue(0);
    ui->status_10->setCurrentIndex(0);

    ui->quantity_10->setValue(0);
    ui->discount_10->setText("");
    ui->comments_10->setText("");
    ui->unitPrice_10->setValue(0);
}

void MainWindow::initAddOrder()
{



    QDate date = QDate::currentDate();
    ui->orderDate->setDate(date);
     ui->requiredDate->setDate(date);


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
    ui->stackedWidget->setCurrentIndex(35);
}
//choose order button from menu
void MainWindow::on_orderButton_clicked()
{
    //refresh affichage
    order o ;
    ui->orderListView->setModel(o.afficherList());
    ui->stackedWidget->setCurrentIndex(34);
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
      ui->orderID_2->setCurrentText(b.getOrderID());
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

void MainWindow::PrintBill()
{
    int i = ui->billListView->currentIndex().data().toInt();
    b.loadData(i);
    b.printPDF();
}
//when u push add bill button
void MainWindow::on_addBill_clicked()
{
ui->orderID->setModel(b.fillOrderIDInBill());
ui->orderID_2->setModel(b.fillOrderIDInBill());
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
    QIntValidator v(0,99999999,this);
    int pos=0;
    QString shipperPhone=ui->shipperPhone->text(),shipperName=ui->shipperName->text();


    QRegularExpression regex("[A-Za-z]+");
    QValidator *validator = new QRegularExpressionValidator(regex, this);


      if((ui->shipperPhone->text().length()==0)  || (ui->shipperName->text().length()==0) || (ui->doubleSpinBox->value()==0)  )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(shipperPhone,pos)) || (ui->shipperPhone->text().length()!=8)  )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("shipperPhone is an 8 digit number .");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
      else if (ui->shipperName->text().size()>20 || ui->shipperName->text().size()<3)
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("the size of the shipper Name is between 3 and 20 !");
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
            b.setOrderID(ui->orderID->currentText());
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
                //reintialisation the add interface
                initAddBill();
         }



ui->tabWidget_3->setCurrentIndex(0);

      }

}


//edit button bill

void MainWindow::on_editButton_clicked()
{


    qDebug() << "bouton: « edit bill » appuyé";

    QMessageBox msg;
    QIntValidator v(0,99999999,this);
    int pos=0;
    QString shipperPhone=ui->shipperPhone_2->text(),billNumber=ui->billNumber_2->text(),shipperName=ui->shipperName_2->text();


    QRegularExpression regex("[A-Za-z]+");
    QValidator *validator = new QRegularExpressionValidator(regex, this);


      if((ui->shipperPhone_2->text().length()==0) || (ui->billNumber_2->text().length()==0)  || (ui->shipperName_2->text().length()==0) || (ui->doubleSpinBox_2->value()==0)  )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(shipperPhone,pos)) || (ui->shipperPhone_2->text().length()!=8)  )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("shipperPhone is an 8 digit number .");
          msg.setStandardButtons(QMessageBox::Ok);
          msg.exec();
      }
      else if (ui->shipperName_2->text().size()>20 || ui->shipperName_2->text().size()<3 )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("the size of the shipper Name is between 3 and 20 !");
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
    b.setOrderID(ui->orderID_2->currentText());
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

    ui->sort_totalAmount->setVisible(true);
    ui->sort_shipperName->setVisible(true);
    ui->sort_releaseDate->setVisible(true);
}

//search bills


void MainWindow::on_search_textChanged(const QString &arg1)
{

         ui->billListView->setModel(b.searchList(arg1));
         if (arg1=="")
          ui->billListView->setModel(b.afficherList());



}

//search orders


void MainWindow::on_searchOrder_textChanged(const QString &arg1)
{


         ui->orderListView->setModel(o.searchList(arg1));

         if (arg1=="")
                ui->orderListView->setModel(o.afficherList());



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
     ui->productCode_10->setCurrentText(o.getProductCode());
     ui->quantity_10->setValue (o.getQuantityOrdered());
     ui->status_10->setCurrentText(o.getStatus());
     ui->orderDate_10->setDate(o.getOrderDate());
     ui->unitPrice_10->setValue(o.getUnitPrice());
     ui->discount_10->setText(o.getDiscount());
     ui->extendedPrice_10->setValue(o.getExtendedPrice());
     ui->requiredDate_10->setDate(o.getRequiredDate());
     ui->customerID_10->setCurrentText(o.getCustomerID());
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

    int i = ui->orderListView->currentIndex().data().toInt();
    QString ch= o.getEmailFromClient(i);
    ui->email_client->setText(ch);
    ui->stackedWidget->setCurrentIndex(36);
    ui->tabWidget->setCurrentIndex(0);

}


void MainWindow::on_addOrder_clicked()
{
    ui->productCode->setModel(o.fillProductIDInOrder());
    ui->customerID_2->setModel(o.fillCustomerIDInOrder());
    ui->productCode_10->setModel(o.fillProductIDInOrder());
    ui->customerID_10->setModel(o.fillCustomerIDInOrder());
    ui->tabWidget_2->setCurrentIndex(1);

}

//add order button////

void MainWindow::on_addButton_2_clicked()
{
    qDebug() << "bouton: « add order » appuyé";

    QMessageBox msg;
    QIntValidator v(0,100000,this);
    int pos=0;
    QString discount=ui->discount->text();

      if( (ui->comments->text().length()==0)|| (ui->discount->text().length()==0)|| (ui->quantity->value()==0) ||  (ui->unitPrice->value()==0) ||  (ui->extendedPrice->value()==0) )
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if(!(v.validate(discount,pos)) )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText("discount is a number .");
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


            o.setProductCode(ui->productCode->currentText());
            o.setQuantityOrdered(ui->quantity->text().toInt());
            o.setStatus(ui->status->currentText());
            o.setOrderDate(ui->orderDate->date());
            o.setUnitPrice(ui->unitPrice->text().toDouble());
            o.setDiscount(ui->discount->text());
            o.setExtendedPrice(ui->extendedPrice->text().toDouble());
            o.setRequiredDate(ui->requiredDate->date());
            o.setCustomerID(ui->customerID_2->currentText());
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

                //reintialisation the add interface
               initAddOrder();
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
    QString discount=ui->discount_10->text();
    QMessageBox msg;
     int id = ui->orderListView->currentIndex().data().toInt();

      if((ui->comments_10->text().length()==0)|| (ui->discount_10->text().length()==0) || (ui->quantity_10->value()==0) || (ui->unitPrice_10->value()==0) || (ui->extendedPrice_10->value()==0))
      {
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setText("no empty fields.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

      }
      else if( !(v.validate(discount,pos)) )
      {
          msg.setIcon(QMessageBox::Critical);
          msg.setText(" discount is a number!");
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
            o.setProductCode(ui->productCode_10->currentText());
            o.setQuantityOrdered(ui->quantity_10->text().toInt());
            o.setStatus(ui->status_10->currentText());
            o.setOrderDate(ui->orderDate_10->date());
            o.setUnitPrice(ui->unitPrice_10->text().toDouble());
            o.setDiscount(ui->discount_10->text());
            o.setExtendedPrice(ui->extendedPrice_10->text().toDouble());
            o.setRequiredDate(ui->requiredDate_10->date());
            o.setCustomerID(ui->customerID_10->currentText());
            o.setComments(ui->comments_10->text());



         bool test= o.edit(id);
         //refresh affichage
           ui->orderListView->setModel(o.afficherList());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("edit dans le tableau");
                 msg.exec();

                  //reintialisation the edit interface
                 initEditOrder();

         }
         else
           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();

                //reintialisation the edit interface
               initEditOrder();
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
    ui->sort_orderID->setVisible(false);
    ui->sort_orderDate->setVisible(false);
    ui->sort_discount->setVisible(false);
    ui->stackedWidget->setCurrentIndex(11);
}



void MainWindow::on_back_2_clicked()
{
    ui->sort_totalAmount->setVisible(false);
    ui->sort_shipperName->setVisible(false);
    ui->sort_releaseDate->setVisible(false);
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
    ui->stackedWidget->setCurrentIndex(36);
    ui->tabWidget->setCurrentIndex(1);

}





//mail sending

void MainWindow::on_sendMailButton_2_clicked()
{

   smtp = new Smtp("recovery.mary2000@gmail.com" , "meriam.123", "smtp.gmail.com",465);
   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

   smtp->sendMail("recovery.mary2000@gmail.com",ui->email_client->text(),ui->subjectLineEdit_2->text(),ui->plainTextEdit_2->toPlainText());



   QMessageBox msg ;
   msg.setIcon(QMessageBox::Information);
    msg.setText("Email ready to send");
       msg.exec();

       ui->stackedWidget->setCurrentIndex(34);
       // reintialisation
       ui->subjectLineEdit_2->setText("");
       ui->plainTextEdit_2->setPlainText("");
}




void MainWindow::on_cancelButton_5_clicked()
{
    initAddOrder();
    ui->tabWidget_2->setCurrentIndex(0);
}


void MainWindow::on_cancelButton_7_clicked()
{
    ui->subjectLineEdit_2->setText("");
    ui->plainTextEdit_2->setPlainText("");
    ui->stackedWidget->setCurrentIndex(34);
}

void MainWindow::on_cancelButton_6_clicked()
{
    initEditBill();
    ui->tabWidget_3->setCurrentIndex(0);
}



void MainWindow::on_signOut_16_clicked()
{
    ui->sort_orderID->setVisible(false);
    ui->sort_orderDate->setVisible(false);
    ui->sort_discount->setVisible(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_18_clicked()
{
    ui->sort_totalAmount->setVisible(false);
    ui->sort_shipperName->setVisible(false);
    ui->sort_releaseDate->setVisible(false);

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

//chedi's work *****************************************************************************************************

void MainWindow::showContextMenuProduct(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView_5->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View Product", this, SLOT(ViewItemProduct()));
    myMenu.addAction("Edit Product",  this, SLOT(EditItemProduct()));
    myMenu.addAction("Delete Product", this, SLOT(DeleteItemProduct()));
    myMenu.addAction("Send Email", this, SLOT(SendEmailToItemProduct()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::DeleteItemProduct()
{
    DeleteConfirmation D;
    D.setModal(true);
    D.exec();

    //Recuperation de l'indice du curseur
    QModelIndex index = ui->listView_5->currentIndex();
    //Recuperation du code du produit sur lequel mon curseur est positionné
    QString itemText = index.data(Qt::DisplayRole).toString();

    if(D.getConfirm()==1)
    {
        //supprimer l'objet P de la table client et on recupére la valeur de retour(query.exec()) dans la variable test
        bool test=P1.Effacer(itemText);

        if(test)//if(test==true)->La requete est executée->QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Deletion of PRODUCT is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView_5->setModel(P1.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion of PRODUCT failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void MainWindow::ViewItemProduct()
{
    QModelIndex index = ui->listView_5->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    ui->tableView_2->setModel(P1.Afficher(itemText));
    ui->stackedWidget->setCurrentIndex(24);
}

void MainWindow::EditItemProduct()
{

    ui->stackedWidget->setCurrentIndex(26);
}

void MainWindow::SendEmailToItemProduct()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_ProductsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_WarehouseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);

}

void MainWindow::on_signOut_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_AddNewProduct_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);


}

void MainWindow::on_pushButton_SortProduct_2_clicked()
{
    ui->listView_5->setModel(P1.Trier());
    QMessageBox::information(nullptr, QObject::tr("SORT "),
                             QObject::tr("sort by Sell-price Done Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_Search_2_clicked()
{
    QString itemText=ui->lineEdit_SearchCustomer_3->text();
    if(P1.Chercher(itemText))
    {
        ui->tableView_2->setModel(P1.Afficher(itemText));
        ui->stackedWidget->setCurrentIndex(23);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("PRODUCT Not Found.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_LoadData_2_clicked()
{

}



void MainWindow::on_signOut_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_Print_4_clicked()
{
    QStringList list;
    QAbstractItemModel *model = ui->tableView_2->model();
    QModelIndex index0 = model->index(0,0);
    QModelIndex index1 = model->index(0,1);
    QModelIndex index2 = model->index(0,2);
    QModelIndex index3 = model->index(0,3);

    QPlainTextEdit text;
    text.setStyleSheet("QPlainTextEdit{color: #ffff00; background-color: #303030;");
    QTextDocument *doc = text.document();
    QFont font = doc->defaultFont();
    font.setBold(true);
    font.setFamily("Arial");
    font.setPixelSize(30);
    doc->setDefaultFont(font);
    text.appendPlainText("                                     Date: "+ui->date->text()+"");
    text.appendPlainText("");
    text.appendPlainText("FLORALLO DEPOT");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("Information of PRODUCT:");
    text.appendPlainText("");
    text.appendPlainText("Product Code: "+index0.data().toString()+"");
    text.appendPlainText("Product Name: "+index1.data().toString()+"");
    text.appendPlainText("Sell Price: "+index2.data().toString()+"");
    text.appendPlainText("Quantity In Stock: "+index3.data().toString()+"");
    QPrinter printer;
    printer.setPrinterName("Print");
    QPrintDialog dlg(&printer,this);
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }
    text.print(&printer);


}

void MainWindow::on_pushButton_Return_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_signOut_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_2_clicked()
{
    smtp = new Smtp("depot.florallo@gmail.com" , "esprit20", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->plainTextEdit_5->toPlainText();

    smtp->sendMail("depot.florallo@gmail.com",ui->lineEdit_Email_3->text(),ui->lineEdit_Subject_3->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_SaveEditProduct_2_clicked()
{
    QString productCode=ui->lineEdit_ProductCodeEdit_2->text();
    QString productName=ui->lineEdit_ProductNameEdit_2->text();
    QString sellPrice=ui->lineEdit_SellPriceEdit_2->text();
    QString quantityInStock=ui->lineEdit_QuantityInStockEdit_2->text();

produit PR(productCode,productName,sellPrice,quantityInStock);
bool test=PR.Editer();

if(test)//if (test==true)->la requete est executÃ©e->QMessageBox::information
       {
           QMessageBox::information(nullptr, QObject::tr("Ok"),
                                    QObject::tr("Edit of PRODUCT is successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

          ui->listView_5->setModel(PR.AfficherListe());
       }
       else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
       {
           QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                 QObject::tr("Edit of PRODUCT failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }

       ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_pushButton_CancelEditProduct_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_signOut_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_SaveAddProduct_2_clicked()
{
    if(ui->lineEdit_ProductCodeInput_2->text().isEmpty())
    {
        ui->lineEdit_ProductCodeInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_ProductCodeInput_2->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_ProductNameInput_2->text().isEmpty())
    {
        ui->lineEdit_ProductNameInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
       ui->lineEdit_ProductNameInput_2->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_QuantityInStockInput_2->text().isEmpty())
    {
        ui->lineEdit_QuantityInStockInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_QuantityInStockInput_2->setStyleSheet("border: 1px solid black");
    }

    if(ui->lineEdit_SellPriceInput_2->text().isEmpty())
    {
        ui->lineEdit_SellPriceInput_2->setStyleSheet("border: 1px solid red");
    }
    else
    {
        ui->lineEdit_SellPriceInput_2->setStyleSheet("border: 1px solid black");
    }

    if((ui->lineEdit_ProductCodeInput_2->text().isEmpty())||(ui->lineEdit_ProductNameInput_2->text().isEmpty())||(ui->lineEdit_QuantityInStockInput_2->text().isEmpty())||(ui->lineEdit_SellPriceInput_2->text().isEmpty()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);

    }
    else
    {

                      QString productCode=ui->lineEdit_ProductCodeInput_2->text();
                      QString productName=ui->lineEdit_ProductNameInput_2->text();
                      QString sellPrice=ui->lineEdit_SellPriceInput_2->text();
                      QString quantityInStock=ui->lineEdit_QuantityInStockInput_2->text();

         produit p(productCode,productName,sellPrice,quantityInStock);
         bool test=p.ajouter();
         if(test)//if (test==true)->la requete est executÃ©e->QMessageBox::information
         {
             QMessageBox::information(nullptr, QObject::tr("Ok"),
                                      QObject::tr("Addition of new PRODUCT is successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

             ui->listView_5->setModel(p.AfficherListe());
             ui->stackedWidget->setCurrentIndex(22);
         }
         else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
         {
             QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                   QObject::tr("Addition of new PRODUCT failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             ui->stackedWidget->setCurrentIndex(23);
         }

    }
}

void MainWindow::on_signOut_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}



void MainWindow::on_pushButton_CancelAddProduct_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}


//arduino
//turn on alarm
void MainWindow::on_pushButton_3_clicked()
{
    A.write_to_arduino("1");

}

//arduino
//turnOffAlarm

void MainWindow::on_pushButton_4_clicked()
{
    A.write_to_arduino("0");

}

//warehouse

void MainWindow::showContextMenuWarehouse(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView_6->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View Warehouse", this, SLOT(viewWarehouse()));
    myMenu.addAction("Edit Warehouse",  this, SLOT(editWarehouse()));
    myMenu.addAction("Delete Warehouse", this, SLOT(deleteWarehouse()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::deleteWarehouse()
{
    DeleteConfirmation D;
    D.setModal(true);
    D.exec();

    QModelIndex index = ui->listView_6->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    if(D.getConfirm()==1)
    {
        //supprimer l'objet P de la table projet et on recupÃ©re la valeur de retour(query.exec()) dans la variable test
        bool test=DEPOT.Effacer(itemText);

        if(test)//if(test==true)->La requete est executÃ©e->QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Deletion WAREHOUSE is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView_6->setModel(DEPOT.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executÃ©e->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion WAREHOUSE failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void MainWindow::viewWarehouse()
{
    QModelIndex index = ui->listView_6->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    ui->tableView_3->setModel(DEPOT.Afficher(itemText));
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::editWarehouse()
{
    ui->stackedWidget->setCurrentIndex(31);
}

void MainWindow::on_pushButton_AddNewWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(32);

}

void MainWindow::on_LoadData_3_clicked()
{
}

void MainWindow::on_signOut_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_Return_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);

}

void MainWindow::on_signOut_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_CancelEditWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);

}

void MainWindow::on_signOut_48_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}



void MainWindow::on_pushButton_SaveEditWarehouse_clicked()
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
  if(test)//if (test==true)->la requete est executÃƒÂ©e->QMessageBox::information
             {
                 QMessageBox::information(nullptr, QObject::tr("Ok"),
                                          QObject::tr("Edit of WAREHOUSE is successful.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);

                 ui->listView_6->setModel(D.AfficherListe());
             }
             else//if(test==false)->la requete n'est pas executÃƒÂ©e->QMessageBox::critical
             {
                 QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                       QObject::tr("Edit of WAREHOUSE failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
             }

             ui->stackedWidget->setCurrentIndex(27);
         }

}

void MainWindow::on_signOut_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_CancelAddWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);

}

void MainWindow::on_pushButton_SaveAddWarehouse_clicked()
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
if(test)//if (test==true)->la requete est executÃƒÂ©e->QMessageBox::information
{
QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("Addition of new warehouse is successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

ui->listView_6->setModel(d.AfficherListe());
ui->stackedWidget->setCurrentIndex(27);
}
else//if(test==false)->la requete n'est pas executÃƒÂ©e->QMessageBox::critical
{
QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                     QObject::tr("Addition of new warehouse failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
ui->stackedWidget->setCurrentIndex(27);
    }
}

}

void MainWindow::on_cancelButton_8_clicked()
{
   ui->stackedWidget->setCurrentIndex(34);
}
//*************************************************************************************************************************
// travail de nessrine
void MainWindow::on_pushButtonADD_clicked()
{
    ui->stackedWidget->setCurrentIndex(39);

}

/*void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
    QString i = ui->listViewSupplier->currentIndex().data().toString();
    s.loadData(i);
    ui->viewID->setText(s.getid());
    ui->viewcampname->setText(s.getcampName());
    ui->viewadress->setText(s.getadress());
    ui->viewville->setText(s.getville());
    ui->viewpays->setText(s.getpays());
    ui->viewfax->setText(s.getfax());
    ui->viewphone->setText(s.gettelephone());
    ui->viewtitle->setText(s.gettitle());
    ui->viewhomepage->setText(s.getpagacc());

}*/

/*void MainWindow::on_pushButton_clicked()
{
    QString i = ui->listViewSupplier->currentIndex().data().toString();
    s.loadData(i);
    ui->lineEdit_editSID->setText(s.getid());
    ui->lineEdit_editCname->setText(s.getcampName());
    ui->lineEdit_editAdress->setText(s.getadress());
    ui->lineEdit_EDitCIty->setText(s.getville());
    ui->lineEdit_editCountry->setText(s.getpays());
    ui->lineEdit_editFAX->setText(s.getfax());
    ui->lineEdit_editPhone->setText(s.gettelephone());
    ui->lineEdit_editcontTitle->setText(s.gettitle());
    ui->lineEdit_EditHomepage->setText(s.getpagacc());
    ui->stackedWidget->setCurrentIndex(40);
}*/

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

    if(ui->lineEdit_Addcontacttitle->text().isEmpty())
    {
        ui->lineEdit_Addcontacttitle->setStyleSheet("border: 2px solid red;");
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

    if(ui->lineEdit_AddPhone->text().isEmpty())
    {
        ui->lineEdit_AddPhone->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_AddCompName->text().isEmpty())
    {
        ui->lineEdit_AddCompName->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEditaddfax->text().isEmpty())
    {
        ui->lineEditaddfax->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->lineEdit_Addhomepage->text().isEmpty())
    {
        ui->lineEdit_Addhomepage->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(test)
    {
        id=ui->lineEditADDSID->text();
        title=ui->lineEdit_Addcontacttitle->text();
        adress=ui->lineEdit_AddAdress->text();
        ville=ui->lineEdit_AddCity->text();
        pays=ui->lineEdit_AddCountry->text();
        campName=ui->lineEdit_AddCompName->text();
        fax=ui->lineEditaddfax->text();
        pagacc=ui->lineEdit_Addhomepage->text();
        telephone=ui->lineEdit_AddPhone->text();

        Suppliers s(id,campName,title,adress,ville,pays,telephone,fax,pagacc);
        bool test2=s.Addsupplier();
        ui->listViewSupplier->setModel(s.afficherList2());//refresh list view


        if(test2)
        {

            QMessageBox :: information(nullptr, QObject :: tr("Add Supplier"),
                                       QObject::tr("supplier Added"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox :: warning(nullptr, QObject :: tr("Add supplier"),
                                   QObject::tr("Error,supplier Not Added :("),QMessageBox::Cancel);

        }

    }
    else
    {
        QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }


    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::on_pushButton_Addcancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);
    //supplier
}

void MainWindow::on_pushButton_matAddlist_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
    //page current ca depend de la nouvelle stacket wideget
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

     ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(43);
    //cancel add de materielle
}

void MainWindow::on_pushButton_SearchMaterial_clicked()
{
    QString id =  ui->lineEdit_SearchMaterial->text();
        qDebug() << id;
        material m;
        bool test=m.search(id);
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

}

void MainWindow::on_lineEdit_SearchMaterial_textChanged(const QString &arg1)
{
    material m ;
    QString info =arg1;
    ui->listViewMateriel->setModel(m.search(info));
}

void MainWindow::on_pushButton_SortMaterial_clicked()
{
    material m;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=m.sortmaterial();
    ui->listViewMateriel->setModel(model);
}

void MainWindow::on_pushButton_statMateriel_clicked()
{
    material m;

    QChartView * chartView=new QChartView(m.statmat());
    chartView ->setParent(ui->horizontalFrame_2);

      ui->stackedWidget->setCurrentIndex(47);
}



void MainWindow::on_pushButton_10_clicked()
{
     ui->stackedWidget->setCurrentIndex(37);
     //pushboutton home_materielle
}

void MainWindow::on_pushButton_confirmMaterialEdit_clicked()
{
    qDebug() << "bouton: « edit material » appuyé";

    QMessageBox msg;
     QString id = ui->listViewMateriel->currentIndex().data().toString();


     //set values
     m.setid(ui->editID->text());
     m.setName(ui->editName->text());
     m.setdescription(ui->editDescription->text());
     m.setQuantity(ui->editQuantity->text());
     m.setUnit(ui->editUnit->text());
     m.setprice(ui->editPrice->text());
     m.setSupplierID(ui->editSupplierID->text());
     m.setCurrency(ui->editCurrency->text());

         bool test= m.EditMaterial(id);
         //refresh affichage
           ui->listViewMateriel->setModel(m.afficherList());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("edit dans le tableau");
                 msg.exec();

                  //reintialisation the add interface


         }
         else

           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();
         }

    ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(43);
     // current index de cancel edit maerielle
}

void MainWindow::on_pushButton_14_clicked()
{
       ui->stackedWidget->setCurrentIndex(43);
    //return view material
}



void MainWindow::on_pushButton_Home_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);
    // current page de la liste home of supplier
}

void MainWindow::on_pushButton_EditSaveSupplier_clicked()
{
    qDebug() << "bouton: « edit supplier » appuyé";

    QMessageBox msg;
     QString id = ui->listViewSupplier->currentIndex().data().toString();


     //set values
     s.setid(ui->lineEdit_editSID->text());
     s.setcampName(ui->lineEdit_editCname->text());
     s.setadress(ui->lineEdit_editAdress->text());
     s.settitle(ui->lineEdit_editcontTitle->text());
     s.setville(ui->lineEdit_EDitCIty->text());
     s.setpays(ui->lineEdit_editCountry->text());
     s.settelephone(ui->lineEdit_editPhone->text());
     s.setfax(ui->lineEdit_editFAX->text());
     s.setpagacc(ui->lineEdit_EditHomepage->text());

         bool test=s.editsupplier(id);
         //refresh affichage
           ui->listViewSupplier->setModel(s.afficherList2());


         if(test)
            { qDebug()<<"done";

             msg.setIcon(QMessageBox::Information);
              msg.setText("edit dans le tableau");
                 msg.exec();

                  //reintialisation the add interface


         }
         else
           { qDebug()<<"error";
               msg.setIcon(QMessageBox::Critical);
             msg.setText("error ");
                msg.exec();
         }
    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::on_pushButton_Editcancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);

}

void MainWindow::on_pushButton_ViewReturn_clicked()
{
     ui->stackedWidget->setCurrentIndex(38);
}



void MainWindow::on_pushButton_7_clicked()
{

    smtp = new Smtp("p.florallo@gmail.com" , "nesrine123", "smtp.gmail.com",465);

    connect(smtp, SIGNAL(status(QString)), this, SLOT(mail(QString)));

    msg=ui->plainTextEdit->toPlainText();

    smtp->sendMail("p.florallo@gmail.com","nesrine.zamni@esprit.tn",ui->lineEditmail->text(),msg);
}

void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(38);
     //cancel send mail
}

void MainWindow::on_pushButton_menusupplier_clicked()
{
    ui->listViewSupplier->setModel(s.afficherList2());
    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::on_pushButton_menuMaterial_clicked()
{
     ui->listViewMateriel->setModel(m.afficherList());
     ui->stackedWidget->setCurrentIndex(43);
}


void MainWindow::on_signOut_63_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_62_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_61_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_60_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_59_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_58_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_57_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_39_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_27_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_28_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_43_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signOut_30_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_31_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_32_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_33_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_34_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_35_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_36_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_profile_10_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_24_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_25_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_26_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_37_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_51_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_16_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_52_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_17_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_53_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_54_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_19_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_55_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_profile_20_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_signOut_56_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnstatmaterial_clicked()
{
     ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_pushButton_return2_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void MainWindow::on_pushButton_arduino_clicked()
{
    ui->stackedWidget->setCurrentIndex(33);

}

void MainWindow::on_pushButton_159_clicked()
{
    produit P1;

        QPieSeries *series = new QPieSeries();
                QSqlQuery query;
                        query=P1.stat();
                while(query.next())
                {
                    series->append(query.value(0).toString(),query.value(3).toInt());
                }

                QChart * chart=new  QChart();
                chart->addSeries(series);
                chart->setTitle("produit");

                QChartView * chartView=new QChartView(chart);
                chartView ->setParent(ui->horizontalFrame_78);
                chartView->setFixedSize(ui->horizontalFrame_78->size());

                ui->stackedWidget->setCurrentIndex(28);



}

void MainWindow::on_signOut_64_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_signOut_65_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_15_clicked()
{
    QPieSeries *series = new QPieSeries();
        QSqlQuery query;
                query=C.stat();
        while(query.next())
        {
            series->append(query.value(0).toString(),query.value(12).toFloat());
        }

        QChart * chart=new  QChart();
        chart->addSeries(series);
        chart->setTitle("Credit limit of customers");

        QChartView * chartView=new QChartView(chart);
        chartView ->setParent(ui->horizontalFrame_3);
        chartView->setFixedSize(ui->horizontalFrame_3->size());
        ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_sortButton_3_clicked()
{
    Employee E;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=E.sortID();
    ui->listView->setModel(model);
}

void MainWindow::on_sortButton_2_clicked()
{
    Employee E;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=E.sortFirstName();
    ui->listView->setModel(model);
}
///meriam sort
void MainWindow::on_sort_totalAmount_clicked()
{
    ui->billListView->setModel(b.afficherOrderedListByTotalAmount());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted by total amount");
    msg.exec();
}



void MainWindow::on_sort_releaseDate_clicked()
{
    ui->billListView->setModel(b.afficherOrderedListByReleaseDate());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted by release date");
    msg.exec();
}

void MainWindow::on_sort_shipperName_clicked()
{
    ui->billListView->setModel(b.afficherOrderedListByShipperName());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted by shipper Name");
    msg.exec();
}



void MainWindow::on_sort_order_clicked()
{
    ui->sort_orderID->setVisible(true);
    ui->sort_orderDate->setVisible(true);
    ui->sort_discount->setVisible(true);
}

void MainWindow::on_sort_discount_clicked()
{
    ui->orderListView->setModel(o.afficherOrderedListByDiscount());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted by discount");
    msg.exec();
}

void MainWindow::on_sort_orderDate_clicked()
{
    ui->orderListView->setModel(o.afficherOrderedListByOrderDate());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted by order date");
    msg.exec();
}

void MainWindow::on_sort_orderID_clicked()
{
    ui->orderListView->setModel(o.afficherOrderedListByOrderID());

    QMessageBox msg ;
    msg.setIcon(QMessageBox::Information);
    msg.setText("table sorted by order id");
    msg.exec();
}
///// end meriam second part
///
/////nesrine

void MainWindow::on_print_clicked()
{
    QPrinter printer;
    printer.setPrinterName("my_printer_Supplier");
    QPrintDialog dialog(&printer,this);
    if ( dialog.exec()== QDialog::Rejected) return ;
    QString id;
    QString campName;
    QString title;
    QString adress;
    QString ville;
    QString pays;
    QString telephone;
    QString fax;
    QString pagacc;

    id= ui->viewID->text();
    campName=ui->viewcampname->text();
    title=ui->viewtitle->text();
    adress=ui->viewadress->text();
    ville=ui->viewville->text();
    pays=ui->viewpays->text();
    telephone=ui->viewphone->text();
    fax=ui->viewfax->text();
    pagacc=ui->viewhomepage->text();


    QPainter painter(this);
    painter.begin(&printer);
    Suppliers s(id,campName,title,adress,ville,pays,telephone,fax,pagacc);

    /*  QString text = "Id :" + id + "\n"
                        + " Company name : " + campName + "\n"
                        + " Title: " + title + "\n"
            + " Adress: " + adress + "\n"
            + " City : " + ville + "\n"
            + " Country: " + pays + "\n"
            + " Phone number : " + telephone + "\n"
            + " Fax : " + fax + "\n"
            + " Home page : " + pagacc  ;
*/
    QFont font = painter.font();
    font.setPointSize(font.pointSize() * 2);
    painter.setFont(font);
    QImage image(":/floralloLogo.png");
    painter.setPen(Qt::cyan);
    painter.drawImage(480,-20,image);
    painter.drawText(230,90,"Supplier inforamtion  : ");

    painter.setPen(Qt::darkBlue);

    painter.drawText(130,160,"id : ");
    painter.drawText(130,185,"Campany name : ");

    painter.drawText(130,210,"Title : ");
    painter.drawText(130,235,"Adress : ");
    painter.drawText(130,260,"City : ");
    painter.drawText(130,285,"Country: ");
    painter.drawText(130,310,"Phone number : ");
    painter.drawText(130,335,"Fax : ");
    painter.drawText(130,360,"Home page : ");


    painter.setPen(Qt::black);

    painter.drawText(300,160,id);
    painter.drawText(300,185,campName);
    painter.drawText(300,210,title);
    painter.drawText(300,235,adress);
    painter.drawText(300,260,ville);
    painter.drawText(300,285,pays);
    painter.drawText(300,310,telephone);
    painter.drawText(300,335,fax);
    painter.drawText(300,360,pagacc);




    painter.end();
}
void MainWindow::editSupplier()
{


    QString i = ui->listViewSupplier->currentIndex().data().toString();
    s.loadData(i);
    ui->lineEdit_editSID->setText(s.getid());
    ui->lineEdit_editCname->setText(s.getcampName());
    ui->lineEdit_editAdress->setText(s.getadress());
    ui->lineEdit_EDitCIty->setText(s.getville());
    ui->lineEdit_editCountry->setText(s.getpays());
    ui->lineEdit_editFAX->setText(s.getfax());
    ui->lineEdit_editPhone->setText(s.gettelephone());
    ui->lineEdit_editcontTitle->setText(s.gettitle());
    ui->lineEdit_EditHomepage->setText(s.getpagacc());
    ui->stackedWidget->setCurrentIndex(40);


}
void MainWindow::viewSupplier()
{


    ui->stackedWidget->setCurrentIndex(41);
    QString i = ui->listViewSupplier->currentIndex().data().toString();
    s.loadData(i);
    ui->viewID->setText(s.getid());
    ui->viewcampname->setText(s.getcampName());
    ui->viewadress->setText(s.getadress());
    ui->viewville->setText(s.getville());
    ui->viewpays->setText(s.getpays());
    ui->viewfax->setText(s.getfax());
    ui->viewphone->setText(s.gettelephone());
    ui->viewtitle->setText(s.gettitle());
    ui->viewhomepage->setText(s.getpagacc());
}
void MainWindow::deleteSupplier()
{
 DeleteConfirmation d;
       QMessageBox msg;

    d.exec();

   if(d.getConfirm()==1)
    {
       bool test= s.deletesupplier(ui->listViewSupplier->currentIndex().data().toString());

       //refresh affichage
       ui->listViewSupplier->setModel(s.afficherList2());

       if(test==true)
           {

            msg.setText("supplier deleted ");
            msg.exec();
           }

   }
   else
   {

        msg.setText("error ");
        msg.exec();
   }
}
void MainWindow::SendMail()
{

 ui->stackedWidget->setCurrentIndex(42);

}
void MainWindow::deleteMaterial()
{

    DeleteConfirmation d;
       QMessageBox msg;



    d.exec();

   if(d.getConfirm()==1)
    {
       bool test= m.deleteMaterial(ui->listViewMateriel->currentIndex().data().toString());

       //refresh affichage
       ui->listViewMateriel->setModel(m.afficherList());

       if(test==true)
           {

            msg.setText("material deleted ");
            msg.exec();
           }

   }
   else
   {

        msg.setText("error ");
        msg.exec();
   }



}
void MainWindow::viewMaterial()
{

    ui->stackedWidget->setCurrentIndex(46);
    QString i = ui->listViewMateriel->currentIndex().data().toString();
    m.loadData(i);
    ui->lineEdit_ViewMaterialID->setText(m.getid());
    ui->lineEdit_ViewMatDes->setText(m.getDescription());
    ui->lineEdit_ViewMatName->setText(m.getName());
    ui->lineEdit_ViewMatSuppID->setText(m.getSupplierID());
    ui->lineEdit_ViewMatQuantite->setText(m.getQuantity());
    ui->lineEdit_ViewMatPrice->setText(m.getprice());
    ui->lineEdit_ViewMatUnit->setText(m.getUnit());
    ui->lineEdit_ViewMatcurrency->setText(m.getcurrency());


}

void MainWindow::editMaterial()
{


    QString i = ui->listViewMateriel->currentIndex().data().toString();
    m.loadData(i);
    ui->editID->setText(m.getid());
    ui->editDescription->setText(m.getDescription());
    ui->editName->setText(m.getName());
    ui->editSupplierID->setText(m.getSupplierID());
    ui->editQuantity->setText(m.getQuantity());
    ui->editPrice->setText(m.getprice());
    ui->editUnit->setText(m.getUnit());
    ui->editCurrency->setText(m.getcurrency());
    ui->stackedWidget->setCurrentIndex(45);





}






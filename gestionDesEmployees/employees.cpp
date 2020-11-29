#include "employees.h"
#include "ui_employees.h"

Employees::Employees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employees)
{
    ui->setupUi(this);

    loadData();

    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //Employees List
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    //Place Holder
    ui->searchLineEdit->setPlaceholderText("  Enter Employee ID...");
    ui->idLineEdit->setPlaceholderText("  Enter ID");
    ui->firstNameLineEdit->setPlaceholderText("  Enter First Name");
    ui->lastNameLineEdit->setPlaceholderText("  Enter Last Name");
    ui->phoneNumberLineEdit->setPlaceholderText("  Enter Phone Number");
    ui->adressLineEdit->setPlaceholderText("  Enter Adress");
    ui->salaryLineEdit->setPlaceholderText("  Enter Salary");
    ui->emailLineEdit->setPlaceholderText("  Enter Email");
    ui->subjectLineEdit->setPlaceholderText("Subject");

    //Controle De Saisie
    ui->idLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->firstNameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lastNameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->phoneNumberLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{7,15}")));
    ui->adressLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->salaryLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->idLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{7}")));
    ui->firstNameLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lastNameLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->phoneNumberLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->adressLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->salaryLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]")));

}

Employees::~Employees()
{
    delete ui;
}

void Employees::loadData()
{
    Employee E;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=E.loadData();
    ui->listWidget->setModel(model);
}

void Employees::showTime()
{
    QTime time=QTime::currentTime();

    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);
    ui->time2->setText(time_text);
    ui->time3->setText(time_text);
    ui->time4->setText(time_text);
    ui->time5->setText(time_text);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date2->setText(datetimetext);
    ui->date3->setText(datetimetext);
    ui->date4->setText(datetimetext);
    ui->date5->setText(datetimetext);
}

void Employees::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(viewEmployee()));
    myMenu.addAction("Edit",  this, SLOT(editEmployee()));
    myMenu.addAction("Delete", this, SLOT(deleteEmployee()));
    myMenu.addAction("Send Email", this, SLOT(sendEmailToEmployee()));

    myMenu.exec(globalPos);
}

void Employees::deleteEmployee()
{
    DeleteConfirmation D;
    D.setModal(true);
    D.exec();

    QModelIndex index = ui->listWidget->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    if(D.getConfirm()==1)
    {
        Employee E;
        bool test=E.Delete(info);

        if(test)
        {
             loadData();
        }
    }
}

void Employees::viewEmployee()
{
    QModelIndex index = ui->listWidget->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Employee E;
    view=E.read(info);

          ui->viewID->setText(view.value(0).toString());
          ui->viewFirstName->setText(view.value(1).toString());
          ui->viewLastName->setText(view.value(2).toString());
          ui->viewBirthDate->setText(view.value(5).toString());
          ui->viewSex->setText(view.value(3).toString());
          ui->viewAdress->setText(view.value(4).toString());
          ui->viewPhoneNumber->setText(view.value(9).toString());
          ui->viewSalary->setText(view.value(10).toString());
          ui->viewHireDate->setText(view.value(6).toString());
          ui->viewJobTitle->setText(view.value(7).toString());
          ui->viewEmail->setText(view.value(8).toString());


    ui->stackedWidget->setCurrentIndex(3);
}

void Employees::editEmployee()
{
    QModelIndex index = ui->listWidget->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Employee E;
    view=E.read(info);

          ui->idLineEdit_2->setText(view.value(0).toString());
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


    ui->stackedWidget->setCurrentIndex(2);
}

void Employees::sendEmailToEmployee()
{
    QModelIndex index = ui->listWidget->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();
    QSqlQuery view;
    Employee E;
    view=E.read(info);

         mail=view.value(8).toString();


    ui->stackedWidget->setCurrentIndex(4);
}

void Employees::on_addButton_clicked()
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

    if(ui->idLineEdit->text().isEmpty())
    {
        ui->idLineEdit->setStyleSheet("border: 2px solid red;");
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
        phoneNumber = ui->phoneNumberLineEdit->text().toInt();
        salary = ui->salaryLineEdit->text().toFloat();
        id = ui->idLineEdit->text();
        firstName = ui->firstNameLineEdit->text();
        lastName = ui->lastNameLineEdit->text();
        adresse = ui->adressLineEdit->text();
        birthDate = ui->birthDateEdit->text();
        hireDate = ui->hireDateEdit->text();
        email = ui->emailLineEdit->text();
        jobTitle = ui->jobTitleBox->currentText();

        Employee E(phoneNumber,salary,id,firstName,lastName,sex,adresse,birthDate,hireDate,jobTitle,email);

        bool test2 = E.create();
        if(test2)
        {
            QMessageBox :: information(nullptr, QObject :: tr("Add Employee"),
                                       QObject::tr("Employee Added"),QMessageBox::Cancel);

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

void Employees::on_cancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    loadData();
}

void Employees::on_saveButton_clicked()
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

    if(ui->idLineEdit_2->text().isEmpty())
    {
        ui->idLineEdit_2->setStyleSheet("border: 2px solid red;");
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


    if(ui->maleRadioButton_2->isCheckable())
    {
        sex="male";
    }

    if(ui->femaleRadioButton_2->isCheckable())
    {
        sex="female";
    }

    if(sex !="male" && sex != "female")
    {
        ui->maleRadioButton_2->setStyleSheet("border: 2px solid red;");
        ui->femaleRadioButton_2->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(test)
    {
        phoneNumber = ui->phoneNumberLineEdit_2->text().toInt();
        salary = ui->salaryLineEdit_2->text().toFloat();
        id = ui->idLineEdit_2->text();
        firstName = ui->firstNameLineEdit_2->text();
        lastName = ui->lastNameLineEdit_2->text();
        adresse = ui->adressLineEdit_2->text();
        birthDate = ui->birthDateEdit_2->text();
        hireDate = ui->hireDateEdit_2->text();
        jobTitle = ui->jobTitleBox_2->currentText();
        email = ui->emailLineEdit_2->text();


        Employee E(phoneNumber,salary,id,firstName,lastName,sex,adresse,birthDate,hireDate,jobTitle,email);

        bool test2 = E.Update();
        if(test2)
        {
            QMessageBox :: information(nullptr, QObject :: tr("Update Employee"),
                                       QObject::tr("Employee Updated"),QMessageBox::Cancel);

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

void Employees::on_cancelButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    loadData();
}

void Employees::on_addEmployeeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Employees::on_returnButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    loadData();
}

void Employees::on_profileButton_clicked()
{
    emit goToProfile();
}

void Employees::on_printButton_clicked()
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
    text.appendPlainText("Print Time: "+ui->date->text()+"");
    text.appendPlainText("");
    text.appendPlainText("");
    text.appendPlainText("Employee information:");
    text.appendPlainText("");
    text.appendPlainText("ID: "+ui->viewID->text()+"");
    text.appendPlainText("First Name: "+ui->viewFirstName->text()+"");
    text.appendPlainText("Last Name: "+ui->viewLastName->text()+"");
    text.appendPlainText("Birth Date: "+ui->viewBirthDate->text()+"");
    text.appendPlainText("Sex: "+ui->viewSex->text()+"");
    text.appendPlainText("Email: "+ui->viewEmail->text()+"");
    text.appendPlainText("Address: "+ui->viewAdress->text()+"");
    text.appendPlainText("Phone Number: "+ui->viewPhoneNumber->text()+"");
    text.appendPlainText("Salary: "+ui->viewSalary->text()+"");
    text.appendPlainText("Hire Date: "+ui->viewHireDate->text()+"");
    text.appendPlainText("Job Title: "+ui->viewJobTitle->text()+"");

    QPrinter printer;
    printer.setPrinterName("Print");
    QPrintDialog dlg(&printer,this);
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }
    text.print(&printer);

}

void Employees::on_sendMailButton_clicked()
{
   smtp = new Smtp("human.resources.florallo@gmail.com" , "khairiisthebest7", "smtp.gmail.com",465);
   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

   msg=ui->plainTextEdit->toPlainText();

   smtp->sendMail("human.resources.florallo@gmail.com",mail,ui->subjectLineEdit->text(),msg);
}

void Employees::on_cancelButton_3_clicked()
{
    loadData();
    ui->stackedWidget->setCurrentIndex(0);
}

void Employees::on_sortButton_clicked()
{
    Employee E;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=E.sort();
    ui->listWidget->setModel(model);
}

void Employees::on_searchLineEdit_textChanged(const QString &arg1)
{
    Employee E;
    QString info =arg1;
    if(info!="")
    ui->listWidget->setModel(E.search(info));
    else
        loadData();

}

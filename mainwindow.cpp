#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadData();

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

    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

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


    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date_2->setText(datetimetext);
    ui->date_3->setText(datetimetext);
    ui->date_4->setText(datetimetext);
    ui->date_5->setText(datetimetext);
    ui->date_6->setText(datetimetext);
    ui->date_7->setText(datetimetext);

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
        //ui->stackedWidget->setCurrentIndex("7ot lehna r9am l'widget mte3k");
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

void MainWindow::statistics()
{

    Employee E;
    QChartView * chartView=new QChartView(E.statistic());
    chartView ->setParent(ui->statisticFrame);

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

void MainWindow::on_statisticButton_clicked()
{
    statistics();
    ui->stackedWidget->setCurrentIndex(10);
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

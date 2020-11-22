#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    //Place Holder
    ui->idLineEdit->setPlaceholderText("  Enter ID");
    ui->passwordLineEdit->setPlaceholderText("  Enter Password");
    ui->idLineEdit_2->setPlaceholderText("  Enter ID");
    ui->passwordLineEdit_2->setPlaceholderText("  Enter Password");

    ui->idLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->idLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));
    ui->passwordLineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+")));

    //Animation
    animation=new QPropertyAnimation(ui->loginTitle,"geometry");
    animation->setDuration(2000);
    animation->setStartValue(ui->loginTitle->geometry());
    animation->setEndValue(QRect(340,90,291,61));
    animation->start();

    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //Signals
    connect(&employees, SIGNAL(goToProfile()), this, SLOT(on_cancelButton_2_clicked()));
    ui->stackedWidget->insertWidget(4, &employees);
}

Login::~Login()
{
    delete ui;
}

void Login::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);
    ui->time_2->setText(time_text);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString();
    ui->date->setText(datetimetext);
    ui->date_2->setText(datetimetext);
}

void Login::on_signInButton_clicked()
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
            view.next();
            qDebug() << view.value(1).toString();
            if(view.value(1).toString() == ui->passwordLineEdit->text())
            {
                 ui->viewID->setText(view.value(0).toString());
                 ui->viewPassword->setText(view.value(1).toString());
                 ui->viewJobTitle->setText(view.value(2).toString());
                 ui->stackedWidget->setCurrentIndex(2);
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

void Login::on_goToSignUpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Login::on_SignUpButton_clicked()
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

         bool test2 = P.create();
         if(test2)
         {
             QMessageBox :: information(nullptr, QObject :: tr("Add Account"),
                                        QObject::tr("Account Added :)"),QMessageBox::Cancel);
         }
         else
         {
             QMessageBox :: warning(nullptr, QObject :: tr("Add Account"),
                                        QObject::tr("Error, Account Not Added :("),QMessageBox::Cancel);

         }

     }
     else
     {
          QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
     }

}

void Login::on_goToSignInButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Login::on_changeInformationButton_clicked()
{
    QString info = ui->viewID->text();
    QSqlQuery view;
    Profile P;
    view=P.read(info);

    while(view.next())
    {
          ui->idLineEdit_3->setText(view.value(0).toString());
          ui->passwordLineEdit_3->setText(view.value(1).toString());
    }

    ui->stackedWidget->setCurrentIndex(3);
}

void Login::on_deleteAccountButton_clicked()
{
    DeleteConfirmation D;
    D.setModal(true);
    D.exec();

    QString info = ui->viewID->text();
    if(D.getConfirm()==1)
    {
        Profile P;
        bool test=P.Delete(info);

        if(test)
        {
             QMessageBox::information(this, tr("Employee Deleted"),tr("OK"), QMessageBox::Ok);
             ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

void Login::on_logOutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Login::on_logOutButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Login::on_access1Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Login::on_access2Button_clicked()
{

}

void Login::on_cancelButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Login::on_saveButton_clicked()
{
    bool test=true;
    QString id;
    QString password;
    QString jobTitle;

    if(ui->idLineEdit_3->text().isEmpty())
    {
        ui->idLineEdit_3->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(ui->passwordLineEdit_3->text().isEmpty())
    {
        ui->passwordLineEdit_3->setStyleSheet("border: 2px solid red;");
        test=false;
    }

    if(test)
    {
        id = ui->idLineEdit_3->text();
        password = ui->passwordLineEdit_3->text();
        jobTitle = ui->jobTitleBox_2->currentText();

        Profile P(id,password,jobTitle);

        bool test2 = P.Update();
        if(test2)
        {
            QMessageBox :: information(nullptr, QObject :: tr("Update Account Information"),
                                       QObject::tr("Account Information Updated"),QMessageBox::Cancel);

            QSqlQuery view = P.read(id);
            view.next();
            ui->viewID->setText(view.value(0).toString());
            ui->viewPassword->setText(view.value(1).toString());
            ui->viewJobTitle->setText(view.value(2).toString());
            ui->stackedWidget->setCurrentIndex(2);
        }
        else
        {
            QMessageBox :: warning(nullptr, QObject :: tr("Update Account Information"),
                                       QObject::tr("Error: Account Information Not Updated :("),QMessageBox::Cancel);

        }

    }
    else
    {
         QMessageBox::warning(this, tr("Warning"),tr("Please Fill The required Fields Marked In Red."), QMessageBox::Ok);
    }

}

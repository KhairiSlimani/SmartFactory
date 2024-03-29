#include "projects.h"
#include "ui_projects.h"
#include "projet.h"


Projects::Projects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Projects)
{
    ui->setupUi(this);
    ui->listView->setModel(P.AfficherListe());

    //Time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();


    //Project's list
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));



    //Place Holder For Add New Customer
    ui->lineEdit_IDProjectInput->setPlaceholderText(" Enter ID");
    ui->lineEdit_NameProjectInput->setPlaceholderText(" Enter Name");
    ui->lineEdit_DescriptionProjectInput->setPlaceholderText(" Enter Description");
    ui->lineEdit_BudgetProjectInput->setPlaceholderText(" Enter Budget");
    ui->lineEdit_CustomerIDProjectInput->setPlaceholderText(" Enter Customer ID");

    //Place Holder For Edit Customer
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

    animation=new QPropertyAnimation(ui->label_2,"geometry");
    animation->setDuration(10000);
    animation->setLoopCount(4);
    animation->setStartValue(ui->label_2->geometry());
    animation->setEndValue(QRect(210,50,251,51));
    animation->start();

}

Projects::~Projects()
{
    delete ui;
}

void Projects::showTime()
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
void Projects::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(viewProject()));
    myMenu.addAction("Edit",  this, SLOT(editProject()));
    myMenu.addAction("Delete", this, SLOT(deleteProject()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void Projects::deleteProject()
{
    deleteconfirmation D;
    D.setModal(true);
    D.exec();

    QModelIndex index = ui->listView->currentIndex();
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
            ui->listView->setModel(P.AfficherListe());
        }
        else//if(test==false)->la requete n'est pas executée->QMessageBox::critical
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Deletion Project failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void Projects::viewProject()
{
    QModelIndex index = ui->listView->currentIndex();
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

    ui->stackedWidget->setCurrentIndex(2);
}

void Projects::editProject()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void Projects::on_pushButton_AddNewProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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

void Projects::on_pushButton_SaveAddProject_clicked()
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


    if(ui->dateEdit_StartDateProjectInput->text()=="01/01/2000")
    {
        ui->dateEdit_StartDateProjectInput->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;");
    }
    else
    {
        ui->dateEdit_StartDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;");

    }

    if(ui->dateEdit_EndDateProjectInput->text()=="01/01/2000")
    {
        ui->dateEdit_EndDateProjectInput->setStyleSheet("border: 2px solid red;"
                                                       "padding: 1px;");
    }
    else
    {
        ui->dateEdit_EndDateProjectInput->setStyleSheet("border: 2px solid black;"
                                                       "padding: 1px;");

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
        Projet P(ID,Name,Description,StartDate,EndDate,Budget,CustomerID);

        //Inserer l'objet P dans la table projet et recuperer la valeur de retour de query.exec() dans la variable test.
        bool test=P.Ajouter();

        if(test)//Si la requete a ete executé convenablement
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Addition of new Project is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView->setModel(P.AfficherListe());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Addition of new Project failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->stackedWidget->setCurrentIndex(3);
    }

}

void Projects::on_pushButton_CancelAddProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Projects::on_pushButton_SaveEditProject_clicked()
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
        Projet P(ID,Name,Description,StartDate,EndDate,Budget,CustomerID);

        //Inserer l'objet P dans la table projet et recuperer la valeur de retour de query.exec() dans la variable test.
        bool test=P.Editer();

        if(test)//Si la requete a ete executé convenablement
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Edit Project is successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->listView->setModel(P.AfficherListe());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Edit Project failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->stackedWidget->setCurrentIndex(3);
    }
}



void Projects::on_pushButton_CancelEditProject_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Projects::on_pushButton_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Projects::on_signOut_8_clicked()
{
    emit(HomeClicked());
}

void Projects::on_signOut_5_clicked()
{
    emit(HomeClicked());
}

void Projects::on_signOut_6_clicked()
{
    emit(HomeClicked());
}

void Projects::on_signOut_7_clicked()
{
    emit(HomeClicked());
}


void Projects::on_pushButton_SortProject_clicked()
{
     ui->listView->setModel(P.Trier());
}

void Projects::on_lineEdit_SearchProject_textChanged(const QString &arg1)
{
    QString information =arg1;
    ui->listView->setModel(P.chercher(information));
    if(ui->lineEdit_SearchProject->text()=="")
    {
        ui->listView->setModel(P.AfficherListe());
    }
}

void Projects::on_pushButton_Print_clicked()
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

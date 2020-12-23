#ifndef PROJECT_H
#define PROJECT_H


#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Project
{

  private:
    QString ID;
    QString Name;
    QString Description;
    QString StartDate;
    QString EndDate;
    float Budget;
    QString CustomerID;

public:
    //getters
    QString getID(){return ID;}
    QString getName(){return Name;}
    QString getDescription(){return Description;}
    QString getStartDate(){return StartDate;}
    QString getEndDate(){return EndDate;}
    float getBudget(){return Budget;}
    QString getCustomerID(){return CustomerID;}

    //Setters
    void setID(QString ID){this->ID=ID;}
    void setName(QString Name){this->Name=Name;}
    void setDescription(QString Description){this->Description=Description;}
    void setStartDate(QString StartDate){this->StartDate=StartDate;}
    void setEndDate(QString EndDate){this->EndDate=EndDate;}
    void setBudget(float Budget){this->Budget=Budget;}
    void setCustomerID(QString CustomerID){this->CustomerID=CustomerID;}

    //Constructors
    Project();
    Project(QString,QString,QString,QString,float,QString);
    Project(QString,QString,QString,QString,QString,float,QString);

    bool Ajouter();
    bool Editer();
    QSqlQuery LoadData();
    QSqlQueryModel* AfficherListe();
    bool Effacer(QString);
    QSqlQuery Lire(QString itemText);
    QSqlQueryModel* Trier();
    QSqlQueryModel *chercher(QString information);
};
#endif // PROJECT_H

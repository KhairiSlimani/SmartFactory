#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet
{

  private:
    QString ID;
    QString Name;
    QString Description;
    QString StartDate;
    QString EndDate;
    float Budget;
    QString CustomerID;
    QString OrderID;
public:
    //getters
    QString getID(){return ID;}
    QString getName(){return Name;}
    QString getDescription(){return Description;}
    QString getStartDate(){return StartDate;}
    QString getEndDate(){return EndDate;}
    float getBudget(){return Budget;}
    QString getCustomerID(){return CustomerID;}
    QString getOrderID(){return OrderID;}

    //Setters
    void setID(QString ID){this->ID=ID;}
    void setName(QString Name){this->Name=Name;}
    void setDescription(QString Description){this->Description=Description;}
    void setStartDate(QString StartDate){this->StartDate=StartDate;}
    void setEndDate(QString EndDate){this->EndDate=EndDate;}
    void setBudget(float Budget){this->Budget=Budget;}
    void setCustomerID(QString CustomerID){this->CustomerID=CustomerID;}
    void setOrderID(QString OrderID){this->OrderID=OrderID;}

    //Constructors
    Projet();
    Projet(QString,QString,QString,QString,QString,float,QString,QString);

    bool Ajouter();
    QSqlQueryModel* Afficher(QString itemText);
    bool Editer();
    QSqlQuery LoadData();
    QSqlQueryModel* AfficherListe();
    bool Effacer(QString);
};

#endif // PROJET_H

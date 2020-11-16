#include "projet.h"



Projet::Projet()
{
  ID="";
  Name="";
  Description="";
  CustomerID="";
  OrderID="";
}

Projet::Projet(QString ID,QString Name,QString Description,QString StartDate,QString EndDate,float Budget,QString CustomerID,QString OrderID)
{
   this->ID=ID;
   this->Name=Name;
   this->Description=Description;
   this->StartDate=StartDate;
   this->EndDate=EndDate;
   this->CustomerID=CustomerID;
   this->Budget=Budget;
   this->OrderID=OrderID;
}

bool Projet::Ajouter()
{
    QSqlQuery query;
    QString BudgetS=QString::number(Budget);
    query.prepare("INSERT INTO projet(ID, Name, Description, StartDate, EndDate, Budget, CustomerID, OrderID)" "VALUES(:ID, :Name, :Description, :StartDate, :EndDate, :Budget, :CustomerID, :OrderID)");

    query.bindValue(":ID",ID);
    query.bindValue(":Name",Name);
    query.bindValue(":Description",Description);
    query.bindValue(":StartDate",StartDate);
    query.bindValue(":EndDate",EndDate);
    query.bindValue(":Budget",BudgetS);
    query.bindValue(":CustomerID",CustomerID);
    query.bindValue(":OrderID",OrderID);

    return query.exec();
}

QSqlQuery Projet::LoadData()
{
    QSqlQuery query;
    query.prepare("select id from projet");
    return query;
}

QSqlQuery Projet::Afficher(QString itemText)
{
    QSqlQuery query;
    query.prepare("select * from projet where id='"+itemText+"'");
    return query;
}

bool Projet::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from projet where id='"+itemText+"'");
    return query.exec();
}

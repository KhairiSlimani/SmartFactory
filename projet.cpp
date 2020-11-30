#include "projet.h"


Projet::Projet()
{
  ID="";
  Name="";
  Description="";
  StartDate="";
  EndDate="";
  Budget=0;
  CustomerID="";
}

Projet::Projet(QString ID,QString Name,QString Description,QString StartDate,QString EndDate,float Budget,QString CustomerID)
{
   this->ID=ID;
   this->Name=Name;
   this->Description=Description;
   this->StartDate=StartDate;
   this->EndDate=EndDate;
   this->CustomerID=CustomerID;
   this->Budget=Budget;
}

bool Projet::Ajouter()
{
    QSqlQuery query;
    QString BudgetS=QString::number(Budget);
    //prepare prend la requete en parametre pour la preparer a l'execution:
    query.prepare("INSERT INTO projet(ID, Name, Description, StartDate, EndDate, Budget, CustomerID)" "VALUES(:ID, :Name, :Description, :StartDate, :EndDate, :Budget, :CustomerID)");

    //Creation des variables liées
    query.bindValue(":ID",ID);
    query.bindValue(":Name",Name);
    query.bindValue(":Description",Description);
    query.bindValue(":StartDate",StartDate);
    query.bindValue(":EndDate",EndDate);
    query.bindValue(":Budget",BudgetS);
    query.bindValue(":CustomerID",CustomerID);

    return query.exec();//exec() envoie la requete a executer.
}

bool Projet::Editer()
{
    QSqlQuery query;
    QString BudgetS=QString::number(Budget);


    //Prepare() prend la requete en parametre pour la préparer a l'execution
    query.prepare("update projet set ID='"+ID+"',Name='"+Name+"',Description='"+Description+"',StartDate='"+StartDate+"',EndDate='"+EndDate+"',Budget='"+BudgetS+"',CustomerID='"+CustomerID+"' where ID='"+ID+"'");

    //Creation des variables liées
    query.bindValue(":ID",ID);
    query.bindValue(":Name",Name);
    query.bindValue(":Description",Description);
    query.bindValue(":StartDate",StartDate);
    query.bindValue(":EndDate",EndDate);
    query.bindValue(":Budget",BudgetS);
    query.bindValue(":CustomerID",CustomerID);

    //exec() envoie la requete pour l'executer
    return query.exec();
}


QSqlQuery Projet::LoadData()
{
    QSqlQuery query;
    query.prepare("select id from projet");
    return query;
}


QSqlQueryModel* Projet::AfficherListe()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery query=LoadData();
    query.exec();
    modal->setQuery(query);
    return modal;
}

bool Projet::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from projet where id='"+itemText+"'");
    return query.exec();
}


QSqlQuery Projet::Lire(QString itemText)
{
    QSqlQuery query;
    query.prepare("select * from Projet where id='"+itemText+"'");
    query.exec();

    return query;

}



QSqlQueryModel* Projet::Trier()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry ;
    qry.prepare(" SELECT ID FROM PROJET ORDER BY BUDGET DESC");
    qry.exec();

    model->setQuery(qry);
    return model;
}



QSqlQueryModel * Projet::chercher(QString information)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select id from Projet where id='"+information+"'");
    query.exec();
    model->setQuery(query);
    return model;
}

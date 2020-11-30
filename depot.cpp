#include "depot.h"
#include <QString>


depot::depot()
{
  warehouseID="";
  typeOfProduct="";
  nameOfDepotManager="";

}

depot::depot(QString NVwarehouseID, QString NVtypeOfProduct , QString NVnameOfDepotManager )
{

    this-> warehouseID=NVwarehouseID;
    this->typeOfProduct=NVtypeOfProduct;
    this-> nameOfDepotManager=NVnameOfDepotManager;
}


bool depot:: ajouter()
{
    QSqlQuery query;

//Prepare() prend la requete en parametre pour la prÃ©parer a l'execution
  query.prepare("INSERT INTO depot (warehouseID, typeOfProduct,nameOfDepotManager)" "VALUES (:warehouseID,:typeOfProduct,:nameOfDepotManager)");
  query.bindValue(":warehouseID",warehouseID);
  query.bindValue(":typeOfProduct",typeOfProduct);
  query.bindValue(":nameOfDepotManager",nameOfDepotManager);

  //exec() envoie la requete pour l'executer
   return query.exec();

}


bool depot::Editer()
{
    QSqlQuery query;

    //Prepare() prend la requete en parametre pour la prÃ©parer a l'execution
    query.prepare("update depot set warehouseID='"+warehouseID+"',typeOfProduct='"+typeOfProduct+"',nameOfDepotManager='"+nameOfDepotManager+"' where warehouseID='"+warehouseID+"'");

    //Creation des variables liÃ©es
    query.bindValue(":warehouseID",warehouseID);
    query.bindValue(":typeOfProduct",typeOfProduct);
    query.bindValue(":nameOfDepotManager",nameOfDepotManager);

    //exec() envoie la requete pour l'executer
    return query.exec();
}

QSqlQueryModel* depot::Afficher(QString itemText)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from depot WHERE warehouseID='"+itemText+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("warehouse ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type Of Product"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("name Of Depot Manager"));
    return model;
}


QSqlQuery depot::LoadData()
{
    QSqlQuery query;
    query.prepare("select warehouseID from depot");
    return query;
}

QSqlQueryModel* depot::AfficherListe()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery query=LoadData();
    query.exec();
    modal->setQuery(query);
    return modal;
}

bool depot::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from depot where warehouseID='"+itemText+"'");
    return query.exec();
}


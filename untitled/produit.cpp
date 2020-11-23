#include "produit.h"
#include <QString>




produit::produit()
{
  productCode="";
  productName="";
  sellPrice=0;
  quantityInStock=0;

}

produit::produit(QString NVproductCode, QString NVproductName , int NVsellPrice, int NVquantityInStock)
{

    this-> productCode=NVproductCode;
    this->productName=NVproductName;
    this-> sellPrice=NVsellPrice;
    this->quantityInStock=NVquantityInStock;

}


bool produit:: ajouter()
{
    QSqlQuery query;
    QString Pprice=QString::number(sellPrice);
    QString QIS=QString::number(quantityInStock);

//Prepare() prend la requete en parametre pour la prÃ©parer a l'execution
  query.prepare("INSERT INTO produit (productCode, productName,sellPrice,quantityInStock)" "VALUES (:productCode,:productName,:sellPrice,:quantityInStock)");
  query.bindValue(":productCode",productCode);
  query.bindValue(":productName",productName);
  query.bindValue(":sellPrice",Pprice);
  query.bindValue(":quantityInStock",QIS);

  //exec() envoie la requete pour l'executer
   return query.exec();

}


bool produit::Editer()
{
    QSqlQuery query;
    QString Pprice=QString::number(sellPrice);
    QString QIS=QString::number(quantityInStock);


    //Prepare() prend la requete en parametre pour la prÃ©parer a l'execution
    query.prepare("update produit set productCode='"+productCode+"',productName='"+productName+"',sellPrice='"+sellPrice+"',quantityInStock='"+quantityInStock+"' where productCode='"+productCode+"'");

    //Creation des variables liÃ©es
    query.bindValue(":productCode",productCode);
    query.bindValue(":productName",productName);
    query.bindValue(":sellPrice",sellPrice);
    query.bindValue(":quantityInStock",quantityInStock);

    //exec() envoie la requete pour l'executer
    return query.exec();
}

QSqlQueryModel* produit::Afficher(QString itemText)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from produit WHERE productCode='"+itemText+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("product code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("product Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("sell price"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantity in stock"));
    return model;
}


QSqlQuery produit::LoadData()
{
    QSqlQuery query;
    query.prepare("select productCode from produit");
    return query;
}

QSqlQueryModel* produit::AfficherListe()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery query=LoadData();
    query.exec();
    modal->setQuery(query);
    return modal;
}

bool produit::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from produit where productCode='"+itemText+"'");
    return query.exec();
}

bool produit::Chercher(QString itemText)
{
    QSqlQuery query;
    query.prepare("select * from produit where productCode='"+itemText+"'");
    query.exec();
    if(query.next())
    {
        return true;
    }

    return false;
}

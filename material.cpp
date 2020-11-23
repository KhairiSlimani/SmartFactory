#include "material.h"
#include"material.h"
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>


material::material()
{
     Name="";
     id="";
     Description="";
     SupplierID="";
     Quantity="" ;
    Unit="";
   price="";
    Currency="";
    Expiratdate="";
}
material::material(QString id,QString Name,QString Description,QString SupplierID,QString Quantity,QString Unit,QString price,QString Currency,QString Expiratdate )
{
    this->id=id;
    this->Name=Name;
    this->Description=Description;
    this->SupplierID=SupplierID;
    this->Quantity=Quantity;
    this->Unit=Unit;
    this->price=price;
    this->Currency=Currency;
    this->Expiratdate=Expiratdate;
}
bool  material::AddMaterial()
{
    QSqlQuery query;
    query.prepare(" Insert into material ( Name,Description,SupplierID,Quantity,Unit,price,Currency,Expiratdate)"" values (;Name;Description;SupplierID;Quantity;Unit;price;Currency;Expiratdate)");
    query.bindValue("Name",Name);
    query.bindValue("id",id);

    query.bindValue("Description",Description);
    query.bindValue("SupplierID",SupplierID);
    query.bindValue("Quantity",Quantity);
    query.bindValue("Unit",Unit);
    query.bindValue("price",price);
    query.bindValue("Currency",Currency);
    query.bindValue("Expiratdate",Expiratdate);
    return query.exec();

}
 QSqlQueryModel * material :: ViewMaterial()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from material ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Description"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("SupplierID"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Quantity"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Unit"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("Currency"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("Expiratdate"));
      model->setHeaderData(8,Qt::Horizontal,QObject::tr("id"));
     return model;
 }
 bool material::deleteMaterial(int)
 {

     QSqlQuery query;
     //QString mid=QString:: number(id);
     query.prepare("delete from supplier where ID= :id");
     //query.bindValue(":id",mid);
     return  query.exec();


 }

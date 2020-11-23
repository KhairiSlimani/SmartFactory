#include "suppliers.h"
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include"qdebug.h"


Suppliers::Suppliers()
{
    id="";

       campName="";
      title="";
       adress="";
       ville="";
      pays="";
      telephone="";
       fax="";
      pagacc="";
}
Suppliers::Suppliers(QString id,QString campName,QString title,QString adress,QString ville,QString pays,QString telephone,QString fax,QString pagacc)
{

    this->id=id;

   this->campName=campName;
    this->title=title;
    this->adress=adress;
    this->ville=ville;
    this->pays=pays;
    this->telephone=telephone;
    this->fax=fax;
    this->pagacc=pagacc;
}
bool Suppliers::Addsupplier()
{
 QSqlQuery query;
 query.prepare(" Insert into supplier ( id ,name,campName,title,adress,ville,pays,telephone,fax,pagacc)"" values (:id :name :campName :title :adress :ville :pays :telephone :fax :pagacc)");
 query.bindValue("id",id);

 query.bindValue("campName",campName);
 query.bindValue("adress",adress);
 query.bindValue("ville",ville);
 query.bindValue("pays",pays);
 query.bindValue("telephone",telephone);
 query.bindValue("fax",fax);
 query.bindValue("pagacc",pagacc);
 return query.exec();
}
QSqlQueryModel * Suppliers :: Viewsupplier()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from suppliers ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("campName"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("pays"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("fax"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("pagacc"));
    return model;

}
bool Suppliers:: deletesupplier(int id)
{
    QSqlQuery query;
    QString sid= QString :: number(id);
    query.prepare("delete from supplier where ID= :id");
    query.bindValue(":id",sid);
    return  query.exec();

}

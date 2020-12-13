#include "suppliers.h"
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include <qdebug.h>
#include<QMessageBox>




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
    bool test;


      QSqlQuery qry;

       qry.prepare("insert into FOURNISSEURS ("
                   "id, "
                   "campname,"
                   "adress,"
                   "pays,"
                   "ville,"
                   "telephone,"
                   "fax,"
                   "pageacc,"
                   "title) "
                   "values(?,?,?,?,?,?,?,?,?)");

       qry.addBindValue(getid());
       qry.addBindValue(getcampName());
       qry.addBindValue(getadress());
       qry.addBindValue(getpays());
       qry.addBindValue(getville());
       qry.addBindValue(gettelephone());
       qry.addBindValue(getfax());
       qry.addBindValue(getpagacc());
       qry.addBindValue(gettitle());


       if(qry.exec())
       {


          test= true;

       }
       else
       {
           qDebug()<<"not done";
            test= false;

       }



return test;

}
bool Suppliers::editsupplier(QString id)
{

    QSqlQuery query;

    query.prepare("update FOURNISSEURS set id=:id,campName=:campName,title=:title,adress=:adress,ville=:ville,pays=:pays,telephone=:telephone,fax=:fax,pageacc=:pagacc WHERE id=:id") ;
    //Creation des variables liées
    query.bindValue(":id",id);
    query.bindValue(":campname",campName);
    query.bindValue(":title",title);
    query.bindValue(":adress",adress);
    query.bindValue(":ville",ville);
    query.bindValue(":pays",pays);
    query.bindValue(":telephone",telephone);
    query.bindValue(":fax",fax);
    query.bindValue(":pageacc",pagacc);



    //exec() envoie la requete pour l'executer
    return query.exec();





}

bool Suppliers:: deletesupplier(QString info)
{
    QSqlQuery query ;

       query.prepare("Delete from fournisseurs  where ID=:id");
       query.bindValue(":id",info);

       return query.exec();

}

 QSqlQueryModel * Suppliers ::afficherList2()
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry;
qry.prepare("SELECT id FROM  fournisseurs  ");
qry.exec();
model->setQuery(qry);
return  model ;
}

 void Suppliers ::loadData(QString i )
 {

     QSqlQuery qry("select * from FOURNISSEURS where id = '"+i+"';");


         while (qry.next())
          {

            id=qry.value(0).toString();
            campName =qry.value(1).toString();
            title=qry.value(2).toString();
            adress=qry.value(3).toString();
            ville=qry.value(4).toString();
            pays=qry.value(5).toString();
            telephone=qry.value(6).toString();
            fax=qry.value(7).toString();
            pagacc=qry.value(8).toString();


            }
         qDebug()<<i;

 }


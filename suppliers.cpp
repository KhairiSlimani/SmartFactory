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
////////////////////
/*bool Suppliers::Addsupplier()
{
 QSqlQuery query;
 query.prepare(" INSERT INTO FOURNISSEURS ( id ,name,campName,title,adress,ville,pays,telephone,fax,pagacc)"" VALUES (:id ,name :campName ,:title :adress ,:ville, :pays, :telephone, :fax, :pagacc)");
 query.bindValue("id",id);

 query.bindValue("campName",campName);
 query.bindValue("adress",adress);
 query.bindValue("ville",ville);
 query.bindValue("pays",pays);
 query.bindValue("telephone",telephone);
 query.bindValue("fax",fax);
 query.bindValue("pagacc",pagacc);
 return query.exec();
}*/
/////////////////////////////


bool Suppliers::Addsupplier()
{


    bool test;
    QMessageBox msg;

      QSqlQuery qry;

       qry.prepare("insert into material ("
                   "id,"
                   "campName, "
                   "adress,"
                   "ville,"
                   "pays,"
                   "telephone,"
                   "fax,"
                   "pagacc,"
                   "title,"

                   "values(?,?,?,?,?,?,?,?,?)");

       qry.addBindValue(getid());
       qry.addBindValue(getcampName());
       qry.addBindValue(getadress());
       qry.addBindValue(getville());
       qry.addBindValue(getpays());
       qry.addBindValue(getpagacc());
       qry.addBindValue(gettelephone());
       qry.addBindValue(getfax());
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
QSqlQuery Suppliers :: Viewsupplier(QString info)
{

    QSqlQuery query;
    query.prepare("select * from fournisseurs where id='"+info+"'");
    query.exec();
    return  query;


}
bool Suppliers:: deletesupplier(QString info)
{

    QSqlQuery query;
    query.prepare("Delete from  fournisseurs where id='"+info+"'");
    return query.exec();

}
 QSqlQueryModel * Suppliers ::afficherList2()
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry;
qry.prepare("select id from fournisseurs");
qry.exec();
model->setQuery(qry);
return  model ;
}



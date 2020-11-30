#include "material.h"
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

}
material::material(QString id,QString Name,QString Description,QString SupplierID,QString Quantity,QString Unit,QString price,QString Currency )
{
    this->id=id;
    this->Name=Name;
    this->Description=Description;
    this->SupplierID=SupplierID;
    this->Quantity=Quantity;
    this->Unit=Unit;
    this->price=price;
    this->Currency=Currency;

}

bool material::AddMaterial()
{
    bool test;
    QMessageBox msg;

      QSqlQuery qry;

       qry.prepare("insert into material ("
                   "id, "
                   "Name,"
                   "Description,"
                   "SupplierID,"
                   "Quantity,"
                   "Unit,"
                   "price,"
                   "Currency) "
                   "values(?,?,?,?,?,?,?,?)");

       qry.addBindValue(getid());
       qry.addBindValue(getName());
       qry.addBindValue(getDescription());
       qry.addBindValue(getSupplierID());
       qry.addBindValue(getQuantity());
       qry.addBindValue(getUnit());
       qry.addBindValue(getprice());
       qry.addBindValue(getcurrency());





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

 QSqlQuery material ::ViewMaterial(QString info)
 {
     QSqlQuery query;
     query.prepare("select * from material where id='"+info+"'");
     query.exec();
     return  query;

 }
 bool material::deleteMaterial(QString info )
 {


     QSqlQuery query;
     query.prepare("Delete from  material where id='"+info+"'");
     return query.exec();


 }
 bool material::EditMaterial()
 {
     QSqlQuery query;


     query.prepare("Edit material set id='"+id+"',Name='"+Name+"',Description='"+Description+"',SupplierID='"+SupplierID+"',Quantity='"+Quantity+"',price='"+price+"',Currency='"+Currency+"'");

     //Creation des variables liées
     query.bindValue(":id",id);
     query.bindValue(":Name",Name);
     query.bindValue(":Description",Description);
     query.bindValue(":SupplierID",SupplierID);
     query.bindValue(":price",price);
     query.bindValue(":currency",Currency);
     query.bindValue(":Quantity",Quantity);


     //exec() envoie la requete pour l'executer
     return query.exec();

 }
 bool material::searchMaterial(QString info)
{
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("select id from material where id='"+info+"'");
     query.exec();
     model->setQuery(query);
     return model;

 }
   QSqlQueryModel * material :: sortmaterial()
   {
       QSqlQueryModel * model=new QSqlQueryModel();
       QSqlQuery query ;
       query.prepare("select id from material order by ID desc");
       query.exec();

       model->setQuery(query);

       return model;
   }

   QSqlQueryModel * material::afficherList()
   {
   QSqlQueryModel * model=new QSqlQueryModel();
   QSqlQuery qry;
   qry.prepare("select id from material");
   qry.exec();
   model->setQuery(qry);
   return  model ;
   }


   QSqlQuery material::statMat()
   {
       QSqlQuery query;
       query.prepare("select * from material");
       query.exec();
       return query;

   }

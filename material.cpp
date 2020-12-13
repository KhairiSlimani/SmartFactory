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



      QSqlQuery qry;

       qry.prepare("insert into material ("
                   "id, "
                   "Name,"
                   "Description,"
                   "Quantity,"
                   "Unit,"
                   "price,"
                   "SupplierID,"
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

     return query;

     //QString ch =QString::number(info);

/* QSqlQuery qry;
 QSqlQueryModel * model=new QSqlQueryModel();
 qry.prepare("select * from material where id=:info");
 qry.bindValue(":id",info);
 qry.exec();
 model->setQuery(qry);

 qDebug()<<info;
 qDebug()<<"afficher done";
 //return model;
 if(qry.exec())
 {


    test= true;

 }
 else
 {
     qDebug()<<"not done";
      test= false;

 }



//return test;*/

 }




 bool material::EditMaterial(QString id)

 {
     QSqlQuery query;





     query.prepare("update MATERIAL set id=:id,Name=:Name,Description=:Description,SupplierID=:SupplierID,price=:price,Currency=:Currency,Quantity=:Quantity,UNIT=:UNIT WHERE id=:id") ;
     //Creation des variables liées
     query.bindValue(":id",id);
     query.bindValue(":Name",Name);
     query.bindValue(":Description",Description);
     query.bindValue(":SupplierID",SupplierID);
     query.bindValue(":price",price);
     query.bindValue(":Currency",Currency);
     query.bindValue(":Quantity",Quantity);
     query.bindValue(":UNIT",Unit);


     //exec() envoie la requete pour l'executer
     return query.exec();

 }


  QSqlQueryModel * material::search(QString info)
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



   QChart* material::statmat()
   {

       QPieSeries *series = new QPieSeries();
          QSqlQuery query("SELECT ID, QUANTITY FROM MATERIAL;");
          while(query.next())
          {
              series->append(query.value(0).toString(),query.value(1).toInt());
          }

          QChart * chart=new  QChart();
          chart->addSeries(series);
          chart->setTitle("Material statistics");

            return   chart;

   }

   bool material::deleteMaterial(QString info){
       QSqlQuery query ;

          query.prepare("Delete from MATERIAL where ID=:id");
          query.bindValue(":id",info);

          return query.exec();

   }
   void material ::loadData(QString i )
   {

       QSqlQuery qry("select * from  MATERIAL where id = '"+i+"';");


           while (qry.next())
            {

              id=qry.value(0).toString();
              Name=qry.value(1).toString();
              Description=qry.value(2).toString();
              Quantity=qry.value(3).toString();
              Unit=qry.value(4).toString();
              price=qry.value(5).toString();
              SupplierID=qry.value(6).toString();
              Currency=qry.value(7).toString();
             }
           qDebug()<<i;

   }

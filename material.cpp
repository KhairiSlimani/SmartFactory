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
   // QString id2=QString::number(id);
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
     bool test;
     /*
     QSqlQuery query;
     query.prepare("select * from material where id='"+info+"'");
     query.exec();

     return query;*/

     //QString ch =QString::number(info);

 QSqlQuery qry;
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



//return test;

 }




 bool material::EditMaterial(int info)
 {
     QSqlQuery query;
    //QString id2 = QString ::number(id);
     query.prepare("update material set id='"+id+"',Name='"+Name+"',Description='"+Description+"',SupplierID='"+SupplierID+"',Quantity='"+Quantity+"',price='"+price+"',Currency='"+Currency+"'");

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

   //QSqlQueryModel* material::AfficherListe()

      /* QSqlQueryModel *modal=new QSqlQueryModel();
       QSqlQuery query=LoadData();
       query.exec();
       modal->setQuery(query);
       return modal;*/
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


//   QSqlQuery material::LoadData()
//   {
//       QSqlQuery query;
//       query.prepare("select id from client");
//       return query;
//   }


   bool material::deleteMaterial(QString info){
       QSqlQuery query ;

          query.prepare("Delete from MATERIAL where ID=:id");
          query.bindValue(":id",info);

          return query.exec();

   }

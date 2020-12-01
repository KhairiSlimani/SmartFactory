#include "bill.h"

bill::bill()
{

    shipperName="";
    payMethod="";
    billNumber="";
    orderID="";
    shipperNumber=0;
    totalAmount=0;
}

bill::bill(QString shipperName,QString billNumber,QString orderID,QString payMethod,int shipperNumber,double totalAmount,QDate releaseDate)
{
    this->shipperName=shipperName;
    this->billNumber=billNumber;
    this->orderID=orderID;
    this->payMethod=payMethod;
    this->shipperNumber=shipperNumber;
    this->totalAmount=totalAmount;
    this->releaseDate=releaseDate;


}

bool bill::ajouter()
{
    bool test;
    QMessageBox msg;

      QSqlQuery qry;
       qry.prepare("insert into BILL ("
                   "BILLNUMBER, "
                   "ORDERID,"
                   "PAYMENTMETHOD,"
                   "RELEASEDATE,"
                   "TOTALAMOUNT,"
                   "SHIPPERNAME,"
                   "SHIPPERPHONE) "
                   "values(?,?,?,?,?,?,?)");

       qry.addBindValue(getBillNumber());
       qry.addBindValue(getOrderID());
       qry.addBindValue(getPayMethod());
       qry.addBindValue(getReleaseDate());
       qry.addBindValue(getTotalAmount());
       qry.addBindValue(getShipperName());
       qry.addBindValue(getShipperNumber());




       if(qry.exec())
       {


          test= true;

       }
       else
       {
           qDebug()<<qry.lastError().text();
            test= false;

       }



return test;
}

QSqlQueryModel * bill::afficher(int i)
{

    QString ch =QString::number(i);

QSqlQuery qry;
QSqlQueryModel * model=new QSqlQueryModel();
qry.prepare("select * from bill where billNumber=:id");
qry.bindValue(":id",i);
qry.exec();
model->setQuery(qry);

qDebug()<<i;
qDebug()<<"afficher done";
return model;
}

QSqlQueryModel * bill::afficherList()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select  billnumber from bill");



return model;
}

bool bill::supprimer(int id)
{
    QSqlQuery query ;
    QString ch =QString::number(id);
    query.prepare("Delete from BILL where BILLNUMBER=:id");
    query.bindValue(":id",id);

    return query.exec();

}

bool bill::edit(int id)
{ QSqlQuery qry ;
    qry.prepare("update BILL set BILLNUMBER=:billNumber,ORDERID=:orderId,PAYMENTMETHOD=:paymentMethod,RELEASEDATE=:releaseDate,TOTALAMOUNT=:totalAmount,SHIPPERNAME=:shipperName,SHIPPERPHONE=:shipperPhone WHERE BILLNUMBER=:billNumber") ;

    qry.bindValue(":billNumber",id);
    qry.bindValue(":orderId",getOrderID());
    qry.bindValue(":paymentMethod",getPayMethod());
    qry.bindValue(":releaseDate",getReleaseDate());
    qry.bindValue(":totalAmount",getTotalAmount());
    qry.bindValue(":shipperName",getShipperName());
    qry.bindValue(":shipperPhone",getShipperNumber());


    return qry.exec();
}

QSqlQueryModel * bill::afficherOrderedList()
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry ;
qry.prepare(" SELECT BILLNUMBER FROM BILL ORDER BY BILLNUMBER DESC");
qry.exec();

model->setQuery(qry);



return model;
}

QSqlQueryModel * bill::searchList(int id)
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry ;
qry.prepare("select BILLNUMBER from bill where BILLNUMBER=:id");
qry.bindValue(":id",id);
qry.exec();

model->setQuery(qry);



return model;
}

void bill::editer(int i )
{
   QString ch = QVariant(i).toString();
    QSqlQuery qry("select * from BILL where BILLNUMBER = "+ch+";");


        while (qry.next())
         {

           billNumber=qry.value(0).toString();

           orderID=qry.value(1).toString();
           payMethod=qry.value(2).toString();
           releaseDate=qry.value(3).toDate();
           totalAmount=qry.value(4).toDouble();
           shipperName=qry.value(5).toString();
           shipperNumber=qry.value(6).toInt();

           }
         qDebug()<<billNumber;

//qDebug()<<b.billNumber;
}

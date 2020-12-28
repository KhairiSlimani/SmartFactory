#include "order.h"
#include <QMap>
#include <QDebug>
order::order()
{
        orderNumber="";
        productCode="";
        status="";
        discount="";
        customerID="";
        comments="";
        quantityOrdered=0;
        unitPrice=0;
        extendedPrice=0;
 }

    order::order(QString orderNumber,QString productCode,QString status,QString discount,QString customerID,QString comments,int quantityOrdered, double unitPrice,double extendedPrice, QDate requiredDate,QDate orderDate)
    {
        this->orderNumber=orderNumber;
        this->productCode=productCode;
        this->status=status;
        this->discount=discount;
        this->customerID=customerID;
        this->comments=comments;
        this->quantityOrdered=quantityOrdered;
        this->unitPrice=unitPrice;
        this->extendedPrice=extendedPrice;
        this->requiredDate=requiredDate;
        this->orderDate=orderDate;


    }

    bool order::ajouter()
    {
        bool test;
        QMessageBox msg;

          QSqlQuery qry;

           qry.prepare("insert into ORDERTAB ("
                       "PRODUCTCODE,"
                       "QUANTITYORDERED,"
                       "STATUS,"
                       "ORDERDATE,"
                       "UNITPRICE,"
                       "DISCOUNT,"
                       "EXTENDEDPRICE,"
                       "REQUIREDDATE,"
                       "CUSTOMERID,"
                       "COMMENTS) "
                       "values(?,?,?,?,?,?,?,?,?,?)");


           qry.addBindValue(getProductCode());
           qry.addBindValue(getQuantityOrdered());
           qry.addBindValue(getStatus());
           qry.addBindValue(getOrderDate());
           qry.addBindValue(getUnitPrice());
           qry.addBindValue(getDiscount());
           qry.addBindValue(getExtendedPrice());
           qry.addBindValue(getRequiredDate());
           qry.addBindValue(getCustomerID());
           qry.addBindValue(getComments());




           if(qry.exec())
           {


              test= true;

           }
           else
           {

                test= false;

           }



    return test;
    }



    QSqlQueryModel * order::afficherList()
    {
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select  orderNumber from ORDERTAB");



    return model;
    }

    bool order::supprimer(int id)
    {
        QSqlQuery query ;
        QString ch =QString::number(id);
        query.prepare("Delete from ORDERTAB where orderNumber=:id");
        query.bindValue(":id",id);

        return query.exec();

    }

    bool order::edit(int id)
    { QSqlQuery qry ;
        qry.prepare("update ORDERTAB set ORDERNUMBER=:orderNumber,CUSTOMERID=:customerId,PRODUCTCODE=:productCode,QUANTITYORDERED=:quantityOrdered,STATUS=:status,ORDERDATE=:orderDate,UNITPRICE=:unitPrice,DISCOUNT=:discount,EXTENDEDPRICE=:extendedPrice,REQUIREDDATE=:requiredDate,COMMENTS=:comments WHERE ORDERNUMBER=:orderNumber") ;

        qry.bindValue(":orderNumber",id);
        qry.bindValue(":customerId",getCustomerID());
        qry.bindValue(":productCode",getProductCode());
        qry.bindValue(":quantityOrdered",getQuantityOrdered());
        qry.bindValue(":status",getStatus());
        qry.bindValue(":orderDate",getOrderDate());
        qry.bindValue(":unitPrice",getUnitPrice());
        qry.bindValue(":discount",getDiscount());
        qry.bindValue(":extendedPrice",getExtendedPrice());
        qry.bindValue(":requiredDate",getRequiredDate());
        qry.bindValue(":comments",getComments());




        return qry.exec();
    }

//statestique ///////////////////////
 QChart* order::stat()
   {
     QMap<QString,int> map;

     QString ch ;
     int i;

    QPieSeries *series = new QPieSeries();
    QSqlQuery query("SELECT PRODUCTNAME, QUANTITYORDERED FROM (ORDERTAB o),(PRODUIT p) WHERE (o.PRODUCTCODE=p.PRODUCTCODE) ;");
    while(query.next())
    {
       ch=query.value(0).toString();
       i=query.value(1).toInt();

  if (map.find(ch)==map.end())
       {
       map.insert(ch,i);
       }
    else
       {
      map[ch]+=i;
       }

    }

    QMap<QString, int>::iterator it;
    for (it = map.begin(); it != map.end(); ++it)
    series->append(it.key(),it.value());

    QChart * chart=new  QChart();
    chart->addSeries(series);
    chart->setTitle("order statistics");

      return   chart;

    }

 void order::loadData(int i )
 {
    QString ch = QVariant(i).toString();
     QSqlQuery qry("select * from ORDERTAB where ORDERNUMBER = "+ch+";");


         while (qry.next())
          {

            orderNumber=qry.value(0).toString();
            productCode =qry.value(1).toString();
            quantityOrdered=qry.value(2).toInt();
            status=qry.value(3).toString();
            orderDate=qry.value(4).toDate();
            unitPrice=qry.value(5).toDouble();
            discount=qry.value(6).toString();
            extendedPrice=qry.value(7).toDouble();
            requiredDate=qry.value(8).toDate();
            customerID=qry.value(9).toString();
            comments=qry.value(10).toString();

            }

 }

 QSqlQueryModel * order::fillCustomerIDInOrder()
 {
   QSqlQueryModel * model=new QSqlQueryModel();
   QSqlQuery qry ;
   qry.prepare(" SELECT id FROM client");
   qry.exec();

   model->setQuery(qry);
     return model;
 }

 QSqlQueryModel * order::fillProductIDInOrder()
 {
   QSqlQueryModel * model=new QSqlQueryModel();
   QSqlQuery qry ;
   qry.prepare(" SELECT productCode FROM produit");
   qry.exec();

   model->setQuery(qry);
     return model;
 }
QString order::getEmailFromClient(int i)
{
    //not finished
    QSqlQuery qry ;
    QString ii = QVariant(i).toString(),ch;
    qDebug()<<ii;
    qry.prepare(" SELECT EMAIL FROM client c where (c.id= '"+ii+"');");
    //qry.exec();
    qry.next();
    ch=qry.value(0).toString();

    qDebug()<<ch;

    return ch ;

}

QSqlQueryModel * order::searchList(int id)
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry ;

qry.prepare("select orderNumber from ordertab where (orderNumber=:id) ");
qry.bindValue(":id",id);
qry.exec();

model->setQuery(qry);



return model;
}
/// problems
QSqlQueryModel * order::searchListByOrderDate(QString commentSearched)
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry ;

qry.prepare("select comments from orderTab where comments=:commentSearched ");
qry.bindValue(":commentSearched",commentSearched);
qry.exec();

model->setQuery(qry);



return model;
}






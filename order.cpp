#include "order.h"

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
                       "ORDERNUMBER, "
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
                       "values(?,?,?,?,?,?,?,?,?,?,?)");

           qry.addBindValue(getOrderNumber());
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
               qDebug()<<qry.lastError().text();
                test= false;

           }



    return test;
    }

    QSqlQueryModel * order::afficher(int i)
    {

        QString ch =QString::number(i);

    QSqlQuery qry;
    QSqlQueryModel * model=new QSqlQueryModel();
    qry.prepare("select * from ORDERTAB where orderNumber=:id");
    qry.bindValue(":id",i);
    qry.exec();
    model->setQuery(qry);

    qDebug()<<i;
    qDebug()<<"afficher done";
    return model;
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







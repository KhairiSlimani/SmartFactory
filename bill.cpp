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
            test= false;

       }



return test;
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

QSqlQueryModel * bill::fillOrderIDInBill()
{
  QSqlQueryModel * model=new QSqlQueryModel();
  QSqlQuery qry ;
  qry.prepare(" SELECT OrderNumber FROM orderTab");
  qry.exec();

  model->setQuery(qry);
    return model;
}

QSqlQueryModel * bill::searchList(int id)
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry ;

qry.prepare("select billnumber from bill where (BILLNUMBER=:id) ");
qry.bindValue(":id",id);
qry.exec();

model->setQuery(qry);



return model;
}

QSqlQueryModel * bill::searchListByShipperName(QString shipperNameSearched)
{
QSqlQueryModel * model=new QSqlQueryModel();
QSqlQuery qry ;

qry.prepare("select shippername from bill where (SHIPPERNAME=:shipperNameSearched) ");
qry.bindValue(":shipperNameSearched",shipperNameSearched);
qry.exec();

model->setQuery(qry);



return model;
}



void bill::loadData(int i )
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

}


void bill::printPDF(){
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/meriam/Documents/facture.pdf");
    QPainter painter,painter2;
    QImage image(":/images/images/facture.jpg");
    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("On n'a pas réussi à créer le pdf.");
        msgBox.exec();
    }
    else{
        QString s = QString::number(shipperNumber);
        QString t= QString::number(totalAmount);
        QFont font = painter.font();

        font.setPointSize(font.pointSize() * 2);
        painter.setFont(font);

        painter.setPen(Qt::darkBlue);
        painter.drawText(40, 40, "FACTURE : ");
        painter.setPen(Qt::blue);
        painter.drawImage(40,640,image);

        painter.drawText(330, 40, "billNumber : ");
        painter.drawText(330, 140, "orderID :");
        painter.drawText(330, 240, "shipperName : ");
        painter.drawText(330, 340, "shipperNumber: ");
        painter.drawText(330, 440, "releaseDate : ");
        painter.drawText(330, 540, "payMethod : ");
        painter.drawText(330, 640, "totalAmount : ");
        painter.setPen(Qt::black);
        painter.drawText(530, 40, this->billNumber);
        painter.drawText(530, 140, this->orderID);
        painter.drawText(530, 240, this->shipperName);
        painter.drawText(530, 340, s);
        painter.drawText(530, 440, this->releaseDate.toString("dd/MM/yyyy"));
        painter.drawText(530, 540, this->payMethod);
        painter.drawText(530, 640, t);
        painter.end();
        qDebug()<<t;
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Le pdf a été créé.");
        msgBox.exec();
    }
}

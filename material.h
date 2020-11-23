#ifndef MATERIAL_H
#define MATERIAL_H
#include<QString>
#include"QtSql/QSqlQueryModel"

class material
{
private:
      QString id;
    QString Name;
    QString Description;
    QString SupplierID;
    QString Quantity ;
    QString Unit;
   QString price;
    QString Currency;
   QString Expiratdate;
      public:
     material();
 material( QString id,QString Name,QString Description,QString SupplierID,QString Quantity,QString Unit,QString price,QString Currency,QString Expiratdate );
       void setName(QString ID){id=ID;}
        void setid(QString nm){Name=nm;}
        void setdescription(QString des){Description=des;}
        void setSupplierID(QString sid){SupplierID=sid;}
        void setQuantity(QString quant){Quantity=quant;}
        void setUnit(QString uni){Unit=uni;}
        void setprice(QString prc){price=prc;}
        void setCurrency(QString cur){Currency=cur;}
        void setexpiratdate(QString exdat){Expiratdate=exdat;}
         QString getid(){return  id;}
        QString getName(){return  Name;}
        QString getDescription(){return  Description;}
        QString getSupplierID(){return  SupplierID;}
        QString getQuantity(){return  Quantity;}
        QString getUnit(){return  Unit;}
        QString getprice(){return  price;}
        QString getcurrency(){return  Currency;}
        QString getExpiratdate(){return  Expiratdate;}
        bool AddMaterial();
        QSqlQueryModel * ViewMaterial();
        bool deleteMaterial(int);

};



#endif // MATERIAL_H

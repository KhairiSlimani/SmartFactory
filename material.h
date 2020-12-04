#ifndef MATERIAL_H
#define MATERIAL_H
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlQueryModel"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include "smtp.h"
#include <QtCharts>
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

      public:
     material();
 material( QString id,QString Name,QString Description,QString SupplierID,QString Quantity,QString Unit,QString price,QString Currency );
       void setName(QString ID){id=ID;}
        void setid(QString nm){Name=nm;}
        void setdescription(QString des){Description=des;}
        void setSupplierID(QString sid){SupplierID=sid;}
        void setQuantity(QString quant){Quantity=quant;}
        void setUnit(QString uni){Unit=uni;}
        void setprice(QString prc){price=prc;}
        void setCurrency(QString cur){Currency=cur;}

         QString getid(){return  id;}
        QString getName(){return  Name;}
        QString getDescription(){return  Description;}
        QString getSupplierID(){return  SupplierID;}
        QString getQuantity(){return  Quantity;}
        QString getUnit(){return  Unit;}
        QString getprice(){return  price;}
        QString getcurrency(){return  Currency;}

        bool AddMaterial();
        bool EditMaterial(int info);


        QSqlQuery ViewMaterial(QString info);
        bool deleteMaterial(QString info);
         QSqlQueryModel * search(QString info);
         QSqlQueryModel * sortmaterial();

          QChart* statmat();
         QSqlQueryModel* afficherList();
         QSqlQueryModel * loadData();

};



#endif // MATERIAL_H

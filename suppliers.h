#ifndef SUPPLIERS_H
#define SUPPLIERS_H
#include<QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlQueryModel"


class Suppliers
{
private:
  QString id;

  QString campName;
  QString title;
  QString adress;
  QString ville;
  QString pays;
  QString telephone;
  QString fax;
  QString pagacc;
public:
  Suppliers();
 Suppliers(QString id,QString campName,QString title,QString adress,QString ville,QString pays,QString telephone,QString fax,QString pagacc);
    void setid(QString i){id=i;}

        void setcampName(QString CN){campName=CN;}
        void settitle(QString tt){title=tt;}
        void setadress(QString adre){adress=adre;}
        void setville(QString vi){ville=vi;}
        void setpays(QString py){pays=py;}
        void settelephone(QString tel){telephone=tel;}
        void setfax(QString fx){fax=fx;}
        void setpagacc(QString pgac){pagacc=pgac;}
        QString getid(){return  id;}

        QString getcampName(){return campName;}
        QString gettitle(){return  title;}
        QString getadress(){return  adress;}
        QString getville(){return  ville;}
        QString getpays(){return  pays;}
        QString gettelephone(){return  telephone;}
        QString getfax(){return  fax;}
        QString getpagacc(){return  pagacc;}
        bool Addsupplier();
        QSqlQuery Viewsupplier(QString info);
        bool deletesupplier(QString info);
        QSqlQueryModel* afficherList2();




};

#endif // SUPPLIERS_H

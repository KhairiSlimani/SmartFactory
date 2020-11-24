#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class produit
{

private:
    QString productCode;
    QString productName;
    int sellPrice;
    int quantityInStock;


public:
    produit();
    produit(QString,QString,int,int);
    QString Get_productCode(){return productCode;}
    QString Get_productName(){return productName;}
    int Get_sellPrice(){return sellPrice;}
    int Get_quantityInStock(){return quantityInStock;}


    void set_productCode(QString productCode){this->productCode=productCode;}
    void set_productName(QString productName){this->productName=productName;}
    void set_sellPrice(int sellPrice){this->sellPrice=sellPrice;}
    void set_quantityInStock(int quantityInStock){this->quantityInStock=quantityInStock;}
    bool ajouter();
    bool Editer();
    QSqlQueryModel* Afficher(QString);
    QSqlQuery LoadData();
    QSqlQueryModel* AfficherListe();
    bool Effacer(QString);
    bool Chercher(QString itemText);



};

#endif // PRODUIT_H




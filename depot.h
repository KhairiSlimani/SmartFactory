#ifndef DEPOT_H
#define DEPOT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>



class depot
{
private:
    QString warehouseID;
    QString typeOfProduct;
    QString nameOfDepotManager;

public:
    depot();
    depot(QString,QString,QString);
    QString Get_warehouseID(){return warehouseID;}
    QString Get_typeOfProduct(){return typeOfProduct;}
    QString Get_nameOfDepotManager(){return nameOfDepotManager;}

    void set_warehouseID(QString warehouseID){this->warehouseID=warehouseID;}
    void set_typeOfProduct(QString typeOfProduct){this->typeOfProduct=typeOfProduct;}
    void set_nameOfDepotManager(QString nameOfDepotManager){this->nameOfDepotManager=nameOfDepotManager;}

    bool ajouter();
    QSqlQueryModel* Afficher(QString itemText);
    bool Editer();
    QSqlQuery LoadData();
    QSqlQueryModel* AfficherListe();
    bool Effacer(QString);
};

#endif // DEPOT_H



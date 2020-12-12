#ifndef ORDER_H
#define ORDER_H
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>


class order
{
private:
    QString orderNumber,productCode,status,discount,customerID,comments;
    QDate requiredDate,orderDate;
    int quantityOrdered;
    double unitPrice,extendedPrice;
public:
    order();
    order(QString,QString,QString,QString,QString,QString,int,double,double,QDate,QDate);
    bool ajouter();
    QSqlQueryModel* afficher(int i);
    QSqlQueryModel * afficherList();
    bool supprimer(int id);
    bool edit(int id);
    QChart* stat();
    void loadData(int i );



     void setOrderNumber(QString ch) {orderNumber=ch;};
     void setProductCode(QString ch) {productCode=ch;};
      void setStatus(QString  x) {status=x;};
      void setCustomerID(QString  x) {customerID=x;};
      void setDiscount(QString  x) {discount=x;};
      void setComments(QString  x) {comments=x;};
      void setQuantityOrdered(int x) {quantityOrdered=x;};
      void setUnitPrice(double  x) {unitPrice=x;};
      void setExtendedPrice(double  x) {extendedPrice=x;};
      void setRequiredDate(QDate ch) {requiredDate=ch;};
      void setOrderDate(QDate ch) {orderDate=ch;};




       QString getOrderNumber() {return orderNumber;};
       QString getProductCode() {return productCode;};
       QString  getStatus() {return status;};
        QString  getCustomerID() {return customerID;};
        QString  getDiscount() {return discount;};
        QString  getComments() {return comments;};
        int  getQuantityOrdered() {return quantityOrdered;};
        double  getUnitPrice() {return unitPrice;};
        double  getExtendedPrice() {return extendedPrice;};
        QDate getRequiredDate() {return requiredDate;};
        QDate getOrderDate() {return orderDate;};

};

#endif // ORDER_H


#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Customer
{
private:
    QString id;
    QString FirstName;
    QString LastName;
    QString CompanyName;
    int PhoneNumber;
    QString Email;
    QString Website;
    QString Street;
    QString City;
    int ZipCode;
    QString Country;
    int BankAccountNumber;
    float CreditLimit;


public:
    Customer();
    Customer(QString,QString,QString,int,QString,QString,QString,QString,int,QString,int,float);
    Customer(QString,QString,QString,QString,int,QString,QString,QString,QString,int,QString,int,float);

    QString getID(){return id;}
    QString getFirstName(){return FirstName;}
    QString getLastName(){return LastName;}
    QString getCompanyName(){return CompanyName;}
    int getPhoneNumber(){return PhoneNumber;}
    QString getEmail(){return Email;}
    QString getWebsite(){return Website;}
    QString getStreet(){return Street;}
    QString getCity(){return City;}
    int getZipCode(){return ZipCode;}
    QString getCountry(){return Country;}
    int getBankAccountNumber(){return BankAccountNumber;}
    float getCreditLimit(){return CreditLimit;}


    void setID(QString id){this->id=id;}
    void setFirstName(QString FirstName){this->FirstName=FirstName;}
    void setLastName(QString LastName){this->LastName=LastName;}
    void setCompanyName(QString CompanyName){this->CompanyName=CompanyName;}
    void setPhoneNumber(int PhoneNumber){this->PhoneNumber=PhoneNumber;}
    void setEmail(int Email){this->Email=Email;}
    void setWebsite(QString Website){this->Website=Website;}
    void setStreet(QString Street){this->Street=Street;}
    void setCity(QString City ){this->City=City;}
    void setZipCode(int ZipCode){this->ZipCode=ZipCode;}
    void setCountry(QString Country){this->Country=Country;}
    void setBankAccountNumber(int BankAccountNumber){this->BankAccountNumber=BankAccountNumber;}
    void setCreditLimit(float CreditLimit){this->CreditLimit=CreditLimit;}


    bool ajouter();
    bool Editer();
    QSqlQuery LoadData();
    QSqlQueryModel* AfficherListe();
    bool Effacer(QString);
    QSqlQueryModel* Trier();
    QSqlQuery Lire(QString itemText);
    QSqlQueryModel *chercher(QString itemText);
    QSqlQuery stat();

};


#endif // CUSTOMER_H

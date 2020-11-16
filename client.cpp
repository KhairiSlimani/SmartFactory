#include "client.h"

client::client()
{
  id="";
  FirstName="";
  LastName="";
  CompanyName="";
  PhoneNumber=0;
  Email="";
  Website="";
  Street="";
  City="";
  ZipCode=0;
  Country="";
  BankAccountNumber=0;
  CreditLimit=0;
}

client::client(QString nvID,QString nvFirstName,QString nvLastName,QString nvCompanyName,int nvPhoneNumber,QString nvEmail,QString nvWebsite,QString nvStreet,QString nvCity,int nvZipCode,QString nvCountry,int nvBankAccountNumber,int nvCreditLimit)
{
   id=nvID;
   FirstName=nvFirstName;
   LastName=nvLastName;
   CompanyName=nvCompanyName;
   PhoneNumber=nvPhoneNumber;
   Email=nvEmail;
   Website=nvWebsite;
   Street=nvStreet;
   City=nvCity;
   ZipCode=nvZipCode;
   Country=nvCountry;
   BankAccountNumber=nvBankAccountNumber;
   CreditLimit=nvCreditLimit;
}

bool client::ajouter()
{
    QSqlQuery query;
    QString PhoneNumberS=QString::number(PhoneNumber);
    QString ZipCodeS=QString::number(ZipCode);
    QString BankAccountNumberS=QString::number(BankAccountNumber);
    QString CreditLimitS=QString::number(CreditLimit);


    query.prepare("INSERT INTO client(id, FirstName, LastName, CompanyName, PhoneNumber, Email, Website, Street, City, ZipCode, Country, BankAccountNumber, CreditLimit)" "VALUES(:id, :FirstName, :LastName, :CompanyName, :PhoneNumber, :Email, :Website, :Street, :City, :ZipCode, :Country, :BankAccountNumber, :CreditLimit)");
    query.bindValue(":id",id);
    query.bindValue(":FirstName",FirstName);
    query.bindValue(":LastName",LastName);
    query.bindValue(":CompanyName",CompanyName);
    query.bindValue(":PhoneNumber",PhoneNumberS);
    query.bindValue(":Email",Email);
    query.bindValue(":Website",Website);
    query.bindValue(":Street",Street);
    query.bindValue(":City",City);
    query.bindValue(":ZipCode",ZipCodeS);
    query.bindValue(":Country",Country);
    query.bindValue(":BankAccountNumber",BankAccountNumberS);
    query.bindValue(":CreditLimit",CreditLimitS);
    return query.exec();
 }

QSqlQuery client::Afficher(QString itemText)
{
    QSqlQuery query;
    query.prepare("select * from client where id='"+itemText+"'");
    return query;
}

QSqlQuery client::LoadData()
{
    QSqlQuery query;
    query.prepare("select id from client");
    return query;
}


bool client::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from client where id='"+itemText+"'");
    return query.exec();
}

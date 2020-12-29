#include "customer.h"

Customer::Customer()
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

Customer::Customer(QString nvFirstName,QString nvLastName,QString nvCompanyName,int nvPhoneNumber,QString nvEmail,QString nvWebsite,QString nvStreet,QString nvCity,int nvZipCode,QString nvCountry,int nvBankAccountNumber,float nvCreditLimit)
{
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

Customer::Customer(QString nvID,QString nvFirstName,QString nvLastName,QString nvCompanyName,int nvPhoneNumber,QString nvEmail,QString nvWebsite,QString nvStreet,QString nvCity,int nvZipCode,QString nvCountry,int nvBankAccountNumber,float nvCreditLimit)
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

bool Customer::ajouter()
{
    QSqlQuery query;
    QString PhoneNumberS=QString::number(PhoneNumber);
    QString ZipCodeS=QString::number(ZipCode);
    QString BankAccountNumberS=QString::number(BankAccountNumber);
    QString CreditLimitS=QString::number(CreditLimit);

    //Prepare() prend la requete en parametre pour la préparer a l'execution
    query.prepare("INSERT INTO client(FirstName, LastName, CompanyName, PhoneNumber, Email, Website, Street, City, ZipCode, Country, BankAccountNumber, CreditLimit)" "VALUES(:FirstName, :LastName, :CompanyName, :PhoneNumber, :Email, :Website, :Street, :City, :ZipCode, :Country, :BankAccountNumber, :CreditLimit)");

    //Creation des variables liées
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

    //exec() envoie la requete pour l'executer
    return query.exec();
 }

bool Customer::Editer()
{
    QSqlQuery query;
    QString PhoneNumberS=QString::number(PhoneNumber);
    QString ZipCodeS=QString::number(ZipCode);
    QString BankAccountNumberS=QString::number(BankAccountNumber);
    QString CreditLimitS=QString::number(CreditLimit);

    //Prepare() prend la requete en parametre pour la préparer a l'execution
    query.prepare("update client set id='"+id+"',Firstname='"+FirstName+"',LastName='"+LastName+"',CompanyName='"+CompanyName+"',PhoneNumber='"+PhoneNumberS+"',Email='"+Email+"',Website='"+Website+"',Street='"+Street+"',City='"+City+"',ZipCode='"+ZipCodeS+"',Country='"+Country+"',BankAccountNumber='"+BankAccountNumberS+"',CreditLimit='"+CreditLimitS+"' where id='"+id+"'");

    //Creation des variables liées
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

    //exec() envoie la requete pour l'executer
    return query.exec();
}


QSqlQuery Customer::LoadData()
{
    QSqlQuery query;
    query.prepare("select id from client");
    return query;
}


QSqlQueryModel* Customer::AfficherListe()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery query=LoadData();
    query.exec();
    modal->setQuery(query);
    return modal;
}


bool Customer::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from client where id='"+itemText+"'");
    return query.exec();
}


QSqlQueryModel* Customer::Trier_CreditLimit()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry ;
    qry.prepare(" SELECT ID FROM CLIENT ORDER BY CREDITLIMIT DESC");
    qry.exec();

    model->setQuery(qry);
    return model;
}
QSqlQueryModel* Customer::Trier_ID()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry ;
    qry.prepare(" SELECT ID FROM CLIENT ORDER BY ID DESC");
    qry.exec();

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* Customer::Trier_FirstName()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry ;
    qry.prepare(" SELECT ID FROM CLIENT ORDER BY FIRSTNAME DESC");
    qry.exec();

    model->setQuery(qry);
    return model;
}

QSqlQuery Customer::Lire(QString itemText)
{
    QSqlQuery query;
    query.prepare("select * from Client where id='"+itemText+"'");
    query.exec();

    return query;

}

QSqlQueryModel * Customer::chercher(QString information)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select id from Client where id='"+information+"'");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQuery Customer::stat()
{
    QSqlQuery query;
        query.prepare("select *from client ");
        query.exec();
        return query;
}

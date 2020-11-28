#include "client.h"
//
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

client::client(QString nvID,QString nvFirstName,QString nvLastName,QString nvCompanyName,int nvPhoneNumber,QString nvEmail,QString nvWebsite,QString nvStreet,QString nvCity,int nvZipCode,QString nvCountry,int nvBankAccountNumber,float nvCreditLimit)
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

    //Prepare() prend la requete en parametre pour la préparer a l'execution
    query.prepare("INSERT INTO client(id, FirstName, LastName, CompanyName, PhoneNumber, Email, Website, Street, City, ZipCode, Country, BankAccountNumber, CreditLimit)" "VALUES(:id, :FirstName, :LastName, :CompanyName, :PhoneNumber, :Email, :Website, :Street, :City, :ZipCode, :Country, :BankAccountNumber, :CreditLimit)");

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

bool client::Editer()
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

QSqlQueryModel* client::Afficher(QString itemText)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from client WHERE id='"+itemText+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Company Name"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Phone Number"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Website"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Street"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("City"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("ZipCode"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("Country"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("Bank Account Number"));
    model->setHeaderData(12,Qt::Horizontal,QObject::tr("Credit Limit"));
    return model;
}

QSqlQuery client::LoadData()
{
    QSqlQuery query;
    query.prepare("select id from client");
    return query;
}


QSqlQueryModel* client::AfficherListe()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery query=LoadData();
    query.exec();
    modal->setQuery(query);
    return modal;
}


bool client::Effacer(QString itemText)
{
    QSqlQuery query;
    query.prepare("Delete from client where id='"+itemText+"'");
    return query.exec();
}


QSqlQueryModel* client::Trier()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry ;
    qry.prepare(" SELECT ID FROM CLIENT ORDER BY CREDITLIMIT DESC");
    qry.exec();

    model->setQuery(qry);
    return model;
}

QSqlQuery client::Lire(QString itemText)
{
    QSqlQuery query;
    query.prepare("select * from Client where id='"+itemText+"'");
    query.exec();

    return query;

}

QSqlQueryModel * client::chercher(QString information)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select id from Client where id='"+information+"'");
    query.exec();
    model->setQuery(query);
    return model;
}

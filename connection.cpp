#include "connection.h"

//Test Tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{
bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("debiche");//inserer nom de l'utilisateur
db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}

void Connection::closeconnection()
{
    db.close();
}

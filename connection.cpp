#include "connection.h"
#include "connection.h"
#include "mainwindow.h"


Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2a");
db.setUserName("zamni");//inserer nom de l'utilisateur
db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}

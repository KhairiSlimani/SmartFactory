#include "connection.h"

Connection::Connection()
{

}

bool Connection::openConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("projetcpp");

    if(db.open())
    {
        test=true;
    }

    return test;
}


void Connection::closeConnection()
{
    db.close();
}

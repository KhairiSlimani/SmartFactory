#include "databaseconnection.h"

Connect::Connect()
{

}

bool Connect::openConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flr");
    db.setUserName("Meriam");
    db.setPassword("Meriam");

    if(db.open())
    {
        test=true;
    }

    return test;
}

void Connect::closeConnection()
{
    db.close();
}

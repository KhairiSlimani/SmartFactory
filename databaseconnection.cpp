#include "databaseconnection.h"

Connect::Connect()
{

}

bool Connect::openConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("florallo");
    db.setUserName("aziza");
    db.setPassword("esprit20");

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

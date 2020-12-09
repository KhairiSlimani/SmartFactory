#include "databaseconnection.h"

Connect::Connect()
{

}

bool Connect::openConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("florallo");
    db.setUserName("florallo");
    db.setPassword("florallo");

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

#include "connection.h"

Connection::Connection()
{

}

bool Connection::openConnection()
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


void Connection::closeConnection()
{
    db.close();
}

#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class Connection
{
private:
    QSqlDatabase db;

public:
    Connection();
    bool openConnection();
    void closeConnection();
};

#endif // CONNECTION_H

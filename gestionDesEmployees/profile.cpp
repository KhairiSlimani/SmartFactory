#include "profile.h"

Profile::Profile()
{

}

Profile::Profile(QString id, QString password, QString jobTitle)
{
    this->id=id;
    this->password=password;
    this->jobTitle=jobTitle;

}

bool Profile::create()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Profile (id,password,jobTitle)" "VALUES (:id,:password,:jobTitle)");
    query.bindValue(":id",id);
    query.bindValue(":password",password);
    query.bindValue(":jobTitle",jobTitle);

    return query.exec();

}

QSqlQuery Profile::read(QString info)
{
    QSqlQuery query;
    query.prepare("select * from Profile where id='"+info+"'");
    if(query.exec())
    {
        return query;
    }
    else
    {
        QSqlQuery err;
        return err;
    }

}

bool Profile::Delete(QString info)
{
    QSqlQuery query;
    query.prepare("Delete from Profile where id='"+info+"'");
    return query.exec();
}

bool Profile::Update()
{
    QSqlQuery query;

    query.prepare("update Profile set id='"+id+"',password='"+password+"',jobTitle='"+jobTitle+"' where id='"+id+"'");

    query.bindValue(":id",id);
    query.bindValue(":password",password);
    query.bindValue(":jobTitle",jobTitle);

    return query.exec();
}

bool Profile::search(QString info)
{
    QSqlQuery query;
    query.prepare("select * from Profile where id='"+info+"'");
    query.exec();
    if(query.next())
    {
        return true;
    }

    return false;
}


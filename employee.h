#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QMessageBox>
#include <QDebug>
#include <QListView>
#include <QPieSeries>
#include <QtCharts>
#include <QChartView>
#include "smtp.h"

class Employee
{
protected:
    int phoneNumber;
    float salary;
    QString id,firstName,lastName,sex,adresse,birthDate,hireDate,jobTitle,email;

public:
    //Constructors
    Employee();
    Employee(int,float,QString,QString,QString,QString,QString,QString,QString,QString,QString);

    //Getters
    int getPhoneNumber(){return phoneNumber;};
    float getSalary(){return salary;};
    QString getId(){return id;};
    QString getFirstName(){return firstName;};
    QString getLastName(){return lastName;};
    QString getSex(){return sex;};
    QString getAdresse(){return adresse;};
    QString getBirthDate(){return birthDate;};
    QString getJobTitle(){return jobTitle;};
    QString getEmail(){return email;};

    //Setters
    void setPhoneNumber(int newPhoneNumber){phoneNumber=newPhoneNumber;};
    void setSalary(float newSalary){salary=newSalary;};
    void setId(QString newId){id=newId;};
    void setFirstName(QString newFirstName){firstName=newFirstName;};
    void setLastName(QString newLastName){lastName=newLastName;};
    void setSex(QString newSex){sex=newSex;};
    void setAdresse(QString newAdresse){adresse=newAdresse;};
    void setBirthDate(QString newBirthDate){birthDate=newBirthDate;};
    void setHireDate(QString newHireDate){hireDate=newHireDate;};
    void setJobTitle(QString newJobTitle){jobTitle=newJobTitle;};
    void setEmail(QString newEmail){email=newEmail;};

    //Methods
    bool create();
    QSqlQuery read(QString);
    bool Update();
    bool Delete(QString);
    QSqlQueryModel * loadData();
    QSqlQueryModel * search(QString);
    QSqlQueryModel * sort();
    QSqlQueryModel * sortID();
    QSqlQueryModel * sortFirstName();
    bool searchID(QString);
    QChart * statistic();
};

#endif // EMPLOYEE_H

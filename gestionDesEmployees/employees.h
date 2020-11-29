#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QListWidgetItem>
#include <QMenu>
#include <QHeaderView>
#include <QMessageBox>
#include <QDebug>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>
#include <QString>
#include "deleteconfirmation.h"
#include "employee.h"
#include "smtp.h"

namespace Ui {
class Employees;
}

class Employees : public QDialog
{
    Q_OBJECT

public:
    explicit Employees(QWidget *parent = nullptr);
    ~Employees();

signals:
    void goToProfile();

private:
    Ui::Employees *ui;
    Smtp* smtp ;
    QString msg;
    QString mail;


private slots:
    void on_profileButton_clicked();
    void on_addEmployeeButton_clicked();
    void on_addButton_clicked();
    void on_cancelButton_clicked();
    void on_saveButton_clicked();
    void on_cancelButton_2_clicked();
    void on_printButton_clicked();
    void on_returnButton_clicked();
    void on_sendMailButton_clicked();
    void on_cancelButton_3_clicked();

    void showTime();

    void showContextMenu(const QPoint&);
    void deleteEmployee();
    void viewEmployee();
    void editEmployee();
    void sendEmailToEmployee();

    void loadData();

    void mailSent(QString)
    {

    };

    void on_sortButton_clicked();
    void on_searchLineEdit_textChanged(const QString &arg1);
};

#endif // EMPLOYEES_H

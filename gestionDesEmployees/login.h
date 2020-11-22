#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include "profile.h"
#include "employees.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_signInButton_clicked();
    void on_goToSignUpButton_clicked();
    void on_SignUpButton_clicked();
    void on_goToSignInButton_clicked();
    void on_changeInformationButton_clicked();
    void on_deleteAccountButton_clicked();
    void on_logOutButton_clicked();
    void on_logOutButton_2_clicked();
    void on_access1Button_clicked();
    void on_access2Button_clicked();

    void showTime();

    void on_cancelButton_2_clicked();

    void on_saveButton_clicked();

private:
    Ui::Login *ui;
    QPropertyAnimation *animation;
    Employees employees;

};
#endif // LOGIN_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QListWidgetItem>
#include <QMenu>
#include <QHeaderView>
#include <QDebug>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>
#include <QString>
#include <QSortFilterProxyModel>
#include<QtMultimedia/QMediaPlayer>
#include<QTextTable>
#include<QScrollBar>
#include "employee.h"
#include "profile.h"
#include "smtp.h"
#include "client.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString id;

public slots:
    void appendMessage(const QString &from, const QString &message);

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
    void on_addEmployeeButton_clicked();
    void on_sortButton_clicked();
    void on_addButton_clicked();
    void on_cancelButton_clicked();
    void on_saveButton_2_clicked();
    void on_cancelButton_3_clicked();
    void on_printButton_clicked();
    void on_returnButton_clicked();
    void on_sendMailButton_clicked();
    void on_cancelButton_4_clicked();
    void on_profileButton_clicked();
    void on_profileButton_2_clicked();
    void on_profileButton_3_clicked();
    void on_profileButton_4_clicked();
    void on_profileButton_5_clicked();
    void showContextMenu(const QPoint&);
    void deleteEmployee();
    void viewEmployee();
    void editEmployee();
    void sendEmailToEmployee();
    void loadData();
    void mailSent(QString){};
    void on_searchLineEdit_textChanged(const QString &arg1);
    void on_profileButton_6_clicked();
    void returnPressed();
    void statistics();
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);
    void showInformation();


    void on_statisticButton_clicked();

    void on_returnButton_2_clicked();

    void on_returnButton_3_clicked();

    void on_profileButton_7_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    Smtp* smtp ;
    QString msg;
    QString mail;
    QMediaPlayer *trashSound;
    Client client;
    QString myNickName;
    QTextTableFormat tableFormat;

};
#endif // MAINWINDOW_H

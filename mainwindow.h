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
#include <QSound>
#include "employee.h"
#include "profile.h"
#include "smtp.h"
#include "client.h"
#include "project.h"
#include "customer.h"
#include "deleteconfirmation.h"
#include "bill.h"
#include "order.h"


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
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);
    void showInformation();

    void on_returnButton_2_clicked();

    void on_returnButton_3_clicked();

    void on_profileButton_7_clicked();

    //declaration yasmine
    void showContextMenuCustomers(const QPoint &pos);

    void on_pushButton_SaveAddCustomer_clicked();

    void on_pushButton_SaveEditCustomer_clicked();

    void on_pushButton_Return_clicked();

    void on_pushButton_CancelEditCustomer_clicked();

    void on_pushButton_CancelAddCustomer_clicked();

    void on_pushButton_return2_clicked();

    void on_signOut_6_clicked();

    void on_signOut_5_clicked();

    void on_signOut_4_clicked();

    void on_signOut_3_clicked();

    void on_signOut_1_clicked();

    void on_pushButton_Print_clicked();

    void on_pushButton_Send_clicked();

    void on_pushButton_SortCustomers_clicked();

    void on_lineEdit_SearchCustomer_textChanged(const QString &arg1);

    void on_CustomersButton_clicked();

    void on_pushButton_AddNewCustomer_clicked();

    void DeleteCustomer();

    void ViewCustomer();

    void EditCustomer();

    void SendEmailToCustomer();
    void on_profile_7_clicked();

    void on_profile_1_clicked();

    void on_profile_3_clicked();

    void on_profile_4_clicked();

    void on_profile_5_clicked();

    void on_profile_6_clicked();
    void showContextMenuProject(const QPoint &pos);
    void deleteProject();
    void viewProject();
    void editProject();

    void on_pushButton_AddNewProject_clicked();

    void on_pushButton_SaveAddProject_clicked();

    void on_pushButton_SaveEditProject_clicked();

    void on_pushButton_CancelAddProject_clicked();

    void on_pushButton_CancelEditProject_clicked();

    void on_pushButton_Return_2_clicked();

    void on_pushButton_SortProject_clicked();

    void on_lineEdit_SearchProject_textChanged(const QString &arg1);

    void on_pushButton_Print_2_clicked();

    void on_signOut_8_clicked();

    void on_signOut_10_clicked();

    void on_signOut_12_clicked();

    void on_signOut_14_clicked();

    void on_signOut_9_clicked();

    void on_signOut_11_clicked();

    void on_signOut_13_clicked();

    void on_signOut_15_clicked();

    void on_ProjectsButton_clicked();

    //meriam declaration

    void statistique();
    void initEditBill();
    void initAddBill();
    void initEditOrder();
    void initAddOrder();

    void showContextMenuBill(const QPoint &pos);
    void showContextMenuOrder(const QPoint &pos);

    void on_orderButton_clicked();

    void on_billButton_clicked();

    void deleteBill();
    void viewBill();
    void editBill();

    void deleteOrder();
    void viewOrder();
    void editOrder();
    void sendMail();

    int on_billListView_doubleClicked(const QModelIndex &index);

    void on_sort_clicked();

    void on_addOrder_clicked();
    void on_editButton_clicked();
    void on_addButton_2_clicked();

    void on_return_9_clicked();

    void on_edit_clicked();

    void on_cancelButton_22_clicked();

    void on_back_clicked();

    void on_addBill_clicked();

    void on_back_2_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_addBill_2_clicked();

    void on_return_11_clicked();

    void on_cancelButton_23_clicked();

    void on_options_clicked();

    //mail functions

     void on_sendMailButton_2_clicked();

     void on_cancelButton_5_clicked();



     void on_cancelButton_7_clicked();

     void on_cancelButton_6_clicked();



     void on_signOut_16_clicked();

     void on_signOut_18_clicked();

     void on_signOut_22_clicked();

     void on_signOut_17_clicked();

     void on_signOut_19_clicked();

     void on_signOut_23_clicked();

     ////////end meriam's declaration

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    Smtp* smtp ;
    QString msg;
    QString mail;
    QMediaPlayer *trashSound;
    Client client;
    Project P;
    QString myNickName;
    QTextTableFormat tableFormat;

    //declaration yasmine
    Customer C;

    //declaration meriam

    bill b;
    order o;
    QPropertyAnimation *animation1;
    QSound *coinSound;

};
#endif // MAINWINDOW_H

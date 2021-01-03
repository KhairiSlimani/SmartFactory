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
#include "produit.h"
#include "depot.h"
#include "arduino.h"
#include "arduino_alcohol.h"
#include"material.h"
#include"suppliers.h"
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLegend>
#include "history.h"



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
    void update();


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
    void update_label();

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
    void PrintBill();

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

     void on_searchOrder_textChanged(const QString &arg1);
     ////////end meriam's declaration
     //start of chedi declaration
     void showContextMenuProduct(const QPoint &pos);
     void showContextMenuWarehouse(const QPoint &pos);

     void DeleteItemProduct();
     void ViewItemProduct();
     void EditItemProduct();
     void SendEmailToItemProduct();
     void on_ProductsButton_clicked();
     void on_WarehouseButton_clicked();
     void on_signOut_40_clicked();
     void on_pushButton_AddNewProduct_2_clicked();
     void on_pushButton_SortProduct_2_clicked();
     void on_pushButton_Search_2_clicked();
     void on_LoadData_2_clicked();
     void on_signOut_41_clicked();
     void on_pushButton_Print_4_clicked();
     void on_pushButton_Return_4_clicked();
     void on_signOut_42_clicked();
     void on_pushButton_2_clicked();
     void on_pushButton_SaveEditProduct_2_clicked();
     void on_pushButton_CancelEditProduct_2_clicked();
     void on_signOut_44_clicked();
     void on_pushButton_SaveAddProduct_2_clicked();
     void on_signOut_45_clicked();
     void on_pushButton_CancelAddProduct_2_clicked();
     void on_pushButton_3_clicked();
     void on_pushButton_4_clicked();


     void deleteWarehouse();
     void viewWarehouse();
     void editWarehouse();


     void on_pushButton_AddNewWarehouse_clicked();

     void on_LoadData_3_clicked();

     void on_signOut_46_clicked();

     void on_pushButton_Return_5_clicked();

     void on_signOut_47_clicked();

     void on_pushButton_CancelEditWarehouse_clicked();

     void on_signOut_48_clicked();

     void on_pushButton_SaveEditWarehouse_clicked();

     void on_signOut_49_clicked();

     void on_pushButton_CancelAddWarehouse_clicked();

     void on_pushButton_SaveAddWarehouse_clicked();

     void on_cancelButton_8_clicked();

     void on_pushButtonADD_clicked();

     void on_pushButton_Add_clicked();

     void on_pushButton_Addcancel_clicked();

     void on_pushButton_matAddlist_clicked();

     void on_pushButton_AddMaterialAdd_clicked();

     void on_pushButton_12_clicked();

     void on_pushButton_SearchMaterial_clicked();

     void on_lineEdit_SearchMaterial_textChanged(const QString &arg1);

     void on_pushButton_SortMaterial_clicked();

     void on_pushButton_statMateriel_clicked();

     void on_pushButton_10_clicked();

     void on_pushButton_confirmMaterialEdit_clicked();

     void on_pushButton_13_clicked();

     void on_pushButton_14_clicked();

     void on_pushButton_Home_clicked();

     void on_pushButton_EditSaveSupplier_clicked();

     void on_pushButton_Editcancel_clicked();

     void on_pushButton_ViewReturn_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();

     void on_pushButton_menusupplier_clicked();

     void on_pushButton_menuMaterial_clicked();

     void on_pushButton_15_clicked();

     void on_signOut_63_clicked();

     void on_signOut_62_clicked();

     void on_signOut_61_clicked();

     void on_signOut_60_clicked();

     void on_signOut_59_clicked();

     void on_signOut_58_clicked();

     void on_signOut_57_clicked();

     void on_signOut_7_clicked();

     void on_signOut_39_clicked();

     void on_signOut_27_clicked();

     void on_signOut_28_clicked();

     void on_signOut_29_clicked();

     void on_signOut_43_clicked();

     void on_signOut_30_clicked();

     void on_signOut_31_clicked();

     void on_signOut_32_clicked();

     void on_signOut_33_clicked();

     void on_signOut_34_clicked();

     void on_signOut_35_clicked();

     void on_signOut_36_clicked();

     void on_profile_10_clicked();

     void on_signOut_24_clicked();

     void on_profile_11_clicked();

     void on_signOut_25_clicked();

     void on_profile_12_clicked();

     void on_signOut_26_clicked();

     void on_profile_13_clicked();

     void on_signOut_37_clicked();

     void on_profile_15_clicked();

     void on_signOut_51_clicked();

     void on_profile_16_clicked();

     void on_signOut_52_clicked();

     void on_profile_17_clicked();

     void on_signOut_53_clicked();

     void on_profile_18_clicked();

     void on_signOut_54_clicked();

     void on_profile_19_clicked();

     void on_signOut_55_clicked();

     void on_profile_20_clicked();

     void on_signOut_56_clicked();

     void on_returnstatmaterial_clicked();

     void on_pushButton_return2_3_clicked();

     void on_pushButton_arduino_clicked();

     void on_pushButton_159_clicked();

     void on_signOut_64_clicked();

     void on_signOut_65_clicked();

     void on_pushButton_16_clicked();

     void on_comboBoxSortCustomers_currentTextChanged(const QString &arg1);

     void on_comboBoxSortProject_currentTextChanged(const QString &arg1);

     void on_accessButton_2_clicked();

     void on_accessButton_3_clicked();

     void on_accessButton_4_clicked();

     void on_sortButton_3_clicked();

     void on_sortButton_2_clicked();

     void on_sort_totalAmount_clicked();

     void on_sort_releaseDate_clicked();

     void on_sort_shipperName_clicked();

     void on_sort_order_clicked();

     void on_sort_discount_clicked();

     void on_sort_orderDate_clicked();

     void on_sort_orderID_clicked();
     //// nessrine'work

     void showContextMenuSupplier(const QPoint &pos);
     void showContextMenuMaterial(const QPoint &pos);
     void deleteSupplier();
     void viewSupplier();
     void editSupplier();
     void SendMail();


     void deleteMaterial();
     void viewMaterial();
     void editMaterial();


     void on_print_clicked();
    //void update_label2();//arduino nesrine

     void on_statisticButton_clicked();


     void on_pushButton_clicked();

     void on_pushButton_Return_3_clicked();

     void on_profile_8_clicked();

     void on_signOut_20_clicked();

     void on_signOut_21_clicked();

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
    Arduino A;
    QByteArray data;
    material m ;
    Suppliers s;



    //declaration yasmine
    Project P;
    Customer C;
    historique h;

    //declaration meriam

    bill b;
    order o;
    QPropertyAnimation *animation1;
    QSound *coinSound;
    //declaration meriam + yesmine
    QByteArray data1;
    arduino_alcohol D;

    //declaration chedi
    produit P1;
    depot DEPOT;


};
#endif // MAINWINDOW_H

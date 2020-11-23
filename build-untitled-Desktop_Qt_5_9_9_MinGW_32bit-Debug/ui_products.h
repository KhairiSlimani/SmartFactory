/********************************************************************************
** Form generated from reading UI file 'products.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTS_H
#define UI_PRODUCTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_products
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame;
    QLabel *labelLogo1;
    QPushButton *profile_1;
    QPushButton *signOut_1;
    QFrame *frame_2;
    QLineEdit *lineEdit_SearchCustomer;
    QPushButton *pushButton_SortProduct;
    QPushButton *pushButton_AddNewProduct;
    QListView *listView;
    QPushButton *LoadData;
    QPushButton *pushButton_Search;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *time;
    QLabel *date;
    QWidget *page_4;
    QFrame *frame_7;
    QLabel *labelLogo2;
    QPushButton *profile_2;
    QPushButton *signOut_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_Return;
    QLabel *time2;
    QLabel *date2;
    QTableView *tableView;
    QPushButton *pushButton_Print;
    QWidget *page_5;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_Email;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_Subject;
    QLabel *label_18;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_return2;
    QFrame *frame_8;
    QLabel *labelLogo3;
    QPushButton *profile_3;
    QPushButton *signOut_3;
    QPushButton *pushButton;
    QWidget *page_3;
    QFrame *frame_5;
    QLabel *labelLogo4;
    QPushButton *profile_4;
    QPushButton *signOut_4;
    QFrame *frame_6;
    QLineEdit *lineEdit_ProductCodeInput_2;
    QLineEdit *lineEdit_ProductNameInput_2;
    QLineEdit *lineEdit_SellPriceInput_2;
    QLineEdit *lineEdit_QuantityInStockInput_2;
    QPushButton *pushButton_SaveEditProduct;
    QPushButton *pushButton_CancelEditProduct;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *time3;
    QLabel *date3;
    QWidget *page_2;
    QFrame *frame_3;
    QLabel *labelLogo5;
    QPushButton *profile_5;
    QPushButton *signOut_5;
    QFrame *frame_4;
    QLineEdit *lineEdit_ProductCodeInput;
    QLineEdit *lineEdit_QuantityInStockInput;
    QLineEdit *lineEdit_SellPriceInput;
    QLineEdit *lineEdit_ProductNameInput;
    QPushButton *pushButton_SaveAddProduct;
    QPushButton *pushButton_CancelAddProduct;
    QLabel *label;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *time4;
    QLabel *date4;

    void setupUi(QWidget *products)
    {
        if (products->objectName().isEmpty())
            products->setObjectName(QStringLiteral("products"));
        products->resize(769, 460);
        stackedWidget = new QStackedWidget(products);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 751, 471));
        stackedWidget->setStyleSheet(QLatin1String("QScrollBar::handle:vertical \n"
"{\n"
"background-color:rgb(85,170,255);\n"
"border-top-left-radius:7px;\n"
"border-top-right-radius:7px;\n"
"subcontrol-position:top;\n"
"subcontrol-origin:margin;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:horizental\n"
"{\n"
"background-color:rgb(255,152,207);\n"
"border-top-left-radius:7px;\n"
"border-top-right-radius:7px;\n"
"subcontrol-position:top;\n"
"subcontrol-origin:margin;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        frame = new QFrame(page);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 191, 461));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelLogo1 = new QLabel(frame);
        labelLogo1->setObjectName(QStringLiteral("labelLogo1"));
        labelLogo1->setGeometry(QRect(10, 30, 171, 171));
        labelLogo1->setStyleSheet(QStringLiteral("border-image:url(://img/floralloLogo.png);"));
        profile_1 = new QPushButton(frame);
        profile_1->setObjectName(QStringLiteral("profile_1"));
        profile_1->setGeometry(QRect(70, 230, 61, 61));
        profile_1->setStyleSheet(QLatin1String("#profile_1\n"
"{\n"
"   border-image:url(://img/profileIcon.png);\n"
"}\n"
"\n"
"#profile_1:hover\n"
"{\n"
"  border-image:url(://img/profileIconHover.png);\n"
"}"));
        signOut_1 = new QPushButton(frame);
        signOut_1->setObjectName(QStringLiteral("signOut_1"));
        signOut_1->setGeometry(QRect(80, 330, 51, 51));
        signOut_1->setStyleSheet(QLatin1String("#signOut_1\n"
"{\n"
"   border-image:url(://img/signOut.png);\n"
"}\n"
"\n"
"#signOut_1:hover\n"
"{\n"
"  border-image:url(://img/signOutHover.png);\n"
"}"));
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(210, 110, 521, 331));
        frame_2->setStyleSheet(QLatin1String("#frame_2\n"
"{\n"
"	border:4px solid rgb(85, 170, 255);\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit_SearchCustomer = new QLineEdit(frame_2);
        lineEdit_SearchCustomer->setObjectName(QStringLiteral("lineEdit_SearchCustomer"));
        lineEdit_SearchCustomer->setGeometry(QRect(300, 20, 141, 31));
        lineEdit_SearchCustomer->setStyleSheet(QLatin1String("#lineEdit_SearchCustomer\n"
"{\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px rgb(85,170,255);\n"
"border-radius: 14px;\n"
"}"));
        pushButton_SortProduct = new QPushButton(frame_2);
        pushButton_SortProduct->setObjectName(QStringLiteral("pushButton_SortProduct"));
        pushButton_SortProduct->setGeometry(QRect(330, 110, 141, 23));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton_SortProduct->setFont(font);
        pushButton_SortProduct->setStyleSheet(QLatin1String("#pushButton_SortCustomers\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 10px;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_SortCustomers:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        pushButton_AddNewProduct = new QPushButton(frame_2);
        pushButton_AddNewProduct->setObjectName(QStringLiteral("pushButton_AddNewProduct"));
        pushButton_AddNewProduct->setGeometry(QRect(318, 150, 171, 23));
        pushButton_AddNewProduct->setFont(font);
        pushButton_AddNewProduct->setStyleSheet(QLatin1String("#pushButton_AddNewCustomer\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 10px;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_AddNewCustomer:hover\n"
"{\n"
"background: rgb(85,170,255);\n"
"}"));
        listView = new QListView(frame_2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(30, 20, 261, 291));
        LoadData = new QPushButton(frame_2);
        LoadData->setObjectName(QStringLiteral("LoadData"));
        LoadData->setGeometry(QRect(380, 230, 75, 23));
        LoadData->setFont(font);
        LoadData->setStyleSheet(QLatin1String("#LoadData\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 10px;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#LoadData:hover\n"
"{\n"
"background: rgb(85,170,255);\n"
"}"));
        pushButton_Search = new QPushButton(frame_2);
        pushButton_Search->setObjectName(QStringLiteral("pushButton_Search"));
        pushButton_Search->setGeometry(QRect(450, 23, 61, 23));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_Search->setFont(font1);
        pushButton_Search->setStyleSheet(QLatin1String("#pushButton_Search\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 10px;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_Search:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 10, 291, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font2.setPointSize(28);
        label_2->setFont(font2);
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(540, 20, 51, 21));
        QFont font3;
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 50, 47, 21));
        label_4->setFont(font3);
        time = new QLabel(page);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(590, 17, 151, 31));
        time->setFont(font3);
        date = new QLabel(page);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(590, 45, 112, 31));
        date->setFont(font3);
        stackedWidget->addWidget(page);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        frame_7 = new QFrame(page_4);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(0, 0, 191, 461));
        frame_7->setStyleSheet(QStringLiteral("background:rgb(85,170,255);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        labelLogo2 = new QLabel(frame_7);
        labelLogo2->setObjectName(QStringLiteral("labelLogo2"));
        labelLogo2->setGeometry(QRect(10, 30, 171, 171));
        labelLogo2->setStyleSheet(QStringLiteral("border-image:url(://img/floralloLogo.png);"));
        profile_2 = new QPushButton(frame_7);
        profile_2->setObjectName(QStringLiteral("profile_2"));
        profile_2->setGeometry(QRect(70, 230, 61, 61));
        profile_2->setStyleSheet(QLatin1String("#profile_2\n"
"{\n"
"   border-image:url(://img/profileIcon.png);\n"
"}\n"
"\n"
"#profile_2:hover\n"
"{\n"
"  border-image:url(://img/profileIconHover.png);\n"
"}"));
        signOut_2 = new QPushButton(frame_7);
        signOut_2->setObjectName(QStringLiteral("signOut_2"));
        signOut_2->setGeometry(QRect(80, 330, 51, 51));
        signOut_2->setStyleSheet(QLatin1String("#signOut_2\n"
"{\n"
"   border-image:url(://img/signOut.png);\n"
"}\n"
"\n"
"#signOut_2:hover\n"
"{\n"
"  border-image:url(://img/signOutHover.png);\n"
"}"));
        label_11 = new QLabel(page_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(210, 90, 311, 61));
        label_11->setFont(font2);
        label_12 = new QLabel(page_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(540, 20, 51, 21));
        label_12->setFont(font3);
        label_13 = new QLabel(page_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(540, 50, 51, 21));
        label_13->setFont(font3);
        pushButton_Return = new QPushButton(page_4);
        pushButton_Return->setObjectName(QStringLiteral("pushButton_Return"));
        pushButton_Return->setGeometry(QRect(600, 410, 75, 23));
        pushButton_Return->setFont(font);
        pushButton_Return->setStyleSheet(QLatin1String("#pushButton_Return\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_Return:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        time2 = new QLabel(page_4);
        time2->setObjectName(QStringLiteral("time2"));
        time2->setGeometry(QRect(590, 17, 151, 31));
        time2->setFont(font3);
        date2 = new QLabel(page_4);
        date2->setObjectName(QStringLiteral("date2"));
        date2->setGeometry(QRect(590, 45, 112, 31));
        date2->setFont(font3);
        tableView = new QTableView(page_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(220, 170, 491, 192));
        pushButton_Print = new QPushButton(page_4);
        pushButton_Print->setObjectName(QStringLiteral("pushButton_Print"));
        pushButton_Print->setGeometry(QRect(450, 410, 75, 23));
        pushButton_Print->setStyleSheet(QLatin1String("#pushButton_Print\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_Print:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_14 = new QLabel(page_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(240, 10, 47, 16));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_14->setFont(font4);
        label_15 = new QLabel(page_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(230, 42, 47, 16));
        label_15->setFont(font4);
        label_16 = new QLabel(page_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(240, 80, 47, 16));
        label_16->setFont(font4);
        label_17 = new QLabel(page_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(200, 110, 71, 21));
        label_17->setFont(font4);
        lineEdit_Email = new QLineEdit(page_5);
        lineEdit_Email->setObjectName(QStringLiteral("lineEdit_Email"));
        lineEdit_Email->setGeometry(QRect(270, 10, 441, 20));
        lineEdit_2 = new QLineEdit(page_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(270, 42, 441, 20));
        lineEdit_3 = new QLineEdit(page_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(270, 77, 441, 20));
        lineEdit_Subject = new QLineEdit(page_5);
        lineEdit_Subject->setObjectName(QStringLiteral("lineEdit_Subject"));
        lineEdit_Subject->setGeometry(QRect(270, 110, 301, 20));
        label_18 = new QLabel(page_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(580, 112, 61, 16));
        label_18->setFont(font4);
        comboBox = new QComboBox(page_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(650, 110, 62, 22));
        plainTextEdit = new QPlainTextEdit(page_5);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(270, 155, 441, 251));
        pushButton_return2 = new QPushButton(page_5);
        pushButton_return2->setObjectName(QStringLiteral("pushButton_return2"));
        pushButton_return2->setGeometry(QRect(450, 420, 75, 23));
        pushButton_return2->setFont(font);
        pushButton_return2->setStyleSheet(QLatin1String("#pushButton_return2\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_return2:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        frame_8 = new QFrame(page_5);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setGeometry(QRect(0, 0, 191, 461));
        frame_8->setStyleSheet(QStringLiteral("background:rgb(85,170,255);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        labelLogo3 = new QLabel(frame_8);
        labelLogo3->setObjectName(QStringLiteral("labelLogo3"));
        labelLogo3->setGeometry(QRect(10, 30, 171, 171));
        labelLogo3->setStyleSheet(QStringLiteral("border-image:url(://img/floralloLogo.png);"));
        profile_3 = new QPushButton(frame_8);
        profile_3->setObjectName(QStringLiteral("profile_3"));
        profile_3->setGeometry(QRect(70, 230, 61, 61));
        profile_3->setStyleSheet(QLatin1String("#profile_3\n"
"{\n"
"   border-image:url(://img/profileIcon.png);\n"
"}\n"
"\n"
"#profile_3:hover\n"
"{\n"
"  border-image:url(://img/profileIconHover.png);\n"
"}"));
        signOut_3 = new QPushButton(frame_8);
        signOut_3->setObjectName(QStringLiteral("signOut_3"));
        signOut_3->setGeometry(QRect(80, 330, 51, 51));
        signOut_3->setStyleSheet(QLatin1String("#signOut_3\n"
"{\n"
"   border-image:url(://img/signOut.png);\n"
"}\n"
"\n"
"#signOut_3:hover\n"
"{\n"
"  border-image:url(://img/signOutHover.png);\n"
"}"));
        pushButton = new QPushButton(page_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 420, 75, 23));
        pushButton->setStyleSheet(QLatin1String("#sendmail\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#sendmail:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        stackedWidget->addWidget(page_5);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        frame_5 = new QFrame(page_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, 0, 191, 461));
        frame_5->setStyleSheet(QStringLiteral("background:rgb(85,170,255);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        labelLogo4 = new QLabel(frame_5);
        labelLogo4->setObjectName(QStringLiteral("labelLogo4"));
        labelLogo4->setGeometry(QRect(10, 30, 171, 171));
        labelLogo4->setStyleSheet(QStringLiteral("border-image:url(://img/floralloLogo.png);"));
        profile_4 = new QPushButton(frame_5);
        profile_4->setObjectName(QStringLiteral("profile_4"));
        profile_4->setGeometry(QRect(70, 230, 61, 61));
        profile_4->setStyleSheet(QLatin1String("#profile_4\n"
"{\n"
"   border-image:url(://img/profileIcon.png);\n"
"}\n"
"\n"
"#profile_4:hover\n"
"{\n"
"  border-image:url(://img/profileIconHover.png);\n"
"}"));
        signOut_4 = new QPushButton(frame_5);
        signOut_4->setObjectName(QStringLiteral("signOut_4"));
        signOut_4->setGeometry(QRect(80, 330, 51, 51));
        signOut_4->setStyleSheet(QLatin1String("#signOut_4\n"
"{\n"
"   border-image:url(://img/signOut.png);\n"
"}\n"
"\n"
"#signOut_4:hover\n"
"{\n"
"  border-image:url(://img/signOutHover.png);\n"
"}"));
        frame_6 = new QFrame(page_3);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(200, 100, 521, 331));
        frame_6->setStyleSheet(QLatin1String("#frame_6\n"
"{\n"
"	border:3px solid rgb(85, 170, 255);\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        lineEdit_ProductCodeInput_2 = new QLineEdit(frame_6);
        lineEdit_ProductCodeInput_2->setObjectName(QStringLiteral("lineEdit_ProductCodeInput_2"));
        lineEdit_ProductCodeInput_2->setGeometry(QRect(130, 40, 221, 22));
        QFont font5;
        font5.setPointSize(10);
        lineEdit_ProductCodeInput_2->setFont(font5);
        lineEdit_ProductCodeInput_2->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        lineEdit_ProductNameInput_2 = new QLineEdit(frame_6);
        lineEdit_ProductNameInput_2->setObjectName(QStringLiteral("lineEdit_ProductNameInput_2"));
        lineEdit_ProductNameInput_2->setGeometry(QRect(130, 110, 221, 22));
        lineEdit_ProductNameInput_2->setFont(font5);
        lineEdit_ProductNameInput_2->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        lineEdit_SellPriceInput_2 = new QLineEdit(frame_6);
        lineEdit_SellPriceInput_2->setObjectName(QStringLiteral("lineEdit_SellPriceInput_2"));
        lineEdit_SellPriceInput_2->setGeometry(QRect(130, 170, 221, 22));
        lineEdit_SellPriceInput_2->setFont(font5);
        lineEdit_SellPriceInput_2->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        lineEdit_QuantityInStockInput_2 = new QLineEdit(frame_6);
        lineEdit_QuantityInStockInput_2->setObjectName(QStringLiteral("lineEdit_QuantityInStockInput_2"));
        lineEdit_QuantityInStockInput_2->setGeometry(QRect(130, 230, 221, 22));
        lineEdit_QuantityInStockInput_2->setFont(font5);
        lineEdit_QuantityInStockInput_2->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        pushButton_SaveEditProduct = new QPushButton(frame_6);
        pushButton_SaveEditProduct->setObjectName(QStringLiteral("pushButton_SaveEditProduct"));
        pushButton_SaveEditProduct->setGeometry(QRect(360, 270, 51, 23));
        pushButton_SaveEditProduct->setFont(font1);
        pushButton_SaveEditProduct->setStyleSheet(QLatin1String("#pushButton_SaveEditCustomer\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_SaveEditCustomer:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        pushButton_CancelEditProduct = new QPushButton(frame_6);
        pushButton_CancelEditProduct->setObjectName(QStringLiteral("pushButton_CancelEditProduct"));
        pushButton_CancelEditProduct->setGeometry(QRect(420, 270, 61, 23));
        pushButton_CancelEditProduct->setFont(font1);
        pushButton_CancelEditProduct->setStyleSheet(QLatin1String("#pushButton_CancelEditCustomer\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_CancelEditCustomer:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        label_22 = new QLabel(frame_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(140, 150, 81, 16));
        label_23 = new QLabel(frame_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(140, 20, 81, 16));
        label_24 = new QLabel(frame_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(140, 80, 91, 16));
        label_25 = new QLabel(frame_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(140, 210, 101, 16));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 30, 291, 51));
        label_8->setFont(font2);
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(540, 20, 51, 21));
        label_9->setFont(font3);
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(540, 50, 51, 21));
        label_10->setFont(font3);
        time3 = new QLabel(page_3);
        time3->setObjectName(QStringLiteral("time3"));
        time3->setGeometry(QRect(590, 16, 151, 31));
        time3->setFont(font3);
        date3 = new QLabel(page_3);
        date3->setObjectName(QStringLiteral("date3"));
        date3->setGeometry(QRect(590, 46, 112, 31));
        date3->setFont(font3);
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 191, 471));
        frame_3->setStyleSheet(QStringLiteral("background:rgb(85,170,255);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        labelLogo5 = new QLabel(frame_3);
        labelLogo5->setObjectName(QStringLiteral("labelLogo5"));
        labelLogo5->setGeometry(QRect(10, 30, 171, 171));
        labelLogo5->setStyleSheet(QStringLiteral("border-image:url(://img/floralloLogo.png);"));
        profile_5 = new QPushButton(frame_3);
        profile_5->setObjectName(QStringLiteral("profile_5"));
        profile_5->setGeometry(QRect(70, 230, 61, 61));
        profile_5->setStyleSheet(QLatin1String("#profile_5\n"
"{\n"
"   border-image:url(://img/profileIcon.png);\n"
"}\n"
"\n"
"#profile_5:hover\n"
"{\n"
"  border-image:url(://img/profileIconHover.png);\n"
"}"));
        signOut_5 = new QPushButton(frame_3);
        signOut_5->setObjectName(QStringLiteral("signOut_5"));
        signOut_5->setGeometry(QRect(80, 330, 51, 51));
        signOut_5->setStyleSheet(QLatin1String("#signOut_5\n"
"{\n"
"   border-image:url(://img/signOut.png);\n"
"}\n"
"\n"
"#signOut_5:hover\n"
"{\n"
"  border-image:url(://img/signOutHover.png);\n"
"}"));
        frame_4 = new QFrame(page_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(210, 110, 521, 331));
        frame_4->setStyleSheet(QLatin1String("#frame_4\n"
"{\n"
"	border:3px solid rgb(85, 170, 255);\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        lineEdit_ProductCodeInput = new QLineEdit(frame_4);
        lineEdit_ProductCodeInput->setObjectName(QStringLiteral("lineEdit_ProductCodeInput"));
        lineEdit_ProductCodeInput->setGeometry(QRect(130, 50, 261, 21));
        lineEdit_ProductCodeInput->setFont(font5);
        lineEdit_ProductCodeInput->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;\n"
""));
        lineEdit_QuantityInStockInput = new QLineEdit(frame_4);
        lineEdit_QuantityInStockInput->setObjectName(QStringLiteral("lineEdit_QuantityInStockInput"));
        lineEdit_QuantityInStockInput->setGeometry(QRect(130, 230, 261, 22));
        lineEdit_QuantityInStockInput->setFont(font5);
        lineEdit_QuantityInStockInput->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        lineEdit_SellPriceInput = new QLineEdit(frame_4);
        lineEdit_SellPriceInput->setObjectName(QStringLiteral("lineEdit_SellPriceInput"));
        lineEdit_SellPriceInput->setGeometry(QRect(130, 170, 261, 22));
        lineEdit_SellPriceInput->setFont(font5);
        lineEdit_SellPriceInput->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        lineEdit_ProductNameInput = new QLineEdit(frame_4);
        lineEdit_ProductNameInput->setObjectName(QStringLiteral("lineEdit_ProductNameInput"));
        lineEdit_ProductNameInput->setGeometry(QRect(130, 110, 261, 22));
        lineEdit_ProductNameInput->setFont(font5);
        lineEdit_ProductNameInput->setStyleSheet(QLatin1String("padding: 1px;\n"
"background: rgb(85,170,255);\n"
"border-radius: 10px;"));
        pushButton_SaveAddProduct = new QPushButton(frame_4);
        pushButton_SaveAddProduct->setObjectName(QStringLiteral("pushButton_SaveAddProduct"));
        pushButton_SaveAddProduct->setGeometry(QRect(360, 270, 51, 23));
        pushButton_SaveAddProduct->setFont(font1);
        pushButton_SaveAddProduct->setStyleSheet(QLatin1String("#pushButton_SaveAddCustomer\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_SaveAddCustomer:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        pushButton_CancelAddProduct = new QPushButton(frame_4);
        pushButton_CancelAddProduct->setObjectName(QStringLiteral("pushButton_CancelAddProduct"));
        pushButton_CancelAddProduct->setGeometry(QRect(420, 270, 61, 23));
        pushButton_CancelAddProduct->setFont(font1);
        pushButton_CancelAddProduct->setStyleSheet(QLatin1String("#pushButton_CancelAddCustomer\n"
"{\n"
"background-color: transparent;\n"
"border-width: 2px;\n"
"border-color: rgb(85,170,255);\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_CancelAddCustomer:hover\n"
"{\n"
"background:rgb(85,170,255);\n"
"}"));
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 81, 16));
        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(130, 90, 91, 16));
        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(130, 150, 81, 16));
        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(130, 210, 101, 16));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(210, 20, 301, 61));
        label_5->setFont(font2);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(540, 20, 47, 20));
        label_6->setFont(font3);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(540, 50, 51, 21));
        label_7->setFont(font3);
        time4 = new QLabel(page_2);
        time4->setObjectName(QStringLiteral("time4"));
        time4->setGeometry(QRect(590, 8, 151, 46));
        time4->setFont(font3);
        date4 = new QLabel(page_2);
        date4->setObjectName(QStringLiteral("date4"));
        date4->setGeometry(QRect(590, 45, 112, 31));
        date4->setFont(font3);
        stackedWidget->addWidget(page_2);

        retranslateUi(products);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(products);
    } // setupUi

    void retranslateUi(QWidget *products)
    {
        products->setWindowTitle(QApplication::translate("products", "Form", Q_NULLPTR));
        labelLogo1->setText(QString());
        profile_1->setText(QString());
        signOut_1->setText(QString());
        pushButton_SortProduct->setText(QApplication::translate("products", "Sort Products", Q_NULLPTR));
        pushButton_AddNewProduct->setText(QApplication::translate("products", "Add New Product", Q_NULLPTR));
        LoadData->setText(QApplication::translate("products", "Load", Q_NULLPTR));
        pushButton_Search->setText(QApplication::translate("products", "Search", Q_NULLPTR));
        label_2->setText(QApplication::translate("products", "products list", Q_NULLPTR));
        label_3->setText(QApplication::translate("products", "Time:", Q_NULLPTR));
        label_4->setText(QApplication::translate("products", "Date:", Q_NULLPTR));
        time->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        date->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        labelLogo2->setText(QString());
        profile_2->setText(QString());
        signOut_2->setText(QString());
        label_11->setText(QApplication::translate("products", "View Product", Q_NULLPTR));
        label_12->setText(QApplication::translate("products", "Time:", Q_NULLPTR));
        label_13->setText(QApplication::translate("products", "Date:", Q_NULLPTR));
        pushButton_Return->setText(QApplication::translate("products", "return", Q_NULLPTR));
        time2->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        date2->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        pushButton_Print->setText(QApplication::translate("products", "print", Q_NULLPTR));
        label_14->setText(QApplication::translate("products", "To:", Q_NULLPTR));
        label_15->setText(QApplication::translate("products", "BCC:", Q_NULLPTR));
        label_16->setText(QApplication::translate("products", "CC:", Q_NULLPTR));
        label_17->setText(QApplication::translate("products", "Subject:", Q_NULLPTR));
        label_18->setText(QApplication::translate("products", "Priority", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("products", "Low", Q_NULLPTR)
         << QApplication::translate("products", "Normal", Q_NULLPTR)
         << QApplication::translate("products", "High", Q_NULLPTR)
        );
        pushButton_return2->setText(QApplication::translate("products", "Return", Q_NULLPTR));
        labelLogo3->setText(QString());
        profile_3->setText(QString());
        signOut_3->setText(QString());
        pushButton->setText(QApplication::translate("products", "Send", Q_NULLPTR));
        labelLogo4->setText(QString());
        profile_4->setText(QString());
        signOut_4->setText(QString());
        pushButton_SaveEditProduct->setText(QApplication::translate("products", "Save", Q_NULLPTR));
        pushButton_CancelEditProduct->setText(QApplication::translate("products", "Cancel", Q_NULLPTR));
        label_22->setText(QApplication::translate("products", "sell price", Q_NULLPTR));
        label_23->setText(QApplication::translate("products", "product code", Q_NULLPTR));
        label_24->setText(QApplication::translate("products", "product name", Q_NULLPTR));
        label_25->setText(QApplication::translate("products", "quantity in stock", Q_NULLPTR));
        label_8->setText(QApplication::translate("products", "Edit Product", Q_NULLPTR));
        label_9->setText(QApplication::translate("products", "Time:", Q_NULLPTR));
        label_10->setText(QApplication::translate("products", "Date:", Q_NULLPTR));
        time3->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        date3->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        labelLogo5->setText(QString());
        profile_5->setText(QString());
        signOut_5->setText(QString());
        pushButton_SaveAddProduct->setText(QApplication::translate("products", "Save", Q_NULLPTR));
        pushButton_CancelAddProduct->setText(QApplication::translate("products", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("products", "product code", Q_NULLPTR));
        label_19->setText(QApplication::translate("products", "product name", Q_NULLPTR));
        label_20->setText(QApplication::translate("products", "sell price", Q_NULLPTR));
        label_21->setText(QApplication::translate("products", "quantity in stock", Q_NULLPTR));
        label_5->setText(QApplication::translate("products", "Add Product", Q_NULLPTR));
        label_6->setText(QApplication::translate("products", "Time:", Q_NULLPTR));
        label_7->setText(QApplication::translate("products", "Date:", Q_NULLPTR));
        time4->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
        date4->setText(QApplication::translate("products", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class products: public Ui_products {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTS_H

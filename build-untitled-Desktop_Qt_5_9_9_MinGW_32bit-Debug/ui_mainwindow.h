/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame;
    QPushButton *signOut;
    QLabel *label;
    QFrame *frame_2;
    QPushButton *CustomerRelationshipManagementButton;
    QPushButton *ProductsButton;
    QPushButton *WarehouseButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(782, 496);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 761, 461));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        frame = new QFrame(page);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 0, 191, 461));
        frame->setStyleSheet(QStringLiteral("background:rgb(85,170,255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        signOut = new QPushButton(frame);
        signOut->setObjectName(QStringLiteral("signOut"));
        signOut->setGeometry(QRect(80, 300, 51, 51));
        signOut->setStyleSheet(QLatin1String("#signOut\n"
"{\n"
"   border-image:url(://img/signOut.png);\n"
"}\n"
"\n"
"#signOut:hover\n"
"{\n"
"  border-image:url(://img/signOutHover.png);\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 171, 161));
        label->setStyleSheet(QStringLiteral("border-image:url(://img/floralloLogo.png);"));
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(210, 50, 521, 331));
        frame_2->setStyleSheet(QLatin1String("#frame_2\n"
"{\n"
"	border:2px solid rgb(85, 170, 255);\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        CustomerRelationshipManagementButton = new QPushButton(frame_2);
        CustomerRelationshipManagementButton->setObjectName(QStringLiteral("CustomerRelationshipManagementButton"));
        CustomerRelationshipManagementButton->setGeometry(QRect(30, 30, 471, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(20);
        CustomerRelationshipManagementButton->setFont(font);
        CustomerRelationshipManagementButton->setStyleSheet(QLatin1String("#CustomerRelationshipManagementButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:solid rgb(85, 170, 255);\n"
"}\n"
""));
        ProductsButton = new QPushButton(frame_2);
        ProductsButton->setObjectName(QStringLiteral("ProductsButton"));
        ProductsButton->setGeometry(QRect(70, 210, 181, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font1.setPointSize(18);
        ProductsButton->setFont(font1);
        ProductsButton->setStyleSheet(QLatin1String("#ProductsButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:transparent;\n"
"	border:2px solid rgb(85, 170, 255);\n"
"}\n"
"\n"
"#ProductsButton:hover\n"
"{\n"
"	background:rgb(85, 170, 255);\n"
"}"));
        WarehouseButton = new QPushButton(frame_2);
        WarehouseButton->setObjectName(QStringLiteral("WarehouseButton"));
        WarehouseButton->setGeometry(QRect(270, 210, 181, 41));
        WarehouseButton->setFont(font1);
        WarehouseButton->setStyleSheet(QLatin1String("#WarehouseButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:transparent;\n"
"	border:2px solid rgb(85, 170, 255);\n"
"}\n"
"\n"
"#WarehouseButton:hover\n"
"{\n"
"	background:rgb(85, 170, 255);\n"
"}"));
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 782, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        signOut->setText(QString());
        label->setText(QString());
        CustomerRelationshipManagementButton->setText(QApplication::translate("MainWindow", "stock management", Q_NULLPTR));
        ProductsButton->setText(QApplication::translate("MainWindow", "Products", Q_NULLPTR));
        WarehouseButton->setText(QApplication::translate("MainWindow", "Warehouse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

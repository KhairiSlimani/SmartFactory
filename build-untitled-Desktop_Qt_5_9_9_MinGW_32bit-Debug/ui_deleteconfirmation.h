/********************************************************************************
** Form generated from reading UI file 'deleteconfirmation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECONFIRMATION_H
#define UI_DELETECONFIRMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteconfirmation
{
public:
    QLabel *label;
    QPushButton *pushButton_CancelDeleteCustomer;
    QPushButton *pushButton_ConfirmDeleteCustomer;

    void setupUi(QWidget *deleteconfirmation)
    {
        if (deleteconfirmation->objectName().isEmpty())
            deleteconfirmation->setObjectName(QStringLiteral("deleteconfirmation"));
        deleteconfirmation->resize(491, 127);
        deleteconfirmation->setStyleSheet(QStringLiteral("	background:rgb(85, 170, 255);"));
        label = new QLabel(deleteconfirmation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 461, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton_CancelDeleteCustomer = new QPushButton(deleteconfirmation);
        pushButton_CancelDeleteCustomer->setObjectName(QStringLiteral("pushButton_CancelDeleteCustomer"));
        pushButton_CancelDeleteCustomer->setGeometry(QRect(240, 70, 81, 31));
        pushButton_CancelDeleteCustomer->setStyleSheet(QLatin1String("#pushButton_CancelDeleteCustomer\n"
"{\n"
"background-color: White;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_CancelDeleteCustomer:hover\n"
"{\n"
"border-color:black;\n"
"}"));
        pushButton_ConfirmDeleteCustomer = new QPushButton(deleteconfirmation);
        pushButton_ConfirmDeleteCustomer->setObjectName(QStringLiteral("pushButton_ConfirmDeleteCustomer"));
        pushButton_ConfirmDeleteCustomer->setGeometry(QRect(130, 70, 81, 31));
        pushButton_ConfirmDeleteCustomer->setStyleSheet(QLatin1String("#pushButton_ConfirmDeleteCustomer\n"
"{\n"
"background-color: White;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"}\n"
"\n"
"#pushButton_ConfirmDeleteCustomer:hover\n"
"{\n"
"border-color:black;\n"
"}"));

        retranslateUi(deleteconfirmation);

        QMetaObject::connectSlotsByName(deleteconfirmation);
    } // setupUi

    void retranslateUi(QWidget *deleteconfirmation)
    {
        deleteconfirmation->setWindowTitle(QApplication::translate("deleteconfirmation", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("deleteconfirmation", "Are you sure you want to delete ?", Q_NULLPTR));
        pushButton_CancelDeleteCustomer->setText(QApplication::translate("deleteconfirmation", "Cancel", Q_NULLPTR));
        pushButton_ConfirmDeleteCustomer->setText(QApplication::translate("deleteconfirmation", "Confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class deleteconfirmation: public Ui_deleteconfirmation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECONFIRMATION_H

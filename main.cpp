#include "mainwindow.h"
#include"suppliers.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>
#include"material.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    material m;
     Suppliers S;
    Connection c;
     MainWindow w;
        bool test=c.createconnect();
        //w.test(test);

        if(test)
        {w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"));
        }
        else

                    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                QObject::tr("connection failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);



                return a.exec();

}

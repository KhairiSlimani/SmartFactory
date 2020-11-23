#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "products.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &produit);
    ui->stackedWidget->insertWidget(2, &depot);
    connect(&produit, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&depot, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

    animation=new QPropertyAnimation(ui->CustomerRelationshipManagementButton,"geometry");
    animation->setDuration(4000);
    animation->setLoopCount(4);
    animation->setStartValue(ui->CustomerRelationshipManagementButton->geometry());
    animation->setEndValue(QRect(30,100,471,51));
    animation->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ProductsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_WarehouseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_signOut_clicked()
{
    close();
}

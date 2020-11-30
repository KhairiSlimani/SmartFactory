#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "customers.h"
#include "projects.h"
#include <QPropertyAnimation>
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

private slots:
    void on_CustomersButton_clicked();

    void on_ProjectsButton_clicked();

    void moveHome();

    void on_signOut_clicked();

private:
    Ui::MainWindow *ui;
    Customers clientt;
    Projects projet;
    QPropertyAnimation *animation;

};
#endif // MAINWINDOW_H

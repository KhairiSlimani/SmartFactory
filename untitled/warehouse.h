#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QWidget>
#include <QTimer>
#include <QMenu>
#include <QDateTime>
#include <QMessageBox>
#include "deleteconfirmation.h"
#include <QPropertyAnimation>
#include "depot.h"

namespace Ui {
class warehouse;
}

class warehouse : public QWidget
{
    Q_OBJECT

public:
    explicit warehouse(QWidget *parent = nullptr);
    ~warehouse();

private slots:
    void on_pushButton_AddNewWarehouse_clicked();


private:
    Ui::warehouse *ui;
    QPropertyAnimation *animation;
    depot DEPOT;

signals:
    void HomeClicked();

private slots:
    void showTime();
    void showContextMenu(const QPoint &pos);
    void deleteWarehouse();
    void viewWarehouse();
    void editWarehouse();
    void on_pushButton_SaveAddWarehouse_clicked();
    void on_pushButton_CancelAddWarehouse_clicked();
    void on_pushButton_SaveEditWarehouse_clicked();
    void on_pushButton_CancelEditWarehouse_clicked();
    void on_pushButton_Return_clicked();

    void on_signOut_8_clicked();
    void on_signOut_5_clicked();
    void on_signOut_6_clicked();
    void on_signOut_7_clicked();

    void on_LoadData_clicked();

};

#endif // WAREHOUSE_H





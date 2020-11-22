#include "deleteconfirmation.h"
#include "ui_deleteconfirmation.h"

DeleteConfirmation::DeleteConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmation)
{
    ui->setupUi(this);
}

DeleteConfirmation::~DeleteConfirmation()
{
    delete ui;
}

void DeleteConfirmation::on_confrimButton_clicked()
{
    confirmDelete=1;
    close();
}

void DeleteConfirmation::on_cancelButton_clicked()
{
    confirmDelete=0;
    close();
}

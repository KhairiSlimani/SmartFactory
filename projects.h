#ifndef PROJECTS_H
#define PROJECTS_H

#include <QWidget>
#include <QTimer>
#include <QMenu>
#include <QDateTime>
#include <QMessageBox>
#include "deleteconfirmation.h"
#include <QPropertyAnimation>
#include "projet.h"
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>

namespace Ui {
class Projects;
}

class Projects : public QWidget
{
    Q_OBJECT

public:
    explicit Projects(QWidget *parent = nullptr);
    ~Projects();

private slots:
    void on_pushButton_AddNewProject_clicked();

private:
    Ui::Projects *ui;
    QPropertyAnimation *animation;
    Projet P;

signals:
    void HomeClicked();

private slots:
    void showTime();
    void showContextMenu(const QPoint &pos);
    void deleteProject();
    void viewProject();
    void editProject();
    void on_pushButton_SaveAddProject_clicked();
    void on_pushButton_CancelAddProject_clicked();
    void on_pushButton_SaveEditProject_clicked();
    void on_pushButton_CancelEditProject_clicked();
    void on_pushButton_Return_clicked();
    void on_signOut_8_clicked();
    void on_signOut_5_clicked();
    void on_signOut_6_clicked();
    void on_signOut_7_clicked();
    void on_pushButton_SortProject_clicked();
    void on_lineEdit_SearchProject_textChanged(const QString &arg1);
    void on_pushButton_Print_clicked();
};

#endif // PROJECTS_H

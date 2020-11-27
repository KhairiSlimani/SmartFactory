#ifndef DELETE_H
#define DELETE_H
#include <QSound>
#include <QDialog>

namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    int getConfirmDelete(){return confirmDelete;};
    void setConfirmDelete(int confirmDelete){this->confirmDelete=confirmDelete;};
    ~Delete();

private slots:
    void on_cancelButton_clicked();

    void on_confrimButton_clicked();

private:
    Ui::Delete *ui;
    int confirmDelete;
    QSound *trash;
};

#endif // DELETE_H

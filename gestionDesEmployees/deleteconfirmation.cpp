#include "deleteconfirmation.h"
#include "ui_deleteconfirmation.h"

DeleteConfirmation::DeleteConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmation)
{
    ui->setupUi(this);
    trashSound=new QMediaPlayer();
    trashSound->setMedia(QUrl("qrc:/sounds/sounds/trashSound.mp3"));

}

DeleteConfirmation::~DeleteConfirmation()
{
    delete ui;
}

void DeleteConfirmation::on_confrimButton_clicked()
{
    confirmDelete=1;
    if(trashSound->state()==QMediaPlayer::PlayingState)
    {
        trashSound->setPosition(0);
    }
    else if(trashSound->state()==QMediaPlayer::StoppedState)
    {
        trashSound->play();
    }
    close();
}

void DeleteConfirmation::on_cancelButton_clicked()
{
    confirmDelete=0;
    close();
}

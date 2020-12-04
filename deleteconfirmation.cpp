#include "deleteconfirmation.h"
#include "ui_deleteconfirmation.h"

deleteconfirmation::deleteconfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteconfirmation)
{
    ui->setupUi(this);
    trashSound=new QMediaPlayer();
    trashSound->setMedia(QUrl("qrc:/sounds/sounds/trashSound.mp3"));

}

deleteconfirmation::~deleteconfirmation()
{
    delete ui;
}



void deleteconfirmation::on_confirmDelete_clicked()
{
    if(trashSound->state()==QMediaPlayer::PlayingState)
    {
        trashSound->setPosition(0);
    }
    else if(trashSound->state()==QMediaPlayer::StoppedState)
    {
        trashSound->play();
    }
    confirmDelete =1;
    close();
}

void deleteconfirmation::on_CancelDelete_clicked()
{
    if(trashSound->state()==QMediaPlayer::PlayingState)
    {
        trashSound->setPosition(0);
    }
    else if(trashSound->state()==QMediaPlayer::StoppedState)
    {
        trashSound->play();
    }
    confirmDelete=0;
    close();
}

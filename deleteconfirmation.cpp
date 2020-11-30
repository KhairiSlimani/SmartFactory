#include "deleteconfirmation.h"
#include "ui_deleteconfirmation.h"
#include <QtMultimedia/QMediaPlayer>

deleteconfirmation::deleteconfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteconfirmation)
{
    ui->setupUi(this);
    trashSound=new QMediaPlayer();
    trashSound->setMedia(QUrl("qrc:/sound/sounds/household_trash_bag_full_throw_into_plastic_bin (1) (online-audio-converter.com) (1).mp3"));
}

deleteconfirmation::~deleteconfirmation()
{
    delete ui;
}

void deleteconfirmation::on_pushButton_ConfirmDeleteCustomer_clicked()
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

void deleteconfirmation::on_pushButton_CancelDeleteCustomer_clicked()
{
    confirmDelete=0;
    close();
}

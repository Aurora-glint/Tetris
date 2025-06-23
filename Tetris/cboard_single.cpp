#include "cboard_single.h"
#include "ui_cboard_single.h"

Cboard_single::Cboard_single(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_single)
{
    ui->setupUi(this);

   // connect(ui->back_menu_button,SIGNAL(back()),this,SLOT(back_menu()));

}

Cboard_single::~Cboard_single()
{
    delete ui;
}


void Cboard_single::on_quit_game_clicked()
{
    emit quit();
    qDebug()<<"quit signal launched "<<Qt::endl;
}


void Cboard_single::on_back_menu_button_clicked()
{
    emit back();
    this->hide();
    qDebug()<<"back signal launched "<<Qt::endl;
}



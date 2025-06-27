#include "cboard_pair.h"
#include "ui_cboard_pair.h"
#include "CTetrimino.h"

Cboard_pair::Cboard_pair(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_pair)
{
    ui->setupUi(this);
}

Cboard_pair::~Cboard_pair()
{
    delete ui;
}



void Cboard_pair::on_back_menu_button_p_clicked()
{
    emit back();
    this->hide();
    // 调用暂停
    //on_pause_button_clicked(0);
    qDebug() << "back signal launched " << Qt::endl;
}


void Cboard_pair::on_quit_game_p_clicked()
{
    emit quit();
    qDebug() << "quit signal launched " << Qt::endl;
}


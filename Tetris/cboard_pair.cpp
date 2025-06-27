#include "cboard_pair.h"
#include "ui_cboard_pair.h"
#include "CTetrimino.h"
#include <QKeyEvent>


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


void Cboard_pair::do_timechange()
{
    qDebug()<<"do_timechange"<<Qt::endl;
    time+=1;
    ui->lcd_time->display(time);//更新时间显示
}

void Cboard_pair::p_setDifficulty(Difficulty diff)
{
    p_curDifficulty = diff;
    QString Difname;

    switch(p_curDifficulty)
    {
    case 0:
        Difname = "Normal";
        break;
    case 1:
        Difname = "Hard";
        break;
    case 2:
        Difname = "Crazy";
        break;
    }

    ui->difficulty_label->setText(Difname);//设置pair文本难度显示
}


Difficulty Cboard_pair::p_getDifficulty()
{
    return p_curDifficulty;
}


void Cboard_pair::changeDifficulty()
{
    p_curDifficulty = Difficulty(((int)p_curDifficulty + 1) % 3);
    QString Difname;

    switch(p_curDifficulty)
    {
    case 0:
        Difname="Normal";
        break;
    case 1:
        Difname="Hard";
        break;
    case 2:
        Difname="Crazy";
        break;
    }

    ui->difficulty_label->setText(Difname);//设置single难度文本显示
}



void Cboard_pair::on_difchange_button_p_clicked(bool checked)
{
    changeDifficulty();
}



// 监听按键事件
void Cboard_pair::keyPressEvent(QKeyEvent *k)
{
    if (Ispaused == true)
    {
        if (k->key() == Qt::Key_Escape)
        {
            Ispaused = false; // 关闭暂停
            k->accept();
        }
        else
        {
            k->ignore(); // 忽视该按键事件
        }
    }
    else
    {
        if(k->key() == Qt::Key_W) qDebug()<<"W"<<Qt::endl;
        if(k->key() == Qt::Key_A) qDebug()<<"A"<<Qt::endl;
        if(k->key() == Qt::Key_S) qDebug()<<"S"<<Qt::endl;
        if(k->key() == Qt::Key_D) qDebug()<<"D"<<Qt::endl;
    }
}

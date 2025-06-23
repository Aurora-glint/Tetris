#include "cboard_single.h"
#include "ui_cboard_single.h"
#include <QKeyEvent>


Cboard_single::Cboard_single(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_single)
{
    ui->setupUi(this);
    Ispaused = true;
   connect(ui->back_menu_button,SIGNAL(back()),this,SLOT(back_menu()));

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



void Cboard_single::on_start_button_clicked()
{
    //emit start_single();弃用
    Ispaused=false;
    qDebug()<<"game started "<<Qt::endl;

}


void Cboard_single::on_pause_button_clicked()
{
    // emit pause_single(); 弃用
    Ispaused=true;
    qDebug()<<"game paused "<<Qt::endl;

}

//监听按键事件
void Cboard_single::keyPressEvent(QKeyEvent *k)
{
    if(Ispaused==true)
    {
        if(k->key()==Qt::Key_Escape)
        {
            Ispaused=false;//关闭暂停
            qDebug()<<"game started "<<Qt::endl;

            k->accept();
        }
        else
        {
            k->ignore();//忽视该按键事件
        }
    }
    else
    {
        if(k->key() == Qt::Key_W)
        {
            qDebug()<<" u pressed key W "<<Qt::endl;
        }

        if(k->key() == Qt::Key_A)
        {
            qDebug()<<" u pressed key A "<<Qt::endl;
        }
        if(k->key() == Qt::Key_S)
        {
            qDebug()<<" u pressed key S "<<Qt::endl;
        }
        if(k->key() == Qt::Key_D)
        {
            qDebug()<<" u pressed key D "<<Qt::endl;
        }
    }

}

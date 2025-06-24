#include "cboard_single.h"
#include "ui_cboard_single.h"
#include <QKeyEvent>
#include <QFrame>

#define TIMEOUT

Cboard_single::Cboard_single(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_single)
{
    ui->setupUi(this);
    Ispaused = true;
   connect(ui->back_menu_button, SIGNAL(back()), this, SLOT(back_menu()));
    //timer = new QTimer ();//实例化timer计时器对象;
    update_timer = new QTimer ();//实例化每秒计时器;
    connect(update_timer, SIGNAL(timeout()), this, SLOT(updateRunningTime()));
    m_timer.start();

}

Cboard_single::~Cboard_single()
{
    delete ui;
}


void Cboard_single::on_quit_game_clicked()
{
    emit quit();
    qDebug() << "quit signal launched " << Qt::endl;
}


void Cboard_single::on_back_menu_button_clicked()
{
    emit back();
    this->hide();
    qDebug() << "back signal launched " << Qt::endl;
}



void Cboard_single::on_start_button_clicked()
{
    //emit start_single();弃用
    Ispaused = false;
    qDebug() << "game started " << Qt::endl;
    //timer->start(TIMEOUT);//启动计时器

    update_timer->start(TIMEOUT);//启动每秒计时器
}


void Cboard_single::on_pause_button_clicked()
{
    // emit pause_single(); 弃用
    Ispaused = true;
    qDebug() << "game paused " << Qt::endl;
    //timer->stop();
}

//监听按键事件
void Cboard_single::keyPressEvent(QKeyEvent *k)
{
    if (Ispaused == true)
    {
        if (k->key() == Qt::Key_Escape)
        {
            Ispaused = false;//关闭暂停
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
            qDebug() << " u pressed key W " << Qt::endl;
        }
        if(k->key() == Qt::Key_A)
        {
            qDebug() << " u pressed key A " << Qt::endl;
        }
        if(k->key() == Qt::Key_S)
        {
            qDebug() << " u pressed key S " << Qt::endl;
        }
        if(k->key() == Qt::Key_D)
        {
            qDebug() << " u pressed key D " << Qt::endl;
        }
    }
}

void Cboard_single::updateRunningTime()
{
    quint64 elapsed = m_timer.elapsed();

    // 转换为时分秒格式（支持长时间运行，如多天）
    QString timeFormat;
    if (elapsed >= 86400000) {  // 1天 = 86400000毫秒
        int days = elapsed / 86400000;
        int hours = (elapsed % 86400000) / 3600000;
        int minutes = (elapsed % 3600000) / 60000;
        int seconds = (elapsed % 60000) / 1000;
        timeFormat = QString("%1天 %2:%3:%4")
                         .arg(days)
                         .arg(hours, 2, 10, QChar('0'))
                         .arg(minutes, 2, 10, QChar('0'))
                         .arg(seconds, 2, 10, QChar('0'));
    } else {
        int hours = elapsed / 3600000;
        int minutes = (elapsed % 3600000) / 60000;
        int seconds = (elapsed % 60000) / 1000;
        timeFormat = QString("%1:%2:%3")
                         .arg(hours, 2, 10, QChar('0'))
                         .arg(minutes, 2, 10, QChar('0'))
                         .arg(seconds, 2, 10, QChar('0'));
    }
    qDebug() << "time updated" << Qt::endl;
    ui->runtimelabel->setText(timeFormat);
}


// 以下为郝润熙所写
void Cboard_single::start_game()
{
    init_board(); // 清空游戏面板
    // 开启计时器（待写）
    cur_block = get_new_block(); // 获取初始方块
    next_block = get_new_block(); // 获取下一个方块

    init_pos(); // 设置下落位置
}

void Cboard_single::init_board()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) all_board[i][j] = None_shape;
    }
}

void Cboard_single::init_pos()
{
    pos.setX(COL / 2 - 1);
    pos.setY(ROW);
}

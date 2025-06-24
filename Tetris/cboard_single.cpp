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
    connect(ui->back_menu_button,SIGNAL(back()),this,SLOT(back_menu()));//关联返回信号
    connect(this,SIGNAL(timechange(int)),this,SLOT(do_timechange()));//关联timechnagne信号和dotimechange槽函数

    //timer = new QTimer ();//实例化timer计时器对象;
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
    init_board(); // 清空游戏面板
    Ispaused = false;
    // 开启计时器（待写）
    cur_block = get_new_block(); // 获取初始方块
    next_block = get_new_block(); // 获取下一个方块

    init_pos(); // 设置下落位置
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
        if(k->key() == Qt::Key_W) rotate();
        if(k->key() == Qt::Key_A) go_left();
        if(k->key() == Qt::Key_S) go_down();
        if(k->key() == Qt::Key_D) go_right();
    }
}

//计时器达到周期后处理事件
void Cboard_single::timerEvent(QTimerEvent *event)
{
    if(!Ispaused)
    {
       //下移一行

        if((event->timerId() == id && !Ispaused))//1秒事件
        {
            time += 1;//每秒存活时间加一
            qDebug()<<"计时 1 "<<time<<Qt::endl;//【测试】成功
        }

        if(event->timerId() == id_1 && !Ispaused)//3秒事件
        {
            //con -> setText("");
        }
        emit timechange(time);
        qDebug()<<"发出 timechange "<<time<<Qt::endl;
    }
}

void Cboard_single::do_timechange()
{
    qDebug()<<"收到 "<<time<<Qt::endl;
    ui->lcd_time->display(time);

}


// 以下为郝润熙所写
void Cboard_single::go_down()
{
    if (try_move(0)) pos.setX(pos.x() + 1);
}

void Cboard_single::go_left()
{
    if (try_move(-1)) pos.setY(pos.y() - 1);
}

void Cboard_single::go_right()
{
    if (try_move(1)) pos.setY(pos.y() + 1);
}

void Cboard_single::rotate()
{
    CTetrimino rotated = cur_block.get_rotatedLeft(); // 得到旋转后的图形
}

// 判断移动位置是否会发生碰撞
bool Cboard_single::try_move(int direction)
{
    if (direction)
    {
        for (int i = 0; i < 4; ++i)
        {
            int new_y = pos.y() + cur_block.Y(i) + direction;
            if (all_board[pos.x() + cur_block.X(i)][new_y] != None_shape) return false; // 若待移到的位置已有方块，返回false
        }
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int new_x = pos.x() + cur_block.X(i) + 1;
            if (all_board[new_x][pos.x() + cur_block.Y(i)] != None_shape) return false; // 若待移到的位置已有方块，返回false
        }
    }
    return true; // 循环结束还为返回，说明待移处没有方块，返回true
}

// 初始化（清除）面板
void Cboard_single::init_board()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) all_board[i][j] = None_shape;
    }
}

// 初始化方块坐标
void Cboard_single::init_pos()
{
    pos.setX(0);
    pos.setY(COL / 2 - 1);
}

CTetrimino Cboard_single::get_new_block()
{
    return CTetrimino(1); // 构造随机形状的方块并返回
}

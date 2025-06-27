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

    initBoard(); // 初始化游戏面板
    next_block = CTetrimino();
    curDifficulty = crasy; // 初始化游戏难度

    Ispaused = true;
    connect(ui->back_menu_button, SIGNAL(back()), this, SLOT(back_menu())); // 关联返回信号
    connect(this, SIGNAL(timechange(int)), this, SLOT(do_timechange())); // 关联timechnagne信号和dotimechange槽函数
    connect(this, SIGNAL(tick()), this, SLOT(do_tickchange())); // 关联返回信号
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
    // 调用暂停
    on_pause_button_clicked(0);
    qDebug() << "back signal launched " << Qt::endl;
}


// 监听按键事件
void Cboard_single::keyPressEvent(QKeyEvent *k)
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
        if(k->key() == Qt::Key_W) rotate();
        if(k->key() == Qt::Key_A) goLeft();
        if(k->key() == Qt::Key_S) goDown();
        if(k->key() == Qt::Key_D) goRight();
    }
}

// 计时器达到周期后处理事件
void Cboard_single::timerEvent(QTimerEvent *event)
{
    if(!Ispaused)
    {
        if((event->timerId() == id && !Ispaused)) time += 1; // 每秒存活时间加一

        if (curDifficulty == normal)
        {
            if((event->timerId() == id && !Ispaused)) goDown();
        }
        else if (curDifficulty == hard)
        {
            if((event->timerId() == id_hard && !Ispaused)) goDown();
        }
        else if (curDifficulty == crasy)
        {
            if((event->timerId() == id_crasy && !Ispaused)) goDown();
        }

        if((event->timerId() == id_t && !Ispaused)) // 30毫秒事件
        {
            emit tick();
        }
        emit timechange(time);
    }
}

void Cboard_single::do_timechange()
{
    ui->lcd_time->display(time);
}

void Cboard_single::do_tickchange()
{
    this->update(); // 每tick更新绘图
    ui->lcd_score->display(score); // 每tick更新分数
}; // 响应每tick变化

// 以下为郝润熙所写
void Cboard_single::startGame()
{
    initBoard(); // 清空游戏面板
    cur_block = getNewBlock(); // 获取初始方块
    next_block = getNewBlock(); // 获取下一个方块
    score = 0; // 清空分数
    time=0;//清空时间

    initPos(); // 设置下落位置
    for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = cur_block.getType(); // 将方块存入游戏面板中
}

void Cboard_single::goDown()
{
    if (tryMove(0))
    {
        pos[0]++;
        for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = cur_block.getType();
    }
    else saveBegin();
}

void Cboard_single::goLeft()
{
    if (tryMove(-1)) pos[1]--;
    for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = cur_block.getType();
}

void Cboard_single::goRight()
{
    if (tryMove(1)) pos[1]++;
    for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = cur_block.getType();
}

void Cboard_single::rotate()
{
    CTetrimino rotated = cur_block.getRotatedLeft(); // 得到旋转后的图形
    int p = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (pos[1] + rotated.Y(i) + p >= COL) --p;
        if (pos[1] + rotated.Y(i) + p < 0) ++p;
    }

    for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = None_shape;

    for (int i = 0; i < 4; ++i)
    {
        if (all_board[pos[0] + rotated.X(i)][pos[1] + rotated.Y(i) + p] != None_shape)
        {
            for (int j = 0; j < 4; ++j) all_board[pos[0] + cur_block.X(j)][pos[1] + cur_block.Y(j)] = cur_block.getType();
            return; // 若有重合，不旋转
        }
    }

    pos[1] += p;
    cur_block = rotated;
    for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = cur_block.getType();
}

void Cboard_single::changeDifficulty()
{
    curDifficulty = Difficulty(((int)curDifficulty + 1) % 3);
    QString Difname;

    switch(curDifficulty)
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

// 判断移动位置是否会发生碰撞或越界
bool Cboard_single::tryMove(int direction)
{
    for (int i = 0; i < 4; ++i) all_board[pos[0] + cur_block.X(i)][pos[1] + cur_block.Y(i)] = None_shape;

    if (direction != 0)
    {
        for (int i = 0; i < 4; ++i)
        {
            int new_y = pos[1] + cur_block.Y(i) + direction;
            int new_x = pos[0] + cur_block.X(i);
            if (new_y < 0 || new_y >= COL) return false; // 出界，返回false
            if (all_board[new_x][new_y] != None_shape) return false; // 若待移到的位置已有方块，返回false
        }
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int new_x = pos[0] + cur_block.X(i) + 1;
            int new_y = pos[1] + cur_block.Y(i);
            if (new_x < 0 || new_x >= ROW) return false; // 出界，返回false
            if (all_board[new_x][new_y] != None_shape) return false; // 若待移到的位置已有方块，返回false
        }
    }
    return true; // 循环结束还未返回，说明待移处没有方块，返回true
}

// 初始化（清除）面板
void Cboard_single::initBoard()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) all_board[i][j] = None_shape;
    }
}

// 初始化方块坐标
void Cboard_single::initPos()
{
    pos[0] = 0;
    pos[1] = COL / 2 - 1;
}

CTetrimino Cboard_single::getNewBlock()
{
    return CTetrimino(1); // 构造随机形状的方块并返回
}


bool Cboard_single::isDelete(int line)
{
    for (int i = 0; i < COL; ++i)
    {
        if (all_board[line][i] == None_shape) return false; // 未填满，不进行消行
    }

    return true; // 全部填满，进行消行
}

void Cboard_single::saveBegin()
{
    // 保存下落到底的方块
    int up = 0, down = ROW;
    for (int i = 0; i < 4; ++i)
    {
        int line = pos[0] + cur_block.X(i);
        all_board[line][pos[1] + cur_block.Y(i)] = cur_block.getType();

        if (line > up) up = line;
        if (line < down) down = line;
    }
    score += 10; // 每成功下落一个方块，得分加10

    // 判断是否需要消行
    int delete_num = 0;
    for (int line = up; line >= down; --line)
    {
        if (isDelete(line))
        {
            for (int i = line; i > 0; --i)
            {
                for (int j = 0; j < COL; ++j) all_board[i][j] = all_board[i - 1][j];
            }
            for (int j = 0; j < COL; ++j) all_board[0][j] = None_shape;

            line++;
            down++;
            delete_num++;
        }
    }

    // 获得分数
    score += 100 * delete_num;
    if (delete_num == 2) score += 50;
    else if (delete_num == 3) score += 125;
    else if (delete_num == 4) score += 200;

    // 判断游戏是否结束
    if (down < 4)
    {
        endGame();
        return;
    }

    // 开始新一轮方块降落
    initPos();
    cur_block = next_block;
    next_block = getNewBlock();
}

void Cboard_single::endGame()
{
    Ispaused = true;
}

void Cboard_single::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // 作绘图区域
    QPen pen(Qt::black); // pen绘制边框
    painter.setPen(pen);
    QRectF frame(o_ , s_);
    painter.drawRect(frame);
    QRect one_block;

    for (int r = 0; r < ROW; ++r)
    {
        int x = o_.y() + BLOCKSIZE * r;
        int y;
        for (int c = 0; c < COL; ++c)
        {
            y = o_.x() + BLOCKSIZE * c;

            one_block.setRect(y,x,BLOCKSIZE,BLOCKSIZE);

            if (all_board[r][c] != None_shape) paint_one_block(painter, one_block, all_board[r][c]);
        }
    }

    // 刷新下一个方块预览图
    for (int i = 0; i < 4; ++i)
    {
        one_block.setRect(10 + 20 * next_block.Y(i), 30 + 20 * next_block.X(i), 20, 20);
        paint_one_block(painter, one_block, next_block.getType());
    }
}

void Cboard_single::paint_one_block(QPainter &painter,const QRect &one_block,const All_Shape shape)
{
    painter.fillRect(one_block,Qt::gray);

    switch((int)shape)
    {
    case 0:
        painter.fillRect(one_block,Qt::black);
        break;
    case 1:
        painter.fillRect(one_block,Qt::gray);
        break;
    case 2:
        painter.fillRect(one_block,Qt::yellow);
        break;
    case 3:
        painter.fillRect(one_block,Qt::green);
        break;
    case 4:
        painter.fillRect(one_block,Qt::cyan);
        break;
    case 5:
        painter.fillRect(one_block,Qt::blue);
        break;
    case 6:
        painter.fillRect(one_block,Qt::magenta);
        break;
    case 7:
        painter.fillRect(one_block,Qt::red);
        break;
    }

    if (shape != None_shape) painter.drawRect(one_block); // 绘制该方块
}

void Cboard_single::on_start_button_clicked(bool checked)
{
    Ispaused = false;
    ui->pause_button->setChecked(true);
    ui->pause_button->setText("暂停 ");
    if(!checked)
    {
        ui->start_button->setText("开始");
        time = 0;
    }
    else if(checked)
    {
        ui->start_button->setText("重新开始");
    }

    qDebug() << "game started " << Qt::endl;
    startGame();
}

void Cboard_single::on_pause_button_clicked(bool checked)
{
    if(!checked)
    {
        Ispaused = true;
        ui->pause_button->setText("继续");
    }
    else if(checked)
    {
        Ispaused = false;
        qDebug() << "game continue " << Qt::endl;
        ui->pause_button->setText("暂停 ");
    }
}

void Cboard_single::setDifficulty(Difficulty diff)
{
    curDifficulty = diff;
    QString Difname;

    switch(curDifficulty)
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

    ui->difficulty_label->setText(Difname);//设置single文本难度显示
}

Difficulty Cboard_single::s_getDifficulty()
{
    return curDifficulty;
}

void Cboard_single::on_difchange_button_clicked(bool checked)
{
    changeDifficulty();
}

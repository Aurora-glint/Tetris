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

void Cboard_pair::startGame()
{
    score[0] = score[1] = 0;
    init_board();

    cur_block[0] = cur_block[1] = getNewBlock();
    pushShape();
}

void Cboard_pair::goDown(int p)
{
    if (tryMove(0, p))
    {
        pos[p][0]++;
        for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
    }
    else saveBegin(p);
}

void Cboard_pair::goLeft(int p)
{
    if (tryMove(-1, p)) pos[p][1]--;
    for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
}

void Cboard_pair::goRight(int p)
{
    if (tryMove(1, p)) pos[p][1]++;
    for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
}

void Cboard_pair::rotate(int p)
{
    CTetrimino rotated = cur_block[p].getRotatedLeft(); // 得到旋转后的图形
    int py = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (pos[p][1] + rotated.Y(i) + py >= COL) --py;
        if (pos[p][1] + rotated.Y(i) + py < 0) ++py;
    }

    for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = None_shape;

    for (int i = 0; i < 4; ++i)
    {
        if (board[p][pos[p][0] + rotated.X(i)][pos[p][1] + rotated.Y(i) + py] != None_shape)
        {
            for (int j = 0; j < 4; ++j) board[p][pos[p][0] + cur_block[p].X(j)][pos[p][1] + cur_block[p].Y(j)] = cur_block[p].getType();
            return; // 若有重合，不旋转
        }
    }

    pos[p][1] += py;
    cur_block[p] = rotated;
    for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
}

void Cboard_pair::init_board()
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j) board[0][i][j] = board[1][i][j] = None_shape;
    }
}

void Cboard_pair::initPos(int p)
{
    pos[p][0] = 0;
    pos[p][1] = COL / 2 - 1;
}

// 判断移动位置是否会发生碰撞或越界
bool Cboard_pair::tryMove(int direction, int p)
{
    for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = None_shape;

    if (direction != 0)
    {
        for (int i = 0; i < 4; ++i)
        {
            int new_y = pos[p][1] + cur_block[p].Y(i) + direction;
            int new_x = pos[p][0] + cur_block[p].X(i);
            if (new_y < 0 || new_y >= COL) return false; // 出界，返回false
            if (board[p][new_x][new_y] != None_shape) return false; // 若待移到的位置已有方块，返回false
        }
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int new_x = pos[p][0] + cur_block[p].X(i) + 1;
            int new_y = pos[p][1] + cur_block[p].Y(i);
            if (new_x < 0 || new_x >= ROW) return false; // 出界，返回false
            if (board[p][new_x][new_y] != None_shape) return false; // 若待移到的位置已有方块，返回false
        }
    }
    return true; // 循环结束还未返回，说明待移处没有方块，返回true
}

bool Cboard_pair::isDelete(int line, int p)
{
    for (int i = 0; i < COL; ++i)
    {
        if (board[p][line][i] == None_shape) return false; // 未填满，不进行消行
    }

    return true; // 全部填满，进行消行
}

void Cboard_pair::saveBegin(int p)
{
    // 保存下落到底的方块
    int up = 0, down = ROW;
    for (int i = 0; i < 4; ++i)
    {
        int line = pos[p][0] + cur_block[p].X(i);
        board[p][line][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();

        if (line > up) up = line;
        if (line < down) down = line;
    }
    score[p] += 10; // 每成功下落一个方块，得分加10

    // 判断是否需要消行
    int delete_num = 0;
    for (int line = up; line >= down; --line)
    {
        if (isDelete(line, p))
        {
            for (int i = line; i > 0; --i)
            {
                for (int j = 0; j < COL; ++j) board[p][i][j] = board[p][i - 1][j];
            }
            for (int j = 0; j < COL; ++j) board[p][0][j] = None_shape;

            line++;
            down++;
            delete_num++;
        }
    }

    // 获得分数
    score[p] += 100 * delete_num;
    if (delete_num == 2) score[p] += 50;
    else if (delete_num == 3) score[p] += 125;
    else if (delete_num == 4) score[p] += 200;

    // 判断游戏是否结束
    if (down < 4)
    {
        endGame();
        return;
    }

    // 开始新一轮方块降落
    initPos(p);
    cur_block[p] = shape[p].front();
    shape[p].pop();
    if (shape[p].empty()) pushShape();
}

void Cboard_pair::endGame()
{
    return;
}

void Cboard_pair::pushShape()
{
    CTetrimino newBlock(0);
    shape[0].push(newBlock);
    shape[1].push(newBlock);
}

CTetrimino Cboard_pair::getNewBlock()
{
    return CTetrimino(0); // 构造随机形状的方块并返回
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

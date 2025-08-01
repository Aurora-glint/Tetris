#include "Cboard_pair.h"
#include "ui_Cboard_pair.h"
#include "CTetrimino.h"
#include <QKeyEvent>

Cboard_pair::Cboard_pair(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_pair)
{
    ui->setupUi(this);

    initBoard(); // 初始化游戏面板
    score[0] = score[1] = 0;
    time = 0;
    Ispaused = true;

    audiooutput->setVolume(0.8f);

    player_0->setSource(QUrl("qrc:/Sound/bell.wav"));//下落音效

    player_1->setSource(QUrl("qrc:/Sound/orb.wav"));//消一行音效

    player_2->setSource(QUrl("qrc:/Sound/levelup.wav"));//消两行

    player_3->setSource(QUrl("qrc:/Sound/return3.wav"));//三行

    player_4->setSource(QUrl("qrc:/Sound/magic-wand.wav"));//四行

    player_end->setSource(QUrl("qrc:/Sound/explode1.wav"));//结束音效
}

Cboard_pair::~Cboard_pair()
{
    delete ui;
}

void Cboard_pair::on_back_menu_button_p_clicked()
{
    emit back();
    this->hide();
}

void Cboard_pair::on_quit_game_p_clicked()
{
    emit quit();
}

void Cboard_pair::paintEvent(QPaintEvent *event)
{
    // 绘制背景图片
    QPainter painter_b(this);
    QPixmap background(":/image/dessert.png");
    painter_b.setOpacity(0.5); // 设置透明度为50%（0.0完全透明，1.0完全不透明）
    painter_b.drawPixmap(rect(), background);

    QPainter painter(this); // 作绘图区域

    QPen penl(Qt::red); // penl绘制上界
    penl.setStyle(Qt::DashLine);
    painter.setPen(penl);
    painter.drawLine(p1_o_ + QPoint(0, 2 * BLOCKSIZE), p1_o_ + QPoint(COL * BLOCKSIZE, 2 * BLOCKSIZE));
    painter.drawLine(p2_o_ + QPoint(0, 2 * BLOCKSIZE), p2_o_ + QPoint(COL * BLOCKSIZE, 2 * BLOCKSIZE));

    QPen pen(Qt::black); // pen绘制边框
    painter.setPen(pen);
    QRectF frame1(p1_o_ , p1_s_);
    QRectF frame2(p2_o_ , p2_s_);
    painter.drawRect(frame1);
    painter.drawRect(frame2);
    QRect one_block;

    for (int r = 0; r < ROW; ++r)
    {
        int x = p1_o_.y() + BLOCKSIZE * r;

        for (int c = 0; c < COL; ++c)
        {
            int p1_y = p1_o_.x() + BLOCKSIZE * c;
            int p2_y = p2_o_.x() + BLOCKSIZE * c;

            one_block.setRect(p1_y, x, BLOCKSIZE, BLOCKSIZE);
            if (board[0][r][c] != None_shape) paint_one_block(painter, one_block, board[0][r][c]);

            one_block.setRect(p2_y, x, BLOCKSIZE, BLOCKSIZE);
            if (board[1][r][c] != None_shape) paint_one_block(painter, one_block, board[1][r][c]);
        }
    }

    // 刷新下一个方块预览图
    for (int i = 0; i < 4; ++i)
    {
        one_block.setRect(10 + 20 * shape[0].front().Y(i), 30 + 20 * shape[0].front().X(i), 20, 20);
        paint_one_block(painter, one_block, shape[0].front().getType());

        one_block.setRect(1400 + 20 * shape[1].front().Y(i), 30 + 20 * shape[1].front().X(i), 20, 20);
        paint_one_block(painter, one_block, shape[1].front().getType());
    }
}

void Cboard_pair::paint_one_block(QPainter &painter, const QRect &one_block, const All_Shape shape)
{
    painter.fillRect(one_block, Qt::gray);

    switch((int)shape)
    {
    case 0:
        painter.fillRect(one_block, Qt::black);
        break;
    case 1:
        painter.fillRect(one_block, Qt::gray);
        break;
    case 2:
        painter.fillRect(one_block, Qt::yellow);
        break;
    case 3:
        painter.fillRect(one_block, Qt::green);
        break;
    case 4:
        painter.fillRect(one_block, Qt::cyan);
        break;
    case 5:
        painter.fillRect(one_block, Qt::blue);
        break;
    case 6:
        painter.fillRect(one_block, Qt::magenta);
        break;
    case 7:
        painter.fillRect(one_block, Qt::red);
        break;
    }

    if (shape != None_shape) painter.drawRect(one_block); // 绘制该方块
}

void Cboard_pair::playMedia(int delete_num)
{
    audiooutput->setVolume(0.9);
    player_0->setAudioOutput(audiooutput);
    player_0->play();

    switch(delete_num)
    {
    case 1:
        player_1->setAudioOutput(audiooutput);
        player_1->play();
        break;
    case 2:
        player_2->setAudioOutput(audiooutput);
        player_2->play();
        break;
    case 3:
        player_3->setAudioOutput(audiooutput);
        player_3->play();
        break;
    case 4:
        player_4->setAudioOutput(audiooutput);
        player_4->play();
        break;
    }
}

void Cboard_pair::startGame()
{
    score[0] = score[1] = 0;
    initBoard();
    Isend[0] = Isend[1] = false;

    cur_block[0] = cur_block[1] = getNewBlock();
    pushShape();
    initPos(0);
    initPos(1);
}

void Cboard_pair::goDown(int p)
{
    if (!Isend[p])
    {
        if (tryMove(0, p))
        {
            pos[p][0]++;
            for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
        }
        else saveBegin(p);
    }
}

void Cboard_pair::goLeft(int p)
{
    if (!Isend[p])
    {
        if (tryMove(-1, p)) pos[p][1]--;
        for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
    }
}

void Cboard_pair::goRight(int p)
{
    if (!Isend[p])
    {
        if (tryMove(1, p)) pos[p][1]++;
        for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
    }
}

void Cboard_pair::rotate(int p)
{
    if (Isend[p]) return;
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
        if (board[p][pos[p][0] + rotated.X(i)][pos[p][1] + rotated.Y(i) + py] != None_shape || pos[p][0] + rotated.X(i) >= ROW)
        {
            for (int j = 0; j < 4; ++j) board[p][pos[p][0] + cur_block[p].X(j)][pos[p][1] + cur_block[p].Y(j)] = cur_block[p].getType();
            return; // 若有重合，不旋转
        }
    }

    pos[p][1] += py;
    cur_block[p] = rotated;
    for (int i = 0; i < 4; ++i) board[p][pos[p][0] + cur_block[p].X(i)][pos[p][1] + cur_block[p].Y(i)] = cur_block[p].getType();
}

void Cboard_pair::initBoard()
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

    playMedia(delete_num);

    // 获得分数
    score[p] += 100 * delete_num;
    switch(delete_num)
    {
    case 2:
        score[p] += 50;
        break;
    case 3:
        score[p] += 125;
        break;
    case 4:
        score[p] += 250;
        break;
    }

    // 判断游戏是否结束
    if (down < 4)
    {
        endGame(p);
        return;
    }

    // 开始新一轮方块降落
    initPos(p);
    cur_block[p] = shape[p].front();
    shape[p].pop();
    if (shape[p].empty()) pushShape();
}

void Cboard_pair::endGame(int p)
{
    Isend[p] = true;
    if (Isend[0] && Isend[1]) Ispaused = true;
    player_end->setAudioOutput(audiooutput);
    player_end->play();
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

void Cboard_pair::do_timechange(int time)
{
    if(!Ispaused)
    {
        this->time += 1;

        if(p_curDifficulty == normal)
        {
            goDown(0);
            goDown(1);
        }
    }
    ui->lcd_time->display(this->time); // 更新时间显示
}

void Cboard_pair::do_time_hard()
{
    if(!Ispaused && p_curDifficulty == hard)
    {
        goDown(0);
        goDown(1);
    }
}

void Cboard_pair::do_time_crazy()
{
    if(!Ispaused && p_curDifficulty == crazy)
    {
        goDown(0);
        goDown(1);
    }
}

void Cboard_pair::do_tickchange()
{
    this->update(); // 每tick更新绘图
    ui->lcd_score1->display(score[0]); // 每tick更新分数
    ui->lcd_score2->display(score[1]); // 每tick更新分数
} // 每tick

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

    ui->difficulty_label->setText(Difname); // 设置pair文本难度显示
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
        Difname = "Normal";
        break;
    case 1:
        Difname = "Hard";
        break;
    case 2:
        Difname = "Crazy";
        break;
    }

    ui->difficulty_label->setText(Difname); // 设置single难度文本显示
}

void Cboard_pair::on_difchange_button_p_clicked(bool checked)
{
    changeDifficulty();
}

// 监听按键事件
void Cboard_pair::keyPressEvent(QKeyEvent *k)
{
    if (k->key() == Qt::Key_Space) on_pause_button_p_clicked(Ispaused);
    if (Ispaused == true) k->ignore(); // 忽视该按键事件
    else
    {
        switch(k->key())
        {
        // 玩家1操作按键
        case Qt::Key_W:
            rotate(0);
            break;
        case Qt::Key_A:
            goLeft(0);
            break;
        case Qt::Key_S:
           goDown(0);
            break;
        case Qt::Key_D:
            goRight(0);
            break;

        // 玩家2操作按键
        case Qt::Key_Up:
            rotate(1);
            break;
        case Qt::Key_Down:
            goDown(1);
            break;
        case Qt::Key_Left:
            goLeft(1);
            break;
        case Qt::Key_Right:
            goRight(1);
            break;
        default:
            QWidget::keyPressEvent(k); // 其他按键传递给父类
        }
    }
}

void Cboard_pair::on_start_button_p_clicked(bool checked)
{
    Ispaused = false;
    ui->pause_button_p->setChecked(true);
    ui->pause_button_p->setText("暂停 ");
    if(!checked)
    {
        ui->start_button_p->setText("开始");
        time = 0;
    }
    else if(checked)
    {
        ui->start_button_p->setText("重新开始");
    }

    startGame();
}

void Cboard_pair::on_pause_button_p_clicked(bool checked)
{
    if (!Isend[0] || !Isend[1])
    {
        if(!checked)
        {
            Ispaused = true;
            ui->pause_button_p->setText("继续");
        }
        else if(checked)
        {
            Ispaused = false;
            ui->pause_button_p->setText("暂停 ");
        }
    }
}

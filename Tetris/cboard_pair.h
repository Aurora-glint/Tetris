#ifndef CBOARD_PAIR_H
#define CBOARD_PAIR_H

#include <QWidget>
#include "CTetrimino.h"
#include <queue>
#include "Cboard.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>

namespace Ui {
class Cboard_pair;
}

class Cboard_pair : public QWidget
{
    Q_OBJECT

public:
    explicit Cboard_pair(QWidget *parent = nullptr);
    ~Cboard_pair();

signals:
    void quit();//退出信号（由主窗口接收）

    void back();//返回信号

private slots:

    void on_back_menu_button_p_clicked();

    void on_quit_game_p_clicked();

    void do_timechange(int);//每秒触发一次的槽函数

    void do_tickchange();//每tick触发一次的槽函数

    void on_difchange_button_p_clicked(bool checked); // 难度切换按钮

    void keyPressEvent(QKeyEvent *k)override;


    void on_start_button_p_clicked(bool checked);

    void on_pause_button_p_clicked(bool checked);

private:
    Ui::Cboard_pair *ui;

    bool Ispaused;

    QPoint p1_o_ = QPoint(145, 60); // p1游戏框起始点
    QPoint p2_o_ = QPoint(900, 60); // p2游戏框起始点
    QPoint p1_s_ = p1_o_ + QPoint(450,750); // p1游戏框右下点
    QPoint p2_s_ = p2_o_ + QPoint(450,750); // p2游戏框右下点
    void paintEvent(QPaintEvent *event) override; // 界面刷新
    void paint_one_block(QPainter &painter, const QRect &one_block, const All_Shape shape);

    int time;

    void changeDifficulty();//循环修改pair难度

// 游戏部分
public slots:
    void startGame(); // 开始游戏按键

    void goDown(int p); // 方块下落
    void goLeft(int p); // 方块左移
    void goRight(int p); // 方块右移
    void rotate(int p); // 方块旋转（逆时针）

private:
    All_Shape board[2][ROW][COL]; // 玩家游戏面板
    int score[2], pos[2][2];
    Difficulty p_curDifficulty;
    std::queue<CTetrimino> shape[2];
    CTetrimino cur_block[2];

    void init_board(); // 清空游戏面板
    void initPos(int p); // 重置方块位置（下落位置）

    bool tryMove(int direction, int p); // 判断是否可以移动（无碰撞，方向左移为-1，右移为1，下移为0）
    bool isDelete(int line, int p); // 判断某一行是否需要消除
    void saveBegin(int p); // 保存下落到底的方块并进行消行，同时开始下一个方块的下落
    void endGame(); // 游戏结束

    void pushShape(); // 产生随机形状

    CTetrimino getNewBlock(); // 随机获取新的方块

public:
    Difficulty p_getDifficulty(); // 获取双人游戏难度
    void p_setDifficulty(Difficulty diff); // 双人界面难度设置
};


#endif // CBOARD_PAIR_H

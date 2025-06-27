#ifndef CBOARD_PAIR_H
#define CBOARD_PAIR_H

#include <QWidget>
#include "CTetrimino.h"
#include "Cboard.h"

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

    void do_timechange();//每秒触发一次的槽函数

    void on_difchange_button_p_clicked(bool checked);//难度切换按钮

private:
    Ui::Cboard_pair *ui;

// 游戏部分
private:
    All_Shape p1_board[ROW][COL], p2_board[ROW][COL]; // 玩家游戏面板
    int p1_score, p2_score;
    Difficulty p_curDifficulty;//当前难度

public:
    Difficulty p_getDifficulty(); // 获取双人游戏难度
    void p_setDifficulty(Difficulty); // 双人界面难度设置

    void changeDifficulty();//双人循环切换难度（绑定切换按钮）

    int time = 0;//计时变量

};


#endif // CBOARD_PAIR_H

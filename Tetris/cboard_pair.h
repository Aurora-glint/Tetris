#ifndef CBOARD_PAIR_H
#define CBOARD_PAIR_H

#include <QWidget>
#include "CTetrimino.h"

enum Difficulty {normal, hard, crasy};

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

private:
    Ui::Cboard_pair *ui;

// 游戏部分
private:
    All_Shape p1_board[ROW][COL], p2_board[ROW][COL]; // 玩家游戏面板
    int p1_score, p2_score;
    Difficulty p_curDifficulty;

public:
    Difficulty p_getDifficulty(); // 获取双人游戏难度
    void p_setDifficulty(); // 双人界面难度设置
};

#endif // CBOARD_PAIR_H

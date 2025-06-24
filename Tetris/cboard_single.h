#ifndef CBOARD_SINGLE_H
#define CBOARD_SINGLE_H
#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <CTetrimino.h>
#include <QPoint>

//#include "Cboard.h"

namespace Ui {
class Cboard_single;
}

class Cboard_single : public QWidget
{
    Q_OBJECT

public:
    explicit Cboard_single(QWidget *parent = nullptr);
    ~Cboard_single();

    bool Ispaused;
    //暂停状态标志
    void keyPressEvent(QKeyEvent *k);
    //监听按键事件

signals:
    void back();//返回信号

    void quit();//退出信号（由主窗口接收）

    //void start_single();

    //void pause_single();
private slots:

    void on_quit_game_clicked();//退出游戏按钮

    void on_back_menu_button_clicked();//返回主菜单按钮

    void on_start_button_clicked();//开始游戏按钮

    void on_pause_button_clicked();//暂停游戏按钮


private:

    int time = 0;

    Ui::Cboard_single *ui;
    void timerEvent(QTimerEvent *event) override;
    //定时器
    QBasicTimer timer;
    int id = startTimer(1000);
    int id_1 = startTimer(3000);

// 以下为郝润熙所写
public slots:
    void start_game();
private:
    CTetrimino cur_block;
    CTetrimino next_block;
    QPoint pos;
    All_Shape all_board[ROW][COL];

    void init_board(); // 初始化（清空）游戏面板
    void init_pos(); // 重置方块位置（下落位置）

    CTetrimino get_new_block(); // 获取新的方块
};

#endif // CBOARD_SINGLE_H

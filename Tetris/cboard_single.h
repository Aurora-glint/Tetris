#ifndef CBOARD_SINGLE_H
#define CBOARD_SINGLE_H
#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <CTetrimino.h>
#include <QPoint>
#include <QBasicTimer>
#include <QPainter>
#include <QPaintEvent>

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
    void keyPressEvent(QKeyEvent *k)override;
    //监听按键事件

signals:
    void back();//返回信号

    void quit();//退出信号（由主窗口接收）

    void timechange(int);//每秒发出一次的信号

    //void start_single();

    //void pause_single();
private slots:

    void on_quit_game_clicked();//退出游戏按钮

    void on_back_menu_button_clicked();//返回主菜单按钮

    void on_start_button_clicked();//开始游戏按钮

    void on_pause_button_clicked();//暂停游戏按钮

    void do_timechange();//响应每秒变化


private:
    Ui::Cboard_single *ui;

    int time = 0;//计时变量

    void timerEvent(QTimerEvent *event) override;//定时器事件

    //定时器timer
    QBasicTimer timer;

    int id = startTimer(1000);
    int id_1 = startTimer(3000);

//方块颜色设置，可根据爱好修改(16进制)
    static constexpr QRgb colorTable[8]
        {
            0x000000,0xCC6666,0x66CC66,0x6666CC,
            0xCCCC66,0xCC66CC,0x66CCCC,0xDAAA00
        };

 //   QColor color = colorTable[shape];
 //需要方块编号，0-8分别对应一种颜色



// 以下为郝润熙所写
private slots:
    void go_down(); // 方块下落
    void go_left(); // 方块左移
    void go_right(); // 方块右移
    void rotate(); // 方块旋转（逆时针）

private:
    CTetrimino cur_block; // 当前正在下落的块
    CTetrimino next_block; // 显示的下一个待下落的块
    QPoint pos; // 块在游戏面板的绝对坐标（以左下角为基准）
    All_Shape all_board[ROW][COL]; // 游戏面板

    bool try_move(int direction); // 判断是否可以移动（无碰撞，方向左移为-1，右移为1，下移为0）

    void init_board(); // 初始化（清空）游戏面板
    void init_pos(); // 重置方块位置（下落位置）

    CTetrimino get_new_block(); // 获取新的方块
    bool is_delete(int line); // 判断某一行是否需要消除
    void save_begin(); // 保存下落到底的方块并进行消行，同时开始下一个方块的下落

    void paintEvent(QPaintEvent *event) override;
};

#endif // CBOARD_SINGLE_H

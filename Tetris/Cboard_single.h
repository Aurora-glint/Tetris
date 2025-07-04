#ifndef CBOARD_SINGLE_H
#define CBOARD_SINGLE_H
#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include "CTetrimino.h"
#include <QPoint>
#include <QBasicTimer>
#include <QPainter>
#include <QPaintEvent>
#include "MainWindow.h"

namespace Ui {
class Cboard_single;
}

class Cboard_single : public QWidget
{
    Q_OBJECT

public:
    explicit Cboard_single(QWidget *parent = nullptr);
    ~Cboard_single();


signals:
    void back();//返回信号

    void quit();//退出信号（由主窗口接收）

    void timechange(int);//每秒发出一次的信号

    void tick();//tick信号30ms

    void time_hard();

    void time_crazy();

private slots:

    void on_quit_game_clicked();//退出游戏按钮

    void on_back_menu_button_clicked();//返回主菜单按钮

    void do_timechange();//响应每秒变化

    void do_tickchange();//响应每tick变化

    void on_start_button_clicked(bool checked);//开始(重置)游戏按钮

    void on_pause_button_clicked(bool checked);//暂停游戏按钮

    void on_difchange_button_clicked(bool checked);//点击切换难度按钮

private:
    Ui::Cboard_single *ui;

    bool Isend; // 游戏结束标志
    bool Ispaused; // 暂停状态标志

    void keyPressEvent(QKeyEvent *k)override; // 监听按键事件

    int time = 0;//计时变量

    void timerEvent(QTimerEvent *event) override;//定时器事件

    //定时器timer及定时事件
    QBasicTimer timer;
    int id_t = startTimer(30);
    int id = startTimer(1000);
    int id_crazy = startTimer(200);
    int id_hard = startTimer(500);

private slots:
    void startGame();

    void goDown(); // 方块下落
    void goLeft(); // 方块左移
    void goRight(); // 方块右移
    void rotate(); // 方块旋转（逆时针）

    void changeDifficulty(); // 修改难度

private:
    CTetrimino cur_block; // 当前正在下落的块
    CTetrimino next_block; // 显示的下一个待下落的块
    int pos[2]; // 块在游戏面板的绝对坐标（以左下角为基准）
    All_Shape all_board[ROW][COL]; // 游戏状态面板
    int score; // 游戏得分
    Difficulty curDifficulty; // 游戏难度

    bool tryMove(int direction); // 判断是否可以移动（无碰撞，方向左移为-1，右移为1，下移为0）

    void initBoard(); // 初始化（清空）游戏面板
    void initPos(); // 重置方块位置（下落位置）

    CTetrimino getNewBlock(); // 获取新的方块
    bool isDelete(int line); // 判断某一行是否需要消除
    void saveBegin(); // 保存下落到底的方块并进行消行，同时开始下一个方块的下落
    void endGame(); // 游戏结束

    void paintEvent(QPaintEvent *event) override; // 绘制函数（每tick一次）

    void paint_one_block(QPainter &painter,const QRect &one_block,const All_Shape shape);

    QPoint o_ = QPoint(100,60);//游戏框起始点
    QPoint s_ = o_ + QPoint(450,750);//游戏框右下点

    QMediaPlayer *player_0 = new QMediaPlayer;
    QMediaPlayer *player_1 = new QMediaPlayer;
    QMediaPlayer *player_2 = new QMediaPlayer;
    QMediaPlayer *player_3 = new QMediaPlayer;
    QMediaPlayer *player_4 = new QMediaPlayer;
    QAudioOutput *audiooutput = new QAudioOutput;
    QMediaPlayer *player_end = new QMediaPlayer;

    void playMedia(int delete_num);
public:
    void setDifficulty(Difficulty diff); // single游戏难度设置
    Difficulty s_getDifficulty(); // 主页面获取single游戏难度
};

#endif // CBOARD_SINGLE_H

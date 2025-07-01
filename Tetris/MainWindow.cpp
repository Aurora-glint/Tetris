#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <Cboard_single.h>
#include <Cboard_pair.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widgets = new Cboard_single;
    widgetp = new Cboard_pair ;

    connect(this->widgets, SIGNAL(back()), this, SLOT(do_showmyshelf())); // 单人游戏返回信号与显示主窗口
    connect(this->widgetp, SIGNAL(back()), this, SLOT(do_showmyshelf())); // 双人游戏返回信号与显示主窗口
    connect(this, SIGNAL(quit()), this, SLOT(do_quit_program())); // 主窗口退出按钮与关闭
    connect(this->widgets, SIGNAL(quit()), this, SLOT(do_quit_program())); // 单人游戏退出按钮与关闭
    connect(this->widgetp, SIGNAL(quit()), this, SLOT(do_quit_program())); // 双人游戏退出按钮与关闭

    connect(this->widgets, SIGNAL(timechange(int)), this->widgets, SLOT(do_timechange())); // 关联timechnagne信号和dotimechange槽函数
    connect(this->widgets, SIGNAL(tick()), this->widgets, SLOT(do_tickchange())); // 关联tick信号

    connect(this->widgets, SIGNAL(timechange(int)), this->widgetp, SLOT(do_timechange(int))); // 关联timechange信号和pairdotimechange槽函数
    connect(this->widgets, SIGNAL(tick()), this->widgetp, SLOT(do_tickchange())); // 关联tickchange信号和pairdotickchange槽函数
    connect(this->widgets, SIGNAL(time_hard()), this->widgetp, SLOT(do_time_hard())); // 关联time_hard信号和pair::do_time_hard槽函数
    connect(this->widgets, SIGNAL(time_crazy()), this->widgetp, SLOT(do_time_crazy())); // 关联time_crazy信号和pair::do_time_crazy槽函数

    group->addButton(ui->EasyradioButton, 0);
    group->addButton(ui->HardradioButton, 1);
    group->addButton(ui->CrazyradioButton, 2);

    // 优化后的状态监听
    connect(group, &QButtonGroup::buttonToggled,
            [=](QAbstractButton *btn, bool checked) {
                if (checked) {
                    //  获取按钮信息
                    QString btnText = btn->text();
                    int id = group->id(btn);

                    //  更新游戏设置
                    widgets->setDifficulty(Difficulty(id));//设置单人游戏的难度
                    widgetp->p_setDifficulty(Difficulty(id));
                }
            });
    ui->EasyradioButton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_single_button_clicked()
{
    this->hide();
    widgets->show();
}

void MainWindow::do_showmyshelf()
{
    this->show();
    setDifficulty(widgets->s_getDifficulty());
    setDifficulty(widgetp->p_getDifficulty());
    //运行两次，结果会以上一次更新的难度为准
}

void MainWindow::do_quit_program()
{
    this->widgetp->close();//关闭双人游戏
    this->widgets->close(); // 关闭子窗口
    this->close(); // 关闭主窗口
}

void MainWindow::on_exit_button_clicked()
{
    emit quit();
}

void MainWindow::setDifficulty(Difficulty diff)
{
    switch(diff)
    {
    case 0:
        ui->EasyradioButton->setChecked(true);
        break;
    case 1:
        ui->HardradioButton->setChecked(true);
        break;
    case 2:
        ui->CrazyradioButton->setChecked(true);
        break;
    }
}

void MainWindow::on_pairbutton_clicked()
{
    this->hide();
    widgetp->show();
}

void MainWindow::on_actionhelp_triggered()
{
    QString helptitle = "游戏指南";
    QString helpinfo = "单人游戏：使用A S D控制方块向左、下、右移动，W使方块旋转\n\n"
                       "多人游戏：player1使用WASD，player2使用方向键⬆⬇⬅➡ \n\n"
        "一次性消多行会有额外加分嗷，快去挑战吧！";
    QMessageBox::information(this,helptitle,helpinfo);
}


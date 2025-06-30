#include "Cboard.h"
#include "ui_Cboard.h"
#include <QDebug>
#include <cboard_single.h>
#include <cboard_pair.h>


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
    connect(this->widgets, SIGNAL(timechange(int)), this->widgetp, SLOT(do_timechange(int))); // 关联timechange信号和pairdotimechange槽函数
    connect(this->widgets, SIGNAL(tick()), this->widgetp, SLOT(do_tickchange())); // 关联tickchange信号和pairdotickchange槽函数
    connect(this->widgets, SIGNAL(time_hard()), this->widgetp, SLOT(do_time_hard())); // 关联time_hard信号和pair::do_time_hard槽函数
    connect(this->widgets, SIGNAL(time_crazy()), this->widgetp, SLOT(do_time_crazy())); // 关联time_crazy信号和pair::do_time_crazy槽函数

    group->addButton(ui->EasyradioButton,0);
    group->addButton(ui->HardradioButton,1);
    group->addButton(ui->CrazyradioButton,2);


    // 优化后的状态监听
    connect(group, &QButtonGroup::buttonToggled,
            [=](QAbstractButton *btn, bool checked) {
                if (checked) {
                    // 1. 获取按钮信息
                    QString btnText = btn->text();
                    int id = group->id(btn);

                    // 2. 打印选择信息
                    qDebug() << "选择的难度:" << btnText << "(ID:" << id << ")";

                    // 3. 更新游戏设置
                    widgets->setDifficulty(Difficulty(id));//设置单人游戏的难度
                    widgetp->p_setDifficulty(Difficulty(id));

                    // 4. 界面反馈
                    //showSelectionFeedback(btn);
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
    this->widgets->close(); // 关闭子窗口
    this->widgetp->close();//关闭双人游戏
    this->close(); // 关闭主窗口
}

void MainWindow::on_exit_button_clicked()
{
    emit quit();
    qDebug() << "quit signal emitted " << Qt::endl;
}

void MainWindow::setDifficulty(Difficulty diff)
{
    //QString Difname;

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
   // p_setDifficulty(widgetp->getDiff)
}


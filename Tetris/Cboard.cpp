#include "Cboard.h"
#include "ui_Cboard.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->widgets, SIGNAL(back()), this, SLOT(do_showmyshelf())); // 单人游戏返回信号与显示主窗口
    connect(this, SIGNAL(quit()), this, SLOT(do_quit_program())); // 主窗口退出按钮与关闭
    connect(this->widgets, SIGNAL(quit()), this, SLOT(do_quit_program())); // 单人游戏退出按钮与关闭

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
                    widgets->setDifficulty(Difficulty(id));

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
    setDifficulty(widgets->getDifficulty());

}

void MainWindow::do_quit_program()
{
    this->widgets->close(); // 关闭子窗口
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
}


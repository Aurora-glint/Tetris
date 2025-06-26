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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_single_button_clicked()
{

    qDebug() << "clicked " << Qt::endl;
    this->hide();
    widgets->show();

}

void MainWindow::do_showmyshelf()
{
    this->show();
}

void MainWindow::do_quit_program()
{
    qDebug() << " quit " << Qt::endl;
    this->widgets->close(); // 关闭子窗口
    this->close(); // 关闭主窗口
}

void MainWindow::on_exit_button_clicked()
{
    emit quit();
    qDebug() << "quit signal emitted " << Qt::endl;
    //this->close();
}

//时间变化事件

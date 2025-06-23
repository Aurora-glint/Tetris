#include "Cboard.h"
#include "ui_Cboard.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->widgets,SIGNAL(back()),this,SLOT(showmyshelf()));
    connect(ui->exit_button,SIGNAL(quit()),this,SLOT(quit_program()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_single_button_clicked()
{

    qDebug()<< "clicked "<< Qt::endl;
    this->hide();
    widgets->show();

}

void MainWindow::showmyshelf()
{
    this->show();

}


void MainWindow::quit_program()
{
    qDebug()<< " quit "<< Qt::endl;
}

void MainWindow::on_exit_button_clicked()
{
    emit quit();
    qDebug()<<"quit signal launched "<<Qt::endl;
}



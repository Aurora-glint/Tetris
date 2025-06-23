#include "Cboard.h"
#include "ui_Cboard.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_single_button_clicked()
{

    qDebug()<< "clicked "<< Qt::endl;
}


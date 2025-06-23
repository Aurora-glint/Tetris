#include "cboard_single.h"
#include "ui_cboard_single.h"

Cboard_single::Cboard_single(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_single)
{
    ui->setupUi(this);
}

Cboard_single::~Cboard_single()
{
    delete ui;
}

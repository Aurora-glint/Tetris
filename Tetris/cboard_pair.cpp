#include "cboard_pair.h"
#include "ui_cboard_pair.h"
#include "CTetrimino.h"

Cboard_pair::Cboard_pair(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cboard_pair)
{
    ui->setupUi(this);
}

Cboard_pair::~Cboard_pair()
{
    delete ui;
}

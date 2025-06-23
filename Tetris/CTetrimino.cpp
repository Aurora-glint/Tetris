#include "CTetrimino.h"
#include <random>

extern int ROW;
extern int COL;

void CTetrimino::set_shape(All_Shape shape)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j) Tetri_shape[i][j] = Shape[shape][i][j];  // 设置形状
    }
}

void CTetrimino::creat_next_shape()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // 定义均匀整数分布 [0, 6]（包含两端）
    std::uniform_int_distribution<> dis(0, 6);

    // 生成随机数
    type = All_Shape(dis(gen));

    set_shape(All_Shape(type));  // 创建下一个随机图形
}

void CTetrimino::border()
{
    for (int i = 0; i < 4; ++i)
    {
        if (left < Tetri_shape[i][0]) left = Tetri_shape[i][0];
        if (right > Tetri_shape[i][0]) right = Tetri_shape[i][0];
        if (up > Tetri_shape[i][1]) up = Tetri_shape[i][1];
        if (down < Tetri_shape[i][1]) down = Tetri_shape[i][1];
    }
}

CTetrimino::CTetrimino():left(4), right(-1), up(-1), down(4)
{
    pos.setX(COL / 2 - 2);
    pos.setY(ROW);
}

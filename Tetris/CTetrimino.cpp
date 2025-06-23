#include "CTetrimino.h"
#include <random>

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

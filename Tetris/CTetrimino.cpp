#include "CTetrimino.h"

void CTetrimino::set_shape(All_Shape shape)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j) Tetri_shape[i][j] = Shape[shape][i][j];  // 设置形状
    }
}

void CTetrimino::creat_random_shape()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // 定义均匀整数分布 [0, 6]（包含两端）
    std::uniform_int_distribution<> dis(0, 6);

    type = All_Shape(dis(gen)); // 生成随机数

    set_shape(All_Shape(type));  // 创建下一个随机图形
}

// 获取边界值
// void CTetrimino::border()
// {
//     for (int i = 0; i < 4; ++i)
//     {
//         if (left < Tetri_shape[i][0]) left = Tetri_shape[i][0];
//         if (right > Tetri_shape[i][0]) right = Tetri_shape[i][0];
//         if (up > Tetri_shape[i][1]) up = Tetri_shape[i][1];
//         if (down < Tetri_shape[i][1]) down = Tetri_shape[i][1];
//     }
// }

void CTetrimino::set_X(int index, int value)
{
    Tetri_shape[index][0] = value;
}

void CTetrimino::set_Y(int index, int value)
{
    Tetri_shape[index][1] = value;
}

CTetrimino CTetrimino::get_rotatedLeft()
{
    if(type == O_shape) return *this;//O块旋转后与原来相同，单独考虑

    CTetrimino result;//定义新的块类用于返回旋转后的结果
    result.set_shape(type);//旋转后形状不变（广义）

    //运用矩阵旋转公式，求得旋转后的x, y
    for (int i = 0;i < 4; ++i)
    {
        result.set_X(i, 3 - Tetri_shape[i][1]);
        result.set_Y(i, Tetri_shape[i][0]);
    }

    // result.border(); //更新结果的边界值

    return result;
}

CTetrimino::CTetrimino():type(None_shape){}

CTetrimino::CTetrimino(int):type(None_shape)
{
    creat_random_shape();
    // border();
}

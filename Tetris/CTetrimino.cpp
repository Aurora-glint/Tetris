#include "CTetrimino.h"

void CTetrimino::setX(int index, int value)
{
    Tetri_shape[index][0] = value;
}

void CTetrimino::setY(int index, int value)
{
    Tetri_shape[index][1] = value;
}

void CTetrimino::setShape(All_Shape shape)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 2; ++j) Tetri_shape[i][j] = Shape[shape][i][j];  // 设置形状
    }
}

void CTetrimino::creatRandomShape()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // 定义均匀整数分布 [0, 6]（包含两端）
    std::uniform_int_distribution<> dis(0, 6);

    type = All_Shape(dis(gen) + 1); // 生成随机数

    setShape(type); // 创建下一个随机图形
}

CTetrimino CTetrimino::getRotatedLeft()
{
    if(type == O_shape) return *this; // O块旋转后与原来相同，单独考虑

    CTetrimino result; // 定义新的块类用于返回旋转后的结果
    result.setShape(type); // 旋转后形状不变（广义）

    // 运用矩阵旋转公式，求得旋转后的x, y
    for (int i = 0;i < 4; ++i)
    {
        result.setX(i, 3 - Tetri_shape[i][1]);
        result.setY(i, Tetri_shape[i][0]);
    }

    return result;
}

All_Shape CTetrimino::getType()
{
    return type;
}

CTetrimino::CTetrimino():type(None_shape){}

CTetrimino::CTetrimino(int):type(None_shape)
{
    creatRandomShape();
}

CTetrimino CTetrimino::operator=(const CTetrimino& date)
{
    type = date.type;

    for (int i = 0; i < 4; ++i)
    {
        Tetri_shape[i][0] = date.Tetri_shape[i][0];
        Tetri_shape[i][1] = date.Tetri_shape[i][1];
    }

    return *this;
}

int CTetrimino::X(int index)
{
    return Tetri_shape[index][0];
}

int CTetrimino::Y(int index)
{
    return Tetri_shape[index][1];
}

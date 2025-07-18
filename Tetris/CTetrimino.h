#ifndef CTETRIMINO_H
#define CTETRIMINO_H

#ifndef BLOCK_WIDTH
#define BLOCK_WIDTH 30
#endif

#ifndef ROW
#define ROW 25
#endif

#ifndef COL
#define COL 15
#endif

#ifndef BLOCKSIZE
#define BLOCKSIZE 30
#endif

#include <random>

enum All_Shape {None_shape, O_shape, I_shape, Z_shape, S_shape, L_shape, J_shape, T_shape};
enum Direction {Up, Down, Left, Right};

class CTetrimino{
    static constexpr int Shape[8][4][2] =
    {
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},  // None_shape
        {{1, 1}, {1, 2}, {2, 1}, {2, 2}},  // O_shape
        {{2, 0}, {2, 1}, {2, 2}, {2, 3}},  // I_shape
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},  // Z_shape
        {{2, 0}, {2, 1}, {1, 1}, {1, 2}},  // S_shape
        {{1, 1}, {2, 1}, {3, 1}, {3, 2}},  // L_shape
        {{1, 2}, {2, 2}, {3, 2}, {3, 1}},  // J_shape
        {{2, 0}, {2, 1}, {1, 1}, {2, 2}}   // T_shape
    };

private:
    int Tetri_shape[4][2];
    All_Shape type;

    void setX(int index, int value); // 修改图形x坐标值
    void setY(int index, int value); // 修改图形Y坐标值

    void setShape(All_Shape shape); // 根据形状设置图形
    void creatRandomShape(); // 随机生成下一个图形

public:
    CTetrimino(); // 无参构造函数，默认为None_shape
    CTetrimino(int); // 有参构造函数，0产生随机形状的方块，其余产生相应的方块

    CTetrimino operator=(const CTetrimino&);

    int X(int index); // 返回方块的x坐标
    int Y(int index); // 返回方块的y坐标

    CTetrimino getRotatedLeft(); // 获取旋转后的Tetrimino类
    All_Shape getType();
};

#endif // CTETRIMINO_H

#ifndef CTETRIMINO_H
#define CTETRIMINO_H

#ifndef BLOCK_WIDTH
#define BLOCK_WIDTH 30
#endif

#ifndef ROW
#define ROW 20
#endif

#ifndef COL
#define COL 10
#endif

#include <random>

enum All_Shape {O_shape, I_shape, Z_shape, S_shape, L_shape, J_shape, T_shape, None_shape};
enum Direction {Up, Down, Left, Right};

class CTetrimino{
    static constexpr int Shape[8][4][2] =
    {
        {{1, 1}, {1, 2}, {2, 1}, {2, 2}},  // O_shape
        {{0, 2}, {1, 2}, {2, 2}, {3, 2}},  // I_shape
        {{1, 2}, {2, 2}, {2, 1}, {3, 1}},  // Z_shape
        {{1, 1}, {2, 1}, {2, 2}, {3, 2}},  // S_shape
        {{1, 0}, {1, 1}, {1, 2}, {2, 1}},  // L_shape
        {{1, 0}, {2, 0}, {2, 1}, {2, 2}},  // J_shape
        {{1, 1}, {2, 1}, {3, 1}, {2, 2}},  // T_shape
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}}   // None_shape
    };
private:
    int Tetri_shape[4][2];
    All_Shape type;

    void set_X(int index, int value); // 修改图形x坐标值
    void set_Y(int index, int value); // 修改图形Y坐标值

    void set_shape(All_Shape shape); // 根据形状设置图形
    void creat_random_shape(); // 随机生成下一个图形

    // void border(); // 确定图形边界（相对坐标）

public:
    CTetrimino(); // 无参构造函数，默认为None_shape
    CTetrimino(int); // 有参构造函数，产生随机形状的方块

    // int left, right, up, down; // 上下左右边界（相对坐标）
    int X(int index);
    int Y(int index);

    CTetrimino get_rotatedLeft(); // 获取旋转后的Tetrimino类
};

#endif // CTETRIMINO_H

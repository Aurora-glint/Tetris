#ifndef CTETRIMINO_H
#define CTETRIMINO_H

#include <QPoint>

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
    int left, right, up, down; // 上下左右边界（相对坐标）
    QPoint pos; // 绝对坐标（以左下角为参考点）

    void set_shape(All_Shape shape); // 根据形状设置图形
    void creat_next_shape(); // 随机生成下一个图形

    void rotatedLeft();

    // void move(Direction dire);
    void border(); // 确定图形边界（相对坐标）

public:
    CTetrimino();

};

#endif // CTETRIMINO_H

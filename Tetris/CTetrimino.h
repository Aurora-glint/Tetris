#ifndef CTETRIMINO_H
#define CTETRIMINO_H

enum All_Shape {O_shape, I_shape, Z_shape, S_shape, L_shape, J_shape, T_shape};
enum Direction {Up, Down, Left, Right};

class CTetrimino{
    static constexpr int Shape[7][4][4] =
    {
        {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},  //O_shape
        {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},  //I_shape
        {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},  //Z_shape
        {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},  //S_shape
        {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}},  //L_shape
        {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}},  //J_shape
        {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}}   //T_shape
    };
private:
    int Tetri_shape[4][4];
    All_Shape type;
    int left, right, up, down, pos_x, pos_y; // 上下左右边界，及绝对坐标

    void set_shape(All_Shape shape); // 根据形状设置图形
    void creat_next_shape(); // 随机生成下一个图形




public:
    CTetrimino();

};

#endif // CTETRIMINO_H

// MyPainterFrame.h
#include <QFrame>
#include <QPainter>
//#include "cboard_single.h"

#ifndef ROW
#define ROW 25
#endif

#ifndef COL
#define COL 15
#endif

class MyPainterFrame : public QFrame {
    Q_OBJECT
public:
    explicit MyPainterFrame(QWidget *parent = nullptr);


    void paint_one_block(QPainter &painter,const QRect &one_block);//绘制单个方块

protected:
    void paintEvent(QPaintEvent *event) override;

private:
        int blockSize = 30;             // 每个方块的大小
};

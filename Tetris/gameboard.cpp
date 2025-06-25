// MyPainterFrame.cpp
#include "gameboard.h"

MyPainterFrame::MyPainterFrame(QWidget *parent)
    : QFrame(parent)
{
}


/*
    for(int c=0;c<COL;c++)
    {
        for(int r=0;r<ROW;r++)
        {
            gameGrid[r][c] = p;
            x+=blockSize;
            y+=blockSize;
            p.setX(x);
            p.setY(y);
}
*/

void MyPainterFrame::paintEvent(QPaintEvent *event) {

    QPainter painter(this);//gameboard作绘图区域
    QPen pen(Qt::black);
    painter.setPen(pen);

    QRect one_block;//单个方块
//TODO

    for(int c=0;c<COL;c++)
    {
        for(int r=0;r<ROW;r++)
        {
            one_block=QRect (gameGrid[c][r].x(),gameGrid[c][r].y(),blockSize,blockSize);

           // paint_one_block(painter,one_block);
        }
    }

  /*  if (!painter.begin(this)) { // 显式开始
        qWarning() << "Failed to begin painting";
        return;
    }
*/
//All_Shape all_board[ROW][COL];


}


void MyPainterFrame::paint_one_block(QPainter &painter,const QRect &one_block)
{

    painter.drawRect(one_block);//绘制该方块
}

// MyPainterFrame.cpp
#include "gameboard.h"

MyPainterFrame::MyPainterFrame(QWidget *parent)
    : QFrame(parent)
{
    // 初始化网格（示例）
    setGameGrid();
    // 设置框架样式
    setFrameStyle(QFrame::Box | QFrame::Raised);
    setLineWidth(2);
}

void MyPainterFrame::setGameGrid()
{
    /*
    // 为每一行分配列空间
    for (int r = 0; r < ROW; ++r) {
        gameGrid[r] = QVector<QPoint>(COL);
        // 填充默认值
        for (int c = 0; c < COL; ++c) {
            gameGrid[r][c] = QPoint(0, 0);
        }
    }
*/
    int x=0;
    int y=0;
    QPoint p(x,y);

    //计算各点坐标

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
    }

    //update(); 触发重绘
}

void MyPainterFrame::paintEvent(QPaintEvent *event) {
    // 1. 调用基类绘制（处理边框等）
    //QFrame::paintEvent(event);
/*
    // 2. 初始化QPainter
    QPainter painter(this);
    if (!painter.isActive()) return;

    painter.setRenderHint(QPainter::Antialiasing);

    // 3. 计算绘制区域（考虑边框偏移）

    // 4. 绘制网格背景

    // 5. 绘制俄罗斯方块


                // 计算方块位置（考虑边框偏移）

                // 绘制方块
                painter.fillRect(x, y, blockSize, blockSize, color);

                // 绘制方块边框
                painter.setPen(QPen(Qt::black, 1));
                painter.drawRect(x, y, blockSize, blockSize);
            }
        }
    }

    // 6. 绘制网格线（可选）
    painter.setPen(QPen(QColor("#404040"), 1));
    for (int row = 0; row <= gameGrid.size(); ++row) {
        int y = contentRect.top() + row * blockSize;
        painter.drawLine(contentRect.left(), y, contentRect.right(), y);
    }
    for (int col = 0; col <= gameGrid[0].size(); ++col) {
        int x = contentRect.left() + col * blockSize;
        painter.drawLine(x, contentRect.top(), x, contentRect.bottom());
    }
    */

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

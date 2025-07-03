#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef ROW
#define ROW 25
#endif

#ifndef COL
#define COL 15
#endif

#include <QMainWindow>
#include <QButtonGroup>
#include <QtMultimedia>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QDialog>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Cboard_single;
class Cboard_pair;

enum Difficulty {normal, hard, crazy};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void setDifficulty(Difficulty);//设置主窗口显示难度（与传入一致）

protected:
    //绘制背景图片
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);

        // 绘制背景图片
        QPainter painter(this);
        QPixmap background(":/image/deepocean.png");
        painter.drawPixmap(rect(), background);
    }

signals:
    void quit();

private slots:
    void on_single_button_clicked();//跳转单人游戏按钮

    void do_showmyshelf();//显示主窗口

    void do_quit_program();//关闭程序

    void on_exit_button_clicked();//主窗口退出按钮

    void on_pairbutton_clicked();//跳转双人游戏按钮

    void on_actionhelp_triggered();//帮助按钮槽函数

private:
    Ui::MainWindow *ui;
    Cboard_single *widgets ;//单人游戏窗口对象
    Cboard_pair *widgetp  ;//双人游戏窗口对象
    QButtonGroup *group = new QButtonGroup(this);

public:

};
#endif // MAINWINDOW_H

#ifndef CBOARD_H
#define CBOARD_H

#include <QMainWindow>
#include <Cboard_single.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void quit();

private slots:
    void on_single_button_clicked();//跳转单人游戏按钮

    void do_showmyshelf();//显示主窗口

    void do_quit_program();//关闭程序

    void on_exit_button_clicked();//主窗口退出按钮

private:
    Ui::MainWindow *ui;
    Cboard_single   *widgets = new Cboard_single ;//单人游戏窗口对象

};
#endif // CBOARD_H

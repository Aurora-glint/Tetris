#ifndef CBOARD_PAIR_H
#define CBOARD_PAIR_H

#include <QWidget>

namespace Ui {
class Cboard_pair;
}

class Cboard_pair : public QWidget
{
    Q_OBJECT

public:
    explicit Cboard_pair(QWidget *parent = nullptr);
    ~Cboard_pair();


signals:
    void quit();//退出信号（由主窗口接收）

    void back();//返回信号



private slots:

    void on_back_menu_button_p_clicked();

    void on_quit_game_p_clicked();

private:
    Ui::Cboard_pair *ui;
};

#endif // CBOARD_PAIR_H

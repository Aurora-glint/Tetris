#ifndef CBOARD_SINGLE_H
#define CBOARD_SINGLE_H

#include <QWidget>
//#include "Cboard.h"

namespace Ui {
class Cboard_single;
}

class Cboard_single : public QWidget
{
    Q_OBJECT

public:
    explicit Cboard_single(QWidget *parent = nullptr);
    ~Cboard_single();


signals:
    void back();

    void quit();


private slots:

    void on_quit_game_clicked();

    void on_back_menu_button_clicked();

private:
    Ui::Cboard_single *ui;
};

#endif // CBOARD_SINGLE_H

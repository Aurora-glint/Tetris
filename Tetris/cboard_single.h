#ifndef CBOARD_SINGLE_H
#define CBOARD_SINGLE_H

#include <QWidget>

namespace Ui {
class Cboard_single;
}

class Cboard_single : public QWidget
{
    Q_OBJECT

public:
    explicit Cboard_single(QWidget *parent = nullptr);
    ~Cboard_single();

private:
    Ui::Cboard_single *ui;
};

#endif // CBOARD_SINGLE_H

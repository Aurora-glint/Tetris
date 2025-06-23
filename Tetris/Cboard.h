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
    void on_single_button_clicked();

    void showmyshelf();

    void quit_program();

    void on_exit_button_clicked();

private:
    Ui::MainWindow *ui;
    Cboard_single   *widgets = new Cboard_single ;
};
#endif // CBOARD_H

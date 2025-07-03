/********************************************************************************
** Form generated from reading UI file 'Cboard_single.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBOARD_SINGLE_H
#define UI_CBOARD_SINGLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cboard_single
{
public:
    QLabel *pre_title;
    QLabel *difficulty_title;
    QLabel *difficulty_label;
    QWidget *layoutWidget;
    QVBoxLayout *buttons;
    QPushButton *start_button;
    QPushButton *pause_button;
    QPushButton *difchange_button;
    QPushButton *back_menu_button;
    QPushButton *quit_game;
    QWidget *layoutWidget1;
    QVBoxLayout *bars;
    QLabel *timetitle;
    QLCDNumber *lcd_time;
    QLabel *timetitle_2;
    QLCDNumber *lcd_score;

    void setupUi(QWidget *Cboard_single)
    {
        if (Cboard_single->objectName().isEmpty())
            Cboard_single->setObjectName("Cboard_single");
        Cboard_single->resize(721, 879);
        Cboard_single->setMinimumSize(QSize(721, 879));
        Cboard_single->setMaximumSize(QSize(721, 879));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/neko.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Cboard_single->setWindowIcon(icon);
        Cboard_single->setStyleSheet(QString::fromUtf8("/*background-color: rgb(255, 255, 255);*/\n"
"/*background-image:url(:/image/tetrisbg.png)*/\n"
"\n"
"background-color: rgb(235, 254, 255);\n"
""));
        pre_title = new QLabel(Cboard_single);
        pre_title->setObjectName("pre_title");
        pre_title->setGeometry(QRect(0, 0, 81, 41));
        pre_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        difficulty_title = new QLabel(Cboard_single);
        difficulty_title->setObjectName("difficulty_title");
        difficulty_title->setGeometry(QRect(-10, 110, 81, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(difficulty_title->sizePolicy().hasHeightForWidth());
        difficulty_title->setSizePolicy(sizePolicy);
        difficulty_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        difficulty_label = new QLabel(Cboard_single);
        difficulty_label->setObjectName("difficulty_label");
        difficulty_label->setGeometry(QRect(0, 180, 81, 41));
        sizePolicy.setHeightForWidth(difficulty_label->sizePolicy().hasHeightForWidth());
        difficulty_label->setSizePolicy(sizePolicy);
        difficulty_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(Cboard_single);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(620, 440, 101, 401));
        buttons = new QVBoxLayout(layoutWidget);
        buttons->setSpacing(40);
        buttons->setObjectName("buttons");
        buttons->setContentsMargins(0, 0, 0, 0);
        start_button = new QPushButton(layoutWidget);
        start_button->setObjectName("start_button");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(start_button->sizePolicy().hasHeightForWidth());
        start_button->setSizePolicy(sizePolicy1);
        start_button->setMouseTracking(true);
        start_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        start_button->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #4CAF50; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    color: white;              /* \351\200\211\344\270\255\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #388E3C; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton{\n"
"    \n"
"	background-color: rgb(170, 255, 255);\n"
"    border: 2px solid #388E3C; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206 */\n"
"}"));
        start_button->setCheckable(true);
        start_button->setChecked(false);

        buttons->addWidget(start_button);

        pause_button = new QPushButton(layoutWidget);
        pause_button->setObjectName("pause_button");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pause_button->sizePolicy().hasHeightForWidth());
        pause_button->setSizePolicy(sizePolicy2);
        pause_button->setMouseTracking(true);
        pause_button->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        pause_button->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #4CAF50; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    color: white;              /* \351\200\211\344\270\255\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #388E3C; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206 */\n"
"	padding: 8px; /* \351\200\211\344\270\255\346\227\266\345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    border-width: 2px; /* \351\200\211\344\270\255\346\227\266\345\212\240\347\262\227\350\276\271\346\241\206 */\n"
"\n"
"}"));
        pause_button->setCheckable(true);
        pause_button->setChecked(true);

        buttons->addWidget(pause_button);

        difchange_button = new QPushButton(layoutWidget);
        difchange_button->setObjectName("difchange_button");
        sizePolicy2.setHeightForWidth(difchange_button->sizePolicy().hasHeightForWidth());
        difchange_button->setSizePolicy(sizePolicy2);
        difchange_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        buttons->addWidget(difchange_button);

        back_menu_button = new QPushButton(layoutWidget);
        back_menu_button->setObjectName("back_menu_button");
        sizePolicy2.setHeightForWidth(back_menu_button->sizePolicy().hasHeightForWidth());
        back_menu_button->setSizePolicy(sizePolicy2);
        back_menu_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        buttons->addWidget(back_menu_button);

        quit_game = new QPushButton(layoutWidget);
        quit_game->setObjectName("quit_game");
        sizePolicy2.setHeightForWidth(quit_game->sizePolicy().hasHeightForWidth());
        quit_game->setSizePolicy(sizePolicy2);
        quit_game->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        buttons->addWidget(quit_game);

        layoutWidget1 = new QWidget(Cboard_single);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(590, 10, 131, 271));
        bars = new QVBoxLayout(layoutWidget1);
        bars->setSpacing(20);
        bars->setObjectName("bars");
        bars->setContentsMargins(0, 0, 0, 0);
        timetitle = new QLabel(layoutWidget1);
        timetitle->setObjectName("timetitle");
        sizePolicy.setHeightForWidth(timetitle->sizePolicy().hasHeightForWidth());
        timetitle->setSizePolicy(sizePolicy);
        timetitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        bars->addWidget(timetitle);

        lcd_time = new QLCDNumber(layoutWidget1);
        lcd_time->setObjectName("lcd_time");
        lcd_time->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_time->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        bars->addWidget(lcd_time);

        timetitle_2 = new QLabel(layoutWidget1);
        timetitle_2->setObjectName("timetitle_2");
        sizePolicy.setHeightForWidth(timetitle_2->sizePolicy().hasHeightForWidth());
        timetitle_2->setSizePolicy(sizePolicy);
        timetitle_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        bars->addWidget(timetitle_2);

        lcd_score = new QLCDNumber(layoutWidget1);
        lcd_score->setObjectName("lcd_score");
        lcd_score->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_score->setDigitCount(7);
        lcd_score->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);

        bars->addWidget(lcd_score);


        retranslateUi(Cboard_single);

        QMetaObject::connectSlotsByName(Cboard_single);
    } // setupUi

    void retranslateUi(QWidget *Cboard_single)
    {
        Cboard_single->setWindowTitle(QCoreApplication::translate("Cboard_single", "Tetris", nullptr));
        pre_title->setText(QCoreApplication::translate("Cboard_single", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\344\270\213\344\270\200\345\235\227</span></p></body></html>", nullptr));
        difficulty_title->setText(QCoreApplication::translate("Cboard_single", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\351\232\276\345\272\246</span></p></body></html>", nullptr));
        difficulty_label->setText(QCoreApplication::translate("Cboard_single", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">HARD</span></p></body></html>", nullptr));
        start_button->setText(QCoreApplication::translate("Cboard_single", "\345\274\200\345\247\213", nullptr));
        pause_button->setText(QCoreApplication::translate("Cboard_single", "\346\232\202\345\201\234", nullptr));
        difchange_button->setText(QCoreApplication::translate("Cboard_single", "\345\210\207\346\215\242\351\232\276\345\272\246", nullptr));
        back_menu_button->setText(QCoreApplication::translate("Cboard_single", "\350\277\224\345\233\236\350\217\234\345\215\225", nullptr));
        quit_game->setText(QCoreApplication::translate("Cboard_single", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        timetitle->setText(QCoreApplication::translate("Cboard_single", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\345\275\223\345\211\215\346\227\266\351\227\264</span></p></body></html>", nullptr));
        timetitle_2->setText(QCoreApplication::translate("Cboard_single", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\345\275\223\345\211\215\345\210\206\346\225\260</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cboard_single: public Ui_Cboard_single {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBOARD_SINGLE_H

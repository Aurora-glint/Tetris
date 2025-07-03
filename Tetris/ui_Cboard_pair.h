/********************************************************************************
** Form generated from reading UI file 'Cboard_pair.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBOARD_PAIR_H
#define UI_CBOARD_PAIR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cboard_pair
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *buttons;
    QPushButton *start_button_p;
    QPushButton *pause_button_p;
    QPushButton *difchange_button_p;
    QPushButton *back_menu_button_p;
    QPushButton *quit_game_p;
    QWidget *layoutWidget_2;
    QVBoxLayout *bars;
    QLabel *timetitle;
    QLCDNumber *lcd_time;
    QLabel *score_title1;
    QLCDNumber *lcd_score1;
    QLabel *score_title2;
    QLCDNumber *lcd_score2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *difficulty_title;
    QLabel *difficulty_label;

    void setupUi(QWidget *Cboard_pair)
    {
        if (Cboard_pair->objectName().isEmpty())
            Cboard_pair->setObjectName("Cboard_pair");
        Cboard_pair->resize(1500, 900);
        QFont font;
        font.setBold(false);
        Cboard_pair->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/MISC1139.ICO"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Cboard_pair->setWindowIcon(icon);
        layoutWidget = new QWidget(Cboard_pair);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1390, 490, 101, 401));
        buttons = new QVBoxLayout(layoutWidget);
        buttons->setSpacing(40);
        buttons->setObjectName("buttons");
        buttons->setContentsMargins(0, 0, 0, 0);
        start_button_p = new QPushButton(layoutWidget);
        start_button_p->setObjectName("start_button_p");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start_button_p->sizePolicy().hasHeightForWidth());
        start_button_p->setSizePolicy(sizePolicy);
        start_button_p->setMouseTracking(true);
        start_button_p->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        start_button_p->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #4CAF50; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    color: white;              /* \351\200\211\344\270\255\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #388E3C; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton{\n"
"    \n"
"	background-color: rgb(170, 255, 255);\n"
"    border: 2px solid #388E3C; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206 */\n"
"}"));
        start_button_p->setCheckable(true);
        start_button_p->setChecked(false);

        buttons->addWidget(start_button_p);

        pause_button_p = new QPushButton(layoutWidget);
        pause_button_p->setObjectName("pause_button_p");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pause_button_p->sizePolicy().hasHeightForWidth());
        pause_button_p->setSizePolicy(sizePolicy1);
        pause_button_p->setMouseTracking(true);
        pause_button_p->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        pause_button_p->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #4CAF50; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    color: white;              /* \351\200\211\344\270\255\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: 2px solid #388E3C; /* \351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206 */\n"
"	padding: 8px; /* \351\200\211\344\270\255\346\227\266\345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    border-width: 2px; /* \351\200\211\344\270\255\346\227\266\345\212\240\347\262\227\350\276\271\346\241\206 */\n"
"\n"
"}"));
        pause_button_p->setCheckable(true);
        pause_button_p->setChecked(true);

        buttons->addWidget(pause_button_p);

        difchange_button_p = new QPushButton(layoutWidget);
        difchange_button_p->setObjectName("difchange_button_p");
        sizePolicy1.setHeightForWidth(difchange_button_p->sizePolicy().hasHeightForWidth());
        difchange_button_p->setSizePolicy(sizePolicy1);
        difchange_button_p->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        buttons->addWidget(difchange_button_p);

        back_menu_button_p = new QPushButton(layoutWidget);
        back_menu_button_p->setObjectName("back_menu_button_p");
        sizePolicy1.setHeightForWidth(back_menu_button_p->sizePolicy().hasHeightForWidth());
        back_menu_button_p->setSizePolicy(sizePolicy1);
        back_menu_button_p->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        buttons->addWidget(back_menu_button_p);

        quit_game_p = new QPushButton(layoutWidget);
        quit_game_p->setObjectName("quit_game_p");
        sizePolicy1.setHeightForWidth(quit_game_p->sizePolicy().hasHeightForWidth());
        quit_game_p->setSizePolicy(sizePolicy1);
        quit_game_p->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        buttons->addWidget(quit_game_p);

        layoutWidget_2 = new QWidget(Cboard_pair);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(700, 10, 101, 341));
        bars = new QVBoxLayout(layoutWidget_2);
        bars->setSpacing(20);
        bars->setObjectName("bars");
        bars->setContentsMargins(0, 6, 0, 0);
        timetitle = new QLabel(layoutWidget_2);
        timetitle->setObjectName("timetitle");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(timetitle->sizePolicy().hasHeightForWidth());
        timetitle->setSizePolicy(sizePolicy2);
        timetitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        bars->addWidget(timetitle);

        lcd_time = new QLCDNumber(layoutWidget_2);
        lcd_time->setObjectName("lcd_time");
        sizePolicy1.setHeightForWidth(lcd_time->sizePolicy().hasHeightForWidth());
        lcd_time->setSizePolicy(sizePolicy1);
        lcd_time->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_time->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        bars->addWidget(lcd_time);

        score_title1 = new QLabel(layoutWidget_2);
        score_title1->setObjectName("score_title1");
        sizePolicy2.setHeightForWidth(score_title1->sizePolicy().hasHeightForWidth());
        score_title1->setSizePolicy(sizePolicy2);
        score_title1->setFrameShape(QFrame::Shape::NoFrame);
        score_title1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        bars->addWidget(score_title1);

        lcd_score1 = new QLCDNumber(layoutWidget_2);
        lcd_score1->setObjectName("lcd_score1");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(10);
        sizePolicy3.setHeightForWidth(lcd_score1->sizePolicy().hasHeightForWidth());
        lcd_score1->setSizePolicy(sizePolicy3);
        lcd_score1->setMinimumSize(QSize(0, 50));
        lcd_score1->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_score1->setDigitCount(7);
        lcd_score1->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);

        bars->addWidget(lcd_score1);

        score_title2 = new QLabel(layoutWidget_2);
        score_title2->setObjectName("score_title2");
        sizePolicy2.setHeightForWidth(score_title2->sizePolicy().hasHeightForWidth());
        score_title2->setSizePolicy(sizePolicy2);
        score_title2->setSizeIncrement(QSize(0, 0));
        score_title2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        bars->addWidget(score_title2);

        lcd_score2 = new QLCDNumber(layoutWidget_2);
        lcd_score2->setObjectName("lcd_score2");
        sizePolicy1.setHeightForWidth(lcd_score2->sizePolicy().hasHeightForWidth());
        lcd_score2->setSizePolicy(sizePolicy1);
        lcd_score2->setMinimumSize(QSize(0, 50));
        lcd_score2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_score2->setDigitCount(7);
        lcd_score2->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);

        bars->addWidget(lcd_score2);

        layoutWidget1 = new QWidget(Cboard_pair);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(710, 750, 91, 131));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        difficulty_title = new QLabel(layoutWidget1);
        difficulty_title->setObjectName("difficulty_title");
        sizePolicy2.setHeightForWidth(difficulty_title->sizePolicy().hasHeightForWidth());
        difficulty_title->setSizePolicy(sizePolicy2);
        difficulty_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(difficulty_title);

        difficulty_label = new QLabel(layoutWidget1);
        difficulty_label->setObjectName("difficulty_label");
        sizePolicy2.setHeightForWidth(difficulty_label->sizePolicy().hasHeightForWidth());
        difficulty_label->setSizePolicy(sizePolicy2);
        difficulty_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(difficulty_label);


        retranslateUi(Cboard_pair);

        QMetaObject::connectSlotsByName(Cboard_pair);
    } // setupUi

    void retranslateUi(QWidget *Cboard_pair)
    {
        Cboard_pair->setWindowTitle(QCoreApplication::translate("Cboard_pair", "pair_game", nullptr));
        start_button_p->setText(QCoreApplication::translate("Cboard_pair", "\345\274\200\345\247\213", nullptr));
        pause_button_p->setText(QCoreApplication::translate("Cboard_pair", "\346\232\202\345\201\234", nullptr));
        difchange_button_p->setText(QCoreApplication::translate("Cboard_pair", "\345\210\207\346\215\242\351\232\276\345\272\246", nullptr));
        back_menu_button_p->setText(QCoreApplication::translate("Cboard_pair", "\350\277\224\345\233\236\350\217\234\345\215\225", nullptr));
        quit_game_p->setText(QCoreApplication::translate("Cboard_pair", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        timetitle->setText(QCoreApplication::translate("Cboard_pair", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\345\275\223\345\211\215\346\227\266\351\227\264</span></p></body></html>", nullptr));
        score_title1->setText(QCoreApplication::translate("Cboard_pair", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">P1\345\210\206\346\225\260</span></p></body></html>", nullptr));
        score_title2->setText(QCoreApplication::translate("Cboard_pair", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">P2\345\210\206\346\225\260</span></p></body></html>", nullptr));
        difficulty_title->setText(QCoreApplication::translate("Cboard_pair", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\351\232\276\345\272\246</span></p></body></html>", nullptr));
        difficulty_label->setText(QCoreApplication::translate("Cboard_pair", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">HARD</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cboard_pair: public Ui_Cboard_pair {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBOARD_PAIR_H

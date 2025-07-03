/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionhelp;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *single_button;
    QPushButton *pairbutton;
    QPushButton *exit_button;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *EasyradioButton;
    QRadioButton *HardradioButton;
    QRadioButton *CrazyradioButton;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/neko22.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionhelp = new QAction(MainWindow);
        actionhelp->setObjectName("actionhelp");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        actionhelp->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(320, 120, 171, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        single_button = new QPushButton(layoutWidget);
        single_button->setObjectName("single_button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(single_button->sizePolicy().hasHeightForWidth());
        single_button->setSizePolicy(sizePolicy);
        single_button->setAutoFillBackground(false);
        single_button->setStyleSheet(QString::fromUtf8(""));
        single_button->setAutoDefault(false);
        single_button->setFlat(false);

        verticalLayout->addWidget(single_button);

        pairbutton = new QPushButton(layoutWidget);
        pairbutton->setObjectName("pairbutton");
        sizePolicy.setHeightForWidth(pairbutton->sizePolicy().hasHeightForWidth());
        pairbutton->setSizePolicy(sizePolicy);
        pairbutton->setStyleSheet(QString::fromUtf8("border-image: url();"));

        verticalLayout->addWidget(pairbutton);

        exit_button = new QPushButton(layoutWidget);
        exit_button->setObjectName("exit_button");
        sizePolicy.setHeightForWidth(exit_button->sizePolicy().hasHeightForWidth());
        exit_button->setSizePolicy(sizePolicy);
        exit_button->setStyleSheet(QString::fromUtf8("border-image: url(:);"));

        verticalLayout->addWidget(exit_button);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(650, 170, 121, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(4, 0, 0, 0);
        EasyradioButton = new QRadioButton(layoutWidget1);
        EasyradioButton->setObjectName("EasyradioButton");
        sizePolicy.setHeightForWidth(EasyradioButton->sizePolicy().hasHeightForWidth());
        EasyradioButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        EasyradioButton->setFont(font);
        EasyradioButton->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        EasyradioButton->setStyleSheet(QString::fromUtf8("border-image: url();\n"
"border-color: rgb(85, 255, 255);"));

        verticalLayout_2->addWidget(EasyradioButton);

        HardradioButton = new QRadioButton(layoutWidget1);
        HardradioButton->setObjectName("HardradioButton");
        sizePolicy.setHeightForWidth(HardradioButton->sizePolicy().hasHeightForWidth());
        HardradioButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        HardradioButton->setFont(font1);
        HardradioButton->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        HardradioButton->setStyleSheet(QString::fromUtf8("border-image: url();"));

        verticalLayout_2->addWidget(HardradioButton);

        CrazyradioButton = new QRadioButton(layoutWidget1);
        CrazyradioButton->setObjectName("CrazyradioButton");
        sizePolicy.setHeightForWidth(CrazyradioButton->sizePolicy().hasHeightForWidth());
        CrazyradioButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        CrazyradioButton->setFont(font2);
        CrazyradioButton->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        CrazyradioButton->setStyleSheet(QString::fromUtf8("border-image: url();"));

        verticalLayout_2->addWidget(CrazyradioButton);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionhelp);

        retranslateUi(MainWindow);

        single_button->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Teris_game", nullptr));
        actionhelp->setText(QCoreApplication::translate("MainWindow", "how to play", nullptr));
        single_button->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\272\272\346\270\270\346\210\217", nullptr));
        pairbutton->setText(QCoreApplication::translate("MainWindow", "\345\244\232\344\272\272\346\270\270\346\210\217", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        EasyradioButton->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        HardradioButton->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        CrazyradioButton->setText(QCoreApplication::translate("MainWindow", "Crazy", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

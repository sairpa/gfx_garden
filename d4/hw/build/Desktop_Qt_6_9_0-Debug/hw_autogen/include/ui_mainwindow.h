/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *editInput;
    QLabel *title;
    QWidget *layoutWidget;
    QGridLayout *Layout;
    QPushButton *six;
    QPushButton *two;
    QPushButton *five;
    QPushButton *seven;
    QPushButton *equal;
    QPushButton *multiply;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *one;
    QPushButton *three;
    QPushButton *four;
    QPushButton *add;
    QPushButton *zero;
    QPushButton *minus;
    QPushButton *divide;
    QPushButton *Clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        editInput = new QLineEdit(centralwidget);
        editInput->setObjectName("editInput");
        editInput->setGeometry(QRect(270, 120, 291, 81));
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(190, 130, 71, 18));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        title->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(190, 220, 372, 252));
        Layout = new QGridLayout(layoutWidget);
        Layout->setObjectName("Layout");
        Layout->setVerticalSpacing(30);
        Layout->setContentsMargins(0, 0, 0, 0);
        six = new QPushButton(layoutWidget);
        six->setObjectName("six");

        Layout->addWidget(six, 3, 2, 1, 1);

        two = new QPushButton(layoutWidget);
        two->setObjectName("two");

        Layout->addWidget(two, 2, 1, 1, 1);

        five = new QPushButton(layoutWidget);
        five->setObjectName("five");

        Layout->addWidget(five, 3, 1, 1, 1);

        seven = new QPushButton(layoutWidget);
        seven->setObjectName("seven");

        Layout->addWidget(seven, 4, 0, 1, 1);

        equal = new QPushButton(layoutWidget);
        equal->setObjectName("equal");

        Layout->addWidget(equal, 1, 2, 1, 1);

        multiply = new QPushButton(layoutWidget);
        multiply->setObjectName("multiply");

        Layout->addWidget(multiply, 1, 0, 1, 1);

        eight = new QPushButton(layoutWidget);
        eight->setObjectName("eight");

        Layout->addWidget(eight, 4, 1, 1, 1);

        nine = new QPushButton(layoutWidget);
        nine->setObjectName("nine");

        Layout->addWidget(nine, 4, 2, 1, 1);

        one = new QPushButton(layoutWidget);
        one->setObjectName("one");

        Layout->addWidget(one, 2, 0, 1, 1);

        three = new QPushButton(layoutWidget);
        three->setObjectName("three");

        Layout->addWidget(three, 2, 2, 1, 1);

        four = new QPushButton(layoutWidget);
        four->setObjectName("four");

        Layout->addWidget(four, 3, 0, 1, 1);

        add = new QPushButton(layoutWidget);
        add->setObjectName("add");

        Layout->addWidget(add, 0, 0, 1, 1);

        zero = new QPushButton(layoutWidget);
        zero->setObjectName("zero");

        Layout->addWidget(zero, 1, 1, 1, 1);

        minus = new QPushButton(layoutWidget);
        minus->setObjectName("minus");

        Layout->addWidget(minus, 0, 1, 1, 1);

        divide = new QPushButton(layoutWidget);
        divide->setObjectName("divide");

        Layout->addWidget(divide, 0, 2, 1, 1);

        Clear = new QPushButton(centralwidget);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(187, 160, 71, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'quizwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZWINDOW_H
#define UI_QUIZWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuizWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QRadioButton *ra_1_1_correct;
    QRadioButton *ra_1_4;
    QRadioButton *ra_1_3;
    QRadioButton *ra_1_2;
    QGroupBox *groupBox_2;
    QRadioButton *ra_2_1;
    QRadioButton *ra_2_4;
    QRadioButton *ra_2_3_correct;
    QRadioButton *ra_2_2;
    QGroupBox *groupBox_3;
    QRadioButton *ra_3_1;
    QRadioButton *ra_3_2;
    QRadioButton *ra_3_3;
    QRadioButton *ra_3_4_correct;
    QGroupBox *groupBox_5;
    QRadioButton *ra_4_1;
    QRadioButton *ra_4_2;
    QRadioButton *ra_4_3;
    QRadioButton *ra_4_4_correct;
    QGroupBox *groupBox_7;
    QRadioButton *ra_5_1;
    QRadioButton *ra_5_2_correct;
    QRadioButton *ra_5_3;
    QRadioButton *ra_5_4;
    QPushButton *finishBtn;
    QLabel *timeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QuizWindow)
    {
        if (QuizWindow->objectName().isEmpty())
            QuizWindow->setObjectName(QString::fromUtf8("QuizWindow"));
        QuizWindow->resize(800, 1000);
        QuizWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(QuizWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 780, 151));
        ra_1_1_correct = new QRadioButton(groupBox);
        ra_1_1_correct->setObjectName(QString::fromUtf8("ra_1_1_correct"));
        ra_1_1_correct->setGeometry(QRect(10, 30, 69, 18));
        ra_1_4 = new QRadioButton(groupBox);
        ra_1_4->setObjectName(QString::fromUtf8("ra_1_4"));
        ra_1_4->setGeometry(QRect(10, 60, 69, 18));
        ra_1_3 = new QRadioButton(groupBox);
        ra_1_3->setObjectName(QString::fromUtf8("ra_1_3"));
        ra_1_3->setGeometry(QRect(10, 90, 69, 18));
        ra_1_2 = new QRadioButton(groupBox);
        ra_1_2->setObjectName(QString::fromUtf8("ra_1_2"));
        ra_1_2->setGeometry(QRect(10, 120, 69, 18));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 180, 780, 151));
        ra_2_1 = new QRadioButton(groupBox_2);
        ra_2_1->setObjectName(QString::fromUtf8("ra_2_1"));
        ra_2_1->setGeometry(QRect(10, 30, 69, 18));
        ra_2_4 = new QRadioButton(groupBox_2);
        ra_2_4->setObjectName(QString::fromUtf8("ra_2_4"));
        ra_2_4->setGeometry(QRect(10, 60, 69, 18));
        ra_2_3_correct = new QRadioButton(groupBox_2);
        ra_2_3_correct->setObjectName(QString::fromUtf8("ra_2_3_correct"));
        ra_2_3_correct->setGeometry(QRect(10, 90, 69, 18));
        ra_2_2 = new QRadioButton(groupBox_2);
        ra_2_2->setObjectName(QString::fromUtf8("ra_2_2"));
        ra_2_2->setGeometry(QRect(10, 120, 69, 18));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 350, 780, 151));
        ra_3_1 = new QRadioButton(groupBox_3);
        ra_3_1->setObjectName(QString::fromUtf8("ra_3_1"));
        ra_3_1->setGeometry(QRect(10, 30, 341, 18));
        ra_3_2 = new QRadioButton(groupBox_3);
        ra_3_2->setObjectName(QString::fromUtf8("ra_3_2"));
        ra_3_2->setGeometry(QRect(10, 60, 341, 18));
        ra_3_3 = new QRadioButton(groupBox_3);
        ra_3_3->setObjectName(QString::fromUtf8("ra_3_3"));
        ra_3_3->setGeometry(QRect(10, 90, 331, 18));
        ra_3_4_correct = new QRadioButton(groupBox_3);
        ra_3_4_correct->setObjectName(QString::fromUtf8("ra_3_4_correct"));
        ra_3_4_correct->setGeometry(QRect(10, 120, 381, 18));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 520, 780, 151));
        ra_4_1 = new QRadioButton(groupBox_5);
        ra_4_1->setObjectName(QString::fromUtf8("ra_4_1"));
        ra_4_1->setGeometry(QRect(10, 30, 321, 18));
        ra_4_2 = new QRadioButton(groupBox_5);
        ra_4_2->setObjectName(QString::fromUtf8("ra_4_2"));
        ra_4_2->setGeometry(QRect(10, 60, 171, 18));
        ra_4_3 = new QRadioButton(groupBox_5);
        ra_4_3->setObjectName(QString::fromUtf8("ra_4_3"));
        ra_4_3->setGeometry(QRect(10, 90, 201, 18));
        ra_4_4_correct = new QRadioButton(groupBox_5);
        ra_4_4_correct->setObjectName(QString::fromUtf8("ra_4_4_correct"));
        ra_4_4_correct->setGeometry(QRect(10, 120, 221, 18));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 690, 780, 151));
        ra_5_1 = new QRadioButton(groupBox_7);
        ra_5_1->setObjectName(QString::fromUtf8("ra_5_1"));
        ra_5_1->setGeometry(QRect(10, 30, 261, 18));
        ra_5_2_correct = new QRadioButton(groupBox_7);
        ra_5_2_correct->setObjectName(QString::fromUtf8("ra_5_2_correct"));
        ra_5_2_correct->setGeometry(QRect(10, 60, 201, 18));
        ra_5_3 = new QRadioButton(groupBox_7);
        ra_5_3->setObjectName(QString::fromUtf8("ra_5_3"));
        ra_5_3->setGeometry(QRect(10, 90, 251, 18));
        ra_5_4 = new QRadioButton(groupBox_7);
        ra_5_4->setObjectName(QString::fromUtf8("ra_5_4"));
        ra_5_4->setGeometry(QRect(10, 120, 311, 18));
        finishBtn = new QPushButton(centralwidget);
        finishBtn->setObjectName(QString::fromUtf8("finishBtn"));
        finishBtn->setGeometry(QRect(649, 927, 111, 31));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(10, 890, 191, 41));
        QFont font;
        font.setPointSize(14);
        timeLabel->setFont(font);
        QuizWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QuizWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        QuizWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(QuizWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QuizWindow->setStatusBar(statusbar);

        retranslateUi(QuizWindow);

        QMetaObject::connectSlotsByName(QuizWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuizWindow)
    {
        QuizWindow->setWindowTitle(QCoreApplication::translate("QuizWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QuizWindow", "1. Which data type is used to store boolean values in C++?", nullptr));
        ra_1_1_correct->setText(QCoreApplication::translate("QuizWindow", "bool", nullptr));
        ra_1_4->setText(QCoreApplication::translate("QuizWindow", "int", nullptr));
        ra_1_3->setText(QCoreApplication::translate("QuizWindow", "boolean", nullptr));
        ra_1_2->setText(QCoreApplication::translate("QuizWindow", "bit", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QuizWindow", "2. Evaluate the following.     (false && true) || false || true", nullptr));
        ra_2_1->setText(QCoreApplication::translate("QuizWindow", "1", nullptr));
        ra_2_4->setText(QCoreApplication::translate("QuizWindow", "0", nullptr));
        ra_2_3_correct->setText(QCoreApplication::translate("QuizWindow", "false", nullptr));
        ra_2_2->setText(QCoreApplication::translate("QuizWindow", "2", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QuizWindow", "3. Pick the correct statement about string objects in C++.", nullptr));
        ra_3_1->setText(QCoreApplication::translate("QuizWindow", "String objects have a dynamic size", nullptr));
        ra_3_2->setText(QCoreApplication::translate("QuizWindow", "String objects use extra memory than required.", nullptr));
        ra_3_3->setText(QCoreApplication::translate("QuizWindow", "String objects have a static size", nullptr));
        ra_3_4_correct->setText(QCoreApplication::translate("QuizWindow", "String objects must be terminated by a null character(\342\200\2300\342\200\231)", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("QuizWindow", "4. What is the identifier given to string class to declare string objects?", nullptr));
        ra_4_1->setText(QCoreApplication::translate("QuizWindow", "Any of the above can be used", nullptr));
        ra_4_2->setText(QCoreApplication::translate("QuizWindow", "String", nullptr));
        ra_4_3->setText(QCoreApplication::translate("QuizWindow", "STRING", nullptr));
        ra_4_4_correct->setText(QCoreApplication::translate("QuizWindow", "string", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("QuizWindow", "5. What is Character-Array?", nullptr));
        ra_5_1->setText(QCoreApplication::translate("QuizWindow", "array of alphabets", nullptr));
        ra_5_2_correct->setText(QCoreApplication::translate("QuizWindow", "array of characters", nullptr));
        ra_5_3->setText(QCoreApplication::translate("QuizWindow", "array of characters terminated by 0", nullptr));
        ra_5_4->setText(QCoreApplication::translate("QuizWindow", "array of well-defined characters", nullptr));
        finishBtn->setText(QCoreApplication::translate("QuizWindow", "Finish", nullptr));
        timeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuizWindow: public Ui_QuizWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZWINDOW_H

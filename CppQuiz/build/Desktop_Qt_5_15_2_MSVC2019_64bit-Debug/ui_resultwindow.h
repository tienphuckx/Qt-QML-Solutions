/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *studentName;
    QLabel *correctQues;
    QLabel *totalQues;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName(QString::fromUtf8("ResultWindow"));
        ResultWindow->resize(640, 480);
        centralwidget = new QWidget(ResultWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 110, 161, 50));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        studentName = new QLabel(centralwidget);
        studentName->setObjectName(QString::fromUtf8("studentName"));
        studentName->setGeometry(QRect(40, 110, 100, 50));
        QFont font1;
        font1.setPointSize(14);
        studentName->setFont(font1);
        correctQues = new QLabel(centralwidget);
        correctQues->setObjectName(QString::fromUtf8("correctQues"));
        correctQues->setGeometry(QRect(70, 220, 100, 50));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        correctQues->setFont(font2);
        totalQues = new QLabel(centralwidget);
        totalQues->setObjectName(QString::fromUtf8("totalQues"));
        totalQues->setGeometry(QRect(270, 220, 100, 50));
        totalQues->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 230, 41, 31));
        label_2->setFont(font);
        ResultWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ResultWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 17));
        ResultWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ResultWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ResultWindow->setStatusBar(statusbar);

        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ResultWindow)
    {
        ResultWindow->setWindowTitle(QCoreApplication::translate("ResultWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ResultWindow", "'s score", nullptr));
        studentName->setText(QString());
        correctQues->setText(QString());
        totalQues->setText(QString());
        label_2->setText(QCoreApplication::translate("ResultWindow", "of", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H

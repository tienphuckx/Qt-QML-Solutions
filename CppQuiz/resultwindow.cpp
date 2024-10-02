#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QDebug>

ResultWindow::ResultWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

ResultWindow::ResultWindow(QWidget *parent, QuizResult *result)
    : QMainWindow(parent) , ui(new Ui::ResultWindow), quizResult(result)
{
    ui->setupUi(this);
    if (!quizResult) {
        qDebug() << "quizResult is nullptr!";
        return;
    }
    ui->studentName->setText(quizResult->getName());
    ui->correctQues->setText(QString::number(quizResult->getCorrectAnswers()));
    ui->totalQues->setText(QString::number(quizResult->getTotalQuestions()));
}


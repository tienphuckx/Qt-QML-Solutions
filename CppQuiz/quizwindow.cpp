#include "quizwindow.h"
#include "ui_quizwindow.h"

QuizWindow::QuizWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuizWindow)
    , countdownTime(1 * 60)
{
    ui->setupUi(this);
    question1 = 0;
    question2 = 0;
    question3 = 0;
    question4 = 0;
    question5 = 0;
    result = 0;
    totalQuestion = 5;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QuizWindow::updateTimer);
    timer->start(500);
    ui->timeLabel->setText(formatTime(countdownTime));
}

QuizWindow::~QuizWindow()
{
    delete ui;
    delete r;
}

void QuizWindow::updateTimer()
{
    countdownTime--;
    if (countdownTime <= 0) {
        timer->stop();
        on_finishBtn_clicked();
    } else {
        ui->timeLabel->setText(formatTime(countdownTime));
    }
}

QString QuizWindow::formatTime(int seconds)
{
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    return QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(remainingSeconds, 2, 10, QChar('0'));
}

void QuizWindow::on_finishBtn_clicked()
{
    if (ui->ra_1_1_correct->isChecked())
        question1 += 1;
    if (ui->ra_2_3_correct->isChecked())
        question2 += 1;
    if (ui->ra_3_4_correct->isChecked())
        question3 += 1;
    if (ui->ra_4_4_correct->isChecked())
        question4 += 1;
    if (ui->ra_5_2_correct->isChecked())
        question5 += 1;
    result = question1 + question2 + question3 + question4 + question5;
    this->hide();

    QString name = "Phuc";
    quizResult = new QuizResult(name, 5, result);
    r = new ResultWindow(this, quizResult);
    r->show();
}

#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QTime>
#include <QTimer>

#include <QMainWindow>
#include "resultwindow.h"

namespace Ui {
class QuizWindow;
}

class QuizResult
{
public:
    QuizResult(QString &name, int totalQuestions, int correctAnswers);
    QuizResult();
    QuizResult(QuizResult *q)
    {
        this->m_name = q->m_name;
        this->m_totalQuestions = q->m_totalQuestions;
        this->m_correctAnswers = q->m_correctAnswers;
    }

    QString getName() const;
    int getTotalQuestions() const;
    int getCorrectAnswers() const;

private:
    QString m_name;
    int m_totalQuestions;
    int m_correctAnswers;
};

class QuizWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuizWindow(QWidget *parent = nullptr);
    ~QuizWindow();

private slots:
    void on_finishBtn_clicked();
    void updateTimer();

private:
    Ui::QuizWindow *ui;
    ResultWindow *r;
    QTimer *timer;
    int question1;
    int question2;
    int question3;
    int question4;
    int question5;
    int countdownTime;
    int totalQuestion;
    int result;
    QuizResult *quizResult;
    QString formatTime(int seconds);
};

#endif // QUIZWINDOW_H

#ifndef QUIZRESULT_H
#define QUIZRESULT_H

#include <QString>

class QuizResult {
public:
    QuizResult(QString &name, int totalQuestions, int correctAnswers);
    QuizResult();
    QuizResult(QuizResult *q) {
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



#endif // QUIZRESULT_H

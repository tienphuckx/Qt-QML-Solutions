#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit ResultWindow(QWidget *parent = nullptr);
        explicit ResultWindow(QWidget *parent = nullptr, QuizResult *quizResult = nullptr);
        ~ResultWindow();

    private:
        Ui::ResultWindow *ui;
        QuizResult* quizResult;
};

#endif // RESULTWINDOW_H

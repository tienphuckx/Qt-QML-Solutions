#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/imgs/logo.png");

    if (pixmap.isNull()) {
        qDebug() << "Failed to load image.";
    } else {
        int w = ui->logo->width();
        int h = ui->logo->height();

        ui->logo->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->logo->setScaledContents(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete q;
}

bool MainWindow::checkLogin(const QString &username, const QString &pwd)
{
    if (username == "phuc" && pwd == "phuc") {
        return true;
    }
    return false;
}

void MainWindow::on_startBtn_clicked()
{
    QString username = ui->username->text();
    QString pwd = ui->password->text();

    if (username == "" || pwd == "" || username.length() < 3 || pwd.length() < 3) {
        ui->errMsg->setText("Username and password in incorrect!");
        return;
    }

    if (!checkLogin(username, pwd)) {
        ui->errMsg->setText("Username and password in incorrect!");
        return;
    }

    this->hide();
    q = new QuizWindow(this);
    q->show();
}


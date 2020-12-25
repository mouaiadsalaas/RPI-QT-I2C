#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/****************************/
/******second step***********/
/****************************/
//here we include our library
//then we go to ui and creat our buttons and slots
#include "wiringPi.h"
#include "wiringPiI2C.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void updateCaption();

private:
    Ui::MainWindow *ui;
    int timerCount=0;
    int fd=0;
    int ANOval,AN1val, AN2val, AN3val;

};

#endif // MAINWINDOW_H

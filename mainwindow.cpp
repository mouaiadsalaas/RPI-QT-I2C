#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <wiringPi.h>

const char PCF8591 = 0x48; // base address

#define AN0	0 	//LDR
#define AN1	1 	//JoyPotX
#define AN2	2 	//joyPotY
#define AN3	3	//ModPot

#define DAC	4


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    mTimer->start(5);

    wiringPiSetup();
    fd = wiringPiI2CSetup(PCF8591);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCaption()
{
    //value=digitalRead(21);
   // timerCount++;
    int ANOval,AN1val, AN2val, AN3val;

       //Read AN0 LDR
       wiringPiI2CReadReg8(fd, PCF8591 + AN0) ; // dummy read
       ANOval = wiringPiI2CReadReg8(fd, PCF8591 + AN0);
       qDebug() << "ANOval = " << ANOval ;

       //Read AN1 Xpot
       //wiringPiI2CReadReg8(fd, PCF8591 + AN1) ; // dummy read
       //AN1val = wiringPiI2CReadReg8(fd, PCF8591 + AN1);
       //qDebug() << "AN1val = " << AN1val ;

       //Read AN2 Ypot
      // wiringPiI2CReadReg8(fd, PCF8591 + AN2) ; // dummy read
       //AN2val = wiringPiI2CReadReg8(fd, PCF8591 + AN2);
       //qDebug() << "AN2val = " << AN2val ;

       //Read AN3 POT
       //wiringPiI2CReadReg8(fd, PCF8591 + AN3) ; // dummy read
       //AN3val = wiringPiI2CReadReg8(fd, PCF8591 + AN3);
       //qDebug() << "AN3val = " << AN3val ;

}

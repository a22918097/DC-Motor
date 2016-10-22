#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMutex>
#include <QMainWindow>
#include <QList>
#include <QStringList>
#include <QObject>
#include "dcmotor.h"
#include "mythread.h"
#include "opencv2/opencv.hpp"
#include "myrobot.h"
namespace Ui {
class MainWindow;
}
enum DIRECTION{
    front = 0,
    back = 1,
    leftleft = 2,
    rightright = 3
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MyRobot *myrobot;
//    dcmotor *right_dcmotor;
//    dcmotor *left_dcmotor;
    QMutex mymutex;
    QStringList command;
    QList<QStringList> commandbuffer;
    void runbuffer(int DIRECTION=0, double velocity=0 , double distance=0 , double angle=0);
    bool waitting;
    void GoForward(double distance_m, double speed);

    void GoBackward(double distance_m, double speed);

    void TurnLeft(double angle, double speed);

    void TurnRight(double angle, double speed);

    // with one wheel un-moved
    void TurnLeftOneLeg(double angle, double speed);

    void TurnRightOneLeg(double angle, double speed);
private slots:
    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_clearlog_clicked();

    void on_pushButton_initial_clicked();


    void on_pushButton_front_clicked();

    void on_pushButton_turn_left_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_turn_one_left_clicked();

    void on_pushButton_trun_one_right_clicked();

    void on_pushButton_trun_right_clicked();

    void on_pushButton_D_clicked();

    void on_pushButton_R_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_clicked();

    void on_pushButton_run_clicked();

private:
    Ui::MainWindow *ui;
    Mythread *mthread;
    //Mythread *mt;
    void checkbusy();
    bool busy;
    void stringdivide(QString s);
    QStringList temp;
    QList<QStringList> ql;
    void runpath(QList<QStringList> qsl);
    void addintobuffer(int DIRECTION=0, double velocity=0 , double distance=0 , double angle=0);
public slots:
    void docheck();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dcmotor.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    dcmotor *right_dcmotor;
    dcmotor *left_dcmotor;

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

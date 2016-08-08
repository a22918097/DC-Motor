#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_stop->setStyleSheet("color: rgb(255, 0, 0);");
    setWindowTitle("DC Motor Contorl");
//    setFixedSize(1920,1050);
    right_dcmotor = new dcmotor();
    left_dcmotor = new dcmotor();
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::GoForward(double distance_m, double speed)
{
    right_dcmotor->SetMaxVelocity(speed);
    left_dcmotor->SetMaxVelocity(-speed);
    double pi=3.14159265;
    // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
    // calibration coeffient: y = 0.9487x
    int value = static_cast<int>((4096*3.333*14)*(distance_m/0.325)/(pi)/0.9487);
//    std::cout << "value = " << value << std::endl;
    right_dcmotor->RotateRelativeDistancce(value);
    left_dcmotor->RotateRelativeDistancce(-value);
}

void MainWindow::GoBackward(double distance_m, double speed)
{
    right_dcmotor->SetMaxVelocity(-speed);
    left_dcmotor->SetMaxVelocity(speed);
    double pi=3.14159265;
    // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
    // calibration coeffient: y = 0.9487x
    int value = static_cast<int>((4096*3.333*14)*(distance_m/0.325)/(pi)/0.9487);
//    std::cout << "value = " << value << std::endl;
    right_dcmotor->RotateRelativeDistancce(-value);
    left_dcmotor->RotateRelativeDistancce(value);
}

void MainWindow::TurnLeft(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        right_dcmotor->SetMaxVelocity(speed);
        left_dcmotor->SetMaxVelocity(speed);

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487);
        right_dcmotor->RotateRelativeDistancce(value);
        left_dcmotor->RotateRelativeDistancce(value);
    }
}

void MainWindow::TurnRight(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        right_dcmotor->SetMaxVelocity(-speed);
        left_dcmotor->SetMaxVelocity(-speed);

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487);
        right_dcmotor->RotateRelativeDistancce(-value);
        left_dcmotor->RotateRelativeDistancce(-value);
    }
}

void MainWindow::TurnLeftOneLeg(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        right_dcmotor->SetMaxVelocity(speed);
        left_dcmotor->stop();

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487*2);
        right_dcmotor->RotateRelativeDistancce(value);
    }
}

void MainWindow::TurnRightOneLeg(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        right_dcmotor->stop();
        left_dcmotor->SetMaxVelocity(speed);

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487*2);
        left_dcmotor->RotateRelativeDistancce((-1)*value);
    }
}


void MainWindow::on_pushButton_left_clicked()
{
    left_dcmotor->Open(ui->comboBox_COMport_left->currentText(),ui->comboBox_baudrate_left->currentText().toInt());


    if (left_dcmotor->isOpen())
        ui->textBrowser->append(
                    "Left DC Motor: "
                    + ui->comboBox_COMport_left->currentText()
                    + " Baud:" + ui->comboBox_baudrate_left->currentText()
                    + " is opened");
    else
        ui->textBrowser->append("[Error] Left DC Motor: cannot open " +
                                ui->comboBox_COMport_left->currentText()
                                + " Baud:" + ui->comboBox_baudrate_left->currentText());
}

void MainWindow::on_pushButton_right_clicked()
{
    right_dcmotor->Open(ui->comboBox_COMport_right->currentText(),ui->comboBox_baudrate_right->currentText().toInt());
    if (right_dcmotor->isOpen())
        ui->textBrowser->append(
                    "Right DC Motor: "
                    + ui->comboBox_COMport_right->currentText()
                    + " Baud:" + ui->comboBox_baudrate_right->currentText()
                    + " is opened");
    else
        ui->textBrowser->append("[Error] Right DC Motor: cannot open " +
                                ui->comboBox_COMport_right->currentText()
                                + " Baud:" + ui->comboBox_baudrate_right->currentText());
}

void MainWindow::on_pushButton_stop_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        right_dcmotor->stop();
        left_dcmotor->stop();
        ui->textBrowser->append(QString("Stop"));
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_clearlog_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::on_pushButton_initial_clicked()
{
    ui->pushButton_left->click();
    ui->pushButton_right->click();
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        left_dcmotor->SetHome();
        right_dcmotor->SetHome();
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}



void MainWindow::on_pushButton_front_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("Go Forward %1m").arg(ui->doubleSpinBox_distance->value()));
        GoForward(ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_velocity->value());
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_turn_left_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("Turn Left %1 degrees").arg(ui->doubleSpinBox_angle->value()));
        TurnLeft(ui->doubleSpinBox_angle->value(),
                          ui->doubleSpinBox_velocity->value());
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_back_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("Go Backward %1m").arg(ui->doubleSpinBox_distance->value()));
        GoBackward(ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_velocity->value());}
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen()).arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_turn_one_left_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("One Left %1 degrees").arg(ui->doubleSpinBox_angle->value()));
        TurnLeftOneLeg(ui->doubleSpinBox_angle->value(),ui->doubleSpinBox_velocity->value());
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_trun_one_right_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("One Right %1 degrees").arg(ui->doubleSpinBox_angle->value()));
        TurnRightOneLeg(ui->doubleSpinBox_angle->value(),ui->doubleSpinBox_velocity->value());

    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_trun_right_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("Turn Right %1 degrees").arg(ui->doubleSpinBox_angle->value()));
        TurnRight(ui->doubleSpinBox_angle->value(),ui->doubleSpinBox_velocity->value());
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_D_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        right_dcmotor->D(ui->doubleSpinBox_velocity->value());
        left_dcmotor->D(ui->doubleSpinBox_velocity->value()*-1);
        ui->textBrowser->append(QString("Run"));
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_R_clicked()
{
    if (right_dcmotor->isOpen() && left_dcmotor->isOpen())
    {
        right_dcmotor->D(ui->doubleSpinBox_velocity->value()*-1);
        left_dcmotor->D(ui->doubleSpinBox_velocity->value());
        ui->textBrowser->append(QString("Run"));
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(right_dcmotor->isOpen())
                                .arg(left_dcmotor->isOpen()));
    }
}

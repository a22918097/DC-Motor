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
    myrobot = new MyRobot();
    mthread = new Mythread();

    QObject::connect(mthread, SIGNAL(checktest()), this, SLOT(docheck()));
    waitting=false;
    busy=false;
}


MainWindow::~MainWindow()
{
    ui->pushButton_stop->click();
    delete ui;
}

void MainWindow::GoForward(double distance_m, double speed)
{
    myrobot->right_dcmotor->SetMaxVelocity(speed);
    myrobot->left_dcmotor->SetMaxVelocity(-speed);
    double pi=3.14159265;
    // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
    // calibration coeffient: y = 0.9487x
    int value = static_cast<int>((4096*3.333*14)*(distance_m/0.325)/(pi)/0.9487);
    //    std::cout << "value = " << value << std::endl;
    myrobot->right_dcmotor->RotateRelativeDistancce(value);
    myrobot->left_dcmotor->RotateRelativeDistancce(-value);
}

void MainWindow::GoBackward(double distance_m, double speed)
{
    //    if(!waitting){
    myrobot->right_dcmotor->SetMaxVelocity(-speed);
    myrobot->left_dcmotor->SetMaxVelocity(speed);
    double pi=3.14159265;
    // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
    // calibration coeffient: y = 0.9487x
    int value = static_cast<int>((4096*3.333*14)*(distance_m/0.325)/(pi)/0.9487);
    //    std::cout << "value = " << value << std::endl;
    myrobot->right_dcmotor->RotateRelativeDistancce(-value);
    myrobot->left_dcmotor->RotateRelativeDistancce(value);
    waitting=true;
    //    }
    //    checkbusy();

}

void MainWindow::TurnLeft(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        myrobot->right_dcmotor->SetMaxVelocity(speed);
        myrobot->left_dcmotor->SetMaxVelocity(speed);

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487);
        myrobot->right_dcmotor->RotateRelativeDistancce(value);
        myrobot->left_dcmotor->RotateRelativeDistancce(value);
    }
}

void MainWindow::TurnRight(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        myrobot->right_dcmotor->SetMaxVelocity(-speed);
        myrobot->left_dcmotor->SetMaxVelocity(-speed);

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487);
        myrobot->right_dcmotor->RotateRelativeDistancce(-value);
        myrobot->left_dcmotor->RotateRelativeDistancce(-value);
    }
}

void MainWindow::TurnLeftOneLeg(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        myrobot->right_dcmotor->SetMaxVelocity(speed);
        myrobot->left_dcmotor->stop();

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487*2);
        myrobot->right_dcmotor->RotateRelativeDistancce(value);
    }
}

void MainWindow::TurnRightOneLeg(double angle, double speed)
{
    if (angle > 0 && angle <= 360)
    {
        myrobot->right_dcmotor->stop();
        myrobot->left_dcmotor->SetMaxVelocity(speed);

        // distance between wheels = 0.57m
        // [encoder:4096]  [motor Gearhead:14]  [wheel gear:3.333] [wheel diameter:0.325m]
        // calibration coeffient: y = 0.9487x
        int value = static_cast<int>((4096*3.333*14)*(0.57/0.325)*angle/360/0.9487*2);
        myrobot->left_dcmotor->RotateRelativeDistancce((-1)*value);
    }
}


void MainWindow::on_pushButton_left_clicked()
{
    myrobot->left_dcmotor->Open(ui->comboBox_COMport_left->currentText(),ui->comboBox_baudrate_left->currentText().toInt());


    if (myrobot->left_dcmotor->isOpen())
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
    myrobot->right_dcmotor->Open(ui->comboBox_COMport_right->currentText(),ui->comboBox_baudrate_right->currentText().toInt());
    if (myrobot->right_dcmotor->isOpen())
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
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        myrobot->right_dcmotor->stop();
        myrobot->left_dcmotor->stop();
        ui->textBrowser->append(QString("Stop"));
        waitting=false;
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
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
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        mthread->start();
        myrobot->left_dcmotor->SetHome();
        myrobot->right_dcmotor->SetHome();
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}



void MainWindow::on_pushButton_front_clicked()
{

    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {

        //GoForward(ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_velocity->value());
        command << QString::number(DIRECTION::front) << QString::number(ui->doubleSpinBox_velocity->value())
                << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(ui->doubleSpinBox_angle->value());
        commandbuffer.append(command);
        command.clear();
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }

}

void MainWindow::on_pushButton_turn_left_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {

        //        TurnLeft(ui->doubleSpinBox_angle->value(),
        //                 ui->doubleSpinBox_velocity->value());
        command << QString::number(DIRECTION::leftleft) << QString::number(ui->doubleSpinBox_velocity->value())
                << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(ui->doubleSpinBox_angle->value());
        commandbuffer.push_back(command);
        command.clear();

    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_back_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        command << QString::number(DIRECTION::back) << QString::number(ui->doubleSpinBox_velocity->value())
                << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(ui->doubleSpinBox_angle->value());
        commandbuffer.push_back(command);
        command.clear();
        //GoBackward(ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_velocity->value());
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen()).arg(myrobot->left_dcmotor->isOpen()));
    }

}

void MainWindow::on_pushButton_turn_one_left_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("One Left %1 degrees").arg(ui->doubleSpinBox_angle->value()));
        TurnLeftOneLeg(ui->doubleSpinBox_angle->value(),ui->doubleSpinBox_velocity->value());
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_trun_one_right_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        ui->textBrowser->append(QString("One Right %1 degrees").arg(ui->doubleSpinBox_angle->value()));
        TurnRightOneLeg(ui->doubleSpinBox_angle->value(),ui->doubleSpinBox_velocity->value());

    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_trun_right_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        //TurnRight(ui->doubleSpinBox_angle->value(),ui->doubleSpinBox_velocity->value());
        command << QString::number(DIRECTION::rightright) << QString::number(ui->doubleSpinBox_velocity->value())
                << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(ui->doubleSpinBox_angle->value());
        commandbuffer.push_back(command);
        command.clear();
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_D_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        myrobot->right_dcmotor->D(ui->doubleSpinBox_velocity->value());
        myrobot->left_dcmotor->D(ui->doubleSpinBox_velocity->value()*-1);
        ui->textBrowser->append(QString("Run"));
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_R_clicked()
{
    if (myrobot->right_dcmotor->isOpen() && myrobot->left_dcmotor->isOpen())
    {
        myrobot->right_dcmotor->D(ui->doubleSpinBox_velocity->value()*-1);
        myrobot->left_dcmotor->D(ui->doubleSpinBox_velocity->value());
        ui->textBrowser->append(QString("Run"));
    }
    else
    {
        ui->textBrowser->append(QString("[Error] Please Open the both dcmotor first right: %1, left: %2")
                                .arg(myrobot->right_dcmotor->isOpen())
                                .arg(myrobot->left_dcmotor->isOpen()));
    }
}

void MainWindow::on_pushButton_read_clicked()
{
    ui->textBrowser->append(myrobot->left_dcmotor->readreadread());
    ui->textBrowser->append(myrobot->right_dcmotor->readreadread());
}

void MainWindow::checkbusy()
{
    mymutex.lock();
    if(myrobot->left_dcmotor->readreadread()=="p\r\n" && myrobot->right_dcmotor->readreadread()=="p\r\n"){

        waitting=false;
        busy=false;

    }
    mymutex.unlock();
        if (!waitting && !commandbuffer.isEmpty() )
        {
            QStringList templist = commandbuffer.at(0);
            runbuffer(templist[0].toInt(),templist[1].toDouble(),templist[2].toDouble(),templist[3].toDouble());
            commandbuffer.removeAt(0);
            waitting=true;
        }
}

void MainWindow::docheck()
{
    checkbusy();
}

void MainWindow::runbuffer(int direction, double velocity, double distance, double angle)
{

    switch(direction)
    {
    //front
    case 0:
        ui->textBrowser->append(QString("Go Forward %1m").arg(distance));
        GoForward(distance,velocity);
        break;
        //back
    case 1:
        ui->textBrowser->append(QString("Go Backward %1m").arg(distance));
        GoBackward(distance,velocity);
        break;
        //left
    case 2:
        ui->textBrowser->append(QString("Turn Left %1 degrees").arg(angle));
        TurnLeft(angle,velocity);
        break;
        //right
    case 3:
        ui->textBrowser->append(QString("Turn Right %1 degrees").arg(angle));
        TurnRight(angle,velocity);
        break;
    default:
        qDebug() << "default";
        break;

    }
}

void MainWindow::on_pushButton_clicked()
{
    //往前
    command << QString::number(DIRECTION::front) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(2) << QString::number(ui->doubleSpinBox_angle->value());
    commandbuffer.append(command);
    command.clear();

    //往右
    command << QString::number(DIRECTION::rightright) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(45);
    commandbuffer.push_back(command);
    command.clear();

    //往前

    command << QString::number(DIRECTION::front) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(1) << QString::number(ui->doubleSpinBox_angle->value());
    commandbuffer.append(command);
    command.clear();



    //往左

    command << QString::number(DIRECTION::leftleft) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(90);
    commandbuffer.push_back(command);
    command.clear();

    //往前
    command << QString::number(DIRECTION::front) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(1) << QString::number(ui->doubleSpinBox_angle->value());
    commandbuffer.append(command);
    command.clear();


    //往右
    command << QString::number(DIRECTION::rightright) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(ui->doubleSpinBox_distance->value()) << QString::number(45);
    commandbuffer.push_back(command);
    command.clear();

    //往前
    command << QString::number(DIRECTION::front) << QString::number(ui->doubleSpinBox_velocity->value())
            << QString::number(2) << QString::number(ui->doubleSpinBox_angle->value());
    commandbuffer.append(command);
    command.clear();
}

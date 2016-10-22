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
        commandbuffer.clear();
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
        addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value(),ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_angle->value());
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
        addintobuffer(DIRECTION::leftleft,ui->doubleSpinBox_velocity->value(),
                      ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_angle->value());

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
        addintobuffer(DIRECTION::back,ui->doubleSpinBox_velocity->value(),
                      ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_angle->value());
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
        addintobuffer(DIRECTION::rightright,ui->doubleSpinBox_velocity->value(),
                      ui->doubleSpinBox_distance->value(),ui->doubleSpinBox_angle->value());
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
    if(myrobot->left_dcmotor->readreadread()=="p\r\n" &&  myrobot->right_dcmotor->readreadread()=="p\r\n"){

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
    addintobuffer(DIRECTION::front,1000,2,0);
    addintobuffer(DIRECTION::rightright,1000,0,45);
    addintobuffer(DIRECTION::front,1000,1,0);
    addintobuffer(DIRECTION::leftleft,1000,0,45);
    addintobuffer(DIRECTION::front,1000,1,0);
    addintobuffer(DIRECTION::leftleft,1000,0,45);
    addintobuffer(DIRECTION::front,1000,2,0);
    addintobuffer(DIRECTION::rightright,1000,0,45);
    addintobuffer(DIRECTION::front,1000,1,0);
}

void MainWindow::on_pushButton_run_clicked()
{
    QString src= "6666666666666677777776666666666666666777755555556666666";
    stringdivide(src);
    runpath(ql);
    //qDebug() << ql;
}
void MainWindow::stringdivide(QString s)
{
    int count=1;
    for(int i=0;i< s.size()-1;i++){
        if(s.at(i) == s.at(i+1))
            count++;
        else{
            temp << QString(s.at(i)) << QString::number(count);
            ql.append(temp);
            count=1;
            temp.clear();
        }
    }
    temp << QString(s.at(s.size()-1)) << QString::number(count);
    ql.append(temp);
}

void MainWindow::runpath(QList<QStringList> qsl)
{

    int degree=0;
    for(int i=0;i<qsl.size();i++)
    {
        int direction = qsl.at(i).at(0).toInt();
        int count= qsl.at(i).at(1).toInt();
        switch(direction){
        case 5:
            if(degree!=-45){
                //左轉45-degree度 直走
                degree=-45-degree;

                addintobuffer(DIRECTION::leftleft,ui->doubleSpinBox_velocity->value()
                              ,0,-degree);
                addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                              ,0.1414*count,0);
            }
            else if(degree==-45)
            {
                addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                              ,0.1414*count,0);
            }
            degree=-45;
            break;
        case 6:
            if(degree==0){
                //直接直走
                addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                              ,0.1*count,0);
            }

            else if(degree!=0){
                //先轉-degree
                degree=0-degree;
                if(degree>0)
                {
                    addintobuffer(DIRECTION::rightright,ui->doubleSpinBox_velocity->value()
                                  ,count*0.1,degree);
                    addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                                  ,0.1*count,0);
                }

                else if(degree < 0){
                    addintobuffer(DIRECTION::leftleft,ui->doubleSpinBox_velocity->value()
                                  ,0,-degree);
                    addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                                  ,0.1*count,0);
                }
            }
            degree=0;
            break;
        case 7:
            if(degree!=45){
                //右轉45-degree 直走
                degree=45-degree;
                addintobuffer(DIRECTION::rightright,ui->doubleSpinBox_velocity->value()
                              ,0,degree);
                addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                              ,0.1414*count,0);
            }
            else if(degree==45){
                //直接直走
                addintobuffer(DIRECTION::front,ui->doubleSpinBox_velocity->value()
                              ,0.1414*count,degree);
            }
            degree=45;
            break;
        default:

            break;
        }

    }
}

void MainWindow::addintobuffer(int DIRECTION, double velocity, double distance, double angle)
{
    command << QString::number(DIRECTION) << QString::number(velocity)
            << QString::number(distance) << QString::number(angle);
    commandbuffer.append(command);
    command.clear();
}

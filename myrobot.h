#ifndef MYROBOT_H
#define MYROBOT_H
#include "dcmotor.h"
#include <QObject>
class MyRobot  :public QObject
{
    Q_OBJECT
public:
    MyRobot();
    dcmotor *right_dcmotor;
    dcmotor *left_dcmotor;
};

#endif // MYROBOT_H

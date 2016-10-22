#include "mythread.h"
#include <QDebug>
Mythread::Mythread(QObject *parent)
{

}

void Mythread::run()
{
    while(1){
        emit checktest();
        msleep(500);
    }
//        if(left_dcmotor->isOpen() && right_dcmotor->isOpen())
//            if (!checkbusy() && !commandbuffer.isEmpty() )
//            {
//                QStringList templist = commandbuffer.at(0);
//                commandbuffer.pop_front();
//                runbuffer(templist[0].toInt(),templist[1].toDouble(),templist[2].toDouble(),templist[3].toDouble());
//            }
//        msleep(1000);
//        qDebug() << left_dcmotor->isOpen() << right_dcmotor->isOpen();
    //    }
}


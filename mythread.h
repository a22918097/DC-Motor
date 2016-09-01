#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QMutex>
#include <QStringList>
#include <QObject>
//#include "mainwindow.h"


class Mythread: public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = 0);
    void run();




signals:
    void checktest();
};

#endif // MYTHREAD_H

#include <QCoreApplication>
#include "Emitter.h"
#include "Reciever.h"
#include <iostream>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    Emitter e;
    Reciever r;

    QObject::connect(&e, &Emitter::emitData, &r, &Reciever::recieveData ,Qt::QueuedConnection);
    e.getName();

    return a.exec();
}

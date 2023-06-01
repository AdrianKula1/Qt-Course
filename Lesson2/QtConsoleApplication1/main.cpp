
#include <QCoreApplication>
#include "test.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test obj;
    //��cz� obj do aplikacji a. Gdy close jest emitowany, chcemy wywo�a� quit
    QObject::connect(&obj, &test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    obj.do_stuff();

    int value = a.exec();
    qInfo() << "Exit value " << value;
    return value;
}

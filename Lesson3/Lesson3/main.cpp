#include <QtCore/QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "Test.h"

Test* getTest(QObject* parent) {
    return new Test(parent);
}

Test* getTest() {
    return new Test();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);

    Test* dog = getTest(&a);
    dog->setObjectName("Ruder");

    Test* dog2 = getTest();
    dog2->setObjectName("Ruder2");
    dog2->setParent(dog);
    
    int value = a.exec();
    qInfo() << "Exit code: " << value;
    return value;
}

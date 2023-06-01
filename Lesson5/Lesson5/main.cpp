#include <QtCore/QCoreApplication>
#include <QScopedPointer>
#include <QDebug>
#include <memory>
#include "Test.h"



void testScoped(QScopedPointer<Test> &ptr) {
    ptr->message("Passed scoped ptr");

    QScopedPointer<Test> &newPtr = ptr;
    newPtr->message("copiedPtr");
}


void testShared(QSharedPointer<Test> ptr) {
    ptr->message("Passed shared ptr");
}

void TestScope() {

    QScopedPointer<Test> ptr(new Test());
    //QScopedPointer<Test> ptr2(ptr);

    ptr->message("Hello");
    testScoped(ptr);
}


void TestShare(Test *test) {
    QSharedPointer<Test> shared(test);
    shared->message("Starting");
    

    QSharedPointer<Test> shared2(shared);
    testShared(shared);
}





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestScope();
    TestShare(new Test());

    return a.exec();
}

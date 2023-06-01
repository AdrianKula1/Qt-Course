#include "Test.h"
#include <QDebug>
Test::Test(QObject* parent) : QObject(parent) {
	qInfo() << this << "Constructed!";
}

Test::~Test()
{
	qInfo() << this << "Deconstructed!";
}

void Test::message(QString message)
{
	qInfo() << this << message;
}

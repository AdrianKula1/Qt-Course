#include "Reciever.h"
#include <QDebug>


Reciever::Reciever(QObject* parent) : QObject(parent) {}

void Reciever::recieveData(int age)
{
	qInfo() << "Recieved!";
	qInfo() << "Your age is: " << age;
}

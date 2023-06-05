#include "Cat.h"
#include <QDebug>
Cat::Cat(QObject* parent) : QObject(parent) {
	qInfo() << "Cat constructed";
}

void Cat::setName(const QString &name)
{
	this->name = name;
}

void Cat::setAge(int age)
{
	this->age = age;
}

QString Cat::getName()
{
	return name;
}

int Cat::getAge()
{
	return age;
}

Cat::~Cat()
{
	qInfo() << "Cat destructed";
}

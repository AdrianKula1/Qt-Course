#include "kitten.h"
#include <QDebug>

kitten::kitten(QObject* parent) : QObject(parent) {}

void kitten::meow()
{
	qWarning() << "I'm hungry!";
}

#include "Emitter.h"
#include <QDebug>
#include <QTextStream>

Emitter::Emitter(QObject* parent) : QObject(parent) {}

void Emitter::getName()
{
	QTextStream Qin(stdin);

	qInfo() << "Hello, please state your age: ";


	QString ageStr = Qin.readLine();
	int ageInt = ageStr.toInt();

	qInfo() << "Data prepared!";
	qInfo() << "Emitting";

	emit emitData(ageInt);
}

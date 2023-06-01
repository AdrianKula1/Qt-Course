#pragma once
#include <QtCore>

class Emitter : public QObject
{
	Q_OBJECT
public:
	explicit Emitter(QObject* parent = nullptr);

	void getName();

signals:
	void emitData(int age);

};

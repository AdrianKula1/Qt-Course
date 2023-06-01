#pragma once
#include <QtCore>
class Reciever : public QObject
{
	Q_OBJECT
public:
	explicit Reciever(QObject* parent=nullptr);

signals:

public slots:
	void recieveData(int age);
};


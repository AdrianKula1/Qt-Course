#pragma once
#include <qobject.h>
#include <qdebug>
class test : public QObject
{
	Q_OBJECT
public:
	explicit test(QObject* parent = nullptr);

signals:
	void close();
	void send_data();

public slots:
	void do_stuff();
	int doStuff2();
};


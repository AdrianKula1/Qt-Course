#pragma once
#include <QObject>
#include <QString>

class Test : public QObject
{
	Q_OBJECT
public:
	explicit Test(QObject* parent = nullptr);
	~Test();


	void message(QString message = "");
signals:

public slots:
};


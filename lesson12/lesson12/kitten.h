#pragma once
#include<QObject>
class kitten : public QObject
{
	Q_OBJECT
public:
	explicit kitten(QObject* parent = nullptr);
	void meow();
signals:

public slots:
};


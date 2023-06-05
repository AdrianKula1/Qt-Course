#pragma once
#include<QObject>
class Cat : public QObject
{
	Q_OBJECT
public:
	explicit Cat(QObject* parent = nullptr);

	void setName(const QString &name);
	void setAge(int age);


	QString getName();
	int getAge();

	~Cat();
signals:

public slots:

private:
	QString name;
	int age;
};


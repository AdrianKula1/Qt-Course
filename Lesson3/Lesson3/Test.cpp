#include "Test.h"

Test::Test(QObject* parent) : QObject(parent) {
	qInfo() << this << " constructed " << parent;
}

Test::~Test(){
	for (QObject* child : children()) {
		qInfo() << this << " - child - " << child;
	}

	qInfo() << this << " destroyed. parent: " << parent();
}

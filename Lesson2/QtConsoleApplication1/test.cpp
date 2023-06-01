#include "test.h"


test::test(QObject* parent) : QObject(parent) {}

int test::doStuff2(){
	qInfo() << "Sending data";
	emit send_data();
	return 1;
}

void test::do_stuff() {
	qInfo() << "this is a slot";
	emit close();
}
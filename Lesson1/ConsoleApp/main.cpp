#include <QtCore/QCoreApplication>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>

#include <iostream>
#include <string>

void getNameCpp(std::string& name) {
    std::cout << "State name: ";
    std::cin >> name;
}

void getNameQt() {
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "State name: ";
    qout.flush();
    QString name = qin.readLine();
    qout << "Hello " << name;
    qout.flush();
}

void getNameBoth() {
    QTextStream qin(stdin);
    qInfo() << "State name: ";
    QString name = qin.readLine();
    qInfo() << "Hello " << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //std::string name;
    //getNameCpp(name);
    //std::cout << "Hello " << name << std::endl;

    //getNameQt();

    getNameBoth();
    return a.exec();
}

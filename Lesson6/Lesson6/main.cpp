#include <QtCore/QCoreApplication>
#include <QString>
#include <QDebug>
#include <iostream>

void fun() {
    
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString line("Hello world");
    qInfo() << line;

    QString line1;
    line1 = "Hello";
    qInfo() << line1;

    int pos = 10, max = 20;
    QString status = QString("Processing file %1 of %2").arg(pos).arg(max);
    qInfo() << status;

    //for (QChar c : status) {
    //    qInfo() << c;
    //}

    //for (int i = 0; i < status.length(); i++) {
    //    qInfo() << status.at(i);
    //}

    qInfo() << "Comparing " << line1.compare("Hello", Qt::CaseSensitive);
    qInfo() << "Starts " << line1.startsWith("HeL", Qt::CaseSensitive);
    qInfo() << "Ends " << line1.endsWith("lo", Qt::CaseSensitive);
    qInfo() << "contains " << line1.contains("ell", Qt::CaseSensitive);
    qInfo() << "index " << line1.indexOf("lo", Qt::CaseSensitive);


    line.append("\r\nWorld");
    qInfo() << line;

    line.replace("rl", "ad");
    qInfo() << line;

    qInfo() << line.toUpper();
    qInfo() << line.toLower();
    qInfo() << line.mid(3, 5);

    QStringList list = line.split("\n");
    foreach(QString item, list) {
        qInfo() << "item " << item.trimmed();
    }

    std::cout << line.toStdString() << std::endl;

    return a.exec();
}

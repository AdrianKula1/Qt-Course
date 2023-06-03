#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QByteArray buffer(10, '\t');
    qInfo() << buffer;

    QByteArray person(QString("Adrian").toLocal8Bit());
    qInfo() << person;

    QByteArray data;
    data.reserve(10);
    qInfo() << data;
    data.resize(10);
    qInfo() << data;

    data.truncate(8);
    qInfo() << data;

    data.clear();
    qInfo() << data;

    //Modify data

    data.resize(5);
    data.fill('\x02');
    qInfo() << data;

    data.replace(0, 1, QByteArray("Adr"));
    qInfo() << data;

    data.replace(0, 99, QByteArray("Adrian"));
    qInfo() << data;

    data.fill('*');
    qInfo() << data;

    data.insert(3, QByteArray("HellO"));
    qInfo() << data;

    data.append('!');
    qInfo() << data;

    data.remove(0, 3);
    qInfo() << data;

    //Read data

    int firstAsteriskPosition = data.indexOf('*');
    int lastAsteriskPosition = data.lastIndexOf('*');
    qInfo() << firstAsteriskPosition << " and " << lastAsteriskPosition;
    
    bool bothAsterisksExisit = firstAsteriskPosition > -1 && lastAsteriskPosition > -1;
    int length = lastAsteriskPosition - firstAsteriskPosition + 1;

    if (bothAsterisksExisit) qInfo() << data.mid(firstAsteriskPosition, length);
    
    data.clear();

    data.append("Adrian");

    for (char c : data) {
        qInfo() << c;
    }

    for (auto c : data.split('i')) {
        qInfo() << c;
    }

    return a.exec();
}

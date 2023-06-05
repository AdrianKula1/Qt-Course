#include <QtCore/QCoreApplication>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

QList<int> getNubers() {
    QList<int> list;
    list << 10 << 10 << 30;

    int random = QRandomGenerator::global()->bounded(1, 10);

    for (int i = 0; i < random; i++) {
        list.append(QRandomGenerator::global()->bounded(1, 100));
    }
    
    return list;
}
 
void listDisplay() {
    QList<int> list = getNubers();
    qInfo() << list;
    qInfo() << list.count(10);
}

void listModify() {
    QList<int> list = getNubers();
    
    list[0] = 1;
    
    list.append(2);
    list << 1000 << 1000;

    qInfo() << list;

    list.insert(0, 2);
    qInfo() << list;
        

    list.removeAt(0);
    qInfo() << list;
    list.removeOne(1000);
    qInfo() << list;
    list.removeAll(1000);
    qInfo() << list;
    list.remove(1, 2);
    qInfo() << list;
}

void listSearch() {
    QList<int> list = getNubers();
    int item=999;
    list.insert(0, item);
    list.append(item);


    int firstIndex = list.indexOf(item);
    qInfo() << firstIndex;
    
    int lastIndex = list.lastIndexOf(item);
    qInfo() << lastIndex;


    int index = list.indexOf(item);
    do {
        qInfo() << "At " << index;
        index = list.indexOf(item, index+1);
    } while (index > -1);
    
    qInfo() << list.contains(1);

    QList<int> items = list.sliced(1, 4);

    qInfo() << list;
    qInfo() << items;


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    listDisplay();

    listModify();

    listSearch();

    return a.exec();
}

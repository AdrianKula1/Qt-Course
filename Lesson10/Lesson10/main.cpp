#include <QtCore/QCoreApplication>
#include <QMap>
#include <QDebug>
#include <QRandomGenerator>
#include "Cat.h"

typedef QMap<QString, QSharedPointer<Cat>> catMap;

void displayMap(catMap &cats) {
    for (QString key : cats.keys()) {
        QSharedPointer<Cat> ptr1 = cats.value(key);
        QSharedPointer<Cat> ptr2 = cats[key];

        qInfo() << key << ptr1->getName() << ptr1->getAge() << ptr1.data();
    }
}

void modifyCat(catMap& cats, QString key) {
    if (!cats.contains(key)) {
        return;
    }

    qInfo() << "Modyfying: " << key;
    cats[key]->setAge(99);
    cats[key]->setName("Fluff");
    
    displayMap(cats);
}

void addCat(catMap& cats) {
    QSharedPointer<Cat> ptr(new Cat());
    ptr->setAge(1000);
    ptr->setName("Bonzo");

    cats.insert("Test", ptr);
    //cats["test"]=ptr;

    displayMap(cats);

}

catMap getCats() {
    catMap cats;

    for (int i = 0; i < 5; i++) {
        QSharedPointer<Cat> ptr(new Cat());
        ptr->setAge(QRandomGenerator::global()->bounded(1, 5));
        ptr->setName("Unknown");

        cats.insert("Pet" + QString::number(i), ptr);
    }

    return cats;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QMap<QString, int> lucky;
    lucky.insert(QString("Adrian"), 16);
    qInfo() << lucky;

    catMap cats = getCats();

    displayMap(cats);

    modifyCat(cats, "Pet2");

    addCat(cats);
    addCat(cats);

    if (cats.find("Test") != cats.end()) {
        qInfo() << "key found! ";
        qInfo() << cats.find("Test").key() << cats.find("Test").value();
    }

    return a.exec();
}

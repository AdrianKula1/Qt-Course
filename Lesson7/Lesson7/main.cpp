#include <QtCore/QCoreApplication>
#include <Qstring>
#include <Qstringview>
#include <Qdebug>

void readme(QString name) {
    name.insert(0, "Mr.");
    qInfo() << name;
}
void readonly(QStringView name) {
    
    qInfo() << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstName = "Adrian";
    QString lastName = "Kula";
    readme(firstName);

    
    qInfo() << firstName.data() << firstName;
    readonly(firstName);

    QString fullName = firstName + " " + lastName;

    for (QStringView part : QStringView(fullName).split(QChar(' '))) {
        qInfo() << part;

        if (part.startsWith(QStringView(firstName), Qt::CaseInsensitive)) {
            qInfo() << "Name Detected";
            readonly(part.mid(1, 3));
        }
    }

    return a.exec();
}

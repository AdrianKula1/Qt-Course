#include <QtCore/QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>
#include <QString>

void test_current() {
    qInfo() << QDir::currentPath();

    QDir dir;
    qInfo() << dir.absolutePath();
}

void testList(QString path, bool recursive = false) {
    QDir root(path);

    if (!root.exists()) {
        qWarning() << "Path not found!";
        return;
    }

    QFileInfoList list = root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);

    qInfo() << "---------------------------- ";

    for (QFileInfo file : list) {
        qInfo() << "Name: " << file.fileName();
        qInfo() << "Path: " << file.filePath();
        qInfo() << "Size: " << file.size();

        QString type = "Unknown";
        file.isDir() ? type = "Dir" : type = "File";

        if (recursive) testList(file.absoluteFilePath());

    }

}

void modify(QDir root) {

    if (root.exists("test")) {
        qInfo() << "Test folder already exists ";
        return;
    }



    if (root.mkdir("test")) {
        QDir dir("test");
        qInfo() << "Created: " << dir.absolutePath();


        if (root.rename("test", "test2")) {
            qInfo() << "\"test\" renamed to \"test2\" ";
            if (root.exists("test")) {
                if (root.rmdir("test2")) {
                    qInfo() << "\"test2\" deleted ";
                }
                else {
                    qInfo() << "\"test2\" is not empty. Cant delete ";
                }
            }
        }


    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //test_current();
    //testList(QDir::currentPath(), true);
    modify(QDir::currentPath());
    return a.exec();
}

#include <QtCore/QCoreApplication>
#include <Qdebug>
#include <QStorageinfo>

void compileTime() {
#ifdef Q_OS_WIN
    qInfo() << " Windows detected ";
#endif

#ifdef Q_OS_WIN32
    qInfo() << " Windows x32 detected ";
#endif

#ifdef Q_OS_WIN64
    qInfo() << " Windows x64 detected ";
#endif

#ifdef Q_OS_MACOS
    qInfo() << " MAC OS detected ";
#endif

#ifdef Q_OS_LINUX
    qInfo() << " Linux detected ";
#endif
}

void runTime() {
    qInfo() << "Pretty protduct name: " << QSysInfo::prettyProductName();
    qInfo() << "Machine host name: " << QSysInfo::machineHostName();
    qInfo() << "Current CPU architecture: " << QSysInfo::currentCpuArchitecture();
}

//--- Storage Details
void display(QStorageInfo &storage, QString title)
{
    qInfo() << "--" << title << "-- ";
    qInfo() << "Name:" << storage.name();
    qInfo() << "Display: " << storage.displayName(); 
    qInfo() << "Root:" << storage.isRoot();
    qInfo() << "Path" << storage.rootPath();
    qInfo() << "Device" << storage.device();
    qInfo() << "File System: " << storage.fileSystemType();
    qInfo() << "ReadOnly: " << storage.isReadOnly();
    qInfo() << "Ready: " << storage.isReady();
    qInfo() << "Size:" << storage.bytesTotal() / 1000 / 1000 << "MB";
    qInfo() << "Available: " << storage.bytesAvailable() / 1000 / 1000 << "MB";
    qInfo() << "Free:" << storage.bytesFree() / 1000 / 1000 << "MB";
    qInfo() << "‒‒‒‒‒‒‒‒‒-";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    compileTime();
    runTime();

    QStorageInfo root = QStorageInfo::root();
    display(root, QString("Root"));

    QList<QStorageInfo> devices = QStorageInfo::mountedVolumes();

    for (QStorageInfo device : devices) {
        display(device, device.name());
    }

    return a.exec();
}

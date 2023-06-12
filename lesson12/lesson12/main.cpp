#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QTextstream>
#include <iostream>
#include "kitten.h"

using namespace std;

//copied from 
//https://doc.qt.io/qt-6/qtlogging.html#QtMessageHandler-typedef

void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char* file = context.file ? context.file : "";
    const char* function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}

void test() {
    qDebug() << "test";
    qInfo() << "test";
    qWarning() << "test";
    qCritical() << "test";
    //If you use qFatal, the application will stop running
    //qFatal() << "test";

    kitten cat;
    cat.meow();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QTextStream qin(stdin);
    cout << "Starting " << endl;

    bool running = true;
    do {
        cout << "Enter a command (start, stop, test or exit)" << endl;
        QString command = qin.readLine();
        qInfo() << "You entered " << command;

        //install
        if(command.toUpper()=="START") qInstallMessageHandler(myMessageOutput);

        //uninstall
        if(command.toUpper()=="STOP") qInstallMessageHandler(0);

        //test
        if (command.toUpper() == "TEST") test();
        
        //exit the loop
        if (command.toUpper() == "EXIT") running = !running;

    } while (running);

    cout << "Finished" << endl;

    return a.exec();
}

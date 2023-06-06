#include <QtCore/QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name: " << Qt::endl;

    QString name = qin.readLine();

    qout << "You entered: " << name << '\n';
    qout << "Enter your age: \n";

    //Push all the data (standard output) to the screen
    qout.flush();

    bool ok;
    //passing ok will set the bool to tell us whether the toInt was successfull or not
    int age = qin.readLine().toInt(&ok);

    if (!ok) {
        qout << "Wrong number " << '\n';
    }else {
        qout << "Your age is : " << age << '\n';
        qout.flush();
    }

    return a.exec();
}

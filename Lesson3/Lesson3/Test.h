#pragma once
#include <qobject.h>
#include <QDebug>

class Test :
    public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject* parent=nullptr);
    ~Test();
signals:

public slots:

};


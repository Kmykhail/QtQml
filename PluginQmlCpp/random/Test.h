#pragma once

#include <QObject>
#include <QVariant>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject * parent = nullptr);

    Q_SIGNAL void status(QVariant data);
    Q_SLOT void generateRandom();
};


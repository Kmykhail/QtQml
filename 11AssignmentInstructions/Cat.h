#pragma once

#include <QObject>

class Cat: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
public:
    explicit Cat(QObject *parent=nullptr);

    QString name() const;
    Q_SIGNAL void nameChanged();
    Q_SIGNAL void meow();

    Q_SLOT void call();
    void setName(QString &name);
private:

    QString m_name;
};


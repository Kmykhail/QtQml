#include "Cat.h"
#include <QDebug>

Cat::Cat(QObject *parent) : QObject(parent)
{

}

QString Cat::name() const
{
    return m_name;
}

void Cat::setName(QString &name)
{
    m_name = name;
    emit nameChanged();
}

void Cat::call()
{
    emit meow();
}

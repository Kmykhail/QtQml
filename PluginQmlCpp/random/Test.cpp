#include "Test.h"

#include <QRandomGenerator>

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::generateRandom()
{
    int num = QRandomGenerator::global()->bounded(1000);
    emit status(QVariant(num));
}

#ifndef SORTFACTORY_H
#define SORTFACTORY_H
#include "sort.h"
#include "transaction.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include <QList>

class SortFactory
{
public:
    SortFactory(QList<Transaction *> l);
    Sort* sortChoice(QString c);

private:
    QList<Transaction*> unsorted;

};

#endif // SORTFACTORY_H

#include "sort.h"


Sort::Sort(QList<Transaction *> l)
{
    sortList = l;
}

QList<Transaction *> Sort::getList()
{
    return sortList;
}

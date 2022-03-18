#ifndef SORT_H
#define SORT_H
#include <QList>
#include "transaction.h"

class Sort
{
public:
    Sort(QList<Transaction*> l);
    QList<Transaction*> getList();
    virtual void sort() = 0;

protected:
    QList<Transaction*> sortList;

};

#endif // SORT_H

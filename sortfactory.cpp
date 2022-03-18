#include "sortfactory.h"

SortFactory::SortFactory(QList<Transaction*> l)
{
    unsorted = l;
}

Sort* SortFactory::sortChoice(QString c)
{
    if(c == "Selection Sort")
        return new SelectionSort(unsorted);
    else if(c == "Insertion Sort")
        return new InsertionSort(unsorted);
    else
        return NULL;
}

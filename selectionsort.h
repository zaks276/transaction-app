#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "sort.h"
#include "transaction.h"

class SelectionSort : public Sort
{
public:
    SelectionSort(QList<Transaction*> l);
    void sort();

private:
    int minLocation(int first, int last);
    void swap(int first, int second);
};

#endif // SELECTIONSORT_H

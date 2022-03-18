#include "selectionsort.h"

SelectionSort::SelectionSort(QList<Transaction *> l):Sort(l)
{
}

void SelectionSort::sort()
{
    int minIndex;
    int length = sortList.length();
    for (int loc = 0; loc < length - 1; loc++)
    {
        minIndex = minLocation(loc, length - 1);
        swap(loc, minIndex);
    }
}

int SelectionSort::minLocation(int first, int last)
{
    int minIndex;
    minIndex = first;
    for (int loc = first + 1; loc <= last; loc++)
        if (sortList[loc]->getAmount() < sortList[minIndex]->getAmount())
            minIndex = loc;

    return minIndex;
} //end minLocation

void SelectionSort::swap(int first, int second)
{
    Transaction* temp;
    temp = sortList[first];
    sortList[first] = sortList[second];
    sortList[second] = temp;
}//end swap

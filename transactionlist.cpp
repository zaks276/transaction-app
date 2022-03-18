#include "transactionlist.h"

TransactionList* TransactionList::instance = 0;

TransactionList::TransactionList()
{
}

TransactionList* TransactionList::getInstance()
{
    if(!instance)
        instance = new TransactionList;

    return instance;
}

void TransactionList::addToList(Transaction *t)
{
    transactionList.append(t);
}

QList<Transaction*> TransactionList::getList()
{
    return transactionList;
}





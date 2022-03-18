#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H
#include "transaction.h"

class TransactionList
{
public:
    static TransactionList* getInstance();
    void addToList(Transaction *t);
    QList<Transaction*> getList();

private:
    TransactionList();
    QList<Transaction*> transactionList;
    static TransactionList* instance;

};

#endif // TRANSACTIONLIST_H

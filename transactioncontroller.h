#ifndef TRANSACTIONCONTROLLER_H
#define TRANSACTIONCONTROLLER_H
#include "transactionlist.h"
#include "transaction.h"
#include "sortfactory.h"
#include "sort.h"

class TransactionController
{
public:
    TransactionController();
    ~TransactionController();
    void setDeposit(QDate d, QTime t, double amount);
    void setWithdrawal(QDate d, QTime t, double amount);
    bool sorting(QString c);

private:
    TransactionList* tL;
};

#endif // TRANSACTIONCONTROLLER_H

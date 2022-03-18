#include "transactioncontroller.h"
#include <QTextStream>

QTextStream out(stdout);

TransactionController::TransactionController()
{

}

TransactionController::~TransactionController()
{
    delete tL;
}

void TransactionController::setDeposit(QDate d, QTime t, double amount)
{
    Transaction *trsd = new Transaction(d,t,amount,Transaction::deposit);
    tL = TransactionList::getInstance();
    tL->addToList(trsd);
    out << trsd->toString();
    Qt::flush(out);
}

void TransactionController::setWithdrawal(QDate d, QTime t, double amount)
{
    Transaction *trsw = new Transaction(d,t,amount,Transaction::withdrawal);
    tL = TransactionList::getInstance();
    tL->addToList(trsw);
    out << trsw->toString();
    Qt::flush(out);
}

bool TransactionController::sorting(QString c)
{
    tL = TransactionList::getInstance();
    QList<Transaction*> list = tL->getList();

    SortFactory sF(list);

    Sort* sAlgorithm = sF.sortChoice(c);

    if(sAlgorithm == NULL)
        return false;

    sAlgorithm->sort();

    out << c << Qt::endl;

    foreach (Transaction* tr, sAlgorithm->getList())
    {
        out << tr->toString();
        Qt::flush(out);
    }
    return true;
}


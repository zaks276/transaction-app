#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDate>
#include <QTime>
#include <QString>


class Transaction
{
public:
    enum transactionType{deposit, withdrawal};
    Transaction();
    Transaction(QDate d, QTime t, double amt, transactionType trnsType);
    double getAmount();
    QDate getDate();
    QTime getTime();
    transactionType getTransType();
    QString enumToString(transactionType trns);
    transactionType stringToEnum(QString trnsType);
    QString toString();

private:
    QDate date;
    QTime time;
    double amount;
    transactionType tType;
};

#endif // TRANSACTION_H

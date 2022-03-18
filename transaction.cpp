#include "transaction.h"
#include <QTextStream>

Transaction::Transaction()
{
}

Transaction::Transaction(QDate d, QTime t, double amt, transactionType trnstype)
{
    date = d;
    time = t;
    amount = amt;
    tType = trnstype;
}

QString Transaction::enumToString(transactionType trns)
{
   QString outString;

   switch(trns){
     case deposit:
       outString = "Deposit";
       break;
     case withdrawal:
       outString = "Withdrawal";
       break;
   }
   return outString;
}

Transaction::transactionType Transaction::stringToEnum(QString trnsType)
{
    transactionType trns;

    if(trnsType == "Deposit")
        trns = Transaction::deposit;
    else if(trnsType == "Withdrawal")
        trns = Transaction::withdrawal;

    return trns;
}

QString Transaction::toString()
{
    QString output;
    output.append(enumToString(tType));
    output.append(": R");
    output.append(QString::number(amount));
    output.append(" on ");
    output.append(date.toString());
    output.append(" at ");
    output.append(time.toString());
    output.append("\n");
    return output;
}

double Transaction::getAmount()
{
    return amount;
}

QDate Transaction::getDate()
{
    return date;
}

QTime Transaction::getTime()
{
    return time;
}

Transaction::transactionType Transaction::getTransType()
{
    return tType;
}

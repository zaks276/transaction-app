#include "xmlfilewriter.h"
#include <QFile>
#include <QTextStream>

XMLFileWriter::XMLFileWriter()
{
    rootElement = doc.createElement("TransactionList");
    doc.appendChild(rootElement);
}

XMLFileWriter::~XMLFileWriter()
{
    delete trnL;
}

bool XMLFileWriter::writeToFile()
{
    trnL = TransactionList::getInstance();
    QList<Transaction*> list = trnL->getList();

    QFile file("transactions.xml");
    if(!file.open(QIODevice::Append))
        return false;

    QTextStream output(&file);
    foreach(Transaction *tranf, list)
    {
        QDomElement transaction = doc.createElement("transaction");

        QDomElement date = doc.createElement("date");
        QDomText dateText = doc.createTextNode(tranf->getDate().toString());

        QDomElement time = doc.createElement("time");
        QDomText timeText = doc.createTextNode(tranf->getTime().toString());

        QDomElement amount = doc.createElement("amount");
        QDomText amountText = doc.createTextNode(QString::number(tranf->getAmount()));

        QDomElement type = doc.createElement("type");
        QDomText typeText = doc.createTextNode(tranf->enumToString(tranf->getTransType()));

        rootElement.appendChild(transaction);

        transaction.appendChild(date);
        date.appendChild(dateText);

        transaction.appendChild(time);
        time.appendChild(timeText);

        transaction.appendChild(amount);
        amount.appendChild(amountText);

        transaction.appendChild(type);
        type.appendChild(typeText);
    }

    output << doc.toString();

    file.close();
    return true;
}

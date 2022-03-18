#ifndef XMLFILEWRITER_H
#define XMLFILEWRITER_H
#include <QDomDocument>
#include <QDomElement>
#include "transactionlist.h"

class XMLFileWriter
{
public:
    XMLFileWriter();
    ~XMLFileWriter();
    bool writeToFile();

private:
    QDomDocument doc;
    QDomElement rootElement;
    TransactionList* trnL;
};

#endif // XMLFILEWRITER_H

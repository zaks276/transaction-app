#include "bankingtransactions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BankingTransactions w;
    w.show();

    return a.exec();
}

#ifndef BANKINGTRANSACTIONS_H
#define BANKINGTRANSACTIONS_H
#include "transactioncontroller.h"
#include "xmlfilewriter.h"

#include <QMainWindow>

namespace Ui {
class BankingTransactions;
}

class BankingTransactions : public QMainWindow
{
    Q_OBJECT

public:
    explicit BankingTransactions(QWidget *parent = 0);
    ~BankingTransactions();

private slots:
    void depositClick();
    void withdrawalClick();
    void toFileClick();
    void sortClick();

private:
    Ui::BankingTransactions *ui;
    TransactionController tC;
    XMLFileWriter writer;
};

#endif // BANKINGTRANSACTIONS_H

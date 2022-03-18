#include "bankingtransactions.h"
#include "ui_bankingtransactions.h"
#include "transactioncontroller.h"
#include <QDate>
#include <QTextStream>
#include <QMessageBox>

QTextStream output(stdout);

BankingTransactions::BankingTransactions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BankingTransactions)
{
    ui->setupUi(this);
    ui->currentDateLabel->setText(QDate::currentDate().toString());
    connect(ui->depositButton, SIGNAL(clicked()), this, SLOT(depositClick()));
    connect(ui->withdrawalButton, SIGNAL(clicked()), this, SLOT(withdrawalClick()));
    connect(ui->toFileButton, SIGNAL(clicked()), this, SLOT(toFileClick()));
    connect(ui->sortButton, SIGNAL(clicked()), this, SLOT(sortClick()));
}

BankingTransactions::~BankingTransactions()
{
    delete ui;
}

void BankingTransactions::depositClick()
{
    double aDeposit;
    aDeposit = (ui->amountSpinBox->value());
    tC.setDeposit(QDate::currentDate(),QTime::currentTime(),aDeposit);
    ui->amountSpinBox->setValue(0.00);
    ui->amountSpinBox->setFocus();
}

void BankingTransactions::withdrawalClick()
{
    double aWithdrawal;
    aWithdrawal = (ui->amountSpinBox->value());
    tC.setWithdrawal(QDate::currentDate(),QTime::currentTime(),aWithdrawal);
    ui->amountSpinBox->setValue(0.00);
    ui->amountSpinBox->setFocus();

}

void BankingTransactions::toFileClick()
{
    bool done = writer.writeToFile();
    if (done)
        QMessageBox::information(this, "Banking Transactions", "Transaction history has been saved");
    else
        QMessageBox::critical(this, "Banking Transactions", "Transaction history has not been saved");
}

void BankingTransactions::sortClick()
{
    bool done = tC.sorting(ui->sortComboBox->currentText());
    if(done)
        QMessageBox::information(this, "Banking Transactions", "Sorting completed successfully");
    else
        QMessageBox::critical(this, "Banking Transactions", "Sorting failed");
}

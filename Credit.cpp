#include "Credit.h"
#include "Date.h"

#include <fstream>
#include <string>
#include <utility>
using namespace std;

Credit::Credit(string c, BankAccount *b, float m) : Transaction(move(c),m), account (b) { }

void Credit::doTransaction() {
    if (account->checkBankCredit() == 0)
        account->setAvailableBalance(account->getAvailableBalance() + amount);
    else {
        account->fillBankCredit(amount);
    }

    auto file = new fstream (account->getHistorical(), ios::app);
    auto date = new Date;

    *file<<"++++ ACCREDITO - Operazione n: "<<numberTransaction<<endl;
    *file<<"     Importo: "<<amount<<" $"<<endl;
    *file<<"     Causale: "<<causal<<endl;
    *file<<"     Data contabile: "<<date->getCurrentDate()<<endl;
    *file<<endl;
    file->close();

    delete date;
    delete file;

    account->printAvailableBalance();
    account->printRealBankCredit();
}

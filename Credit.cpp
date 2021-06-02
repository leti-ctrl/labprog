#include "Credit.h"


#include <fstream>
#include <string>
#include <utility>
using namespace std;

Credit::Credit(string c, BankAccount* a, float m) : Transaction(move(c),m) , account(a) { }

void Credit::doTransaction() {

    if (account->checkBankCredit() == 0)
        account->setAvailableBalance(account->getAvailableBalance() + amount);
    else {
        account->fillBankCredit(amount);
    }

    auto file = new fstream (account->getHistorical(), ios::app);

    *file<<"++++ ACCREDITO - Operazione n: "<<numberTransaction<<endl;
    *file<<"     Importo: "<<amount<<" $"<<endl;
    *file<<"     Causale: "<<causal<<endl;
    *file<<"     Data contabile: "<<dateTransaction->getCurrentDate() <<endl;
    *file<<endl;
    file->close();

    delete file;

    account->printAvailableBalance();
    account->printRealBankCredit();
}

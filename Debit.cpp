#include "Debit.h"

#include <string>
#include <utility>
#include <fstream>
using namespace std;

Debit::Debit(string c, float m, BankAccount* a) : Transaction (move(c),m), account(a) { }

void Debit::doTransaction() {

    auto file = new fstream (account->getHistorical(), ios::app);
    int legal = account->isLegalTransaction(amount);

    if (legal == 0){
        *file <<"---- ADDEBITO - Operazione n: "<<numberTransaction<<endl;
        *file <<"     Importo: "<<amount<<" $"<<endl;
    }
    else
        *file <<"-ERROR- ADDEBITO - Operazione n: -"<<amount<<" $  -FALLITO- "<<endl;

    *file <<"     Causale: "<<causal<<endl;
    *file <<"     Data contabile: "<<dateTransaction->getCurrentDate()<<endl;
    *file<<endl;
    file->close();

    delete file;

    account->printAvailableBalance();
    account->printRealBankCredit();
}


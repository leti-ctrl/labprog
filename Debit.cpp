#include "Debit.h"
#include "Date.h"

#include <string>
#include <utility>
#include <fstream>
using namespace std;

Debit::Debit(string c, BankAccount* b, float m) : Transaction (move(c),m), account (b) { }

void Debit::doTransaction() {

    auto file = new fstream (account->getHistorical(), ios::app);
    auto date = new Date;
    int legal = account->isLegalTransaction(amount);

    if (legal == 0){
        *file <<"---- ADDEBITO - Operazione n: "<<numberTransaction<<endl;
        *file <<"     Importo: "<<amount<<" $"<<endl;
    }
    else
        *file <<"-ERROR- ADDEBITO - Operazione n: -"<<amount<<" $  -FALLITO- "<<endl;

    *file <<"     Causale: "<<causal<<endl;
    *file <<"     Data contabile: "<<date->getCurrentDate()<<endl;
    *file<<endl;
    file->close();
    delete date;
    delete file;

    account->printAvailableBalance();
    account->printRealBankCredit();
}


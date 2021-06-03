#include "BankAccount.h"

#include "Date.h"
#include "BankTransfer.h"
#include "Credit.h"
#include "Debit.h"

#include<iostream>
#include<cstdlib>
#include <fstream>
#include <utility>
using namespace std;

BankAccount::BankAccount(string s, string t, float a, float b):
        owner(move(s)), type(move(t)), availableBalance(a), bankCredit(b), realBankCredit (b) {

    //crea in modo random il numero del cc
    numberAccount = rand()%100000000+10000000;

    numberTransaction = 0;

    historical = new char [10];
    sprintf(historical, "%d" , numberAccount);

    //inizializza lo storico
    auto file = new fstream (historical, ios::out);
    auto date = new Date;
    *file << "########## Conto corrente numero: " << getNumberAccount() <<" ##########"<< endl;
    *file << "Proprietario: " << owner << endl;
    *file << "Scopo di utilizzo del C/C: "<< type << endl;
    *file << "Data di apertura: " << date->getCurrentDate() << endl;
    *file << "Fido massimo: " << getBankCredit() << endl;
    *file << endl;
    file->close();
    delete date;
    delete file;
}

BankAccount::~BankAccount() {
    delete historical;

    for (int i = 0; i<numberTransaction; i++)
        delete listTransaction [i];
}

const string &BankAccount::getOwner() const {
    return owner;
}

int BankAccount::getNumberAccount() const {
    return numberAccount;
}

float BankAccount::getAvailableBalance() const {
    return availableBalance;
}

void BankAccount::setAvailableBalance(float a) {
    BankAccount::availableBalance = a;
}


float BankAccount::getBankCredit() const {
    return bankCredit;
}

float BankAccount::getRealBankCredit() const {
    return realBankCredit;
}


int BankAccount::isLegalTransaction(float money) {
    //controlla se è possibile effettuare una transazione qualsiasi, cioè se c'è abbastanza denaro
    //ritorna 0 se è possibile prelevare i soldi dal saldo oppure se è possibile prelevare i soldi dal fido;
    //ritorna 1 se non è possibile fare tale operazione

    if (availableBalance >= money){
        availableBalance -= money;
        return 0;
    }
    else if (realBankCredit + availableBalance >= money) {
        float dif = money - availableBalance;
        availableBalance = 0;
        realBankCredit -= dif;
        return 0;
    }
    else
        return 1;
}

int BankAccount::checkBankCredit() {
    //controlla il fido per capire, poi, dove andare a mettere i soldi in entrata
    //ritorna 0 se il fido è massimo, altrimenti torna 1
    //a questo punto devo chiamare pfillBankCredit per capire dove mettere i soldi

    if (realBankCredit == bankCredit)
        return 0;
    else
        return 1;

}

void BankAccount::fillBankCredit(float money) {
    //dopo aver controllato se il fido non è massimo, sistema i soldi in ingresso distinguendo due casi:
    //se money riesce, al massimo, a riempire il fido
    //se money riesce a riempire il fido e avanzano anche dei soldi, che andranno sul saldo

    if (money+realBankCredit > bankCredit) {
        float dif = bankCredit - realBankCredit;
        realBankCredit = bankCredit;
        availableBalance += money - dif;
    }

    else
        realBankCredit += money;
}

void BankAccount::printAvailableBalance() {
    auto file = new fstream (historical, ios::app);
    *file<< "     Saldo: "<<getAvailableBalance()<<" $"<<endl;
    file->close();
    delete file;
}

void BankAccount::printRealBankCredit() {
    auto file = new fstream (historical, ios::app);
    *file<< "     Fido: "<<getRealBankCredit()<<" $"<<endl;
    *file<<endl;
    file->close();
    delete file;
}

char *BankAccount::getHistorical() const {
    return historical;
}

void BankAccount::checkNumberTransaction() {
    if (numberTransaction == MAX_NUM_TRANSACTION){
        delete listTransaction[0];
        for (int i = 0; i < MAX_NUM_TRANSACTION ; i++)
            listTransaction [i] = listTransaction [i+1];
        numberTransaction -= 1;
    }
}

void BankAccount::doBankTransfer(string causal, float amount, BankAccount *recipient) {
    checkNumberTransaction();

    string c;
    c.assign(causal);

    listTransaction[numberTransaction] = new BankTransfer (move(causal), amount, this, recipient);
    recipient->setListTransaction(new BankTransfer (move(c), amount, this, recipient));
    listTransaction[numberTransaction]->doTransaction();

    numberTransaction += 1;
}

void BankAccount::doCredit(string causal, float amount) {
    checkNumberTransaction();

    listTransaction[numberTransaction] = new Credit (move(causal), amount, this);
    listTransaction[numberTransaction]->doTransaction();

    numberTransaction += 1;
}

void BankAccount::doDebit(string causal, float amount) {
    checkNumberTransaction();

    listTransaction[numberTransaction] = new Debit (move(causal) , amount , this);
    listTransaction[numberTransaction]->doTransaction();

    numberTransaction += 1;
}

void BankAccount::setListTransaction(Transaction *transaction) {
    checkNumberTransaction();

    listTransaction[numberTransaction] = transaction;
    numberTransaction++;
}

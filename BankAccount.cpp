//
// Created by letiz on 19/05/2021.
//

#include "BankAccount.h"

#include<iostream>
#include<cstdlib>
#include <cstring>
using namespace std;

BankAccount::BankAccount(const char *n, const char *s, float a, float b) :
                        name(n) , surname (s), availableBalance(a), bankCredit(b) , realBankCredit(b){

    //crea in modo random il numero del cc
    numberAccount = rand()%1000000000000+100000000000;

    //crea la stringa per dare il nome al cc
    strcpy(owner,surname);
    strcat(owner,name);

    //inizializza lo storico
    historical.open(owner, ios::out);
    historical << "### Conto corrente di: " << getName() << " " << getSurname() << endl;
    historical << "    Numero: " << getNumberAccount() << endl;
    historical << "    Fido massimo: " << getBankCredit() << endl;
    historical << endl;
    historical.close();
}

const char *BankAccount::getName() const {
    return name;
}

const char *BankAccount::getSurname() const {
    return surname;
}

const char *BankAccount::getOwner() const {
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


void BankAccount::readHistory() {
    //legge lo storico riga per riga

    historical.open(owner, ios::in);
    char ch;
    while(!historical.eof())
    {
        historical.get(ch);
        cout << ch;
    }

    historical.close();
}

int BankAccount::isLegalTransaction(float money) {
    //controlla se è possibile effettuare una transazione qualsiasi, cioè se c'è abbastanza denaro
    //ritorna 0 se è possibile prelevare i soldi dal saldo,
    //ritorna 0 se è possibile prelevare i soldi dal fido;
    //ritorna 1 se non è possibile fare tale operazione

    if (availableBalance >= money){
        availableBalance -= money;
        return 0;
    }
    else if (realBankCredit >= money) {
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

void BankAccount::setRealBankCredit(float r) {
    BankAccount::realBankCredit = realBankCredit;
}

void BankAccount::printAvailableBalance() {
    historical.open(owner, ios::app);
    historical<< "     Saldo: "<<getAvailableBalance()<<" $"<<endl;
    historical.close();
}

void BankAccount::printRealBankCredit() {
    historical.open(owner, ios::app);
    historical<< "     Fido: "<<getRealBankCredit()<<" $"<<endl;
    historical.close();
}





#include "Customer.h"

#include "Date.h"

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

Customer::Customer(string n, string s, int day, int month, int year, string place) {

    name = move(n);
    surname = move(s);
    numberBA = 0;

    fileBA = new char [20];
    sprintf(fileBA, "%s %s", name.c_str(), surname.c_str());

    auto file = new fstream (fileBA, ios::out);
    *file << "###############              " << fileBA << "              ###############" << endl;
    *file << "Nato a " << place << " il " << day << "/" << month << "/" << year <<endl;
    *file << endl;
    *file <<"LISTA DEI CONTI INTESTATI: "<<endl;
    file->close();
    delete file;
}

Customer::Customer(string n, const string& pIVA) {

    name = move(n);
    surname = " ";
    numberBA = 0;

    fileBA = new char [20];
    sprintf(fileBA, "%s", name.c_str());

    auto file = new fstream (fileBA, ios::out);
    *file << "###############              " << fileBA << "              ###############" << endl;
    *file << "Partita IVA: "<< pIVA << endl;
    *file << endl;
    *file <<"LISTA DEI CONTI INTESTATI: " << endl;
    file->close();
    delete file;
}

Customer::~Customer() {
    delete fileBA;

    for (int i = 0; i < numberBA; i++)
        delete listBA[i];
}

void Customer::checkNumberBankAccount() {
    if (numberBA == MAX_BANK_ACCOUNT){
        delete listBA[0];
        for (int i = 0; i < MAX_BANK_ACCOUNT; i++)
            listBA [i] = listBA [i + 1];
        numberBA -= 1;
    }
}

void Customer::createBankAccount(float m) {
    //distinguo se sto creando un cc per un azienda o per una persona fisica,
    //in questo modo posso dare due fido diversi e tipi di cc diversi.
    if (surname == " ") { // creo un cc per un azienda
        string type [4] = {"Gestione stipendi", "Spese aziendali", "Fornitori", "Clienti"};
        float fido = 10000;

        int choose = rand()%4;

        checkNumberBankAccount();
        listBA[numberBA] = new BankAccount (name, type[choose], m, fido);
        addAccountToList(type[choose]);
        numberBA++;
    }
    else{ // crea un cc per una persona fisica.
        string type [4] = {"Personale", "Lavoro", "Figli* minorenne", "Acquisti online"};
        float fido = 1000;

        int choose = rand()%4;

        checkNumberBankAccount();
        listBA[numberBA] = new BankAccount (name, type[choose], m, fido);
        addAccountToList(type[choose]);
        numberBA++;
    }
}

BankAccount *Customer::getAccount() {
    cout<<"############# "<<name<<endl;
    cout<< "# Selezionare il cc desiderato: "<< endl;
    int choose = MAX_BANK_ACCOUNT;

    while (choose >= MAX_BANK_ACCOUNT) {
        for (int i = 0; i < numberBA; i++) {
            cout<< "# Premere " << i << " per il conto " << listBA[i]->getNumberAccount() << endl;
            cout<< "#    - Saldo: " << listBA[i]->getAvailableBalance() << " $" << endl;
        }
        cin >> choose;
    }
    cout<<"##########################"<<endl;

    return listBA[choose];
}

void Customer::addAccountToList(string t) {
    auto file = new fstream (fileBA, ios::app);
    *file<<"# " << numberBA+1 << "   Conto numero: "<< listBA[numberBA]->getNumberAccount() << endl;
    *file<<"        Tipo: " << t << endl;
    *file<<"        Saldo: " << listBA[numberBA]->getAvailableBalance() << endl;
    *file<<endl;
    file->close();
    delete file;
}

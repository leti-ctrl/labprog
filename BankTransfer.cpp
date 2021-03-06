#include "BankTransfer.h"

#include <fstream>
#include <string>
#include <utility>
using namespace std;

BankTransfer::BankTransfer(string c,  float m, BankAccount* s, BankAccount* r):
Transaction(move(c), m), sender(s), recipient(r) {}

void BankTransfer::doTransaction() {
    //apre lo storico dei cc
    auto fileSender = new fstream (sender->getHistorical(), ios::app);
    auto fileRecipient = new fstream (recipient->getHistorical(), ios::app);

    //sistema i soldi al mittente
    int legal = sender->isLegalTransaction(amount);

    //sistema gli storici
    if (legal == 0) {

        //sistema i soldi al destinatario
        if (recipient->checkBankCredit() == 0)
            recipient->setAvailableBalance(recipient->getAvailableBalance() + amount);
        else {
            recipient->fillBankCredit(amount);
        }

        *fileSender << "---- BONIFICO - Operazione n: " << numberTransaction << endl;

        *fileRecipient << "++++ BONIFICO - Operazione n: " << numberTransaction <<
                       " di " << sender->getOwner() << " conto numero: " << sender->getNumberAccount() << endl;

    }

    else {
        *fileSender << "-ERROR- BONIFICO IN USCITA - Operazione n: " << numberTransaction << endl;

        *fileRecipient << "-ERROR- BONIFICO IN ENTRATA - Operazione n: " << numberTransaction << endl;

    }

    *fileSender << "     Intestato a " << recipient->getOwner()<<" sul conto " << recipient->getNumberAccount()<<endl;
    *fileSender << "     Causale: " << causal << endl;
    *fileSender << "     Importo: " << amount << " $" << endl;
    *fileSender << "     Data contabile: " << dateTransaction->getCurrentDate() << endl;
    *fileSender << endl;
    fileSender->close();
    delete fileSender;

    *fileRecipient << "     Causale: " << causal << endl;
    *fileRecipient << "     Importo: " << amount << " $" << endl;
    *fileRecipient << "     Data contabile: " << dateTransaction->getCurrentDate() << endl;
    *fileRecipient << endl;
    fileRecipient->close();
    delete fileRecipient;


    sender->printAvailableBalance();
    sender->printRealBankCredit();

    recipient->printAvailableBalance();
    recipient->printRealBankCredit();
}

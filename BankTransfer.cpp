#include "BankTransfer.h"

BankTransfer::BankTransfer(BankAccount *s, BankAccount *r, float m) : sender(s), recipient(r), money(m) {

    //genera il numero della transazione
    number = rand()%1000+100;

    //apre lo storico dei cc
    fstream hsend (sender->getOwner(), ios::app);
    fstream hrec (recipient->getOwner(), ios::app);


    //sistema i soldi al mittente
    int legal = sender->isLegalTransaction(money);

    //sistema gli storici
    if (legal == 0) {
        
        //sistema i soldi al destinatario
        if (recipient->checkBankCredit() == 0)
            recipient->setAvailableBalance(recipient->getAvailableBalance() + money);
        else {
            recipient->fillBankCredit(money);
        }

        hsend<<"---- Bonifico in uscita n: "<<number<<endl;
        hsend<<"     A "<<recipient->getName()<<" "<<recipient->getSurname()<<" : -"<<money<<" $"<<endl;

        hrec<<"++++ Bonifico in entrata n: "<<number<<endl;
        hrec<<"     Da "<<sender->getName()<<" "<< sender->getSurname()<<" : +"<<money<<" $"<<endl;
    }

    else {
        hsend << "ERR- Bonifico in uscita : -" << money << " $  -FALLITO- " << endl;
        hsend << "     A " << recipient->getName() << " " << recipient->getSurname() << " : -" << money << " $" << endl;

        hrec<<"ERR- Bonifico in entrata n: "<<number<<endl;
        hrec<<"     Da "<<sender->getName()<<" "<< sender->getSurname()<<" : +"<<money<<" $"<<endl;
    }

    hsend.close();
    hrec.close();

    sender->printAvailableBalance();
    sender->printRealBankCredit();

    recipient->printAvailableBalance();
    recipient->printRealBankCredit();

}

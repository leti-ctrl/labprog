#include "ATM.h"

ATM::ATM(BankAccount* b, float m) : account (b), money(m){
  
    fstream a (account->getOwner(), ios::app);
  
    int legal = account->isLegalTransaction(money);
  
    if (legal == 0)
        a<<"---- Prelievo ATM : -"<<money<<" $"<<endl;
    else
        a<<"ERR- Prelievo ATM : -"<<money<<" $  -FALLITO- "<<endl;

    a.close();

    account->printAvailableBalance();
    account->printRealBankCredit();
}

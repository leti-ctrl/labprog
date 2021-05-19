#include "Credit.h"

Credit::Credit(BankAccount *b, float m) : account (b), money(m){

    if (account->checkBankCredit() == 0)
        account->setAvailableBalance(account->getAvailableBalance() + money);
    else {
        account->fillBankCredit(money);
    }

    fstream a (account->getOwner(), ios::app);
    a<<"++++ Accredito: +"<<money<<" $"<<endl;
    a.close();

    account->printAvailableBalance();
    account->printRealBankCredit();
}

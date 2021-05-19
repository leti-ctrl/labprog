#ifndef LABPROG_BANKACCOUNT_H
#define LABPROG_BANKACCOUNT_H

#include <fstream>
using namespace std;

class BankAccount {

public:
    BankAccount(const char* n, const char* s, float a = 0, float b = 1000);

    const char *getName() const;
    const char *getSurname() const;
    const char *getOwner() const;

    int getNumberAccount() const;

    float getAvailableBalance() const;
    void setAvailableBalance(float a);
    void printAvailableBalance();

    float getBankCredit() const;
    float getRealBankCredit() const;
    void setRealBankCredit(float r);
    void printRealBankCredit ();

    int isLegalTransaction (float money);
    int checkBankCredit ();
    void fillBankCredit (float money);
    
    void readHistory ();

private:
    const char* name;
    const char* surname;
    char owner [50];
    int numberAccount;
    float availableBalance;
    const float bankCredit;
    float realBankCredit;

    fstream historical;
};


#endif //LABPROG_BANKACCOUNT_H

#ifndef LABPROG_ATM_H
#define LABPROG_ATM_H


#include "BankAccount.h"

class ATM {
public:

    ATM (BankAccount* b, float m);

private:
    BankAccount* account;
    float money;
};


#endif //LABPROG_ATM_H

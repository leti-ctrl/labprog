#ifndef LABPROG_CREDIT_H
#define LABPROG_CREDIT_H

#include "BankAccount.h"

class Credit {
public:

    Credit (BankAccount* b, float m);

private:
    BankAccount* account;
    float money;
};

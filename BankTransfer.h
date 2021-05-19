//
// Created by letiz on 19/05/2021.
//

#ifndef LABPROG_BANKTRANSFER_H
#define LABPROG_BANKTRANSFER_H

#include "BankAccount.h"

class BankTransfer {
public:

    BankTransfer (BankAccount* s, BankAccount* r, float m);

private:
    int number;
    BankAccount* sender;
    BankAccount* recipient;
    float money;
};


#endif //LABPROG_BANKTRANSFER_H

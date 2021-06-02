#include "Transaction.h"
#include "Date.h"

#include <cstdlib>
#include <string>
#include <utility>
using namespace std;

Transaction::Transaction(string c, float a) {
    causal = move (c);
    amount = a;
    numberTransaction = rand()%10000+1000;
    dateTransaction = new Date();
}

Transaction::Transaction(const Transaction &copy) {
    numberTransaction = copy.getNumberTransaction();
    causal = copy.getCausal();
    amount = copy.getAmount();
    dateTransaction = copy.getDateTransaction();
}

Transaction::~Transaction() {
    delete dateTransaction;
}

long Transaction::getNumberTransaction() const {
    return numberTransaction;
}

const string &Transaction::getCausal() const {
    return causal;
}

float Transaction::getAmount() const {
    return amount;
}

Date *Transaction::getDateTransaction() const {
    return dateTransaction;
}



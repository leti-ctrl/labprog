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

Transaction::~Transaction() {
    delete dateTransaction;
}

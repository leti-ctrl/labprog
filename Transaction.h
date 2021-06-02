#include "Date.h"

#include <string>
using namespace std;

class Transaction {
public:

    explicit Transaction (string c, float a);
    Transaction (const Transaction& copy);
    virtual ~Transaction();

    virtual void doTransaction () = 0;

protected:
    long int numberTransaction;
    string causal;
    float amount;
    Date* dateTransaction;
};

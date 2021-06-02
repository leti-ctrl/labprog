#include "Date.h"

#include <string>
using namespace std;

class Transaction {
public:

    explicit Transaction (string c, float a);
    Transaction (const Transaction& copy);
    virtual ~Transaction();

    long getNumberTransaction() const;
    const string &getCausal() const;
    float getAmount() const;
    Date *getDateTransaction() const;

    virtual void doTransaction () = 0;

protected:
    long int numberTransaction;
    string causal;
    float amount;
    Date* dateTransaction;
};

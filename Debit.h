#include "BankAccount.h"
#include "Transaction.h"

#include <string>
using namespace std;

class Debit : public Transaction {
public:

    Debit (string c, float m, BankAccount* a);
    ~Debit() override = default;

    void doTransaction () override;

private:
    BankAccount* account;
};

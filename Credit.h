#include "BankAccount.h"
#include "Transaction.h"

#include <string>
using namespace std;

class Credit : public Transaction {
public:

    Credit (string c, BankAccount* b, float m);
    ~Credit() override = default;

    void doTransaction () override;

private:
    BankAccount* account;
};

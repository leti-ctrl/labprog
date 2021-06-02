#include "BankAccount.h"
#include "Transaction.h"

#include <string>
using namespace std;

class Credit : public Transaction {
public:

    Credit (string c, float m, BankAccount* a);
    ~Credit() override = default;

    void doTransaction () override;

private:
    BankAccount* account;
};

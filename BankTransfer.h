#include "BankAccount.h"
#include "Transaction.h"

#include <string>
using namespace std;

class BankTransfer : public Transaction {
public:

    BankTransfer (string c, float m, BankAccount* s, BankAccount* r);
    ~BankTransfer() override = default;

    void doTransaction () override;

private:
    BankAccount* sender;
    BankAccount* recipient;
};

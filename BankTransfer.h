#include "BankAccount.h"
#include "Transaction.h"

#include <string>
using namespace std;

class BankTransfer : public Transaction {
public:

    BankTransfer (string c, BankAccount* s, BankAccount* r, float m);
    ~BankTransfer() override = default;

    void doTransaction () override;

private:
    BankAccount* sender;
    BankAccount* recipient;
};

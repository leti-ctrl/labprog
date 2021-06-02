#include <string>
using namespace std;

static const int MAX_NUM_TRANSACTION = 50;


#include "Transaction.h"

class BankAccount {

public:
    explicit BankAccount(string s, string t, float a = 0, float b = 1000);
    ~BankAccount();

    const string &getOwner() const;
    char *getHistorical() const;
    int getNumberAccount() const;

    float getAvailableBalance() const;
    void setAvailableBalance(float a);
    void printAvailableBalance();

    float getBankCredit() const;
    float getRealBankCredit() const;
    void printRealBankCredit ();

    int isLegalTransaction (float money);
    int checkBankCredit ();
    void fillBankCredit (float money);

    void checkNumberTransaction ();
    void doBankTransfer (string causal, float amount, BankAccount* recipient);
    void doCredit (string causal, float amount);
    void doDebit (string causal, float amount);
    
    void setListTransaction(Transaction* transaction);

private:
    string owner;
    string type;
    int numberAccount;
    char* historical;

    float availableBalance;
    const float bankCredit;
    float realBankCredit;

    Transaction* listTransaction [MAX_NUM_TRANSACTION] {};
    int numberTransaction;
};

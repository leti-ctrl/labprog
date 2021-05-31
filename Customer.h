#include "BankAccount.h"

#include <string>
using namespace std;

static const int MAX_BANK_ACCOUNT = 10;

class Customer {
public:
    Customer (string n, string s, int day, int month, int year, string place); //persona fisica
    Customer (string n, const string& pIVA); //azienda
    ~Customer();

    void createBankAccount (float m = 0);
    void checkNumberBankAccount ();

    BankAccount* getAccount ();

    void addAccountToList (string t);

private:
    string name;
    string surname;

    char* fileBA;

    BankAccount* listBA [MAX_BANK_ACCOUNT] {};
    int numberBA;
};

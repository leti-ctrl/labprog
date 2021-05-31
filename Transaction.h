#include <string>
using namespace std;

class Transaction {
public:

    explicit Transaction (string c, float a);
    virtual ~Transaction() = default;;

    virtual void doTransaction () = 0;

protected:
    long int numberTransaction;
    string causal;
    float amount;
};

#include <iostream>
#include "BankAccount.h"
#include "ATM.h"
#include "Credit.h"
#include "BankTransfer.h"
using namespace std;

int main() {

    BankAccount mr ("Mario", "Rossi" );
    BankAccount pb ("Paolo", "Bianchi" );
    BankAccount fn ("Franco", "Neri" );

    ATM aten (&mr, 70);
    ATM atwenty (&pb, 20);
    ATM afifty (&fn, 50);

    Credit cthirty (&mr, 80);
    Credit cforty (&pb, 40);
    Credit cseventy (&fn, 70);

    BankTransfer bttwenty (&pb, & mr, 20);
    BankTransfer btthirty (&mr, &fn, 40);
    BankTransfer btforty (&fn, &pb, 40);



    mr.readHistory();
    pb.readHistory();
    fn.readHistory();
    return 0;
}

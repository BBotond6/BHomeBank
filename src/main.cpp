
#include <iostream>

#include "BasicTypes.hpp"
#include "Transaction.hpp"

using namespace std;

int main()
{

    OtpTransaction t(1999,2,3,"terere");
    t.PrintDateComment();

    system("PAUSE");
    return 0;
}

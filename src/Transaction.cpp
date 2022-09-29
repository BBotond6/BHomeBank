
#include "Transaction.hpp"
#include "BasicTypes.hpp"
#include <iostream>

using namespace std;

Transaction::Transaction(){}

Transaction::Transaction(unsigned short year,unsigned char month,unsigned char day)
{
    this -> Date.SetDate(year,month,day);
}

Transaction::~Transaction(){}

OtpTransaction::OtpTransaction(){}

OtpTransaction::OtpTransaction(unsigned short year,unsigned char month,
                        unsigned char day,string comment):
                        Transaction(year,month,day)
{
    Comment = comment;
}

void OtpTransaction::PrintDateComment()
{
    cout << Date.GetTextForm() << endl;
}

OtpTransaction::~OtpTransaction(){}

RevolutTransaction::RevolutTransaction(){}

RevolutTransaction::~RevolutTransaction(){}

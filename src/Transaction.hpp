
#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP 

#include "BasicTypes.hpp"

class Transaction
{
protected:
    Date Date;
    Time Time;
    double Amount;
    string Place;
public:
    Transaction();
    Transaction(unsigned short year,unsigned char month,unsigned char day);
    ~Transaction();
};

class OtpTransaction : public Transaction
{
    private:
        unsigned char Mode;
        string Comment;
    public:
        OtpTransaction();
        OtpTransaction(unsigned short year,unsigned char month,unsigned char day,
                        string comment);
        ~OtpTransaction();
        void PrintDateComment();
};

class RevolutTransaction : public Transaction
{
    private:
        string Currency;
    public:
        RevolutTransaction();
        ~RevolutTransaction();
};

#endif //TRANSACTION_HPP

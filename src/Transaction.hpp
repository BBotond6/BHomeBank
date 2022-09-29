
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
    ~Transaction();
};

class OtpTransaction : public Transaction
{
    private:
        unsigned char Mode;
        string Comment;
    public:
        OtpTransaction();
        ~OtpTransaction();
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

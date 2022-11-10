
#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP 

#include "BasicTypes.hpp"
#include "BasicFunctions.hpp"

#include <iostream>
#include <vector>

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
    virtual void PrintDatas();
};

class OtpTransaction : public Transaction
{
    private:
        unsigned char Mode;
        string Comment;
    public:
        OtpTransaction(string OtpLine);
        ~OtpTransaction();
        void PrintDatas();
};

class RevolutTransaction : public Transaction
{
    private:
        string Currency1;
        string Currency2;
        double Amount2;
        string Comment;
    public:
        RevolutTransaction(string Date, string Place, string TimeComment, string Currency1, string Currency2);
        ~RevolutTransaction();
        void PrintDatas();
};

#endif //TRANSACTION_HPP

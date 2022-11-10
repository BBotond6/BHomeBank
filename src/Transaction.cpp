
#include "Transaction.hpp"

using namespace std;

Transaction::Transaction(){}

void Transaction::PrintDatas()
{
    cout << "Date: " << Date.GetTextForm() << endl;
    cout << "Time: " << Time.GetTextForm() << endl;
    cout << "Amount: " << Amount << endl;
    cout << "Place: " << Place << endl;
}

Transaction::~Transaction(){}

OtpTransaction::OtpTransaction(string OtpLine)
{
    vector<string> Elements = Split(OtpLine, "\t");

    vector<string> Date = Split(Split(Elements.at(0), " ").at(0), ".");
    this -> Date.SetDate((unsigned short)stoi(Date.at(0)), (unsigned char)stoi(Date.at(1)), (unsigned char)stoi(Date.at(2)));
    
    vector<string> Time = Split(Split(Elements.at(0), " ").at(1), ":");
    this -> Time.SetTime((unsigned char)stoi(Time.at(0)), (unsigned char)stoi(Time.at(1)), (unsigned char)stoi(Time.at(2)));
    this -> Amount = stod(RemoveChar(Elements.at(2), '.'));

    this -> Place = Elements.at(3);
    this -> Comment = Elements.at(4);
}

void OtpTransaction::PrintDatas()
{
    cout << "Date: " << Date.GetTextForm() << endl;
    cout << "Time: " << Time.GetTextForm() << endl;
    cout << "Amount: " << Amount << endl;
    cout << "Place: " << Place << endl;
    cout << "Mode: " << Mode << endl;
    cout << "Comment: " << Comment << endl;
}

OtpTransaction::~OtpTransaction(){}

RevolutTransaction::RevolutTransaction(string Date, string Place, string TimeComment, string Currency1, string Currency2)
{
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};

    this -> Date.SetDate((unsigned short)stoi(Split(Date, " ")[2]), (unsigned char)(IndexOf(months, Split(Date, " ")[1], sizeof(months)/sizeof(months[0])) + 1), (unsigned char)stoi(Split(Date, ":")[0]));
    this -> Place = Place;
    this -> Time.SetTime((unsigned char)stoi(Split(Split(TimeComment, " ")[0], ":")[0]), (unsigned char)stoi(Split(Split(TimeComment, " ")[0], ":")[1]), 0);
    if(Split(TimeComment, " ").size() > 1){
        this -> Comment = TimeComment.substr(8, TimeComment.length() - 8);
    }else{
        this -> Comment = "";
    }

    this -> Amount = stod(Split(Currency1, " ")[0] + RemoveChar(Split(Currency1, " ")[2], ','));
    this -> Currency1 = Split(Currency1, " ")[1];

    this -> Amount2 = stod(Split(Currency2, " ")[0] + RemoveChar(Split(Currency2, " ")[2], ','));
    this -> Currency2 = Split(Currency2, " ")[1];
}

void RevolutTransaction::PrintDatas()
{
    cout << "Date: " << Date.GetTextForm() << endl;
    cout << "Time: " << Time.GetTextForm() << endl;
    cout << "Amount: " << Amount << endl;
    cout << "Place: " << Place << endl;
    cout << "Currency1: " << Currency1 << endl;
    cout << "Currency2: " << Currency2 << endl;
    cout << "Amount2: " << Amount2 << endl;
    cout << "Comment: " << Comment << endl;
}

RevolutTransaction::~RevolutTransaction(){}

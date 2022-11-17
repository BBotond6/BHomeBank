
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
    string Months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
    
    this -> Date.SetDate((unsigned short)stoi(Split(Date, " ")[2]), (unsigned char)(IndexOf(Months, Split(Date, " ")[1], sizeof(Months)/sizeof(Months[0])) + 1), (unsigned char)stoi(Split(Date, ":")[0]));
    this -> Place = Place;
    if(Split(TimeComment, "~").size() == 1){
        this -> Time.SetTime((unsigned char)stoi(Split(TimeComment, ":")[0]), (unsigned char)stoi(Split(TimeComment, ":")[1]), 0);
        this -> Comment = "";
        this -> Success = true;
    }
    if(Split(TimeComment, "~").size() == 2){
        if(Split(Split(TimeComment, "~")[0], ":").size() == 2){
            this -> Time.SetTime((unsigned char)stoi(Split(Split(TimeComment, "~")[0], ":")[0]), (unsigned char)stoi(Split(Split(TimeComment, "~")[0], ":")[1]), 0);
            this -> Comment = Split(TimeComment, "~")[1].substr(1, Split(TimeComment, "~")[1].length());
            this -> Success = true;
        }else{
            this -> Time.SetTime((unsigned char)stoi(Split(Split(TimeComment, "~")[1], ":")[0]), (unsigned char)stoi(Split(Split(TimeComment, "~")[1], ":")[1]), 0);
            this -> Comment = "";
            if(Split(TimeComment, "~")[0] == "Failed " || Split(TimeComment, "~")[0] == "Declined "){
                this -> Success = false;
            }else{
                this -> Success = true;
            }
        }
    }else if((Split(TimeComment, "~").size() == 3)){
        this -> Time.SetTime((unsigned char)stoi(Split(Split(TimeComment, "~")[1], ":")[0]), (unsigned char)stoi(Split(Split(TimeComment, "~")[1], ":")[1]), 0);
        this -> Comment = Split(TimeComment, "~")[2].substr(1, Split(TimeComment, "~")[2].length());
        if(Split(TimeComment, "~")[0] == "Failed " || Split(TimeComment, "~")[0] == "Declined "){
            this -> Success = false;
        }else{
            this -> Success = true;
        }
    }

    this -> Amount = stod(Split(Currency1, " ")[0] + RemoveChar(Split(Currency1, " ")[2], ','));
    this -> Currency1 = Split(Currency1, " ")[1];

    if(Currency2 != ""){
        this -> Amount2 = stod(Split(Currency2, " ")[0] + RemoveChar(Split(Currency2, " ")[2], ','));
        this -> Currency2 = Split(Currency2, " ")[1];
    }else{
        this -> Amount2 = 0;
        this -> Currency2 = "";
    }
}

void RevolutTransaction::PrintDatas()
{
    cout << "Date: " << Date.GetTextForm() << endl;
    cout << "Time: " << Time.GetTextForm() << endl;
    cout << "Place: " << Place << endl;
    cout << "Currency1: " << Currency1 << endl;
    cout << "Amount: " << Amount << endl;
    cout << "Currency2: " << Currency2 << endl;
    cout << "Amount2: " << Amount2 << endl;
    cout << "Comment: " << Comment << endl;
    cout << "Success: " << Success <<endl;
}

RevolutTransaction::~RevolutTransaction(){}

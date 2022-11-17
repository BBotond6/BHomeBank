#include "DataFunctions.hpp"

void ReadTransactions(string File, vector<Transaction*> *Destination)
{
    string Number = "x";
    if(File.length() > 6){
        Number = Split(File, ".")[0].substr(Split(File, ".")[0].length() - 6, Split(File, ".")[0].length());
    }

    if(File.substr(0, 2) == "oi" && Split(File, ".").size() == 2 && Split(File, ".")[1] == "txt" && IsNumber(Number)){
        *Destination = ReadOtpTransaction(File);
    }else if(File.substr(0, 1) == "r" && Split(File, ".").size() == 2 && Split(File, ".")[1] == "txt" && IsNumber(Number)){
        *Destination = ReadRevolutTransaction(File);
    }else{
        cout << "\"" + File + " is not a transaction file!" << endl;
    }
}

vector<Transaction*> ReadOtpTransaction(string TxtFile)
{
    fstream File;
    File.open("../data/" + TxtFile);

    vector<Transaction*> Result;
    if(File){
        string Line;
        string OtpLine = "";

        while(getline(File, Line, '\n')){
            Line = GetEnglishForm(Line);

            if(Line != " " && Line != " \n" && Line != "\n" && Line != "Reszletek"){
                OtpLine += Line;
            }else if(Line == "Reszletek"){
                int i = 0;

                for(i = 0; i < (int)OtpLine.length() - 1; i++){
                    if(OtpLine.at(i) == '\t' && OtpLine.at(i+1) == '\t'){
                        OtpLine = OtpLine.substr(0, i+1) + "EMPTY" + OtpLine.substr(i+1, OtpLine.length());
                    }
                }

                OtpLine = OtpLine.substr(0, OtpLine.length()-1);
                Result.push_back(new OtpTransaction(RemoveChar(OtpLine, '\n')));
                OtpLine = "";
            }
        }
    }else{
        cout << TxtFile + " file do not exist!" << endl;
    }

    File.close();

    return Result;
}

vector<Transaction*> ReadRevolutTransaction(string TxtFile)
{
    fstream File;
    File.open("../data/" + TxtFile);

    vector<Transaction*> Result;

    if(File){
        string Line;
        string PrevLine;
        string Date;
        string Place;
        string TimeComment;
        string Currency1;
        string Currency2;

        string Months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
        int Position = 0;

        while(getline(File, Line, '\n')){
            Line = GetEnglishForm(Line);
            
            if((Split(Line, " ").size() == 2 || Split(Line, " ").size() == 3) && IndexOf(Months, Split(Line, " ")[1], sizeof(Months)/sizeof(Months[0])) != -1){
                if(Position == 3 && Split(PrevLine, " ").size() == 3 && (Split(PrevLine, " ")[0] == "-" || Split(PrevLine, " ")[0] == "+") && IsNumber(RemoveChar(RemoveChar(Split(PrevLine, " ")[2], '.'), ','))){
                    Currency2 = "";
                    Result.push_back(new RevolutTransaction(Date, Place, TimeComment, Currency1, Currency2));
                    Position = 0;
                }else if(Position == 4 && Split(PrevLine, " ").size() == 3 && (Split(PrevLine, " ")[0] == "-" || Split(PrevLine, " ")[0] == "+") && IsNumber(RemoveChar(RemoveChar(Split(PrevLine, " ")[2], '.'), ','))){
                    Result.push_back(new RevolutTransaction(Date, Place, TimeComment, Currency1, Currency2));
                    Position = 0;
                }
                if(Split(Line, " ").size() == 3){
                    Date = RemoveChar(Line, '\n');
                }else{
                    Date = RemoveChar(Line + " " + TxtFile.substr(TxtFile.length() - 10, 4), '\n');
                }
            }else if(PrevLine == "" && Position == 0){
                Place = Line;
                Position++;
            }else if(Split(Line, ":").size() == 2 && Split(Line, ":")[0].length() >= 2 && Split(Line, ":")[1].length() >= 2 && Position == 1){
                if(IsNumber(Split(Line, ":")[0].substr(Split(Line, ":")[0].length() - 2, 2)) && IsNumber(Split(Line, ":")[1].substr(0, 2))){
                    TimeComment = Line;
                    Position++;
                }
            }else if(Split(Line, " ").size() == 3 && (Split(Line, " ")[0] == "-" || Split(Line, " ")[0] == "+") && IsNumber(RemoveChar(RemoveChar(Split(Line, " ")[2], '.'), ','))){
                if(Position == 2){
                    Currency1 = Line;
                    Position++;
                }else if(Position == 3){
                    Currency2 = Line;
                    Position++;
                }
            }else if(Line == ""){
                if(Position == 3 && Split(PrevLine, " ").size() == 3 && (Split(PrevLine, " ")[0] == "-" || Split(PrevLine, " ")[0] == "+") && IsNumber(RemoveChar(RemoveChar(Split(PrevLine, " ")[2], '.'), ','))){
                    Currency2 = "";
                    Result.push_back(new RevolutTransaction(Date, Place, TimeComment, Currency1, Currency2));
                    Position = 0;
                }else if(Position == 4 && Split(PrevLine, " ").size() == 3 && (Split(PrevLine, " ")[0] == "-" || Split(PrevLine, " ")[0] == "+") && IsNumber(RemoveChar(RemoveChar(Split(PrevLine, " ")[2], '.'), ','))){
                    Result.push_back(new RevolutTransaction(Date, Place, TimeComment, Currency1, Currency2));
                    Position = 0;
                }
            }

            PrevLine = Line;
        }

        //Push back the last line
        if(Split(PrevLine, " ").size() == 3 && (Split(PrevLine, " ")[0] == "-" || Split(PrevLine, " ")[0] == "+") && IsNumber(RemoveChar(RemoveChar(Split(PrevLine, " ")[2], '.'), ','))){
            Result.push_back(new RevolutTransaction(Date, Place, TimeComment, Currency1, Currency2));
        }

    }else{
        cout << TxtFile + " file do not exist!" << endl;
    }

    File.close();

    return Result;
}

#include "DataFunctions.hpp"

void ReadTransactions(string File, vector<Transaction*> *Destination)
{
    if(File.substr(0, 2) == "oi" && Split(File, ".").size() == 2 && Split(File, ".")[1] == "txt"){
        *Destination = ReadOtpTransaction(File);
    }else if(File.substr(0, 1) == "r" && Split(File, ".").size() == 2 && Split(File, ".")[1] == "txt"){

    }else{
        cout << "\"" + File + " is not a transaction file!" << endl;
    }
}

vector<Transaction*> ReadOtpTransaction(string TxtFile)
{
    fstream File;
    File.open("../datas/" + TxtFile);

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

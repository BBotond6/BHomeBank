#include "BasicFunctions.hpp"

using namespace std;

vector<string> Split(string Input, string Sub)
{
    vector<string> result;
    unsigned int Size = Sub.length();
    unsigned int StartIndex = 0;
    unsigned int EndIndex = 0;
    while((EndIndex + Size) < Input.length()){
        if(Sub.compare(Input.substr(EndIndex, Size)) == false && (EndIndex + Size) < Input.length()){
            result.push_back(Input.substr(StartIndex, (EndIndex - StartIndex)));
            StartIndex = EndIndex + Size;
        }else if(Sub.compare(Input.substr(EndIndex, Size)) && (EndIndex + Size) == (Input.length() - 1)){
            result.push_back(Input.substr(StartIndex, (EndIndex - Input.length())));
        }
        EndIndex++;
    }
    return result;
}

int IndexOf(string Input[], string Element, int length)
{
    int i = 0;
    while (i<length && Element.compare(Input[i]) != false)
    {
        i++;
    }
    
    if (i < length)
    {
        return i;
    }else
    {
        return -1;
    }
}

string RemoveChar(string str, char c)
{
    string result;
    int i = 0;

    while(i < (int)str.length()){
        if(str[i] != c){
            result += str[i];
        }
        i++;
    }

    return result;
}

string GetEnglishForm(string Input)
{
    Input += "~";
    string Result = "";
    int i = 0;
    //CHARACTERS = {'á', 'é', 'í', 'ó', 'ö', 'ő', 'ú', 'ü', 'ű', 'Á', 'É', 'Í', 'Ó', 'Ö', 'Ő', 'Ú', 'Ü', 'Ű'};
    int hu1[] = {-61, -61, -61, -61, -61, -59, -61, -61, -59, -61, -61, -61, -61, -61, -59, -61, -61, -59, -59, -59, -62, -60, -60, -59, -59, -59};
    int hu2[] = {-95, -87, -83, -77, -74, -111, -70, -68, -79, -127, -119, -115, -109, -106, -112, -102, -100, -80, -69, -68, -73, -97, -80, -97, -98, -101};
    char eng[] = {'a', 'e', 'i', 'o', 'o', 'o', 'u', 'u', 'u', 'A', 'E', 'I', 'O', 'O', 'O', 'U', 'U', 'U', 'Z', 'z', '~', 'g', 'I', 's', 'S', 's'};

    while(i < (int)Input.length() - 1){
        if(i < (int)Input.length() - 2 && (int)Input.at(i) == -30 && (int)Input.at(i+1) == -126){  //Switch EUR character to EUR
            if((int)Input.at(i) == -30 && (int)Input.at(i+1) == -126 && (int)Input.at(i+2) == -84){
                Result += "EUR ";
                i+=2;
            }else if((int)Input.at(i+1) < 0){
                cout << "ERROR: in \"BasicFunction.cpp\" Unknow character in \"" + Input + "\" - length = 3 - index = " << i << "!" << endl;
                exit(0);
            }
        }else if(Input.at(i) == '$'){   //Replace $ character to USD
            Result += "USD ";
        }else{
            int j = 0;
            while(j < (int)sizeof(hu1)){
                if((int)Input.at(i) < 0){
                    if((int)Input.at(i) == hu1[j] && (int)Input.at(i+1) == hu2[j]){
                        Result += string(1,eng[j]);
                        i++;
                        break;
                    }
                }
                j++;
            }
            if(j == sizeof(hu1) && (int)Input.at(i) > 0){
                Result += string(1,Input.at(i));
            }else if(i < (int)Input.length() - 2 && j == sizeof(hu1) && (int)Input.at(i) < 0 && (int)Input.at(i+1) < 0 && (int)Input.at(i+2) < 0){
                cout << "ERROR: in \"BasicFunction.cpp\" Unknow character in \"" + Input + "\" - length = 3 - index = " << i << "!" << endl;
                i+=2;
                exit(0);
            }else if(j == sizeof(hu1) && (int)Input.at(i) < 0 && (int)Input.at(i+1) < 0){
                cout << "ERROR: in \"BasicFunction.cpp\" Unknow character in \"" + Input + "\" - length = 2 - index = " << i << "!" << endl;
                i++;
                exit(0);
            }else if(j == sizeof(hu1) && (int)Input.at(i) < 0){
                cout << "ERROR: in \"BasicFunction.cpp\" Unknow character in \"" + Input + "\" - length = 1 - index = " << i << "!" << endl;
                exit(0);
            }
        }
        i++;
    }
    return Result;
}

bool IsNumber(string Input)
{
    for(char const &c : Input){
        if(isdigit(c) == 0){
            return false;
        }
    }
    return true;
}

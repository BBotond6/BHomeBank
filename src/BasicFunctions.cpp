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
    int i= 0;

    while(i < (int)str.length()){
        if(str[i] != c){
            result += str[i];
        }
        i++;
    }

    return result;
}

#ifndef BASICFUNCTIONS_HPP
#define BASICFUNCTIONS_HPP

#include <iostream>
#include <vector>

using namespace std;

//Split string by a specific string
vector<string> Split(string Input, string Sub);

//Get the element index in the array
int IndexOf(string Input[], string Element, int length);

//Remove char from a string
string RemoveChar(string str, char c);

//Change the foreign characters to english in the input string
string GetEnglishForm(string Input);

//Check that the input string is a number
bool IsNumber(string Input);

#endif //BASICFUNCTIONS_HPP

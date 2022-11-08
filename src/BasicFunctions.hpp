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

#endif //BASICFUNCTIONS_HPP

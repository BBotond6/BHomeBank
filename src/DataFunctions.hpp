#ifndef DATAFUNCTIONS_HPP
#define DATAFUNCTIONS_HPP

#include "Transaction.hpp"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Read transactions from the txt file to a Transaction vector
void ReadTransactions(string File, vector<Transaction*> *Destination);

//Read Otp transactions from a txt file
vector<Transaction*> ReadOtpTransaction(string TxtFile);

//Read Revolut transactions from a txt file
vector<Transaction*> ReadRevolutTransaction(string TxtFile);

#endif //DATAFUNCTIONS_HPP


#include "BasicTypes.hpp"

#include <iostream>

using namespace std;


Date::Date(unsigned short year, unsigned short month, unsigned short day)
{
    Year = year;
    Month = month;
    Day = day;
}

unsigned short Date::GetDay(){
    cout << "Getday()...." << endl;
    return Day;
}

unsigned short Date::GetMonth(){
    return this -> Month;
}

unsigned short Date::GetYear(){
    return this -> Year;
}

Date::~Date(){}

Time::Time(unsigned short hour, unsigned short min, unsigned short sec)
{
    this -> Hour = hour;
    this -> Min = min;
    this -> Sec = sec;
}

unsigned short Time::GetHour(){
    return this -> Hour;
}

unsigned short Time::GetMin(){
    return this -> Min;
}

unsigned short Time::GetSec(){
    return this -> Sec;
}

Time::~ Time(){}

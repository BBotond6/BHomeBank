
#include "BasicTypes.hpp"

#include <iostream>

using namespace std;


Date::Date(unsigned short year, unsigned short month, unsigned short day)
{
    this -> Year = year;
    this -> Month = month;
    this -> Day = day;
}

unsigned short Date::GetDay(){
    return Day;
}

unsigned short Date::GetMonth(){
    return Month;
}

unsigned short Date::GetYear(){
    return Year;
}

string Date::GetTextForm(){
    return to_string(Day) + "/" +to_string(Month) + "/" + to_string(Year);
}

Date::~Date(){}

Time::Time(unsigned short hour, unsigned short min, unsigned short sec)
{
    this -> Hour = hour;
    this -> Min = min;
    this -> Sec = sec;
}

unsigned short Time::GetHour(){
    return Hour;
}

unsigned short Time::GetMin(){
    return Min;
}

unsigned short Time::GetSec(){
    return Sec;
}

string Time::GetTextForm(){
    return to_string(Hour) + ":" +to_string(Min) + ":" + to_string(Sec);
}

Time::~ Time(){}

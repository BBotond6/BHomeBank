
#include "BasicTypes.hpp"

using namespace std;


Date::Date(){}

Date::Date(unsigned short year, unsigned char month, unsigned char day)
{
    this -> Year = year;
    this -> Month = month;
    this -> Day = day;
}

void Date::SetDate(unsigned short year, unsigned char month, unsigned char day)
{
    this -> Year = year;
    this -> Month = month;
    this -> Day = day;
}

unsigned char Date::GetDay(){
    return Day;
}

unsigned char Date::GetMonth(){
    return Month;
}

unsigned short Date::GetYear(){
    return Year;
}

string Date::GetTextForm(){
    return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
}

Date::~Date(){}

Time::Time(){}

Time::Time(unsigned char hour, unsigned char min, unsigned char sec)
{
    this -> Hour = hour;
    this -> Min = min;
    this -> Sec = sec;
}

void Time::SetTime(unsigned char hour, unsigned char min, unsigned char sec)
{
    this -> Hour = hour;
    this -> Min = min;
    this -> Sec = sec;
}

unsigned char Time::GetHour(){
    return Hour;
}

unsigned char Time::GetMin(){
    return Min;
}

unsigned char Time::GetSec(){
    return Sec;
}

string Time::GetTextForm(){
    return to_string(Hour) + ":" +to_string(Min) + ":" + to_string(Sec);
}

Time::~ Time(){}

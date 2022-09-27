
#ifndef BASICTYPES_HPP
#define BASICTYPES_HPP

#include <iostream>

using namespace std;

//Class Date Day/Month/Year
class Date
{
private:
    unsigned short Day;
    unsigned short Month;
    unsigned short Year;
public:
    Date(unsigned short year, unsigned short month, unsigned short day);
    ~Date(); 
    unsigned short GetYear();
    unsigned short GetMonth();
    unsigned short GetDay();
    string GetTextForm();
};


//Class Time Hour/Min/Sec
class Time
{
private:
    unsigned short Hour;
    unsigned short Min;
    unsigned short Sec;
public:
    Time(unsigned short hour, unsigned short min, unsigned short sec);
    ~Time();
    unsigned short GetHour();
    unsigned short GetMin();
    unsigned short GetSec();
    string GetTextForm();
};



#endif //BASICTYPES_HPP
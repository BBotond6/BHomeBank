
#ifndef BASICTYPES_HPP
#define BASICTYPES_HPP

#include <iostream>

using namespace std;

//Class Date Day/Month/Year
class Date
{
private:
    unsigned char Day;
    unsigned char Month;
    unsigned short Year;
public:
    Date(unsigned short year, unsigned char month, unsigned char day);
    Date();
    ~Date(); 
    unsigned short GetYear();
    unsigned char GetMonth();
    unsigned char GetDay();
    string GetTextForm();

    void SetDate(unsigned short year, unsigned char month, unsigned char day);
};


//Class Time Hour/Min/Sec
class Time
{
private:
    unsigned char Hour;
    unsigned char Min;
    unsigned char Sec;
public:
    Time(unsigned char hour, unsigned char min, unsigned char sec);
    Time();
    ~Time();
    unsigned char GetHour();
    unsigned char GetMin();
    unsigned char GetSec();
    string GetTextForm();

    void SetTime(unsigned char hour, unsigned char min, unsigned char sec);
};



#endif //BASICTYPES_HPP
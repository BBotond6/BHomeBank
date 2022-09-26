
#ifndef BASICTYPES_HPP
#define BASICTYPES_HPP

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
};



#endif //BASICTYPES_HPP
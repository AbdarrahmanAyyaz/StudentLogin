#pragma once
#include "datetype.h"
class DateTime : public DateType
{
public:
    DateTime();
    DateTime(int, int, int, int, int, int);
    void SetHours(int);
    int GetHours();
    void SetMinutes(int);
    int GetMinutes();
    void SetSeconds(int);
    int GetSeconds();
private:
    int hr;  //variable to store the hours
    int min; //variable to store the minutes
    int sec; //variable to store the seconds
};
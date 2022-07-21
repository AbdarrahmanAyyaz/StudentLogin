#pragma once
class DateType
{
public:
    DateType();
    DateType(int, int, int);
    void SetMonth(int);
    int GetMonth();
    void SetDay(int);
    int GetDay();
    void SetYear(int);
    int GetYear();
protected:
    int month, day, year;
};
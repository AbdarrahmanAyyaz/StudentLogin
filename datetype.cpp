#include "datetype.h"
using namespace std;

DateType::DateType()
{
	day = 1;
	month = 1;
	year = 2000;
}

DateType::DateType(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void DateType::SetMonth(int m)
{
	month = m;
}

int DateType::GetMonth()
{
	return month;
}

void DateType::SetDay(int d)
{
	day = d;
}

int DateType::GetDay()
{
	return day;
}

void DateType::SetYear(int yr)
{
	year = yr;
}

int DateType::GetYear()
{
	return year;
}
#include "datetime.h"
using namespace std;

DateTime::DateTime()
{
	month = 1;
	day = 1;
	year = 2000;
	hr = 12;
	min = 0;
	sec = 0;
}

DateTime::DateTime(int mon, int da, int yr, int h, int m, int s)
{
	month = mon;
	day = da;
	year = yr;
	hr = h;
	min = m;
	sec = s;
}

void DateTime::SetHours(int h)
{
	hr = h;
}

int DateTime::GetHours()
{
	return hr;
}

void DateTime::SetMinutes(int m)
{
	min = m;
}

int DateTime::GetMinutes()
{
	return min;
}

void DateTime::SetSeconds(int s)
{
	sec = s;
}

int DateTime::GetSeconds()
{
	return sec;
}
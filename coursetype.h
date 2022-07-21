#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "facultytype.h"
#include "datetype.h"
using namespace std;

struct CourseDetail
{
	string Term;
	int Year;
	string StartDate, EndDate, CourseName, ClassID;
	int Section;
	string MeetingDays, Location, MeetingInformation, Instructor;
	int Units;
};

class CourseType
{
public:
	CourseType();
	vector <CourseDetail> LoadData();
	void AddRecord(vector <CourseDetail>&);
	void ReadRecord(vector <CourseDetail>);
	void DisplayRecord(vector <CourseDetail>);
	void EditRecord(vector <CourseDetail>&);
	void DeleteRecord(vector <CourseDetail>&);
	CourseDetail cd;
private:
	//CourseDetail cd;
	FacultyType instructor;
	DateType startDate; // convert previous date string to class DateType
	DateType endDate;  // convert previous date string to class DateType
	string ToUpperString(string);
};
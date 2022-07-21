#pragma once
#include "persontype.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

enum StudentMenu {
    Show = 's', Edit = 'e', ExitStudentMenu = 'x'
};
class StudentType : public PersonType
{
public:
    //Mutator
    void setStudentID(string);
    //Accessor
    string getStudentID();
    vector <StudentType> LoadData();
    void CreateStudentMenu();
    void ShowData(vector <StudentType>);
    void EditStudentRecord(vector <StudentType>&);
private:
    string studentID;
};
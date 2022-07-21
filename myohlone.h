#pragma once
#include <vector>
#include "persontype.h"
#include "logininfo.h"
#include "coursetype.h"

using namespace std;
enum ohloneMenu
{ 
    Display = 'l', View = 'v', Add = 'a', Edito = 'e', Delete = 'd', Exit = 'x' 
};

class MyOhlone {
public:
    // doAuthentication
    char loginMenu();
    bool doLogin();

    // doCourses
    void doDisplay();
    void doView();
    void doAdd();
    void doEdit();
    void doDelete();
    
    MyOhlone();
    ~MyOhlone();

private:
    void readUsers(string usercsv);
    void readCourses(string coursecsv);

    vector<CourseType*>* list;
    vector <LoginInfo> users;
    PersonType student;
    LoginInfo loginInfo;
};

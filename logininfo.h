#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include "datetime.h"
using namespace std;
class LoginInfo
{
public:
    //mutator member functions
    void setUser(string);
    void setPass(string);
    //accessor member functions
    string getUser();
    string getPass();
    //constructors
    //LoginInfo();
    //~LoginInfo();

    //Required Functions
    void DisplayRecord(vector <LoginInfo>);
    vector <LoginInfo> LoadData();
    bool UserAuthentication(string, string, vector <LoginInfo>);
    void CreateAccount(vector <LoginInfo>&);
    void ResetPassword(vector <LoginInfo>&);
    void UpdateLoginDateTime(string, vector <LoginInfo>&);
    void UpdateLogoutDateTime(string, vector <LoginInfo>&);
//protected:
    string username;
    string password;
    DateTime loginDateTime;
    DateTime logoutDateTime;
    
};
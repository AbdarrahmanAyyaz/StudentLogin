#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class PersonType
{
public:
    //Constructor
    PersonType();
    PersonType(string, string, string, string, string, string, string);
    //Mutators
    void SetfirstName(string);
    void SetlastName(string);
    void Setaddress(string);
    void Setcity(string);
    void Setstate(string);
    void Setzip(string);
    void Setphone(string);
    //Accessor
    string getfirstName();
    string getlastName();
    string getaddress();
    string getcity();
    string getstate();
    string getzip();
    string getphone();
protected:
    string firstName; // first name (id)
    string lastName; // last name (password)
    string address; // student address
    string city; // student's city
    string state; // student's state
    string zip; // student zip code
    string phone; // student's phone number
};
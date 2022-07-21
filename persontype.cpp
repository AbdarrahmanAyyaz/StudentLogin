#include "persontype.h"
using namespace std;
PersonType::PersonType()
{
	firstName = "firstname";
	lastName = "lastname";
	address = "address";
	city = "city";
	state = "state";
	zip = "zipcode";
	phone = "phone";
}

PersonType::PersonType(string first, string last, string add, string cty, string st, string zi, string ph)
{
	firstName = first;
	lastName = last;
	address = add;
	city = cty;
	state = st;
	zip = zi;
	phone = ph;
}

//Mutators
void PersonType::SetfirstName(string first)
{
	firstName = first;
}

void PersonType::SetlastName(string last)
{
	lastName = last;
}

void PersonType::Setaddress(string add)
{
	address = add;
}

void PersonType::Setcity(string cty)
{
	city = cty;
}

void PersonType::Setstate(string st)
{
	state = st;
}

void PersonType::Setzip(string zi)
{
	zip = zi;
}

void PersonType::Setphone(string ph)
{
	phone = ph;
}

//Accessor
string PersonType::getfirstName()
{
	return firstName;
}

string PersonType::getlastName()
{
	return lastName;
}

string PersonType::getaddress()
{
	return address;
}

string PersonType::getcity()
{
	return city;
}

string PersonType::getstate()
{
	return state;
}

string PersonType::getzip()
{
	return zip;
}

string PersonType::getphone()
{
	return phone;
}
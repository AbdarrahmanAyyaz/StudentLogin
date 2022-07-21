#include <vector>
#include <string>
#include <iostream>
#include "myohlone.h"

using namespace std;

MyOhlone::MyOhlone() 
{
	list = new vector<CourseType*>;	// everything in the list is a coursetype pointer
    readCourses("courses.csv");
	readUsers("users.csv");
}

MyOhlone::~MyOhlone() {
	// todo before...

	// delete list
	delete list;	// everything in the list is a coursetype pointer
}

char MyOhlone::loginMenu() {
	char ch;
	cout << "Login Menu" << endl;
	cout << "====================" << endl;
	cout << "l - Login" << endl;
	cout << "c - Create Account" << endl;
	cout << "r - Reset " << endl;
	cout << "x - Exit login menu" << endl;
	cin >> ch;
	return ch;
}

// Login info
bool MyOhlone::doLogin() 
{
	bool valid = false;
	string userId,
		pswd;
	cout << "Enter username: ";
	cin >> userId;
	cout << "Enter password: ";
	cin >> pswd;
	for (int i = 0; i < this->users.size(); i++) {
		LoginInfo ptrUser = this->users.at(i);
		if (userId == ptrUser.getUser() &&
			pswd == ptrUser.getPass()) {
			valid = true;
			break;
		}
	}
	return valid;
}

void MyOhlone::readUsers(string filename) {
	
	LoginInfo user;
    string line;
    int lineNum = 0;
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open(filename, ios::in);

    string sDay, sMonth, sYear, sTime, sHH, sMM, sSS;
    DateTime d1;

    while (getline(fin, line))
    {
        istringstream iss(line);
        lineNum++;

        // Try to extract login Information from the line. If successful, ok will be true.
        bool ok = false;
        string usern, passw;
        do
        {
            if (!getline(iss, usern, ','))
                break;
            user.setUser(usern);
            if (!getline(iss, passw, ','))
                break;
            user.setPass(passw);
            if (!getline(iss, sMonth, '-'))
                break;
            if (!getline(iss, sDay, '-'))
                break;  //stop getting input at '-'
            if (!getline(iss, sYear, ' '))
                break;
            if (!getline(iss, sHH, ':'))
                break;
            if (!getline(iss, sMM, ':'))
                break;
            if (!getline(iss, sSS, ','))
                break;
            user.loginDateTime.SetMonth(atoi(sMonth.c_str()));
            user.loginDateTime.SetDay(atoi(sDay.c_str()));
            user.loginDateTime.SetYear(atoi(sYear.c_str()));
            user.loginDateTime.SetHours(atoi(sHH.c_str()));
            user.loginDateTime.SetMinutes(atoi(sMM.c_str()));
            user.loginDateTime.SetSeconds(atoi(sSS.c_str()));

            if (!getline(iss, sMonth, '-'))
                break;
            if (!getline(iss, sDay, '-'))
                break;  //stop getting input at '-'
            if (!getline(iss, sYear, ' '))
                break;
            if (!getline(iss, sHH, ':'))
                break;
            if (!getline(iss, sMM, ':'))
                break;
            if (!getline(iss, sSS, '\n'))
                break;
            user.logoutDateTime.SetMonth(atoi(sMonth.c_str()));
            user.logoutDateTime.SetDay(atoi(sDay.c_str()));
            user.logoutDateTime.SetYear(atoi(sYear.c_str()));
            user.logoutDateTime.SetHours(atoi(sHH.c_str()));
            user.logoutDateTime.SetMinutes(atoi(sMM.c_str()));
            user.logoutDateTime.SetSeconds(atoi(sSS.c_str()));
            ok = true;
        } while (false);
        // If all is well, add the user to user-vector.
        if (ok)
        {
            this->users.push_back(user);
        }
        else
        {
            cout << "Failed to parse line " << lineNum << ": " << line << endl;
        }
    }
    fin.close();
}

void MyOhlone::readCourses(string filename) {
	// ex.
    CourseType* ptrCourse = new CourseType();
    
    string line;
    int lineNum = 0;
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open(filename, ios::in);

    while (getline(fin, line))
    {
        ptrCourse = new CourseType();
        istringstream iss(line);
        lineNum++;

        // Try to extract course data from the line. If successful, ok will be true.
        bool ok = false;
        do
        {
            string val;
            if (!getline(iss, ptrCourse->cd.Term, ','))
                break;
            if (!getline(iss, val, ','))
                break;
            ptrCourse->cd.Year = atoi(val.c_str());
            if (!getline(iss, ptrCourse->cd.StartDate, ',')) break;
            if (!getline(iss, ptrCourse->cd.EndDate, ',')) break;
            if (!getline(iss, ptrCourse->cd.CourseName, ',')) break;
            if (!getline(iss, ptrCourse->cd.ClassID, ',')) break;
            if (!getline(iss, val, ','))
                break;
            ptrCourse->cd.Section = atoi(val.c_str());
            if (!getline(iss, ptrCourse->cd.MeetingDays, ',')) break;
            if (!getline(iss, ptrCourse->cd.Location, ',')) break;
            if (!getline(iss, ptrCourse->cd.MeetingInformation, ',')) break;
            if (!getline(iss, ptrCourse->cd.Instructor, ',')) break;
            if (!getline(iss, val, ','))
                break;
            ptrCourse->cd.Units = atoi(val.c_str());

            ok = true;
        } while (false);
        // If all is well, add the course to course-vector.
        if (ok)
        {
            list->push_back(ptrCourse);
            //delete ptrCourse;
        }
        else
        {
            cout << "Failed to parse line " << lineNum << ": " << line << endl;
        }
    }
    fin.close();
}

void MyOhlone::doDisplay()
{
    int coursenumber = 1;
    for (int i = 0; i < (*list).size(); i++)
    {
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Course Number " << coursenumber << ":" << endl;
        cout << "Term: " << setw(18) << " " << (*list).at(i)->cd.Term << "\nYear: " << setw(18) << " " << (*list).at(i)->cd.Year << "\nStart Date: " << setw(12) << " " << (*list).at(i)->cd.StartDate << "\nEnd Date: " << setw(14) << " " << (*list).at(i)->cd.EndDate << "\nCourse Name: " << setw(11) << " " << (*list).at(i)->cd.CourseName << "\nClass ID: " << setw(14) << " " << (*list).at(i)->cd.ClassID << "\nSection: " << setw(15) << " " << (*list).at(i)->cd.Section << "\nMeeting Days: " << setw(10) << " " << (*list).at(i)->cd.MeetingDays << "\nLocation: " << setw(14) << " " << (*list).at(i)->cd.Location << "\nMeeting Information:" << setw(4) << " " << (*list).at(i)->cd.MeetingInformation << "\nInstructor: " << setw(12) << " " << (*list).at(i)->cd.Instructor << "\nUnits: " << setw(17) << " " << (*list).at(i)->cd.Units << endl;
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
        coursenumber++;
    }
}
void MyOhlone::doView()
{
    // Get the course title of which the data is required
    string coursename;
    cin.ignore();
    cout << "Enter the course name: ";
    getline(cin, coursename);
    int count = 0;
    for (int i = 0; i < list->size(); i++)
    {
        if (list->at(i)->cd.CourseName.compare(coursename) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    if (count >= 0 && count < list->size())
    {
        cout << "Details of course is: " << endl;
        cout << "Term: " << setw(18) << " " << list->at(count)->cd.Term << "\nYear: " << setw(18) << " " << list->at(count)->cd.Year << "\nStart Date: " << setw(12) << " " << list->at(count)->cd.StartDate << "\nEnd Date: " << setw(14) << " " << list->at(count)->cd.EndDate << "\nCourse Name: " << setw(11) << " " << list->at(count)->cd.CourseName << "\nClass ID: " << setw(14) << " " << list->at(count)->cd.ClassID << "\nSection: " << setw(15) << " " << list->at(count)->cd.Section << "\nMeeting Days: " << setw(10) << " " << list->at(count)->cd.MeetingDays << "\nLocation: " << setw(14) << " " << list->at(count)->cd.Location << "\nMeeting Information:" << setw(4) << " " << list->at(count)->cd.MeetingInformation << "\nInstructor: " << setw(12) << " " << list->at(count)->cd.Instructor << "\nUnits: " << setw(17) << " " << list->at(count)->cd.Units << endl;
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
    }
    else
    {
        cout << "Record not found\n";
    }
}

void MyOhlone::doAdd()
{
    CourseType* obj = new CourseType();
    // file pointer
    fstream fout;
    string sval;
    int ival;
    // opens an existing csv file or creates a new file.
    fout.open("courses.csv", ios::out | ios::app);

    cout << "Enter the details of a course:" << endl;
    cin.ignore();
    cout << "Term: ";
    getline(cin, sval);
    obj->cd.Term = sval;
    cout << "Enter the Year: ";
    cin >> ival; //int
    obj->cd.Year = ival;
    cin.ignore();
    cout << "Enter the Start Date (MM/DD/YYYY): ";
    getline(cin, sval);
    obj->cd.StartDate = sval;
    //cin.ignore();
    cout << "Enter the End Date (MM/DD/YYYY): ";
    getline(cin, sval);
    obj->cd.EndDate = sval;
    //cin.ignore();
    cout << "Enter the Course Name: ";
    getline(cin, sval);
    obj->cd.CourseName = sval;
    //cin.ignore();
    cout << "Enter the Class ID: ";
    getline(cin, sval);
    obj->cd.ClassID = sval;
    //cin.ignore();
    cout << "Enter the Section: ";
    cin >> ival;  //int
    obj->cd.Section = ival;
    cin.ignore();
    cout << "Enter the Meeting days (M, T, W, TH, F, S, Su): ";
    getline(cin, sval);
    obj->cd.MeetingDays = sval;
    //cin.ignore();
    cout << "Enter the Location (online, hybrid, or on - campus): ";
    getline(cin, sval);
    obj->cd.Location = sval;
    //cin.ignore();
    cout << "Enter the Meeting Information: ";
    getline(cin, sval);
    obj->cd.MeetingInformation = sval;
    //cin.ignore();
    cout << "Enter the Instructor: ";
    getline(cin, sval);
    obj->cd.Instructor = sval;
    cout << "Enter the Units: ";
    cin >> ival;    //int
    obj->cd.Units = ival;
    list->push_back(obj);
    // Insert the data to file
    fout << obj->cd.Term << ","
        << obj->cd.Year << ","
        << obj->cd.StartDate << ","
        << obj->cd.EndDate << ","
        << obj->cd.CourseName << ","
        << obj->cd.ClassID << ","
        << obj->cd.Section << ","
        << obj->cd.MeetingDays << ","
        << obj->cd.Location << ","
        << obj->cd.MeetingInformation << ","
        << obj->cd.Instructor << ","
        << obj->cd.Units
        << "\n";
    cout << "Course details have been successfully added into the file!" << endl;
    fout.close();
}

void MyOhlone::doEdit() 
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("courses.csv", ios::in);

    // Create a new file to store updated data
    fout.open("coursesnew.csv", ios::out);

    //CourseDetail editcd;
    // Get the course title of which the data is required
    string coursename;
    cin.ignore();
    cout << "Enter the course name: ";
    getline(cin, coursename);

    int count = 0;
    for (int i = 0; i < list->size(); i++)
    {
        if (list->at(i)->cd.CourseName.compare(coursename) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    if (count >= 0 && count < list->size())
    {
        cout << "Enter the new details of a course:" << endl;
        //cin.ignore();
        cout << "Term: ";
        getline(cin, list->at(count)->cd.Term);
        cout << "Enter the Year: ";
        cin >> list->at(count)->cd.Year; //int
        cin.ignore();
        cout << "Enter the Start Date (MM/DD/YYYY): ";
        getline(cin, list->at(count)->cd.StartDate);
        cout << "Enter the End Date (MM/DD/YYYY): ";
        getline(cin, list->at(count)->cd.EndDate);
        cout << "Enter the Course Name: ";
        getline(cin, list->at(count)->cd.CourseName);
        cout << "Enter the Class ID: ";
        getline(cin, list->at(count)->cd.ClassID);
        cout << "Enter the Section: ";
        cin >> list->at(count)->cd.Section;  //int
        cin.ignore();
        cout << "Enter the Meeting days (M, T, W, TH, F, S, Su): ";
        getline(cin, list->at(count)->cd.MeetingDays);
        cout << "Enter the Location (online, hybrid, or on - campus) ";
        getline(cin, list->at(count)->cd.Location);
        cout << "Enter the Meeting Information: ";
        getline(cin, list->at(count)->cd.MeetingInformation);
        cout << "Enter the Instructor: ";
        getline(cin, list->at(count)->cd.Instructor);
        cout << "Enter the Units: ";
        cin >> list->at(count)->cd.Units;    //int
        for (int index = 0; index < list->size(); index++)
        {
            // Insert the data to file
            fout << list->at(index)->cd.Term << ","
                << list->at(index)->cd.Year << ","
                << list->at(index)->cd.StartDate << ","
                << list->at(index)->cd.EndDate << ","
                << list->at(index)->cd.CourseName << ","
                << list->at(index)->cd.ClassID << ","
                << list->at(index)->cd.Section << ","
                << list->at(index)->cd.MeetingDays << ","
                << list->at(index)->cd.Location << ","
                << list->at(index)->cd.MeetingInformation << ","
                << list->at(index)->cd.Instructor << ","
                << list->at(index)->cd.Units
                << "\n";
        }

        fin.close();
        fout.close();

        // removing the existing file
        remove("courses.csv");
        int status;
        // renaming the updated file with the existing file name
        status = rename("coursesnew.csv", "courses.csv");
        if (status == 0)
        {
            cout << "Details of course are updated and saved in the file! " << endl;
        }
    }
    else
    {
        cout << "Record not found\n";
    }
}
void MyOhlone::doDelete()
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("courses.csv", ios::in);

    // Create a new file to store updated data
    fout.open("coursesnew.csv", ios::out);

    // Get the course title of which the data is required
    string coursename;
    cin.ignore();
    cout << "Enter the course name: ";
    getline(cin, coursename);

    int count = 0;
    for (int i = 0; i < list->size(); i++)
    {
        if (list->at(i)->cd.CourseName.compare(coursename) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    string coursena;
    if (count >= 0 && count < list->size())
    {
        coursena = list->at(count)->cd.CourseName;
        list->erase(list->begin() + count);
        for (int index = 0; index < list->size(); index++)
        {
            // Insert the data to file
            fout << list->at(index)->cd.Term << ","
                << list->at(index)->cd.Year << ","
                << list->at(index)->cd.StartDate << ","
                << list->at(index)->cd.EndDate << ","
                << list->at(index)->cd.CourseName << ","
                << list->at(index)->cd.ClassID << ","
                << list->at(index)->cd.Section << ","
                << list->at(index)->cd.MeetingDays << ","
                << list->at(index)->cd.Location << ","
                << list->at(index)->cd.MeetingInformation << ","
                << list->at(index)->cd.Instructor << ","
                << list->at(index)->cd.Units
                << "\n";
        }

        fin.close();
        fout.close();

        // removing the existing file
        remove("courses.csv");
        int status;
        // renaming the updated file with the existing file name
        status = rename("coursesnew.csv", "courses.csv");
        if (status == 0)
        {
            cout << coursena << " (course title ) is successfully deleted from the file!" << endl;
        }
    }
    else
    {
        cout << "Record not found\n";
    }
    
}
//void MyOhlone::readData(vector <CourseDetail> Courses) 
//{
//    
//    for (int i = 0; i < list->size(); i++)
//    {
//        list->at(i)->ReadRecord(Courses);
//    }
//}


/*******************************************************

 * Program Name: Lab 2 - MyOhlone

 * Author: Abdarrahman Ayyaz

 * Date: 03/05/22

 * Description: Developing a program that displays login menu and also lets student go into profile and see information while keeping track of login and logout time.
 *******************************************************/
#include <iostream>
#include "logininfo.h"
#include "studenttype.h"
#include "myohlone.h"
using namespace std;
//if initialize that is what it is, in this case it is l
enum LoginMenu {Login = 'l', Create = 'c', Reset = 'r', ExitMenu = 'x' };
enum MainMenu {
    StudentProfile = 'p', Myohlone = 's', Logout = 'o', ExitLoginMenu = 'x'
};
char loginMenu(vector <LoginInfo>&);
char studentProfileMenu(vector <StudentType>&);
char OhloneMenu(MyOhlone*);
char mainMenu();

int main()
{
    //vector which is linked to logininfo
    vector <LoginInfo> logobj;
    
    //MyOhlone* ptrOhlone = new MyOhlone(); // create an instance of myOhlone
    ////if call to function ->

    //delete ptrOhlone;
    char flagvalue;
    do
    {
        flagvalue = loginMenu(logobj);
        
    } while (flagvalue != 'x');
    

    return 0;
}
//vector is referenced here for menu function
char loginMenu(vector <LoginInfo>& logobj)
{
    vector <StudentType> Studentobj;
    LoginInfo li;
    //MyOhlone* ptrOhlone = NULL;
    logobj = li.LoadData();
    //li.DisplayRecord(logobj);
    char ch, mainch, stuch;
    //bool flag = true;
    cout << "Login Menu" << endl;
    cout << "=====================" << endl;
    cout << "l - Login - prompt the user - username and password, and authentication" << endl;
    cout << "c - Create Account" << endl;
    cout << "r - Reset Password" << endl;
    cout << "x - Exit login menu" << endl;
    cout << "Enter choice: ";
    cin >> ch;
    string username, password;
    MyOhlone* ptrOhlone = new MyOhlone();
    char ohlonech;
    //needed with enum
    LoginMenu choice = static_cast<LoginMenu>(ch);
    switch (choice)
    {
    case Login:
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (li.UserAuthentication(username, password, logobj))
        {
            li.UpdateLoginDateTime(username, logobj);
            do
            {
                mainch = mainMenu();
                if (toupper(mainch) == 'P')
                {
                    do
                    {
                        stuch = studentProfileMenu(Studentobj);
                    } while (stuch != 'x');
                }
                else if (toupper(mainch) == 'S')
                {
                    do
                    {
                        ohlonech = OhloneMenu(ptrOhlone);
                    } while (ohlonech != 'x');
                }
            } while (mainch != 'o');
            li.UpdateLogoutDateTime(username, logobj);
        }
        return 'l';
        break;
    case Create:
        li.CreateAccount(logobj);
        return 'c';
        break;
    case Reset:
        li.ResetPassword(logobj);
        return 'r';
        break;
    case ExitMenu:
        return 'x';
        break;
    default:
        break;
    }
    //return flag;
}

char mainMenu() {
    char ch = 'x';
    cout << "Main Menu" << endl;
    cout << "====================" << endl;
    cout << "p) Student Profile" << endl;
    cout << "s) MyOhlone" << endl;
    cout << "o) Logout" << endl;
    cout << "x) Exit Login Menu" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    MainMenu choice = static_cast<MainMenu>(ch);
    switch (choice)
    {
    case StudentProfile:
        return ch;
        break;
    case Myohlone:
        return ch;
        break;
    case Logout:
        return ch;
        break;
    case ExitLoginMenu:
        //return 'x';
        exit(0);
        break;
    default:
        break;
    }
    return ch;
}

char studentProfileMenu(vector <StudentType>& studentobj)
{
    StudentType sobj;
    studentobj = sobj.LoadData();
    char info;
    cout << "Student Profile Menu" << endl;
    cout << "=====================" << endl;
    cout << "s) Show student profile: First Name, Last Name, student ID, address, city, state, zip, phone" << endl;
    cout << "e) Edit student profile" << endl;
    cout << "x) Exit" << endl;
    cout << "Enter your choice: ";
    cin >> info;
    StudentMenu choice = static_cast<StudentMenu>(info);
    switch (choice)
    {
    case Show:
        sobj.ShowData(studentobj);
        break;
    case Edit:
        sobj.EditStudentRecord(studentobj);
        break;
    case ExitStudentMenu:
        //return 'x';
        break;
    default:
        break;
    }
    return info;
}

char OhloneMenu(MyOhlone* ptrOhlone) {
    //vector <CourseDetail> Courses;
    //Courses = ptrOhlone->LoadData();
    
    char ch = 'x';
    cout << "Ohlone Menu" << endl;
    cout << setw(20) << setfill('-') << " " << endl;
    cout << setfill(' ');
    cout << "l - Display list of courses" << endl;
    cout << "v - View course details" << endl;
    cout << "a - Add a course" << endl;
    cout << "e - Edit a course" << endl;
    cout << "d - Delete a course" << endl;
    cout << "x - Exit program" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    ohloneMenu choice = static_cast<ohloneMenu> (ch);
    switch (choice)
    {
        case Display:
            cout << "display" << endl;
            ptrOhlone->doDisplay();
            system("pause>0");
            return ch;
    		break;
    	case View:
            ptrOhlone->doView();
            return ch;
            break; 
        case Add:
            ptrOhlone->doAdd();
            break;
    	case Edito:
            ptrOhlone->doEdit();
            break;
    	case Delete:
            ptrOhlone->doDelete();
            break;
    	case Exit:
            return ch;
            break;
    	default:
    		break;
    	}
    return ch;
}

//#include <iostream>
//#include <string>
//#include "myOhlone.h"
//
//#include "LoginInfo.h"
//
//using  namespace std;
//
//// prototype
//char mainMenu();
//
//int main() {
//    //MyOhlone* ptrOhlone = new MyOhlone(); // create an instance of myOHlone
//    MyOhlone myOhlone;
//    MyOhlone* ptrOhlone = &myOhlone;
//
//    char ch = ptrOhlone->loginMenu();
//    if (ch == 'l') // login
//    {
//        if (ptrOhlone->doLogin()) {
//            mainMenu();
//        }
//        else {
//            cout << "Fail to login!" << endl;
//        }
//    }
//    else if (ch == 'c') // create account
//    {
//        //doCreateAccount();
//    }
//    else if (ch == 'r') // reset pswd {
//    {
//        // doResetPswd();
//    }
//    else if (ch == 'x') // exit login menu
//    {
//        // exit - bye!
//    }
//    delete ptrOhlone;
//
//    return 0;
//}
//

//
//
//char studentProfileMenu() {
//
//    // TODO...
//    cout << "====================" << endl;
//
//    //"s) Show student profile : First Name, Last Name, student ID, address, city, state, zip, phone
//
//    cout << "e) Edit student profile" << endl;
//
//    cout << "x) Exit" << endl;
//
//    char ch = 'x';
//    return ch;
//}


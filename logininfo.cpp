#include "logininfo.h"
using namespace std;
//users data is being stored in the vector from the file
/*******************************************************

 * Function Name: LoadData

 * Purpose: Users data stored in the vector from the file

 * Parameter: none

 * Return: obj

 *******************************************************/
vector <LoginInfo> LoginInfo::LoadData()
{
    vector <LoginInfo> obj;

    LoginInfo loginfo;
    string line;
    int lineNum = 0;
    // File pointer
    fstream fin;
    //variable gets declared for filehandling

    // Open an existing file
    fin.open("users.csv", ios::in); // second is the mode

    string sDay, sMonth, sYear, sTime, sHH, sMM, sSS;
    DateTime d1;
    
    while (getline(fin, line))
    {
        //if values will be diferent initializations
        istringstream iss(line);
        lineNum++;

        // Try to extract login Information from the line. If successful, ok will be true.
        bool ok = false;
        do
        {
            if (!getline(iss, loginfo.username, ','))
                //parsing through first line and will seperate at comma
                break;
            if (!getline(iss, loginfo.password, ','))
                break;
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
            loginfo.loginDateTime.SetMonth(atoi(sMonth.c_str()));
            loginfo.loginDateTime.SetDay(atoi(sDay.c_str()));
            loginfo.loginDateTime.SetYear(atoi(sYear.c_str()));
            loginfo.loginDateTime.SetHours(atoi(sHH.c_str()));
            loginfo.loginDateTime.SetMinutes(atoi(sMM.c_str()));
            loginfo.loginDateTime.SetSeconds(atoi(sSS.c_str()));

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
            loginfo.logoutDateTime.SetMonth(atoi(sMonth.c_str()));
            loginfo.logoutDateTime.SetDay(atoi(sDay.c_str()));
            loginfo.logoutDateTime.SetYear(atoi(sYear.c_str()));
            loginfo.logoutDateTime.SetHours(atoi(sHH.c_str()));
            loginfo.logoutDateTime.SetMinutes(atoi(sMM.c_str()));
            loginfo.logoutDateTime.SetSeconds(atoi(sSS.c_str()));
            ok = true;
        } while (false);
        // If all is well, add the user to user-vector.
        if (ok)
        {
            obj.push_back(loginfo);
        }
        else
        {
            cout << "Failed to parse line " << lineNum << ": " << line << endl;
        }
    }
    fin.close();
    return obj;
}
/*******************************************************

 * Function Name: DisplayRecord

 * Purpose: displaying the user info

 * Parameter: referenced vector object

 * Return: none

 *******************************************************/
void LoginInfo::DisplayRecord(vector <LoginInfo> obj)
{
    int usernumber = 1;
    for (int i = 0; i < obj.size(); i++)
    {
        cout << setw(40) << setfill('+') << " " << endl;
        cout << setfill(' ');
        cout << "User Number " << usernumber << ":" << endl;
        cout << "Name: " << setw(18) << " " << obj[i].getUser() << "\nPassword: " << setw(18) << " " << obj[i].getPass() << "\nLogin Date: " << setw(12) << " " << obj[i].loginDateTime.GetMonth() << "-" << obj[i].loginDateTime.GetDay() << "-" << obj[i].loginDateTime.GetYear() << " " << obj[i].loginDateTime.GetHours() << ":" << obj[i].loginDateTime.GetMinutes() << ":" << obj[i].loginDateTime.GetSeconds() << "\nLogout Date: " << setw(12) << " " << obj[i].logoutDateTime.GetMonth() << "-" << obj[i].logoutDateTime.GetDay() << "-" << obj[i].logoutDateTime.GetYear() << " " << obj[i].logoutDateTime.GetHours() << ":" << obj[i].logoutDateTime.GetMinutes() << ":" << obj[i].logoutDateTime.GetSeconds() << endl;
        cout << setw(40) << setfill('+') << " " << endl;
        cout << setfill(' ');
        usernumber++;
    }
}
/*******************************************************

 * Function Name: UserAuthentication

 * Purpose: checking username and password and comparing them to ensure the data is available in file

 * Parameter: string user, string pass, referenced vector object

 * Return: none

 *******************************************************/
bool LoginInfo::UserAuthentication(string user, string pass, vector <LoginInfo> obj)
{
    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if ((obj[i].getUser().compare(user) == 0) && (obj[i].getPass().compare(pass) == 0))
        {
            break;
        }
        else
        {
            count++;
        }
    }
    if (count >= 0 && count < obj.size())
    {
        cout << user << " is authenticated!" << endl;
        return true;
    }
    else
    {
        cout << "Either Username or password is wrong or not found in the database\n";
        return false;
    }
}
/*******************************************************

 * Function Name: CreateAccount

 * Purpose: creating a new account and loading in to the vector of objects

 * Parameter: referenced vector object

 * Return: none

 *******************************************************/
void LoginInfo::CreateAccount(vector <LoginInfo>& obj)
{
    /*struct tm newtime;
    __time32_t long_time;
    //char timebuf[26];
    errno_t err;
    _time32(&long_time);
    // Convert to local time.
    err = _localtime32_s(&newtime, &long_time);
    //time_t ttime = time(0);
    //tm* local_time = localtime(&ttime);*/
  time_t t = std::time (0);    // get time now
  tm *now = localtime (&t);
  //cout << (now->tm_year + 1900) << '-'
    //<< (now->tm_mon + 1) << '-' << now->tm_mday << "\n";
    //cout << (now->tm_hour ) << '-'
    //<< (now->tm_min ) << '-' << now->tm_sec << "\n";
    LoginInfo newuser;
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("users.csv", ios::out | ios::app);

    cout << "Enter the details of a new user:" << endl;
    
    cout << "UserName: ";
    string nuser;
    cin >> nuser;
    newuser.setUser(nuser);
    cout << "Password: ";
    string npass;
    cin >> npass;
    newuser.setPass(npass);
    //newuser.loginDateTime.SetMonth(1 + local_time->tm_mon);
    newuser.loginDateTime.SetMonth(now->tm_mon + 1);
    newuser.loginDateTime.SetDay(now->tm_mday);
    newuser.loginDateTime.SetYear(now->tm_year + 1900);
    newuser.loginDateTime.SetHours(now->tm_hour);
    newuser.loginDateTime.SetMinutes(now->tm_min);
    newuser.loginDateTime.SetSeconds(now->tm_sec);
    newuser.logoutDateTime.SetMonth(now->tm_mon + 1);
    newuser.logoutDateTime.SetDay(now->tm_mday);
    newuser.logoutDateTime.SetYear(now->tm_year + 1900);
    newuser.logoutDateTime.SetHours(now->tm_hour);
    newuser.logoutDateTime.SetMinutes(now->tm_min);
    newuser.logoutDateTime.SetSeconds(now->tm_sec);
    obj.push_back(newuser);
    // Insert the data to file
    fout << newuser.getUser() << ","
        << newuser.getPass() << ","
        << newuser.loginDateTime.GetMonth() << "-"
        << newuser.loginDateTime.GetDay() << "-"
        << newuser.loginDateTime.GetYear() << " "
        << newuser.loginDateTime.GetHours() << ":"
        << newuser.loginDateTime.GetMinutes() << ":"
        << newuser.loginDateTime.GetSeconds() << ","
        << newuser.logoutDateTime.GetMonth() << "-"
        << newuser.logoutDateTime.GetDay() << "-"
        << newuser.logoutDateTime.GetYear() << " "
        << newuser.logoutDateTime.GetHours() << ":"
        << newuser.logoutDateTime.GetMinutes() << ":"
        << newuser.logoutDateTime.GetSeconds() << ","
        << "\n";
    cout << "New User is successfully created!" << endl;
    fout.close();
}
/*******************************************************

 * Function Name: ResetPassword

 * Purpose: Reseting the password against the username verifying if it is available or not then updating

 * Parameter: referenced vector object

 * Return: none

 *******************************************************/
void LoginInfo::ResetPassword(vector <LoginInfo>& obj)
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("users.csv", ios::in);

    // Create a new file to store updated data
    fout.open("usersnew.csv", ios::out);

    // Get the username of which the password is being reset
    string userna, newpass, renewpass;
    cout << "Enter the Username: ";
    cin >> userna;

    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getUser().compare(userna) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    if (count >= 0 && count < obj.size())
    {
        do
        {
            cout << "Enter the new password: ";
            cin >> newpass;
            cout << "Re-enter the new password: ";
            cin >> renewpass;
            if (renewpass.compare(newpass) == 0)
            {
                obj[count].setPass(newpass);
                break;
            }
            else
            {
                cout << "Both passwords are not matched, please try again!" << endl;
            }
        } while (true);
               
        for (int index = 0; index < obj.size(); index++)
        {
            // Insert the data to file
            fout << obj[index].getUser() << ","
                << obj[index].getPass() << ","
                << obj[index].loginDateTime.GetMonth() << "-"
                << obj[index].loginDateTime.GetDay() << "-"
                << obj[index].loginDateTime.GetYear() << " "
                << obj[index].loginDateTime.GetHours() << ":"
                << obj[index].loginDateTime.GetMinutes() << ":"
                << obj[index].loginDateTime.GetSeconds() << ","
                << obj[index].logoutDateTime.GetMonth() << "-"
                << obj[index].logoutDateTime.GetDay() << "-"
                << obj[index].logoutDateTime.GetYear() << " "
                << obj[index].logoutDateTime.GetHours() << ":"
                << obj[index].logoutDateTime.GetMinutes() << ":"
                << obj[index].logoutDateTime.GetSeconds() << ","
                << "\n";
        }

        fin.close();
        fout.close();

        // removing the existing file
        remove("users.csv");
        int status;
        // renaming the updated file with the existing file name
        status = rename("usersnew.csv", "users.csv");
        if (status == 0)
        {
            cout << "New Password is updated! " << endl;
        }
    }
    else
    {
        cout << "Record not found\n";
    }
}
//whenever when a user logs in to the system it will update the login time to the file
/*******************************************************

 * Function Name: UpdateLoginDateTime

 * Purpose: Whenever a user logs in to the system it will update the login time to the file

 * Parameter: string username, referenced vector obj

 * Return: none

 *******************************************************/
void LoginInfo::UpdateLoginDateTime(string username, vector <LoginInfo>& obj)
{
    /*struct tm newtime;
    __time32_t long_time;
    errno_t err;
    _time32(&long_time);
    // Convert to local time.
    err = _localtime32_s(&newtime, &long_time);*/
     time_t t = std::time (0);    // get time now
  tm *now = localtime (&t);

    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("users.csv", ios::in);

    // Create a new file to store updated data
    fout.open("usersnew.csv", ios::out);

    //LoginInfo editlogindatetime;
    
    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getUser().compare(username) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
      //cout << (now->tm_year + 1900) << '-'
    //<< (now->tm_mon + 1) << '-' << now->tm_mday << "\n";
    //cout << (now->tm_hour ) << '-'
    //<< (now->tm_min ) << '-' << now->tm_sec << "\n";
    if (count >= 0 && count < obj.size())
    {
        obj[count].loginDateTime.SetMonth(now->tm_mon + 1);
        obj[count].loginDateTime.SetDay(now->tm_mday);
        obj[count].loginDateTime.SetYear((now->tm_year + 1900));
        obj[count].loginDateTime.SetHours(now->tm_hour);
        obj[count].loginDateTime.SetMinutes(now->tm_min);
        obj[count].loginDateTime.SetSeconds(now->tm_sec);
        for (int index = 0; index < obj.size(); index++)
        {
            // Insert the data to file
            fout << obj[index].getUser() << ","
                << obj[index].getPass() << ","
                << obj[index].loginDateTime.GetMonth() << "-"
                << obj[index].loginDateTime.GetDay() << "-"
                << obj[index].loginDateTime.GetYear() << " "
                << obj[index].loginDateTime.GetHours() << ":"
                << obj[index].loginDateTime.GetMinutes() << ":"
                << obj[index].loginDateTime.GetSeconds() << ","
                << obj[index].logoutDateTime.GetMonth() << "-"
                << obj[index].logoutDateTime.GetDay() << "-"
                << obj[index].logoutDateTime.GetYear() << " "
                << obj[index].logoutDateTime.GetHours() << ":"
                << obj[index].logoutDateTime.GetMinutes() << ":"
                << obj[index].logoutDateTime.GetSeconds() << ","
                << "\n";
        }

        fin.close();
        fout.close();

        // removing the existing file
        remove("users.csv");
        int status;
        // renaming the updated file with the existing file name
        status = rename("usersnew.csv", "users.csv");
        if (status == 0)
        {
            cout << "Login Time is updated! " << endl;
        }
    }
    else
    {
        cout << "Record not found\n";
    }
}
/*******************************************************

 * Function Name: UpdateLogoutTime

 * Purpose: Whenever a user logs out of the system it will update the log out time to the file

 * Parameter: string username, referenced vector object

 * Return: none

 *******************************************************/
void LoginInfo::UpdateLogoutDateTime(string username, vector <LoginInfo>& obj)
{
   /* struct tm newtime;
    __time32_t long_time;
    errno_t err;
    _time32(&long_time);
    // Convert to local time.
    err = _localtime32_s(&newtime, &long_time);*/
    time_t t = std::time (0);    // get time now
  tm *now = localtime (&t);
    //cout << (now->tm_year + 1900) << '-'
    //<< (now->tm_mon + 1) << '-' << now->tm_mday << "\n";
    //cout << (now->tm_hour ) << '-'
    //<< (now->tm_min ) << '-' << now->tm_sec << "\n";

    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("users.csv", ios::in);

    // Create a new file to store updated data
    fout.open("usersnew.csv", ios::out);

    //LoginInfo editlogindatetime;

    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getUser().compare(username) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    if (count >= 0 && count < obj.size())
    {
        obj[count].logoutDateTime.SetMonth(now->tm_mon + 1);
        obj[count].logoutDateTime.SetDay(now->tm_mday);
        obj[count].logoutDateTime.SetYear(now->tm_year + 1900);
        obj[count].logoutDateTime.SetHours(now->tm_hour);
        obj[count].logoutDateTime.SetMinutes(now->tm_min);
        obj[count].logoutDateTime.SetSeconds(now->tm_sec);
        for (int index = 0; index < obj.size(); index++)
        {
            // Insert the data to file
            fout << obj[index].getUser() << ","
                << obj[index].getPass() << ","
                << obj[index].loginDateTime.GetMonth() << "-"
                << obj[index].loginDateTime.GetDay() << "-"
                << obj[index].loginDateTime.GetYear() << " "
                << obj[index].loginDateTime.GetHours() << ":"
                << obj[index].loginDateTime.GetMinutes() << ":"
                << obj[index].loginDateTime.GetSeconds() << ","
                << obj[index].logoutDateTime.GetMonth() << "-"
                << obj[index].logoutDateTime.GetDay() << "-"
                << obj[index].logoutDateTime.GetYear() << " "
                << obj[index].logoutDateTime.GetHours() << ":"
                << obj[index].logoutDateTime.GetMinutes() << ":"
                << obj[index].logoutDateTime.GetSeconds() << ","
                << "\n";
        }

        fin.close();
        fout.close();

        // removing the existing file
        remove("users.csv");
        int status;
        // renaming the updated file with the existing file name
        status = rename("usersnew.csv", "users.csv");
        if (status == 0)
            //if it is successful
        {
            cout << "Logout Time is updated! " << endl;
        }
    }
    else
    {
        cout << "Record not found\n";
    }
}

void LoginInfo::setUser(string ustr)
{
    username = ustr;
}

void LoginInfo::setPass(string pstr)
{
    password = pstr;
}


string LoginInfo::getUser()
{
    return username;
}

string LoginInfo::getPass()
{
    return password;
}

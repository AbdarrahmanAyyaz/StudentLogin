#include "studenttype.h"
using namespace std;
/*******************************************************

 * Function Name: CreateStudentMenu

 * Purpose: Student menu

 * Parameter: none

 * Return: none

 *******************************************************/
void StudentType::CreateStudentMenu()
{
	char choice;
	cout << "s) Show student profile : First Name, Last Name, student ID, address, city, state, zip, phone\ne) Edit student profile\nx) Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	StudentMenu menu = static_cast<StudentMenu>(choice);
	switch (menu)
	{
	case Show:
       
		break;
	case Edit:
		break;
	case ExitStudentMenu:
		break;
	default:
		break;
	}
}
/*******************************************************

 * Function Name: LoadData

 * Purpose: loading data from students file to the vector

 * Parameter: none

 * Return: none

 *******************************************************/
//loading the data from students file to the vector
vector <StudentType> StudentType::LoadData()
{
    vector <StudentType> obj;
    StudentType tempobj;
    string line;
    int lineNum = 0;
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("students.csv", ios::in);

    while (getline(fin, line))
    {
        istringstream iss(line);
        lineNum++;

        // Try to extract student data from the line. If successful, ok will be true.
        bool ok = false;
        do
        {
            //string val;
            if (!getline(iss, tempobj.firstName, ','))
                break;
            if (!getline(iss, tempobj.lastName, ','))
                break;
            if (!getline(iss, tempobj.studentID, ','))
                break;
            //tempobj.studentID = atoi(val.c_str());
            if (!getline(iss, tempobj.address, ',')) break;
            if (!getline(iss, tempobj.city, ',')) break;
            if (!getline(iss, tempobj.state, ',')) break;
            if (!getline(iss, tempobj.zip, ',')) break;
            if (!getline(iss, tempobj.phone, ','))
                break;
            ok = true;
        } while (false);
        // If all is well, add the course to course-vector.
        if (ok)
        {
            obj.push_back(tempobj);
        }
        else
        {
            cout << "Failed to parse the line " << lineNum << ": " << line << endl;
        }
    }
    fin.close();
    return obj;
}
/*******************************************************

 * Function Name: ShowData

 * Purpose: Displaying the student data

 * Parameter: referenced vector object

 * Return: none

 *******************************************************/
//displaying the student data
void StudentType::ShowData(vector <StudentType> obj)
{
    int studentnumber = 1;
    for (int i = 0; i < obj.size(); i++)
    {
        cout << setw(35) << setfill('-') << " " << endl;
        cout << setfill(' ');
        cout << "Student Number " << studentnumber << ":" << endl;
        cout << "First Name: " << setw(5) << " " << obj[i].getfirstName() << "\nLast Name: " << setw(6) << " " << obj[i].getlastName() << "\nStudent ID: " << setw(5) << " " << obj[i].getStudentID() << "\nAddress: " << setw(8) << " " << obj[i].getaddress() << "\nCity: " << setw(11) << " " << obj[i].getcity() << "\nState: " << setw(10) << " " << obj[i].getstate() << "\nZip Code: " << setw(7) << " " << obj[i].getzip() << "\nPhone No: " << setw(7) << " " << obj[i].getphone() << endl;
        cout << setw(35) << setfill('-') << " " << endl;
        studentnumber++;
    }
}
// setting the student ID for studnets
void StudentType::setStudentID(string _StudentID)
{
    studentID = _StudentID;
}
// Editing the student information by comparing the given values and then editing the information
void StudentType::EditStudentRecord(vector <StudentType>& obj)
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("students.csv", ios::in);

    // Create a new file to store updated data
    fout.open("studentsnew.csv", ios::out);

    //StudentType editstudent;
    // Get the student ID of which the data is required
    string studentname;
    //cin.ignore();
    cout << "Enter the student ID: ";
    cin >> studentID;
    //getline(cin, studentID);

    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getStudentID().compare(studentID) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    string str;
    if (count >= 0 && count < obj.size())
    {
        cout << "Enter the new details of a student:" << endl;
        //cin.ignore();
        cout << "First Name: ";
        //getline(cin, genstr);
        cin >> str;
        obj[count].SetfirstName(str);
        cout << "Last Name: ";
        //getline(cin, genstr);
        cin >> str;
        obj[count].SetlastName(str);
        //cin.ignore();
        cout << "Student ID: ";
        cin >> str;
        obj[count].setStudentID(str);
        cin.ignore();
        cout << "Address: ";
        getline(cin, str);
        //cin >> genstr;
        obj[count].Setaddress(str);
        cout << "City: ";
        cin >> str;
        obj[count].Setcity(str);
        cout << "State: ";
        cin >> str;
        obj[count].Setstate(str);
        cout << "Zip Code: ";
        cin >> str;
        obj[count].Setzip(str);
        cout << "Phone No: ";
        cin >> str;
        obj[count].Setphone(str);
        
        for (int index = 0; index < obj.size(); index++)
        {
            // Insert the data to file
            fout << obj[index].getfirstName() << ","
                << obj[index].getlastName() << ","
                << obj[index].getStudentID() << ","
                << obj[index].getaddress() << ","
                << obj[index].getcity() << ","
                << obj[index].getstate() << ","
                << obj[index].getzip() << ","
                << obj[index].getphone()
                << "\n";
        }

        fin.close();
        fout.close();

        // removing the existing file
        remove("students.csv");
        int status;
        // renaming the updated file with the existing file name
        status = rename("studentsnew.csv", "students.csv");
        if (status == 0)
        {
            cout << "Details of student are updated and saved in the file! " << endl;
        }
    }
    else
    {
        cout << "Record not found\n";
    }
}
string StudentType::getStudentID()
{
    return studentID;
}

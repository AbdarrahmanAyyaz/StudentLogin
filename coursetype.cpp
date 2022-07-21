#include "coursetype.h"
using namespace std;

//initializing the constructor
CourseType::CourseType()
{
    cd.Term = "spring";
    cd.Year = 2022;
    cd.StartDate = "1/24/2022";
    cd.EndDate = "5/20/2022";
    cd.CourseName = "Discrete Structures";
    cd.ClassID = "CS-113-02";
    cd.Section = 85689;
    cd.MeetingDays = "T TH";
    cd.Location = "On-Campus";
    cd.MeetingInformation = "Newark";
    cd.Instructor = "Pham";
    cd.Units = 3;
}

//Loading the data from file to vector of objects
vector <CourseDetail> CourseType::LoadData()
{
    vector <CourseDetail> obj;

    string line;
    int lineNum = 0;
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("courses.csv", ios::in);

    while (getline(fin, line))
    {
        istringstream iss(line);
        lineNum++;

        // Try to extract course data from the line. If successful, ok will be true.
        bool ok = false;
        do
        {
            string val;
            if (!getline(iss, cd.Term, ','))
                break;
            if (!getline(iss, val, ','))
                break;
            cd.Year = atoi(val.c_str());
            if (!getline(iss, cd.StartDate, ',')) break;
            if (!getline(iss, cd.EndDate, ',')) break;
            if (!getline(iss, cd.CourseName, ',')) break;
            if (!getline(iss, cd.ClassID, ',')) break;
            if (!getline(iss, val, ','))
                break;
            cd.Section = atoi(val.c_str());
            if (!getline(iss, cd.MeetingDays, ',')) break;
            if (!getline(iss, cd.Location, ',')) break;
            if (!getline(iss, cd.MeetingInformation, ',')) break;
            if (!getline(iss, cd.Instructor, ',')) break;
            if (!getline(iss, val, ','))
                break;
            cd.Units = atoi(val.c_str());

            ok = true;
        } while (false);
        // If all is well, add the course to course-vector.
        if (ok)
        {
            obj.push_back(cd);
        }
        else
        {
            cout << "Failed to parse the line " << lineNum << ": " << line << endl;
        }
    }
    fin.close();
    return obj;
}
//displaying the record
void CourseType::DisplayRecord(vector <CourseDetail> obj)
{
    int coursenumber = 1;
    for (int i = 0; i < obj.size(); i++)
    {
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Course Number " << coursenumber << ":" << endl;
        cout << "Term: " << setw(18) << " " << obj[i].Term << "\nYear: " << setw(18) << " " << obj[i].Year << "\nStart Date: " << setw(12) << " " << obj[i].StartDate << "\nEnd Date: " << setw(14) << " " << obj[i].EndDate << "\nCourse Name: " << setw(11) << " " << obj[i].CourseName << "\nClass ID: " << setw(14) << " " << obj[i].ClassID << "\nSection: " << setw(15) << " " << obj[i].Section << "\nMeeting Days: " << setw(10) << " " << obj[i].MeetingDays << "\nLocation: " << setw(14) << " " << obj[i].Location << "\nMeeting Information:" << setw(4) << " " << obj[i].MeetingInformation << "\nInstructor: " << setw(12) << " " << obj[i].Instructor << "\nUnits: " << setw(17) << " " << obj[i].Units << endl;
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
        coursenumber++;
    }
}

void CourseType::ReadRecord(vector <CourseDetail> obj)
{
    // Get the course title of which the data is required
    string coursename;
    cin.ignore();
    cout << "Enter the course name: ";
    getline(cin, coursename);
    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if (ToUpperString(obj[i].CourseName).compare(ToUpperString(coursename)) == 0)
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
        cout << "Details of course is: " << endl;
        cout << "Term: " << setw(18) << " " << obj[count].Term << "\nYear: " << setw(18) << " " << obj[count].Year << "\nStart Date: " << setw(12) << " " << obj[count].StartDate << "\nEnd Date: " << setw(14) << " " << obj[count].EndDate << "\nCourse Name: " << setw(11) << " " << obj[count].CourseName << "\nClass ID: " << setw(14) << " " << obj[count].ClassID << "\nSection: " << setw(15) << " " << obj[count].Section << "\nMeeting Days: " << setw(10) << " " << obj[count].MeetingDays << "\nLocation: " << setw(14) << " " << obj[count].Location << "\nMeeting Information:" << setw(4) << " " << obj[count].MeetingInformation << "\nInstructor: " << setw(12) << " " << obj[count].Instructor << "\nUnits: " << setw(17) << " " << obj[count].Units << endl;
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
    }
    else
    {
        cout << "Record not found\n";
    }
}

void CourseType::AddRecord(vector <CourseDetail>& obj)
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("courses.csv", ios::out | ios::app);

    cout << "Enter the details of a course:" << endl;
    cin.ignore();
    cout << "Term: ";
    getline(cin, cd.Term);
    cout << "Enter the Year: ";
    cin >> cd.Year; //int
    cin.ignore();
    cout << "Enter the Start Date (MM/DD/YYYY): ";
    getline(cin, cd.StartDate);
    //cin.ignore();
    cout << "Enter the End Date (MM/DD/YYYY): ";
    getline(cin, cd.EndDate);
    //cin.ignore();
    cout << "Enter the Course Name: ";
    getline(cin, cd.CourseName);
    //cin.ignore();
    cout << "Enter the Class ID: ";
    getline(cin, cd.ClassID);
    //cin.ignore();
    cout << "Enter the Section: ";
    cin >> cd.Section;  //int
    cin.ignore();
    cout << "Enter the Meeting days (M, T, W, TH, F, S, Su): ";
    getline(cin, cd.MeetingDays);
    //cin.ignore();
    cout << "Enter the Location (online, hybrid, or on - campus): ";
    getline(cin, cd.Location);
    //cin.ignore();
    cout << "Enter the Meeting Information: ";
    getline(cin, cd.MeetingInformation);
    //cin.ignore();
    cout << "Enter the Instructor: ";
    getline(cin, cd.Instructor);
    cout << "Enter the Units: ";
    cin >> cd.Units;    //int
    obj.push_back(cd);
    // Insert the data to file
    fout << cd.Term << ","
        << cd.Year << ","
        << cd.StartDate << ","
        << cd.EndDate << ","
        << cd.CourseName << ","
        << cd.ClassID << ","
        << cd.Section << ","
        << cd.MeetingDays << ","
        << cd.Location << ","
        << cd.MeetingInformation << ","
        << cd.Instructor << ","
        << cd.Units
        << "\n";
    cout << "Course details have been successfully added into the file!" << endl;
    fout.close();
}

void CourseType::EditRecord(vector <CourseDetail>& obj)
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("courses.csv", ios::in);

    // Create a new file to store updated data
    fout.open("coursesnew.csv", ios::out);

    CourseDetail editcd;
    // Get the course title of which the data is required
    string coursename;
    cin.ignore();
    cout << "Enter the course name: ";
    getline(cin, coursename);

    int count = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if (ToUpperString(obj[i].CourseName).compare(ToUpperString(coursename)) == 0)
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
        cout << "Enter the new details of a course:" << endl;
        //cin.ignore();
        cout << "Term: ";
        getline(cin, editcd.Term);
        obj[count].Term = editcd.Term;
        cout << "Enter the Year: ";
        cin >> editcd.Year; //int
        obj[count].Year = editcd.Year;
        cin.ignore();
        cout << "Enter the Start Date (MM/DD/YYYY): ";
        getline(cin, editcd.StartDate);
        obj[count].StartDate = editcd.StartDate;
        cout << "Enter the End Date (MM/DD/YYYY): ";
        getline(cin, editcd.EndDate);
        obj[count].EndDate = editcd.EndDate;
        cout << "Enter the Course Name: ";
        getline(cin, editcd.CourseName);
        obj[count].CourseName = editcd.CourseName;
        cout << "Enter the Class ID: ";
        getline(cin, editcd.ClassID);
        obj[count].ClassID = editcd.ClassID;
        cout << "Enter the Section: ";
        cin >> editcd.Section;  //int
        obj[count].Section = editcd.Section;
        cin.ignore();
        cout << "Enter the Meeting days (M, T, W, TH, F, S, Su): ";
        getline(cin, editcd.MeetingDays);
        obj[count].MeetingDays = editcd.MeetingDays;
        cout << "Enter the Location (online, hybrid, or on - campus) ";
        getline(cin, editcd.Location);
        obj[count].Location = editcd.Location;
        cout << "Enter the Meeting Information: ";
        getline(cin, editcd.MeetingInformation);
        obj[count].MeetingInformation = editcd.MeetingInformation;
        cout << "Enter the Instructor: ";
        getline(cin, editcd.Instructor);
        obj[count].Instructor = editcd.Instructor;
        cout << "Enter the Units: ";
        cin >> editcd.Units;    //int
        obj[count].Units = editcd.Units;

        for (int index = 0; index < obj.size(); index++)
        {
            // Insert the data to file
            fout << obj[index].Term << ","
                << obj[index].Year << ","
                << obj[index].StartDate << ","
                << obj[index].EndDate << ","
                << obj[index].CourseName << ","
                << obj[index].ClassID << ","
                << obj[index].Section << ","
                << obj[index].MeetingDays << ","
                << obj[index].Location << ","
                << obj[index].MeetingInformation << ","
                << obj[index].Instructor << ","
                << obj[index].Units
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

void CourseType::DeleteRecord(vector <CourseDetail>& obj)
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
    for (int i = 0; i < obj.size(); i++)
    {
        if (ToUpperString(obj[i].CourseName).compare(ToUpperString(coursename)) == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    string coursena;
    if (count >= 0 && count < obj.size())
    {
        coursena = obj[count].CourseName;
        obj.erase(obj.begin() + count);
        for (int index = 0; index < obj.size(); index++)
        {
            // Insert the data to file
            fout << obj[index].Term << ","
                << obj[index].Year << ","
                << obj[index].StartDate << ","
                << obj[index].EndDate << ","
                << obj[index].CourseName << ","
                << obj[index].ClassID << ","
                << obj[index].Section << ","
                << obj[index].MeetingDays << ","
                << obj[index].Location << ","
                << obj[index].MeetingInformation << ","
                << obj[index].Instructor << ","
                << obj[index].Units
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

string CourseType::ToUpperString(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')   //checking for lowercase characters
            str[i] = str[i] - 32;        //converting lowercase to uppercase  
    }
    return str;
}
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include "instructor.h"
#include "student.h"

using namespace std;

void makePersonInfo(string & fName, string & lName, int & age, string & lNum);
string makeHours();
float makeGPA();

int main()
{
    srand(time(NULL));
    string fName;
    string lName;
    int age;
    string lNum;
    string officeHrs;
    float gpa;

cout << "This tests instructor code: uncomment next line to use it " << endl;
#define testInstruct
#ifdef testInstruct

    const int MAXINSTRUCTORS = 4;
    int numInstructors = 0;
    Instructor ** theInstructors = new Instructor*[MAXINSTRUCTORS];

    // create instructors
    for (int i = 0; i < MAXINSTRUCTORS; i++)
    {
        makePersonInfo(fName, lName, age, lNum);
        officeHrs = makeHours();
        theInstructors[i] = new Instructor(fName, lName, age, lNum, officeHrs);
    }

    cout << "Faculty " << endl;
    cout << " shoud show 4 instructors with names, ages, Lnumbers, and office hours\n";
    cout << "     Name      " << " Age " << " LNumber " << "   Office Hours " << endl;
    for ( int i = 0; i < MAXINSTRUCTORS; i++ )
    {
        fName = theInstructors[i]->getFirstName();
        lName = theInstructors[i]->getLastName();
        age = theInstructors[i]->getAge();
        lNum = theInstructors[i]->getLNumber();
        officeHrs = theInstructors[i]->getOfficeHours();
        cout << setw(7) << fName << setw(8) << lName << setw(4) << age <<
            setw(10) << lNum << " " << officeHrs << endl;
    }
#endif // testInstruct

cout << "\n\nThis tests student code:  uncomment next line to use it" << endl;
//#define testStudent
#ifdef testStudent

    const int MAXSTUDENTS = 8;
    int numStudents = 0;
    Student ** theStudents = new Student*[MAXSTUDENTS];

    //create students
    for (int i = 0; i < MAXSTUDENTS; i++)
    {
        makePersonInfo(fName, lName, age, lNum);
        gpa = makeGPA();
        theStudents[i] = new Student(fName, lName, age, lNum, gpa);
    }

    cout << "\n\nStudents " << endl;
    cout << " should show 8 students with names, ages, Lnumbers, and GPAS\n";
    cout << "     Name      " << " Age " << " LNumber " << " GPA " << endl;
    for ( int i = 0; i < MAXSTUDENTS; i++ )
    {
        fName = theStudents[i]->getFirstName();
        lName = theStudents[i]->getLastName();
        age = theStudents[i]->getAge();
        lNum = theStudents[i]->getLNumber();
        gpa = theStudents[i]->getGPA();
        cout << setw(7) << fName << setw(8) << lName << setw(4) << age <<
            setw(10) << lNum << setw(6) << setprecision(2) << fixed << gpa << endl;
    }
#endif // testStudent

cout << "\n\nThis tests job code:  uncomment next line to use it" << endl;
//#define testPoly
#ifdef testPoly

    const int MAXPERSONS = 3;
    int numPersons = 0;
    Person ** thePersons = new Person*[MAXPERSONS];

    cout << "\n\nShowing jobs " << endl;
    cout << "should output Test One Undefined, Test Two Instructor, Test Three Student\n";

    thePersons[0] = new Person("Test", "One", 42, "L00000001");
    thePersons[1] = new Instructor("Test", "Two", 55, "L00000002");
    thePersons[2] = new Student("Test", "Three", 21, "L00000003");

    for (int i = 0; i < MAXPERSONS; i++)
    {
        cout << thePersons[i]->getFirstName() <<" "<< thePersons[i]->getLastName()
            <<" "<< thePersons[i]->getJob() << endl;
    }
#endif //testPoly

		//cleaning up
#ifdef testInstruct
	for (int i=0; i < MAXINSTRUCTORS; i++)
    {
        delete theInstructors[i];
    }
    delete []theInstructors;
#endif

#ifdef testStudent
    for (int i=0; i < MAXSTUDENTS; i++)
    {
        delete theStudents[i];
    }
    delete []theStudents;
#endif

#ifdef testPoly
	for (int i=0; i < MAXPERSONS; i++)
	{
		delete thePersons[i];
	}
	delete []thePersons;
#endif

    return 0;
}

void makePersonInfo(string & fName, string & lName, int & age, string & lNum)
{
    const int FIRSTS = 8;
    const int LASTS = 7;
    string firstNames[FIRSTS] = {"Bill", "Mary", "John", "Nancy", "Paul", "George", "Frodo", "Linda"};
    string lastNames[LASTS] = {"Jones", "Smith", "Green", "White", "Baggins", "Dunhill", "Bourne"};

    const int MINAGE = 18;
    const int AGERANGE = 40;

    const int LRANGE = 1000000;

    stringstream ss;

    fName = firstNames[rand()%FIRSTS];
    lName = lastNames[rand()%LASTS];
    age = rand()%AGERANGE + MINAGE;
    ss << "L00" << setw(6) << setfill('0') << rand()%LRANGE;
    lNum = ss.str();
}

string makeHours()
{
    const int NUMHRS = 9;
    string someHours[NUMHRS] = {"8-9", "9-10", "10-11", "11-12", "12-1", "1-2", "2-3", "3-4", "4-5"};

    stringstream ss;

    return "Mon:" + someHours[rand()%NUMHRS] + " Tue:" + someHours[rand()%NUMHRS]
        + " Wed:" + someHours[rand()%NUMHRS] + " Thu:" + someHours[rand()%NUMHRS];
}

float makeGPA()
{
    return rand()%3+2 + static_cast<float>(rand()%100)/100.0;
}

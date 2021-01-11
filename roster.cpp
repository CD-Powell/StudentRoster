#include "roster.h"

void Roster::parse(string studentinfo) /* parses each row of student info data - one row at a time */
{
	DegreeProgram dn = UNDECIDED; /* Default value for degree program */
	if (studentinfo.at(9) == 'NETWORK') dn = NETWORK; /* Booktype is identified by THIRD character of degree program at index 2 */
	else if (studentinfo.at(9) == 'SECURITY') dn = SECURITY;
	else if (studentinfo.at(9) == 'SOFTWARE') dn = SOFTWARE;

	int right = studentinfo.find(","); // first substring
	string sID = studentinfo.substr(0, right); // extract student's ID

	int left = right + 1; // second substring begin, move past comma
	right = studentinfo.find(",", left);
	string sFirst = studentinfo.substr(left, right - left); // extract student's first name

	left = right + 1; // third substring begin, move past comma, continue going
	right = studentinfo.find(",", left);
	string sLast = studentinfo.substr(left, right - left); // extract student's last name

	left = right + 1;
	right = studentinfo.find(",", left);
	string sEmail = studentinfo.substr(left, right - left); // extract student's email

	left = right + 1;
	right = studentinfo.find(",", left);
	int sAge = stoi(studentinfo.substr(left, right - left)); // extract student's age

	left = right + 1;
	right = studentinfo.find(",", left);
	int sDays1 = stoi(studentinfo.substr(left, right - left)); // extract days 1

	left = right + 1;
	right = studentinfo.find(",", left);
	int sDays2 = stoi(studentinfo.substr(left, right - left)); // extract days 2

	left = right + 1;
	right = studentinfo.find(",", left);
	int sDays3 = stoi(studentinfo.substr(left, right - left)); // extract days 3
	
	left = right + 1;
	right = studentinfo.find(",", left);
	string dn = studentinfo.substr(left, right - left); // extract degree name

	add(sID, sFirst, sLast, sEmail, sAge, sDays1, sDays2, sDays3, dn);
}

/* Add method for roster */
void Roster::add(string sID, string sFirst, string sLast, string sEmail, int sAge, int sDays1, int sDays2, int sDays3, DegreeProgram dn)
{
	/* Adding days back into an array for the constructor */
	const int arrayOfDays[3] = { sDays1,sDays2,sDays3 };
	/* Creation of new student objects at lastIndex starting at -1 */
	/* Using full constructor of student objects */
	classRosterArray[++lastIndex] = new Student(sID, sFirst, sLast, sEmail, sAge, arrayOfDays, dn);
}


void Roster::removeStudentByID(string id)	/* Remove method to remove students individually by student's ID */
{
	bool exists = false;	/* assume student id is not here initially */
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == id)
		{
			exists = true; /* student id is found, student (id) exists */
			if (i < numStudents - 1)
			{
				Student* hold = classRosterArray[i];	/* creates a temporary space to hold student data in an array */
				classRosterArray[i] = classRosterArray[numStudents - 1];	/* points to the last index position in the temp array */
				classRosterArray[numStudents - 1] = hold;	/* assigns current position as the last index position on the temp array */
			}
			Roster::lastIndex--;	/* decrements lastIndex so that last position of index in student data array is no longer visible */
		}
	}
	if (exists)
	{
		cout << id << " deleted from Student Class Roster." << endl << endl;
		this->printAll(); /* displays printout of all students in classRosterArray; correct if removed student does NOT display */
	}
	else cout << "No student with " << id << " found." << endl << endl << endl;
}


/* Prints a complete tab-separated list of all students in the student data table */
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}


/* Prints a student's average number of days in the three courses, identified by student's ID */
void Roster::printAverageDays(string id)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == id)
		{
			cout << id << ": ";
			cout << (
				classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3.0 << endl;
		}
	}
}


/* Verification of student's email addresses; displays all invalid email addresses */
/* Note: a valid email should include an at sign ('@') and period (".") and should not include a space (" "). */
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = classRosterArray[i]->getEmail();
		if ((email.find("@") == string::npos) ||
			(email.find(".") == string::npos) ||
			(email.find(" ") != string::npos))
		{
			cout << email << ": " << classRosterArray[i]->getFirst() << " " << classRosterArray[i]->getLast() << endl;
		}
	}
}


/* Display only books which match a given degree name */
void Roster::printByDegreeName(DegreeProgram dn)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeName() == dn) classRosterArray[i]->print();
	}
}


Roster::~Roster() /* Destructor */
{
	cout << "Calling destructor " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Deleting index entry #" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
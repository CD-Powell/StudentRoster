#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

	void parse(string studentinfo);
	void add(string sID,
		string sFirst,
		string sLast,
		string sEmail,
		int sAge,
		int sDays1,
		int sDays2,
		int sDays3,
		DegreeProgram dn);

	void printAll();						     //Calling the print method for each student
	void printByDegreeName(DegreeProgram dn);   //Degree name is passed in
	void printInvalidEmails();				   //Prints invalid emails; Email should include at sign ('@') AND period ('.') and should NOT include a space (' ')
	void printAverageDays(string id);		  //Prints the average days per course for each student
	void removeStudentByID(string id);       //Remove student by student's ID
	~Roster();								// Destructor
};
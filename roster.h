#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

	void parse(string row);
	void add(string ID,
		string First,
		string Last,
		string Email,
		double Age,
		double Days1,
		double Days2,
		double Days3,
		DegreeProgram dn);

	void printAll();						     //Calling the print method for each student
	void printByDegreeName(DegreeProgram dn);   //Degree name is passed in
	void printInvalidEmails();				   //Prints invalid emails
	void printAverageDays(string ID);		  //Prints the average days per course for each student
	void removeStudentByID(string ID);       //Remove student by student's ID
	~Roster();		/* Destructor */
};
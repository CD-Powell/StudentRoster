#pragma once
#include <iostream>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

class Student	/* Creation of Student class */
{
public:
	const static int numDaysArraySize = 4;

	string id;					          //Student's ID number
	string first;					     //Student's first name
	string last;					    //Student's last name
	string email;					   //Student's email address
	double age;						  //Student's current age
	double days[numDaysArraySize];	 //Array of number of days to complete each course for current term
	DegreeProgram degreeName;		//Name of student's declared degree program

	Student();		 /* Parameterless constructor for Student class setting Student to default values */
	Student(		/* Start of full constructor */
		string id,
		string first,
		string last,
		string email,
		double age,
		double days[],
		DegreeProgram degreeName);	/* End of full constructor */
	~Student();	 /* Destructor */

	/* Getters (Accessors) */
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	double getAge();
	double* getDays();
	DegreeProgram getDegreeName();

	/* Setters (Mutators) */
	void setID(string id);
	void setFirst(string first);
	void setLast(string last);
	void setEmail(string email);
	void setAge(double age);
	void setDays(double days[]);
	void setDegreeName(DegreeProgram dn);

	static void printHeader(); /* Displays a header for the data to follow below it to be identified */

	void print(); /* Displays the current/active student's data */
};
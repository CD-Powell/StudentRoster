#pragma once
#include "degree.h"
#include "student.h"

using std::cout;
using std::endl;
using std::string;

Student::Student() /* Parameterless constructor —— sets class to default values*/
{
	this->id = "";
	this->first = "";
	this->last = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < numDaysArraySize; i++) this->days[i] = days[0];
	this->degreeName = DegreeProgram::UNDECIDED;
}

Student::Student(string id, string first, string last, string email, double age, double days[], DegreeProgram degreeName) /*Full Constructor*/
{
	this->id = id;
	this->first = first;
	this->last = last;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numDaysArraySize; i++) this->days[i] = days[i];
	this->degreeName = degreeName;
}

Student::~Student() {};		/*Destructor*/

string Student::getID() { return this->id; }
string Student::getFirst() { return this->first; }
string Student::getLast() { return this->last; }
string Student::getEmail() { return this->email; }
double Student::getAge() { return this->age; }
double* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeName() { return this->degreeName; }

void Student::setID(string id) { this->id = id; }
void Student::setFirst(string first) { this->first = first; }
void Student::setLast(string last) { this->last = last; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(double age) { this->age = age; }
void Student::setDays(double days[])
{
	for (int i = 0; i < numDaysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeName(DegreeProgram dn) { this->degreeName = dn; }

void Student::printHeader() /*Print the header*/
{
	cout << "Output format: Student ID|First Name|Last Name|Email|Age|Average Days\n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirst() << '\t';
	cout << this->getLast() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeName()] << '\n';
}
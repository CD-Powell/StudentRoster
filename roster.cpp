/*order is parse method, add method, printAll method, printByBookType, printInvalidIDs method,
printByAveragePrices, removal removeBookByID, destructor*/ 

#include "roster.h"

void Roster::parse(string studentinfo) /* parses each row of student info data - one row at a time */
{
	DegreeProgram dn;
	if (studentinfo.at(2) == 'T') dn = NETWORK;
	else if (studentinfo.at(2) == 'C') dn = SECURITY;
	else if (studentinfo.at(2) == 'F') dn = SOFTWARE;
	else dn = UNDECIDED;
	{

	}
	{

	} (studentinfo.at(2) ==

	if (bookdata.at(0) == 'F') bt = FICTION;
	else if (bookdata.at(0) == 'N') bt = NONFICTION;
	else bt = UNDECIDED;
}

 
ROSTER::ROSTER () /* Parameterless constructor —— sets class to default values*/


/*
The entire student list will be stored in one array of students called classRosterArray. Specific
data-related output will be directed to the console.


const string studentData[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Christopher,Powell,cpow181@wgu.edu,33,14,26,8,SOFTWARE"
*/
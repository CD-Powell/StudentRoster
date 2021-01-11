#include "roster.h"

int main()
{
	/* FULL STRINGS TO PARSE INTO INDIVIDUAL DATA*/
	const string studentinfo[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Christopher,Powell,cpow181@wgu.edu,33,14,26,8,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster; /* Default parameterless constructor for roster*/


	/* Printall for the parsed student data */
	for (int i = 0; i < numStudents; i++) roster.parse(studentinfo[i]);
	cout << "Displaying all students: " << std::endl;
	roster.printAll();


	/* Print students by degree program. Example shown is using SOFTWARE students */
	for (int i = 0; i < 4; i++)
	{
		cout << "Displaying by degree program:" << degreeProgramStrings[i] << std::endl;
		roster.printByDegreeName((DegreeProgram)SOFTWARE);
	}

	/* Displays invalid emails based on established parameters for what are invalid emails */
	cout << "Displaying invalid emails:" << std::endl;
	roster.printInvalidEmails();

	/* Showing the average course days for each student */
	cout << "Displaying average course days:" << std::endl;
	for (int i = 0; i < roster.lastIndex; i++)
	{
		roster.printAverageDays(roster.classRosterArray[i]->getID());

		/* Removing student object by id. Showing using example ID of A3 */
		cout << "Removing student with ID A3" << std::endl;
		roster.removeStudentByID("A3"); cout << std::endl;
	}
};
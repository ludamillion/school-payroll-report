// This program reads employee information from two files
// and sorts them alphabetically into departments and
// finally prints a control-break payroll report
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010

#include "payrolllib.h"

int main(int argc, char** argv)
{
	RecordTree tree[5]; // Creates a RecordTree object for each department
	Payroll p1;
	double wage = 0;
	double hours = 0;
	double wageAdjustment = 0;
	int dependents = 0;
	int id = 0;
	string firstName;
	string lastName;
	char department;
	char married;
	char insured;
	
	system("cls");

	// Checks for the correct number of arguments
	// Prints a proper usage message if number of args is incorrect
	if (argc != 3)
	{
		cout << "Error: Invalid Arguements" << endl;
		cout << "Usage: Payroll [file 1] [file 2]" << endl;
		pause();
		exit(1);
	}

	// Opens files entered in command-line for reading
	ifstream dFile1(*(argv + 1), ios::in);
	ifstream dFile2(*(argv + 2), ios::in);

	// Prints error and exits if either file fails to open properly
	if (!dFile1 || !dFile2)
	{
		cout << "Error: Could not load file \'";
		cout << (!dFile1 ? *(argv + 1) : *(argv + 2)) << '\'' << endl;
		pause();
		exit(2);
	}

	// Reads through the two files and stores the values in temporary
	// variables.
	while (dFile1 >> id)
	{
		dFile1 >> lastName >> firstName >> wage >> hours >> department;
		dFile2 >> id >> wageAdjustment >> married >> dependents >> insured;

		// Assigns the employee information to the corresponding fields
		// in the temporary Payroll object
		p1.setID(id);
		p1.setLastName(lastName);
		p1.setFirstName(firstName);
		p1.setWage(wage);
		p1.setHours(hours);
		p1.setDepartment(department);
		p1.setWageAdjustment(wageAdjustment);
		p1.setMarried(married);
		p1.setDependents(dependents);
		p1.setInsured(insured);

		// Determines the gross pay for the current employee
		p1.adjustGross();
		
		// Creates a node and stores the current employee Payroll object
		// in the RecordTree object correspanding to their department.
		tree[charToInt(department)].insertNode(p1);
	}

	printReport(tree);
	pause();
	return 0;
}

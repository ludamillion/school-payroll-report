// Implementation file for the methods used in the payroll program
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010

#include "payrolllib.h"

void pause()
{
	cout << "\nPress Enter to continue...";
	cin.ignore();
	exit(0);
}

void printHeader()
{
	cout << left << setw(6) << "\nID";
	cout << setw(11) << "Last";
	cout << setw(10) << "First";
	cout << setw(10) << "Gross";
	cout << setw(10) << "FICA";
	cout << setw(8) << "Fed";
	cout << setw(10) << "State";
	cout << setw(6) << "Ins";
	cout << setw(9) << "Net Pay";
	cout << endl << endl;
}

// Converts the department designation character
// from the file into an index for the RecordTree array
int charToInt(char dept)
{
	switch(dept)
	{
	case 'A': return 0;
	case 'M': return 1;
	case 'Q': return 2;
	case 'S': return 3;
	case 'H': return 4;
	default: return ' '; // This just supresses a warning from VS 2008
	}
}

string getDepartment(int dept)
{
	switch(dept)
	{
	case 0: return "Accounting";
	case 1: return "Manufacturing";
	case 2: return "Quality Control";
	case 3: return "Sales";
	case 4: return "Shipping";
	default: return ""; // Again this supresses a warning from VS 2008
	}
}

// Does the actual work of printing out the control-break report
void printReport(RecordTree tree[])
{
	double subTotal = 0;
	double grandTotal = 0;
	
	for (int i = 0; i < 5; i++)
	{
		cout << "Department: " << getDepartment(i) << endl;
		printHeader();
		tree[i].displayInOrder();
		tree[i].accumulateNet(subTotal);
		grandTotal += subTotal;

		cout << endl << setw(32) << "" << left << "Subtotal:" 
			 << right << setw(36) << subTotal << endl << endl;
		subTotal = 0;
	}
	
	cout << setw(32) << "" << left << "Grand Total:" 
		 << right << setw(33) << grandTotal << endl << endl;
}
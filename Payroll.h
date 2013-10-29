// This is the definition files for the payroll class
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010
//
// Comments on code in corresponding implementation file

#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>
using namespace std;

class Payroll
{
private:
	int id;
	int dependents;
	string lastName;
	string firstName;
	char department;
	bool married;
	bool insured;
	double wageAdjustment;
	double wage;
	double hours;
	double grossPay;	
	double adjustedGross;

public:
	Payroll() {}
	Payroll(Payroll &);
	
	~Payroll() {}

	void setID(int);
	void setDependents(int);
	void setLastName(string);
	void setFirstName(string);
	void setDepartment(char);
	void setMarried(char);
	void setInsured(char);
	void setWageAdjustment(double);
	void setWage(double);
	void setHours(double);
	void setGrossPay(double);

	void adjustGross();
	
	int getID();
	char getDept();
	double getGross();
	double getFICA();
	double getFedTax();
	double getStateTax();
	double getInsurence();
	double getNetPay();
	string getLastName();
	string getFirstName();

	bool operator < (Payroll);
	bool operator == (Payroll);
	bool operator > (Payroll);
};
#endif
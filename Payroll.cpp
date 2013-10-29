// Implementation file for the Payroll class
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010
//
// Most of this class should be self-explanatory
// It is mostly setters and getters. The getters
// use the formulas from the spec-sheet to determine
// the value returned

#include "Payroll.h"

Payroll::Payroll(Payroll &obj)
{
	id = obj.id;
	dependents = obj.dependents;
	lastName = obj.lastName;
	firstName = obj.firstName;
	department = obj.department;
	married = obj.married;
	insured = obj.insured;
	wageAdjustment = obj.wageAdjustment;
	wage = obj.wage;
	hours = obj.hours;
	grossPay = obj.grossPay;	
	adjustedGross = obj.adjustedGross;
}

void Payroll::setID(int id)
{ this->id = id; }

void Payroll::setDependents(int dependents)
{ this->dependents = dependents; }

void Payroll::setLastName(string name)
{ this->lastName = name; }

void Payroll::setFirstName(string name)
{ this->firstName = name; }

void Payroll::setDepartment(char dept)
{ this->department = dept; }

void Payroll::setMarried(char married)
{ 
	if (married == 'M')
		this->married = true;
	else
		this->married = false;
}

void Payroll::setInsured(char insured)
{ 
	if (insured == 'Y')
		this->insured = true;
	else
		this->insured = false;
}

void Payroll::setWageAdjustment(double wageAdjustment)
{ this->wageAdjustment = (wageAdjustment/100.00); }

void Payroll::setWage(double wage)
{ this->wage = wage; }

void Payroll::setHours(double hours)
{ this->hours = hours; }

void Payroll::setGrossPay(double)
{ this->grossPay = grossPay; }

void Payroll::adjustGross()
{
	double gross = 0;
	
	if (hours <= 40)
		gross = wage * hours;
	else
		gross = (wage * 40) + (wage * ((hours - 40) * 1.5));

	if (wageAdjustment < 0)
		adjustedGross = gross - (gross * (-wageAdjustment));
	else
		adjustedGross = gross + (gross * wageAdjustment);
}

int Payroll::getID()
{ return id; }

char Payroll::getDept()
{ return department; }

double Payroll::getGross()
{ return adjustedGross; }

double Payroll::getFICA()
{ return adjustedGross * 0.08; }

double Payroll::getFedTax()
{
	double tempGross = adjustedGross;

	if(married)
		tempGross -= 25.00 * dependents;
	else
		tempGross -= 15.00 * dependents;

	if (adjustedGross < 101.0)
		return tempGross * 0.15;
	else if (adjustedGross < 201.0)
		return tempGross * 0.18;
	else if (adjustedGross < 301.0)
		return tempGross * 0.19;
	else if (adjustedGross < 401.0)
		return tempGross * 0.20;
	else
		return tempGross * 0.25;
}

double Payroll::getStateTax()
{
	double tempGross = adjustedGross;

	if(married)
		tempGross -= 15.00 * dependents;
	else
		tempGross -= 10.00 * dependents;

	return tempGross * 0.0595;
}

double Payroll::getInsurence()
{
	double deduction = 0;

	if (insured)
	{
		if (married)
			deduction = 0.04;
		else
			deduction = 0.02;
	}

	return adjustedGross * deduction;
}

double Payroll::getNetPay()
{ 
	double deductions = getFICA() + getFedTax() + getStateTax() + getInsurence();
	return adjustedGross - deductions;
}

string Payroll::getLastName()
{ return lastName; }

string Payroll::getFirstName()
{ return firstName; }

// These operator overloads are required in order for
// each employee's payroll object to be sorted correctly 
// in the RecordTree.
bool Payroll::operator < (Payroll other)
{
	bool status = false;

	// Compares last names
	if (this->getLastName() < other.getLastName())
		status = true;
	else if (this->getLastName() > other.getLastName())
		status = false;
	else // If last names match compares firstnames
	{
		if (this->getFirstName() < other.getFirstName())
			status = true;
		else if (this->getFirstName() > other.getFirstName())
			status = false;
	}
	return status;
}

bool Payroll::operator > (Payroll other)
{
	bool status = false;

	if (this->getLastName() > other.getLastName())
		status = true;
	else if (this->getLastName() < other.getLastName())
		status = false;
	else
	{
		if (this->getFirstName() > other.getFirstName())
			status = true;
		else if (this->getFirstName() < other.getFirstName())
			status = false;
	}
	return status;
}

bool Payroll::operator == (Payroll other)
{
	bool status = false;

	if ((this->getLastName() == other.getLastName()) && 
		(this->getFirstName() == other.getFirstName()) )
			status = true;
	
	return status;
}
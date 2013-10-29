// Prototypes for the methods and libraries used in the payroll program
//
// Programmer: Luke Inglis
// Class: CIT-237
// Date: Last Modified, 4/21/2010
//
// Comments on code in corresponding implementation file


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ios;

#include <string>

#include <iomanip>
using std::setw;

#include "Payroll.h"
#include "RecordTree.h"

void pause();
void printHeader();
string getDepartment(int);
int charToInt(char);
void printReport(RecordTree[]);
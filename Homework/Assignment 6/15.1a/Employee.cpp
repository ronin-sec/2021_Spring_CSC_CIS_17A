//Implementation of the employee class, contains the definition of all
//class functions/methods.

#include "Employee.h"
using namespace std; 


Employee::Employee(const string& name, int number, const string& hireDate)
	: name(name), number(number), hireDate(hireDate)
{ }

void Employee::SetName(const string & name)
{
	this->name = name;
}

void Employee::SetNumber(int number)
{
	this->number = number;
}

void Employee::SetHireDate(const string& hireDate)
{
	this->hireDate = hireDate;
}

string Employee::GetName() const
{
	return name;
}

int Employee::GetNumber() const
{
	return number;
}

string Employee::GetDate() const
{
	return hireDate;
}

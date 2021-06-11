
#pragma once

#include <string>

using std::string;

class Employee
{
private:
	string name;
	int number;
	string hireDate;

public:
	Employee(const string& name = "NoName", int number = 0, const string& hireDate = "0/0/0");
	void SetName(const string& name);
	void SetNumber(int number);
	void SetHireDate(const string& hireDate);
	string GetName() const;
	int GetNumber() const;
	string GetDate() const;
};
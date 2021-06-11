#include <iostream>

#include "Date.h"
using namespace std;

string Date::GetMonthName() const
{
	switch (month)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "ERROR MONTH";
	}
}

Date::Date(int month, int day, int year)
	: month(1), day(1)
{
	if (day < 1 || day > 12)
		throw InvalidDay();

	if (month < 1 || month > 12)
		throw InvalidMonth();

	this->month = month;
	this->day = day;
	this->year = year;
}

void Date::Show(Representing representing) const
{
	switch (representing)
	{
	case Date::Representing::BY_SLASH:
		cout << month << "/" << day << "/" << year << endl;
		break;

	case Date::Representing::MONTH_DAY_COMA_YEAR:
		cout << GetMonthName() << " " << day << ", " << year << endl;
		break;

	case Date::Representing::DAY_MONTH_YEAR:
		cout << day << " " << GetMonthName() << " " << year << endl;
		break;

	default:
		cout << "Incorrect representing.\n";
		break;
	}
}

void InvalidDay::ShowErrorMessage() const
{
	cout << "Invalid day has been passed to the class.\n";
}

void InvalidMonth::ShowErrorMessage() const
{
	cout << "Invalid month has been passed to the class.\n";
}
#include <iostream>

#include "DayOY.h"

using std::cout;
using std::cerr;
using std::endl;

pair<string, int> DayOfYear::months[MONTHS_AMOUNT] =
{
	{ "January", 31 }, { "February", 28 }, { "March", 31 },
	{ "April", 30 }, { "May", 31 }, { "June", 30 },
	{ "July", 31 }, { "August", 31 }, { "September", 30 },
	{ "October", 31 }, { "November", 30 }, { "December", 31 }
};

DayOfYear::DayOfYear(int dayNumber)
	: dayNumber(0)
{
	if (dayNumber <= 0 || dayNumber > 365)
	{
		cerr << "Incorrect day number in consturctor.\n";
		exit(1);
	}

	this->dayNumber = dayNumber;
}

DayOfYear::DayOfYear(const string& monthName, int dayOfMonth)
	: dayNumber(0)
{
	size_t monthIndex;
	for (monthIndex = 0; monthIndex < MONTHS_AMOUNT; monthIndex++)
		if (months[monthIndex].first == monthName)
			break;

	if (monthIndex == MONTHS_AMOUNT)
	{
		cerr << "Incorrect name of month in consturctor.\n";
		exit(1);
	}

	if (dayOfMonth < 0 || dayOfMonth > months[monthIndex].second)
	{
		cerr << "Incorrect day of month in consturctor.\n";
		exit(1);
	}

	for (size_t i = 0; i < monthIndex; i++)
		dayNumber += months[i].second;

	dayNumber += dayOfMonth;
}

void DayOfYear::print() const
{
	string monthName;
	int daysInMonth;
	int copyDayNumber = dayNumber;

	for (size_t i = 0; i < MONTHS_AMOUNT; i++)
	{
		monthName = months[i].first;
		daysInMonth = months[i].second;

		if (copyDayNumber - daysInMonth <= 0)
			break;
		else
			copyDayNumber -= daysInMonth;
	}

	cout << monthName << " " << copyDayNumber << endl;
}

DayOfYear& DayOfYear::operator++()
{
	dayNumber = dayNumber == 365 ? 1 : dayNumber + 1;

	return *this;
}

DayOfYear DayOfYear::operator++(int)
{
	DayOfYear temp{ *this };

	dayNumber = dayNumber == 365 ? 1 : dayNumber + 1;

	return temp;
}

DayOfYear& DayOfYear::operator--()
{
	dayNumber = dayNumber == 1 ? 365 : dayNumber - 1;

	return *this;
}

DayOfYear DayOfYear::operator--(int)
{
	DayOfYear temp{ *this };

	dayNumber = dayNumber == 1 ? 365 : dayNumber - 1;

	return temp;
}
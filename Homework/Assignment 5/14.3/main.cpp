/*
3. Day of the Year Modification
Modify the DayOfTear class, written in Programming Challenge 2, to add a constuctor
that takes two parameters: a string object representing a month and an integer in
the range 0 through 31 representing the day of the month. The constructor should
then initialize the integer member of the class to represent the day specified by
the month and day of month parameters. The constructor should terminate the program
with an appropriate error message if the number entered for a day is outside the range
of days for the month given.
Add the following overloaded operators:
++ prefix and postfix inrement operators. These operators should modify the DayOfYear
   object so it represents the next day. If the day is already the end of the year,
   the new value of the object will represent the first day of the year.
-- prefix and postfix decrement operators. These operators should modify the DayOfYear
   object so it represents the previous day. If the day is already the first day of
   the year, the new value of the object will represent the last day of the year.
*/

#include <iostream>

#include "DayOY.h"

using std::cout;

int main()
{
	{
		cout << "Test constructor with 1 parameter:\n";
		DayOfYear day1{ 2 }, day2{ 32 }, day3{ 365 };

		day1.print();
		day2.print();
		day3.print();
	}

	{
		cout << "Test constructor with 2 parameters:\n";
		DayOfYear day1{ "January", 2 }, day2{ "February", 1 }, day3{ "December", 31 };

		day1.print();
		day2.print();
		day3.print();
	}

	{
		cout << "Test increment and decrement:\n";
		DayOfYear day1{ "January", 2 }, day2{ "February", 1 }, day3{ "December", 31 };

		DayOfYear temp1 = day1++;
		DayOfYear temp2 = --day2;
		DayOfYear temp3 = day3++;
		DayOfYear temp4 = day1--;

		temp1.print();
		temp2.print();
		temp3.print();
		temp4.print();

		day1.print();
		day2.print();
		day3.print();
	}

	return 0;
}

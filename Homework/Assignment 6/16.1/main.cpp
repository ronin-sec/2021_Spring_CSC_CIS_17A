/*
1. Date Exceptions

Modify the Date class you wrote for Programming Challenge 1 of Chapter 13 (Date).
The class should implement the following exception classes:

InvalidDay - Throw when an invalid day (< 1 or > 31) is passed to the class.
InvalidMonth - Throw when an invalid month (< 1 or > 12) is passed to the class.

Demonstrate the class in a driver program.
*/

/* 
 * File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on May 30, 2021
 */

#include <cstdlib>
#include "Date.h"

using namespace std;
int main()
{
	try
	{
		Date date1{ 20, 10, 2004 };
	}
	catch (const InvalidDay& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const InvalidMonth& exc)
	{
		exc.ShowErrorMessage();
	}

	try
	{
		Date date1{ 12, 30, 2444 };
	}
	catch (const InvalidDay& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const InvalidMonth& exc)
	{
		exc.ShowErrorMessage();
	}

	return 0;
}

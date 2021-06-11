/* 
 * File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on May 30, 2021
 */

#include <cstdlib>
#include "MilTime.h"

using namespace std;

int main(int argc, char** argv) {

    try
	{
		MilTime time1{ 20, 10000 };
	}
	catch (const BadHour& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const BadSeconds& exc)
	{
		exc.ShowErrorMessage();
	}

	try
	{
		MilTime time2{ 10000, 20 };
	}
	catch (const BadHour& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const BadSeconds& exc)
	{
		exc.ShowErrorMessage();
	}

    return 0;
}


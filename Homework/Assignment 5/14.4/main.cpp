/*
5. Time Off
NOTE: This assignment assumes you have already completed Programming Challenge 4.
Design a class named TimeOff. The purpose of the class is to track an employee's
sick leave, vacation, and unpaid time off. It should have, as members, the following
instances of the NumDays class described in Programming Challenge 4:
maxSickDays - A NumDays object that records the maximum number of days of
			  sick leave the employee may take.
sickTaken   - A NumDays object that records the number of days of sick leave the
			  employee may take.
maxVacation - A numDays object that records the maximum number of days of
			  paid vacation the employee may take.
vacTaken    - A NumDays object that records the number of days of paid vacation
			  the employee has already taken.
maxUnpaid   - A NumDays object that records the maximum numbe rof days of
			  unpaid vacation the employee has taken.
unpaidTaken - A NumDays object taht records the number of days of unpaid leave
			  the employee has taken.
Additionally, the class should have members for holding the employee's name and
identification number. It should have an appropriate constructor and member functions
for storing and retrieving data in any of the member objects.
Input Validation: Company policy state that an employee may not accumulate more
that 240 hours of paid vacation. The class should not allow the maxVacation object
to store a value greater than this amount.
*/

#include <iostream>
#include "TimeOff.h"
#include "NumDays.h"

using std::cout;
using std::endl;

int main()
{
	TimeOff time1
	{
		"Demien Blogan",
		1,
		NumDays{ 5 },
		NumDays{ 6 },
		NumDays{ 34 },
		NumDays{ 1 },
		NumDays{ 36 },
		NumDays{ 61 }
	};

	cout << "Employee's name: " << time1.GetEmployeeName() << endl;
	cout << "Employee's ID: " << time1.GetEmployeeID() << endl;
	cout << "Max Sick Days: " << time1.GetMaxSickDays() << endl;
	cout << "Sick Taken: " << time1.GetSickTaken() << endl;
	cout << "Max Vacation: " << time1.GetMaxVacation() << endl;
	cout << "Vac Taken: " << time1.GetVacTaken() << endl;
	cout << "Max Unpaid: " << time1.GetMaxUnpaid() << endl;
	cout << "Unpaid Taken: " << time1.GetUnpaidTaken() << endl;

	return 0;
}
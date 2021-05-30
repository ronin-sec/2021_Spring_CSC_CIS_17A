#include "TimeOff.h"

TimeOff::TimeOff(
	const string& employeeName,
	int employeeID,
	const NumDays& maxSickDays,
	const NumDays& sickTaken,
	const NumDays& maxVacation,
	const NumDays& vacTaken,
	const NumDays& maxUnpaid,
	const NumDays& unpaidTaken)
	: employeeName(employeeName),
	employeeID(employeeID),
	maxSickDays(maxSickDays),
	sickTaken(sickTaken),
	maxVacation(maxVacation),
	vacTaken(vacTaken),
	maxUnpaid(maxUnpaid),
	unpaidTaken(unpaidTaken)
{ }

void TimeOff::SetEmployeeName(const string & employeeName)
{
	this->employeeName = employeeName;
}

void TimeOff::SetEmployeeID(int employeeID)
{
	this->employeeID = employeeID;
}

void TimeOff::SetMaxSickDays(const NumDays& maxSickDays)
{
	this->maxSickDays = maxSickDays;
}

void TimeOff::SetSickTaken(const NumDays& sickTaken)
{
	this->sickTaken = sickTaken;
}

void TimeOff::SetMaxVacation(const NumDays& maxVacation)
{
	double days = maxVacation.GetDays();
	if (days * NumDays::MAX_WORK_HOURS_PER_DAY <= 240)
		this->maxVacation = maxVacation;
}

void TimeOff::SetVacTaken(const NumDays& vacTaken)
{
	this->vacTaken = vacTaken;
}

void TimeOff::SetMaxUnpaid(const NumDays& maxUnpaid)
{
	this->maxUnpaid = maxUnpaid;
}

void TimeOff::SetUnpaidTaken(const NumDays& unpaidTaken)
{
	this->unpaidTaken = unpaidTaken;
}

const string& TimeOff::GetEmployeeName() const
{
	return employeeName;
}

int TimeOff::GetEmployeeID() const
{
	return employeeID;
}

double TimeOff::GetMaxSickDays() const
{
	return maxSickDays.GetDays();
}

double TimeOff::GetSickTaken() const
{
	return sickTaken.GetDays();
}

double TimeOff::GetMaxVacation() const
{
	return maxVacation.GetDays();
}

double TimeOff::GetVacTaken() const
{
	return vacTaken.GetDays();
}

double TimeOff::GetMaxUnpaid() const
{
	return maxUnpaid.GetDays();
}

double TimeOff::GetUnpaidTaken() const
{
	return unpaidTaken.GetDays();
}
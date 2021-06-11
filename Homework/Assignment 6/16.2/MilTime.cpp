#include <iostream>
#include "MilTime.h"

using std::cout;

MilTime::MilTime(int milHours, int milSeconds)
	: milHours(0), milSeconds(0), Time()
{
	setTime(milHours, milSeconds);
}

void MilTime::setTime(int milHours, int milSeconds)
{
	if (milHours < 0 || milHours > 2359)
		throw BadHour();

	if (milSeconds < 0 || milSeconds > 59)
		throw BadSeconds();

	this->milHours = milHours;

	hour = milHours / 100;
	min = milHours % 100;

	this->milSeconds = milSeconds;
	sec = milSeconds;
}

int MilTime::getHour() const
{
	return milHours;
}

int MilTime::getStandHr() const
{
	return hour;
}

void BadHour::ShowErrorMessage() const
{
	cout << "Invalid hour (< 0 or > 2359) is passed to the class.\n";
}

void BadSeconds::ShowErrorMessage() const
{
	cout << "Invalid numbero f seconds (< 0 or > 59) is passed to the class.\n";
}
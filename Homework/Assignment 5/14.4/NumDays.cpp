#include "NumDays.h"

const int NumDays::MAX_WORK_HOURS_PER_DAY = 8;

NumDays::NumDays(int workedHours)
	: workedHours(0)
{
	if (workedHours > 0)
		this->workedHours = workedHours;
}

double NumDays::GetDays() const
{
	double days = workedHours / static_cast<double>(MAX_WORK_HOURS_PER_DAY);

	return days;
}

NumDays NumDays::operator+(const NumDays& other) const
{
	int sumHours = this->workedHours + other.workedHours;

	return NumDays{ sumHours };
}

NumDays NumDays::operator-(const NumDays& other) const
{
	int sumHours = this->workedHours - other.workedHours;

	return NumDays{ sumHours };
}

NumDays& NumDays::operator++()
{
	workedHours++;

	return *this;
}

NumDays NumDays::operator++(int)
{
	NumDays copy{ *this };

	workedHours++;

	return copy;
}

NumDays& NumDays::operator--()
{
	workedHours = workedHours - 1 < 0 ? 0 : workedHours - 1;

	return *this;
}

NumDays NumDays::operator--(int)
{
	NumDays copy{ *this };

	workedHours = workedHours - 1 < 0 ? 0 : workedHours - 1;

	return copy;
}
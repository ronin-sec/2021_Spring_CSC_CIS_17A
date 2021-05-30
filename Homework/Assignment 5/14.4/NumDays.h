#pragma once
class NumDays
{
private:
	int workedHours;

public:
	static const int MAX_WORK_HOURS_PER_DAY;

	NumDays(int workedHours = 0);

	double GetDays() const;

	NumDays operator+(const NumDays& other) const;
	NumDays operator-(const NumDays& other) const;
	NumDays& operator++();
	NumDays operator++(int);
	NumDays& operator--();
	NumDays operator--(int);
};
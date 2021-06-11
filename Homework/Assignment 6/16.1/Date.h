#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class InvalidDay
{ 
public:
	void ShowErrorMessage() const;
};

class InvalidMonth
{
public:
	void ShowErrorMessage() const;
};

class Date
{
private:
	int month;
	int day;
	int year;

	string GetMonthName() const;

public:
	enum class Representing
	{
		BY_SLASH,            // mm/dd/yyyy
		MONTH_DAY_COMA_YEAR, // month dd, yyyy
		DAY_MONTH_YEAR       // dd month yyyy
	};

	Date(int month = 1, int day = 1, int year = 1);

	void Show(Representing representing = Representing::BY_SLASH) const;
};

#endif /* DATE_H */
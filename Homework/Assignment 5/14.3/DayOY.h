#include <string>

using std::string;
using std::pair;

class DayOfYear
{
private:
	enum { MONTHS_AMOUNT = 12 };
	static pair<string, int> months[MONTHS_AMOUNT];
	int dayNumber;

public:
	DayOfYear(int dayNumber);
	DayOfYear(const string& monthName, int dayOfMonth);
	
	void print() const;

	DayOfYear& operator++();
	DayOfYear operator++(int);
	DayOfYear& operator--();
	DayOfYear operator--(int);
};
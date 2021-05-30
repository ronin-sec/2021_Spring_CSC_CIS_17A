#include <string>

using std::string;

class Procedure
{
private:
	string name;
	string date;
	string practioner;
	double charges;

public:
	Procedure(const string& name, const string& date, const string& practioner, double charges)
		: name(name), date(date), practioner(practioner), charges(charges)
	{ }

	void SetName(const string& name) { this->name = name; }
	void SetDate(const string& date) { this->date = date; }
	void SetPractioner(const string& name) { this->practioner = practioner; }
	void SetCharges(double charges) { this->charges = charges; }

	string GetName() const { return name; }
	string GetDate() const { return date; }
	string GetPractioner() const { return practioner; }
	double GetCharges() const { return charges; }
};

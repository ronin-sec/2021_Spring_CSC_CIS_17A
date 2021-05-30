#include <string>
#include "NumDays.h"

using std::string;

class TimeOff
{
private:
	string employeeName;
	int employeeID;
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays vacTaken;
	NumDays maxUnpaid;
	NumDays unpaidTaken;

public:
	TimeOff(
		const string& employeeName = "",
		int employeeID = 0,
		const NumDays& maxSickDays = NumDays(),
		const NumDays& sickTaken = NumDays(),
		const NumDays& maxVacation = NumDays(),
		const NumDays& vacTaken = NumDays(),
		const NumDays& maxUnpaid = NumDays(),
		const NumDays& unpaidTaken = NumDays());

	void SetEmployeeName(const string& employeeName);
	void SetEmployeeID(int employeeID);
	void SetMaxSickDays(const NumDays& maxSickDays);
	void SetSickTaken(const NumDays& sickTaken);
	void SetMaxVacation(const NumDays& maxVacation);
	void SetVacTaken(const NumDays& vacTaken);
	void SetMaxUnpaid(const NumDays& maxUnpaid);
	void SetUnpaidTaken(const NumDays& unpaidTaken);

	const string& GetEmployeeName() const;
	int GetEmployeeID() const;
	double GetMaxSickDays() const;
	double GetSickTaken() const;
	double GetMaxVacation() const;
	double GetVacTaken() const;
	double GetMaxUnpaid() const;
	double GetUnpaidTaken() const;
};

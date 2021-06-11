#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time
{
private:
	Time time;
	int milHours;
	int milSeconds;

public:
	MilTime(int milHours = 0, int milSeconds = 0);
	void setTime(int milHours, int milSeconds);
	int getHour() const;
	int getStandHr() const;
};

#endif /* MILTIME_H */
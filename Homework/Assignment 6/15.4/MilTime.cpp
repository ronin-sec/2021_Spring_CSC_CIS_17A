//Implementation for the MilTime class
#include "MilTime.h"

MilTime::MilTime(int milHours, int milSeconds)
    : milHours(0), milSeconds(0), time()
{
    setTime(milHours, milSeconds);
}

void MilTime::setTime(int milHours, int milSeconds)
{
    if (milHours >= 0 && milHours <= 2359)
    {
        this->milHours = milHours;       
        
        int hr = milHours / 100;        
        if(hr <= 12){
            hour = hr;
        }else if(hr > 12){
            hour = hr - 12;
        }
        
        min = milHours % 100;
    }

    if (milSeconds >= 0 && milSeconds <= 59)
    {
        this->milSeconds = milSeconds;
        sec = milSeconds;
    }

}

int MilTime::getHour() const
{
    return milHours;
}

int MilTime::getStandHr() const
{
    return hour;
}
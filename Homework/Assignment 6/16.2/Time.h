/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: antero
 *
 * Created on May 30, 2021, 10:39 PM
 */

#ifndef TIME_H
#define TIME_H

class Time
{
protected:
	int hour;
	int min;
	int sec;

public:
	Time(int h = 0, int m = 0, int s = 0)
		: hour(h), min(m), sec(s)
	{ }

	int getHours() const
	{
		return hour;
	}

	int getMin() const
	{
		return min;
	}

	int getSec() const
	{
		return sec;
	}
};

#endif /* TIME_H */


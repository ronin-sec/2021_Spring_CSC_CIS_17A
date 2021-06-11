/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: antero
 *
 * Created on May 30, 2021, 10:41 PM
 */

#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"

class BadHour
{
public:
	void ShowErrorMessage() const;
};

class BadSeconds
{
public:
	void ShowErrorMessage() const;
};

class MilTime : public Time
{
private:
	int milHours;
	int milSeconds;

public:
	MilTime(int milHours = 0, int milSeconds = 0);
	void setTime(int milHours, int milSeconds);
	int getHour() const;
	int getStandHr() const;
};

#endif /* MILTIME_H */


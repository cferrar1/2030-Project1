#pragma once

#ifndef WEEK_H
#define WEEK_H

#include "Day.h"

class week
{
public:
	day days[7];
	
	float max();
	float min();
	int count();
	float sum(int & overflow);
	int biggestDelta();
	void printWeek();
	int overflow = 0;
};

#endif // !DAY_H


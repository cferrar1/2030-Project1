#pragma once

#ifndef DAY_H
#define DAY_H

#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

class day
{
public:
	day();
	float max();
	float min();
	int getSize();
	float sum(int & overflow);
	void printDay();
	void addData(float data); 
	int overflow = 0;
private:
	LinkedList values = LinkedList(); 
	int size = 0;

};

#endif // !DAY_H


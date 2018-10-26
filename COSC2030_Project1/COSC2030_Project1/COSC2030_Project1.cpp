
#include "stdafx.h"
#include "Day.h"
#include "Week.h"
#include "LinkedList.h"
#include <string>
#include <sstream>

bool isFloat(string input);

int main()
{
	string input;
	int day = 0;
	week week1 = week();
	week week2 = week();
	while (day < 14)
	{
		cout << "Day " << day + 1 << ": Input a Measurement, N for the Next Day, D for a Daily Summary, or W for a Weekly Summary: ";
		cin >> input;

		if (input == "N" || input == "Next")
		{
			day++;
		}
		else if (input == "D" || input == "Day")
		{
			if (day < 7)
			{
				week1.days[day].printDay();
			}
			else
			{
				week2.days[day - 7].printDay();
			}
		}
		else if (input == "W" || input == "Week")
		{
			if (day < 7)
			{
				week1.printWeek();
			}
			else
			{
				week2.printWeek();
			}
		}
		else if (isFloat(input))
		{
			float indata = stof(input);
			if (day < 7)
			{
				week1.days[day].addData(indata);
			}
			else
			{
				week2.days[day - 7].addData(indata);
			}
		}
	}
	cout << endl << "---- WEEK 1 ----" << endl;
	week1.printWeek();
	cout << endl << "---- WEEK 2 ----" << endl;
	week2.printWeek();

	return 0;
}

bool isFloat(const string input) // From https://stackoverflow.com/questions/447206/c-isfloat-function
{
	istringstream iss(input);
	float f;
	iss >> noskipws >> f;
	return (iss.eof() && !iss.fail());
}
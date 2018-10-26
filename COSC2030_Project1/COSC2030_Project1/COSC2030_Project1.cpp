
#include "stdafx.h"
#include "Day.h"
#include "Week.h"
#include "LinkedList.h"


int main()
{
	float input;
	int day = 0;
	week week1 = week();
	week week2 = week();
	while (day < 14)
	{
		cout << "Input a Measurement, N (100) for the Next Day, D (101) for a Daily Summary, or W (102) for a Weekly Summary: ";
		cin >> input;

		if (input == 100)
		{
			day++;
			cout << "Advanced Day, now on Day " << day + 1 << endl;
		}
		else if (input == 101)
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
		else if (input == 102)
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
		else if (input > 0)
		{
			if (day < 7)
			{
				week1.days[day].addData(input);
			}
			else
			{
				week2.days[day - 7].addData(input);
			}
		}
	}
	cout << endl << "---- WEEK 1 ----" << endl;
	week1.printWeek();
	cout << endl << "---- WEEK 2 ----" << endl;
	week2.printWeek();

	return 0;
}
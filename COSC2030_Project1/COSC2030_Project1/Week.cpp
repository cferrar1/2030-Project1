#include "stdafx.h"
#include "Week.h"


float week::max()
{
	float max;

	for (int i = 0; i < 7; i++)
	{
		float tempmax = days[i].max();
		if (i == 0)
		{
			max = tempmax;
		}
		else if (tempmax > max)
		{
			max = tempmax;
		}
	}
	return max;
}


float week::min()
{
	if (count() == 0)
	{
		return 0;
	}

	float min = numeric_limits<float>::max();
	for (int i = 0; i < 7; i++)
	{
		if (days[i].getSize() > 0)
		{
			float tempmin = days[i].min();
			if (tempmin < min)
			{
				min = tempmin;
			}
		}

	}
	return min;
}


int week::count()
{
	int cnt = 0;
	for (int i = 0; i < 7; i++) 
	{
		cnt = cnt + days[i].getSize();
	}
	return cnt;
}

//TODO (maybe?)
float week::sum(int & overflow)
{
	float max = numeric_limits<float>::max();
	float remainder = max;
	float sum = 0;
	float daysum;
	overflow = 0;
	for (int i = 0; i < 7; i++)
	{
		daysum = days[i].sum(days[i].overflow);
		overflow = overflow + days[i].overflow;
		if (daysum > remainder)
		{
			overflow++;
			sum = remainder - daysum;
		}
		else
		{
			sum = sum + daysum;
		}
	}
	return sum;
}

int week::biggestDelta()
{
	int maxdel = 0;
	int del;
	for (int i = 1; i < 7; i++)
	{
		del = days[i].getSize() - days[i - 1].getSize();
		if (del > maxdel)
		{
			maxdel = del;
		}
	}
	return maxdel;
}


void week::printWeek()
{
	cout << endl << "----WEEKLY SUMMARY----" << endl;
	cout << "Weekly Sum: " << sum(overflow) << " + " << overflow << "*" << numeric_limits<float>::max() << endl;
	cout << "Weekly Max: " << max() << endl;
	cout << "Weekly Min: " << min() << endl;
	cout << "Weekly Count: " << count() << endl;
	cout << "Biggest Delta: " << biggestDelta() << endl << endl;
}


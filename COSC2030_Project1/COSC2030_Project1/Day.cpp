#include "stdafx.h"
#include "Day.h"


day::day()
{
}

// Finds the maximum value of that day
float day::max()
{
	float max = 0.0;
	Node*temp = values.head;

	while (!temp == NULL)
	{
		if (temp->data > max)
		{
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}

// Finds the minimum value of that day
float day::min()
{
	float min = 0;
	if (getSize() > 0)
	{
		Node* temp = values.head;
		min = temp->data;
		while (!temp == NULL)  // Run until the end of the list
		{
			if (temp->data < min)
			{
				min = temp->data;
			}
			temp = temp->next;
		}
	}
	return min;
}

// Returns the size of the linked list
int day::getSize()
{
	return values.length;
}


// Returns the sum of the list and changes the overflow value to account for data over max float
float day::sum(int & overflow) 
{
	Node *temp = values.head;
	float max = numeric_limits<float>::max();
	float remainder = max;
	float sum = 0;
	overflow = 0;
	while (!temp == NULL)
	{
		if (temp->data > remainder)
		{
			overflow++;
			sum = temp->data - remainder;
		}
		else
		{
			sum = sum + temp->data;
		}
		remainder = max - sum;
		temp = temp->next;
	}
	return sum;
}


void day::printDay()
{
	cout << endl << "----Daily Summary----" << endl;
	cout << "Daily Sum: " << sum(overflow) << " + " << overflow << "*" << numeric_limits<float>::max() << endl;
	cout << "Daily Max: " << max() << endl;
	cout << "Daily Min: " << min() << endl;
	cout << "Daily Count: " << getSize() << endl << endl;
}

void day::addData(float data)  // Assume input will be less than max float
{
	values.add(data);
}

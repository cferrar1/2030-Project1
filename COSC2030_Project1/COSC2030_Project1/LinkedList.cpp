#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

void LinkedList::add(float in)
{
	Node* temp = new Node();
	temp->data = in;
	temp->next = NULL;
	if (this->head == NULL)
	{
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		this->tail->next = temp;
		this->tail = temp;
	}
	this->length++;
}

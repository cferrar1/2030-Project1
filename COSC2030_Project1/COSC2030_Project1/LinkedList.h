#pragma once
// I got help for this from https://gist.github.com/charlierm/5691020 and the textbook

#include <iostream>
#include <cstdlib>

class Node
{
public:
	Node * next;
	float data;

};

class LinkedList
{
public:
	int length;
	Node* head;
	Node* tail;
	LinkedList();
	void add(float data);
};
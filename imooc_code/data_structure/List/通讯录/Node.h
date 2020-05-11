#pragma once

#include"Person.h"

class Node
{
public:
	Person data;
	Node *next;
	void printNode();
};
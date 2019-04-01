#pragma once
#include <iostream>

using namespace std;

// Class for Input restricted deque(front)
class deque
{
	char *arr;	
	int left;		
	int right;		
	int max;
	int current_size;

public:
	deque(int size);		
	~deque();
	char remove_front();
	void add(int x);
	char remove_end();
	char peek_front();
	char peek_end();
	int size();

	
};
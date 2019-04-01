#include "Deque.h"

using namespace std;

deque::deque(int size)
{
	arr = new char[size];
	left = -1;
	right = -1;
	max = size;
	current_size = 0;
}

deque::~deque() {
	delete arr;
}

char deque::remove_end()
{
	if (left == -1) {
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	
	char elem = arr[right];

	if (left == right) /*queue has only one element*/
	{
		left = -1;
		right = -1;
	}
	else
	{
		if (right == 0)
			right = max-1;
		else
			right = right-1;
	}

	current_size--;

	return elem;
}

void deque::add(int x)
{
	if ((left == 0 && right == max - 1) || (left == right + 1))
	{
		printf("\n OVERFLOW");
		return;
	}
	if (left == -1) /* if queue is initially empty */
	{
		left = 0;
		right = 0;
	}
	else
	{
		if (right == max - 1) /*right is at last position of queue */
			right = 0;
		else
			right = right + 1;
	}
	arr[right] = x;
	
	current_size++;
}

char deque::remove_front()
{
	if (left == -1)
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	char elem = arr[left];
	
	if (left == right) /*Queue has only one element */
	{
		left = -1;
		right = -1;
	}
	else
	{
		if (left == max-1)
			left = 0;
		else
			left = left + 1;
	}

	current_size--;

	return elem;
}

char deque::peek_end()
{
	if (left == -1)
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[right];
}

char deque::peek_front()
{
	if (right == -1)
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[left];
}

int deque::size() {
	return current_size;
}
#include <iostream>

using namespace std;

int LinearSearch(int array[], int size, int target);

int array00[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

int main()
{
	cout << "Target is at index: " << LinearSearch(array00, 20, 3);
}

int LinearSearch(int array[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == target)
		{
			return i;
		}
	}
	return -1;
}
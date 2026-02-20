#include <iostream>
#include <cassert>

using namespace std;

int LinearSearch(int array[], int size, int target);

int array00[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

int main()
{
	cout << "Target is: 3 |" << "| Target is at index: " << LinearSearch(array00, 20, 3) << endl;
	assert(LinearSearch(array00,20,3) == 2);

	cout << "Target is : 7 |" << "| Target is at index : " << LinearSearch(array00, 20, 7) << endl;
	assert(LinearSearch(array00, 20, 7) == 11);

	cout << "Target is : 67 |" << "|Target is at index: " << LinearSearch(array00, 20, 67) << endl;
	assert(LinearSearch(array00, 20, 67) == 0);

	cout << "Target is : 88 |" << "|Target is at index: " << LinearSearch(array00, 20, 88) << endl;
	assert(LinearSearch(array00, 20, 88) == -1);
}

// compare target against each element in the array and return if found if not return -1
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
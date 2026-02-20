#include <iostream>

using namespace std;

int LinearSearch(int array, int target);

int main()
{

}

int LinearSearch(int array[], int target)
{
	int size = sizeof(array) / sizeof(array[0]);
	
	for (int i = 0; i < size; i++)
	{
		if (array[i] == target)
		{
			return i;
		}
	}
	return -1;
}
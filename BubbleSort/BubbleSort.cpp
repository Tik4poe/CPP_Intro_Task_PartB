#include <iostream>
#include <cassert>

using namespace std;

void BubbleSort(int array[], int size);

int array01[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

int main()
{
	BubbleSort(array01, 20);
}

void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size -1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			int temp = array[j];
			if (array[j] > array[j + 1])
			{
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
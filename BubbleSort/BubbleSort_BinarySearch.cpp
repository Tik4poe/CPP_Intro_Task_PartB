#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void BubbleSort(vector<int> array);
int BinarySearch(vector<int> array, int key);

vector<int> array01 = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

int main()
{
	BubbleSort(array01);

	BinarySearch(array01, 83);

	cout << "|========== END ===========|" << endl;
}

void BubbleSort(vector<int> array)
{
	pair<int, int> p;// create pair once

	int size = array.size();

	// outer loop for each element in the array
	for (int i = 0; i < size - 1; i++)
	{
		// at each element compare and sort
		for (int j = 0; j < size - i - 1; j++)
		{
			int temp = array[j];// assign current to temp
			if (array[j] > array[j + 1])// compare current to adjacent(left)
			{
				// if current larger than swap
				array[j] = array[j + 1]; 
				array[j + 1] = temp;
			}
		}
	}

	// once sorted then check if sort is correct
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			p.first = array[j];// assign current to first
			p.second = array[j + 1];// assign adjacent(left) to second
			assert(p.first <= p.second);// compare
		}
	}
}

int BinarySearch(vector<int> array, int target)
{
	int low = 0;
	int high = array.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		
		if (array[mid] == target)
		{
			return mid;
		}

		if (array[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
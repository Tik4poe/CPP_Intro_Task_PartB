#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void BubbleSort(vector<int>& array);
int BinarySearch(vector<int> &array, int key);

vector<int> array01 = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

int main()
{
	int counter = 0;
	int userInt = 0;
	BubbleSort(array01);

	assert(BinarySearch(array01, 11) == 4);
	assert(BinarySearch(array01, 23) == 8);
	assert(BinarySearch(array01, 97) == 19);
	assert(BinarySearch(array01, 88) == -1);

	while (counter <= 5)
	{
		cout << "what number would you like to search for: ";// ask for number
		cin >> userInt; cout << endl;// contain it in userInt

		int result = BinarySearch(array01, userInt);// send to be search for in the sorted collection

		if (result != -1)
		{
			cout << "your number " << userInt << "is at index: " << result << endl;// found it inform the user
		}
		else
		{
			cout << "your number was not found" << endl;// not found inform user
		}

		counter++;// ensures while loop ends
	}

	cout << "|========== END ===========|" << endl;
}

void BubbleSort(vector<int>& array)
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


// comment that makes sense
int BinarySearch(vector<int> &array, int target)
{
	int low = 0;// left side of array
	int high = array.size() - 1;// right side of array

	while (low <= high)
	{
		int mid = low + (high - low) / 2;// what it's comparing to
		
		if (array[mid] == target)// found target then return its index
		{
			return mid;
		}

		if (array[mid] < target)// if target is higher raise low
		{
			low = mid + 1;
		}
		else// else lower high
		{
			high = mid - 1;
		}
	}
	return -1;// return this if not found
}
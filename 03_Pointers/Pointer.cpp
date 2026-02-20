#include <iostream>
#include <cassert>

using namespace std;

void PointerSwap(int* a, int* b);

int main()
{

}

// use temp var to help swap values
void PointerSwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
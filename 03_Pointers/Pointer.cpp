#include <iostream>
#include <cassert>

using namespace std;

void PointerSwap(int* a, int* b);

int main()
{
	// the variables
	int a = 8;
	int b = 69;

	PointerSwap(&a, &b);

	// testing
	assert(a == 69);
	assert(b == 8);
}

// use temp var to help swap values
void PointerSwap(int* a, int* b)
{
	int temp = *a;// hold a to swap to other variable
	*a = *b;// puts b in a
	*b = temp;// puts a in b
}
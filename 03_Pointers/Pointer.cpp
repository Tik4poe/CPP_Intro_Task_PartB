#include <iostream>
#include <cassert>

using namespace std;

void PointerSwap(int* a, int* b);

int main()
{
	int a = 8;
	int b = 69;

	PointerSwap(&a, &b);

	assert(a == 69);
	assert(b == 8);
}

// use temp var to help swap values
void PointerSwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
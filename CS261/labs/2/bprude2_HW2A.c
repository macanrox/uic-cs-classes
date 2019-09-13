#include <stdio.h>

/* Divide by the power of 2. We assume that 0 <= k < w-1. */
int divide_power2(int x, int k)
{
	int y;
	
	/*If the original number is negative, we compensate for the
	 missing 1. */
	y = x >> 31;
	x += y;
	x >>= k;
	
	return k;
}

int main(int argc, const char *argv[])
{
	int divide_power2(int x, int k);
}
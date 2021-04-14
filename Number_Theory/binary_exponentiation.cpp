#include <iostream>

using namespace std;

unsigned long long int power(int base, int power)
{
	// variable to store the result
	unsigned long long int result = 1;

	// repeat until power is not zero
	while(power != 0)
	{
		// if power is even
		if(power % 2 == 0)
		{
			// square the base
			base *= base;
			// halve the power
			power /= 2;
		}
		// if the power is odd
		else
		{
			// multiply result by base
			result *= base;
			// decrement power
			--power;
		}
	}

	// compute the power
	return result;
}

int main()
{
	// base and power to be calculated
	int base = 4;
	int pow = 15;

	// print the value of base ^ power
	cout << "\nValue of " << base << "^" << pow << " is ";
	cout << power(base, pow) << "\n";

    return 0;
}


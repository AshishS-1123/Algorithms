#include <iostream>

using namespace std;

int mod_expo(int base, int power, int mod)
{
	// variable to store the result
	int result = 1;

	// repeat until power is not zero
	while(power != 0)
	{
		// if power is even
		if(power % 2 == 0)
		{
			// square the base
			base = (base * base) % mod;
			// halve the power
			power /= 2;
		}
		// if power is odd
		else
		{
			// multiply result by base
			result = (result * base) % mod;
			// decrement power
			--power;
		}
	}

	return result;
}

int main()
{
	// variable to store the base, power and modulus
	int base = 3, power = 6, mod = 5;

	cout << "\nValue of (" << base << "^" << power << ") mod " << mod << " is";
	cout << " :: " << mod_expo(base, power, mod) << "\n";

    return 0;
}


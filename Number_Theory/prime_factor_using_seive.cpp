#include <iostream>

using namespace std;

// global array to store whether first 50 element are prime or not
int smallest_prime[51]; // all these values are initialised as false

void seive_of_eratosthenes()
{
	// variable to store the size of array
	int n = 51;

	// initialize all element of seive as -1
	for(int i = 0; i < n; ++i)
		smallest_prime[i] = -1;

	// repeat for all element from 2 to sqrt(n)
	for(int i = 2; i <= n; ++i)
	{
		// if this number does not have a prime factor
		if(smallest_prime[i] == -1)
		{
			// for all multiples of this number
			for(int j = i*i; j <= n; j += i)
				// if the multiple does not have prime factor
				if(smallest_prime[j] == -1)
					// make this number as smallest prime factor
					smallest_prime[j] = i;
		}
	}
}

void print_prime_factors(int num)
{
	
}

int main()
{
	// numbers whose prime factors need to be calcuated
	int num[] = {16, 22, 19, 35, 36, 48, 49};
	// number of element in test case
	int n = sizeof(num) / sizeof(num[0]);

	// repeat for all elements
	for(auto item : num)
	{
		cout << "\nFor " << item << ", factor are:: ";
		print_prime_factors(item);
	}

    return 0;
}


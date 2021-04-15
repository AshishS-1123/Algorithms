#include <iostream>

using namespace std;

// global array to store whether first 50 element are prime or not
bool not_prime[51]; // all these values are initialised as false

void seive_of_eratosthenes()
{
	// variable to store the size of array
	int n = 51;

	// repeat for all element from 2 to sqrt(n)
	for(int i = 2; i*i <= n; ++i)
	{
		// if this number is prime
		if(not_prime[i] == false)
		{
			// mark all its multiples from square(i) to n as not prime
			for(int j = i*i; j <= n; j += i)
				not_prime[j] = true;
		}
	}

}

int main()
{
	// numbers to be tested for primality
	int a[] = {2,3,4,5,6,12,15,34,45};

	// size of array
	int n = (int)sizeof(a) / sizeof(a[0]);

	// run the seive_of_eratosthenes
	seive_of_eratosthenes();

	// for all the numbers is test case
	for(auto item : a)
	{
		// check if this number is prime
		if(not_prime[item])
			cout << item << " is not prime.\n";
		else
			cout << item << " is prime.\n";
	}

    return 0;
}


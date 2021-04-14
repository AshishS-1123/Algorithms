#include <iostream>

using namespace std;

bool is_prime(int num)
{
	// if number is 1, then not prime
	if(num == 1)
		return false;
	
	// for all numbers from 2 to sqrt(num)
	for(int i = 2; i*i <= num; ++i)
	{
		// check if num is divisible
		if(num % i == 0)
			// if divisible then not prime
			return false;
	}

	// if none of the numbers divided, then prime
	return true;
}

int main()
{
	// numbers to be tested for prime
	int a[5] = {3, 7, 22, 55, 1024};

	// for all numbers check if prime
	for(auto item : a)
	{
		if(is_prime(item))
			cout << item << " is prime.\n";
		else
			cout << item << " is not prime.\n";
	}
	
	return 0;
}

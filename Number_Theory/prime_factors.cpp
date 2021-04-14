#include <iostream>

using namespace std;

void print_prime_factors(int num)
{
	// variable to store number of times a factor occurs
	int count = 0;

	// repeat for all numbers from 2 to sqrt(num)
	for(int i = 2; i*i <= num; ++i)
	{
		// check if i divides num
		if(num % i == 0)
		{
			// initialize count to 0
			count = 0;

			// count the number of times i divides num
			while(num % i == 0)
			{
				// increment number of times this factor occurs
				++count;
				// remove this factor from num
				num /= i;
			}

			// print the factor and number of times it occurs
			cout << "\t" << i << "^" << count << "\n";
		}
	}

	// if num is not 1, then it is a factor of itself
	if(num > 1)
		cout << "\t" << num << "^" << 1 << "\n";
}

int main()
{
	// number whose prime factors are to be found
	int num = 2*2*2 * 3*3 * 7*7*7*7 * 11;

	cout << "Prime factors of " << num << " are...\n";

	// print factors of the number
	print_prime_factors(num);

    return 0;
}


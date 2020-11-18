#include <iostream>

using namespace std;

// Function : power
// Description : calculates and returns value of base raised to the power of exponent
// Paramters : base -> base of expression to be evaluated
//             exponent -> exponent of expression to be evaluated
// Return Value : power -> value of base raised to power of exponent
int power( int base, int exponent )
{
    // if the exponent is 0, any number raised to 0 is 1
    if ( exponent == 0 )
        // return 1
        return 1;

    // if the exponent is an even number
    if ( exponent % 2 == 0 )
        // subdivide to problem into 2 root problems
        return power( base, int(exponent / 2) ) * power( base, int(exponent / 2) );
    // if the exponent is and odd number
    else
        // subdivide to problem into 2 root problems
        return base * power( base, int(exponent / 2) ) * power( base, int(exponent / 2) );
}

int main()
{
    // variable to hold the value of base in expression
    int base;
    // variable to hold the value of exponent in expression
    int exponent;

    // prompt user to enter the value of base
    cout << "    Enter Value of Base :: ";
    // get the value of ebase and store in corresponding variable
    cin >> base;

    // prompt the user to enter the value of exponent
    cout << "Enter Value of Exponent :: ";
    // get the value of exponent and store in corresponding variable
    cin >> exponent;

    cout << "\n\t" << base << " to the power of " << exponent << " is :: ";
    // print the result
    cout << power( base, exponent ) << "\n";

    return 0;
}

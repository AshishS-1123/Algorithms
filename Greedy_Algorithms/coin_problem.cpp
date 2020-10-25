#include <bits/stdc++.h>

#define endl "\n";

using namespace std;

// Function: get_optimal_combination
// Description: greedily searches for optimal combination of coins to generate the given sum
// Paramters: coins -> vector of available coins from which to select
//            sum -> the expected sum the the selected coins must corresspond to
// Return Value: combination -> vector containing the coins that sum to 'sum'
vector < int > get_optimal_combination( vector < int > coins, int sum )
{
    // create a vector to hold the combination of coins
    vector < int > combination;

    // sort the given coins in decreasing order
    // this is because, we always take the coins for largest value first
    sort( coins.rbegin(), coins.rend() );

    // variable to hold the index of coin we are currently processing
    int index = 0;

    // repeat until all values of coins have been used
    while ( index < coins.size() )
    {
        // if the current coin value is less or equal to the amount required,
        if ( coins[ index ] <= sum )
        {
            // add this value to the combination vector
            combination.push_back( coins[ index ] );

            // decrement the required amount by the value added
            sum -= coins[ index ];
        }
        // if the current is not usable,
        else
        {
            // increment the index, to move onto the next coin
            ++index;
        }
    }

    // return the calcuated combination of values
    return combination;
}

int main()
{
    // variable to hold the number of types of coins available
    int number_of_coins = 5;

    // vector containing the available coins
    vector < int > coins{ 1,2,5,10,20};

    // variable containing the required sum
    int sum = 53;

    // get the combination of coins required to satisfy the given sum
    vector < int > combination = get_optimal_combination(coins, sum);

    // print the calculated coin values
    cout << "For expected sum " << sum << ", coins are ";
    for ( int i = 0; i < combination.size(); ++i )
        cout << combination[ i ] << " ";


    return 0;
}

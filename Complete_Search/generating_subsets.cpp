#include <bits/stdc++.h>

#define endl "\n";

using namespace std;

// global variable to hold the max index of array to be processed
int length = 0;
// global variable to hold the index up to which elements have been added to subset
int subset_index = 0;

// Function: recursive_subset_search
// Description: generates all subsets of given array and prints it
// Parameters: array -> pointer to array to be processed
//             subset -> pointer to array to be processed
//             k -> index of array currently being processed
// Return Value: void
void recursive_subset_search(int* array, int* subset, int k)
{
    // if all the elements have been processed,
    if ( k >= length )
    {
        // print all of them one by one
        cout << "{ ";
        for ( int i = 0; i < subset_index ; ++i )
            cout << subset[i] << " ";
        cout << "}" << endl;
    }
    // otherwise,
    else
    {
        // process the next element with current element excluded
        recursive_subset_search(array, subset, k+1);

        // add the current element to the subset
        subset[ subset_index++ ] = array[ k ];

        // process the next element with the current element included
        recursive_subset_search(array, subset, k+1);

        // remove the current element from the subset
        --subset_index;
    }
}

// Function: iterative_subset_search
// Description: generates all subsets of given array and prints it
// Paramters: array -> pointer to array to be processed
// Return Value: None
void iterative_subset_search(int* array)
{
    // generate numbers with as many bits as there are elements in array
    for ( int i = 0; i < (1 << length); ++i )
    {
        // create an array to hold the subset
        int subset[length];

        // store the index of last element in the subset
        subset_index = 0;

        // repeat the following for all elements in the array
        for ( int j = 0; j < length; ++j )
        {
            // if the bit at the index of current element is 1 in the generated number,
            if ( i & ( 1 << j ) )
            {
                // add this element to the subset
                subset[ subset_index ] = array[j];
                // increment the number if elements in the subset
                ++subset_index;
            }
        }

        // print all the elements in the subset
        cout << "{ ";
        for ( int i = 0; i < subset_index; ++i )
            cout << subset[ i ] << " ";
        cout << "}" << endl;

    }
}

int main()
{
    // create an array of 5 elements to be processed
    int array[5] = {10,20,30,40,50};

    // store the length of array in the global variable n
    length = 5;

    // create array to store the subset generated
    int subset[5];

    cout << "Subsets generated using Recursion ::\n";

    // recursively generate the subsets
    recursive_subset_search(array, subset, 0);

    cout << "Subsets generated using Iteration ::\n";

    // iteratively generate the subsets
    iterative_subset_search(array);

    return 0;
}

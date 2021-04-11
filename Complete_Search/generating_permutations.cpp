#include <bits/stdc++.h>

#define endl "\n";

using namespace std;

// global variable to store the number of terms generated in permutation
int terms = 0;

// Function: recursive_permutation_search
// Description: generates all permutations of array using recursion and prints it
// Paramters: array -> pointer to array to be processed
//            permutation -> pointer to array where permutation will be stored
//            procedded -> pointer to array of booleans representing which element has been processed in array
//            length -> size of array to be processed
// Return Value: void
void recursive_permutation_search(int* array, int* permutation, bool* processed, int length)
{
    // if all the terms in the array have been processed,
    if ( terms == length )
    {
        // print the permutation
        cout << "{ ";
        for ( int i = 0; i < length; ++i )
            cout << permutation[i] << " ";
        cout << "}" << endl;
    }
    // otherwise,
    else
    {
        // loop through every element in the array
        for ( int i = 0; i < length; ++i )
        {
            // if the current element has already been processed,
            if ( processed[i] == true )
                // skip that element
                continue;

            // if not, then mark that element to be placed at the current index in permutation
            processed[i] = true;
            // store the current element in the permutation
            permutation[ terms ] = array[i];
            // increment the number of items present in the permutaation
            ++terms;

            // generate permutations of remaining elements
            recursive_permutation_search( array, permutation, processed, length );

            // mark the element to not be included in current position in the permutation
            processed[i] = false;
            // decrement the number of element in the permutation, effectively removing current element
            --terms;
        }
    }
}

int main()
{
    // variable containing length of array
    int length = 5;

    // array of elements to be processed
    int array[length] = {10, 20, 30, 40, 50};

    // array to hold the generated permutation
    int permutation[length];

    // array of bools representing which element has been included in the permutation
    bool processed[length] = {false, false, false, false, false};

    // generate the permutation recursively
    recursive_permutation_search(array, permutation, processed, length);

    return 0;
}

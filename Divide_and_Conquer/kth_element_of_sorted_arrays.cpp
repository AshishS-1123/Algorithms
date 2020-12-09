#include <iostream>

using namespace std;

// Function: get_element
// Description: returns the elements that would appear at the given index in sorted array
// Parameters: array_a -> pointer to first sorted array
//             array_b -> pointer to second sprted array
//             length_a -> length of first array
//             length_b -> length of second array
//             index -> index at which element should appear
// Return Value: element that will appear at the given index
int get_element(int* array_a, int* array_b, int length_a, int length_b, int index)
{
    // create a variable to hold the current element index in first array
    int index_a = 0;
    // create a variable to hold the current element index in second array
    int index_b = 0;
    // create a variable to hold the current element index in sorted array
    int index_sorted = 0;

    // repeat the following until all elements in at least one array have been procesed
    while( index_a < length_a && index_b < length_b )
    {
        // if current element of first array is less than second array
        if ( array_a[index_a] < array_b[index_b] )
        {
            // increment index of element in sorted array
            ++index_sorted;

            // if this element occurs at the desired position in sorted array
            if ( index_sorted == index )
                // return it
                return array_a[index_a];
            // otherwise
            else
                // move on to next element in thsi array
                ++index_a;
        }
        // if current element of first array is greater than second array
        else
        {
            // increment index of element in sorted array
            ++index_sorted;

            // if this element occurs at the desired position in sorted array
            if ( index_sorted == index )
                // return it
                return array_b[index_b];
            // otherwise
            else
                // move on to next element in this array
                ++index_b;
        }
    }

    // process remaining element of first array, if left
    while ( index_a < length_a )
    {
        // increment index of element in sorted array
        ++index_sorted;

        // if this element occurs at the desired position in sorted array
        if ( index_sorted == index )
            // return it
            return array_a[index_a];
            // otherwise
        else
            // move on to the next element in current array
            ++index_a;
    }

    // process remaining elements of second array, if any
    while ( index_b < length_b )
    {
        // increment index of element in sorted array
        ++index_sorted;

        // if this element occurs at desired position in sorted array
        if ( index_sorted == index )
            // return it
            return array_b[index_b];
        // otherwise
        else
            // move on to the next element in current array
            ++index_b;
    }

    // if the element could not be found, return -1
    return -1;
}

int main()
{
    // create a variable to hold length of first array
    int length_a = 5;
    // create avariable to hold lenght of second array
    int length_b = 5;

    // variable to hold first array
    int array_a[length_a] = {1,3,5,7,9};

    // variable to hold second array
    int array_b[length_b] = {2,4,6,8,10};

    // create a variable to hold the index at which the element should occur
    int required_index = 1;

    // print the first array
    cout << "\n\n The first array is: ";
    for ( int i = 0; i < length_a; ++i )
        cout << array_a[i] << " ";

    // print the second array
    cout << "\nThe second array is: ";
    for ( int i = 0; i < length_b; ++i )
        cout << array_b[i] << " ";

    // print the index
    cout << "\n\n\tTo find: element at index " << required_index << "\n";

    // get the element located at that index
    int element_at_index = get_element(array_a, array_b, length_a, length_b, required_index);

    // print the element found
    cout << "\n\t Element found at index " << element_at_index << " in sorted array\n";
}

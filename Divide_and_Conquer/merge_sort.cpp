#include <iostream>

#define endl "\n";

using namespace std;

// Function : merge
// Description : Merges two sorted array such result is sorted array
// Parameters : array -> pointer to main array
//              left -> starting index of ist array
//              mid -> ending index of 1st array, starting index of 2nd array
//              right -> ending index of second array
// Return Value : void
void merge(int* array, int left, int mid, int right)
{
    // calculate and store the length of 1st array
    int left_length = mid - left + 1;

    // calculate and store length of 2nd array
    int right_length = right - mid;

    // create a temporary array to hold the 1st array
    int left_temp[left_length];

    // create a temporary array to hold the 2nd array
    int right_temp[right_length];

    // copy 1st array to the temporary array
    for( int i = 0; i < left_length; ++i )
        left_temp[i] = array[left + i];

    // calculate the 2nd array to the temporary array
    for( int i = 0; i < right_length; ++i )
        right_temp[i] = array[mid + i + 1];

    // variable to hold the index of array upto which it has been sorted
    int index = left;

    // varaible to hold the index of 1st array
    int left_index = 0;

    // variable to hold the index of 2nd array
    int right_index = 0;

    // repeat until all elements of 1st or 2nd array have been added
    while( left_index < left_length && right_index < right_length )
    {
        // if current element of 1st array is less than element of 2nd
        if ( left_temp[left_index] < right_temp[right_index] )
        {
            // add the current element of 1st array to the array
            array[index] = left_temp[left_index];
            // increment to the next element
            ++left_index;
        }
        // otherwise,
        else
        {
            //add the current element of 2nd element to the array
            array[index] = right_temp[right_index];
            // increment to the next element
            ++right_index;
        }

        // increment index to add next element
        ++index;
    }

    // iterate through remaining elements of 1st array and add them
    for( ; left_index < left_length; ++left_index, ++index )
    {
        array[index] = left_temp[left_index];
    }

    // iterate through remaining elements of 2nd array and add them
    for( ; right_index < right_length; ++right_index, ++index )
    {
        array[index] = right_temp[right_index];
    }
}

// Function : merge_sort
// Description : sorts the array using merge sort
// Paramters : array -> pointer to array to be sorted
//             left -> starting index from where to sort
//             right -> end index upto which to sort
// Return Value: void
void merge_sort( int* array, int left, int right )
{
    // if the starting and ending indices are valid,
    if ( left < right )
    {
        // find the middle point between starting and ending index
        int mid = ( right + left ) / 2;

        // resursively sort the left subarray
        merge_sort( array, left, mid);

        // resursively sort the right subarray
        merge_sort( array, mid + 1, right);

        // merge the two sorted arrays
        merge(array, left, mid, right);
    }
}

int main()
{
    // varaible to hold the length of array to be sorted
    int length = 10;

    // array to be sorted
    int array[length] = {3,12,4,13,51,3,5,34,24,1};

    // print the original array
    cout << "Unsorted Array :: \n\t";
    for( int i = 0; i < length; ++i )
        cout << array[i] << " ";
    cout << endl;

    // sort the array
    merge_sort(array, 0, length-1);

    // print the sorted array
    cout << "Sorted Array :: \n\t";
    for( int i = 0; i < length; ++i )
        cout << array[i] << " ";
    cout << endl;

    return 0;
}

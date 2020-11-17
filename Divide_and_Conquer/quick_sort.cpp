#include <iostream>

using namespace std;

// Function : swap
// Description : swaps two elements by their addresses
// Parameters : first_element -> pointer to first element
//              second_element -> pointer to seconf element
// Return Value : void
void swap( int* first_element, int* second_element )
{
    // create a temporary variable to hold the value of first number
    int* temp = first_element;

    // replace the value in first element by that in second number
    first_element = second_element;

    // replace the value in second element by that in the temporary variable
    second_element = temp;
}

// Function : get_partition_index
// Description : places elements such that all element before pivot are smaller
//               than it, and all elements after pivot are larger.
//               It then returns position of pivot element
// Parameters : array -> array to be processed
//              start -> starting index from where to partition
//              end -> ending index upto which to partition
// Return Value : partition_index -> position of pivot after partitioning
int get_partition_index(int* array, int start, int end)
{
    // select the pivot as last element
    int pivot = array[end];

    // initialize the partition index
    int partition_index = start - 1;

    // repeat the following for all elements between start and end
    for ( int j = start; j < end; ++j )
    {
        // if the current element is less than the pivot
        if ( array[j] < pivot )
        {
            // increment the partition index
            ++partition_index;

            // swap the current element in the partitioned part
            swap( array[partition_index], array[j] );
        }
    }

    // increment the partition_index
    ++partition_index;

    // put the pivot in the partitioned part
    swap( array[partition_index], array[end] );

    // return the partition index
    return partition_index;
}

// Function : quick_sort_recursive
// Description : sorts the given array recursively using quick sort
// Parameters : array -> pointer to array to be sorted
//              start -> starting index form where to sort
//              end -> ending index upto which to sort
// Return Value : void
void quick_sort_recursive(int* array, int start, int end)
{
    // the any element if left to be processed
    if ( start < end )
    {
        // partition the array between start and end and get the partition index
        int partition_index = get_partition_index(array, start, end);

        // sort the first partition of array
        quick_sort_recursive(array, start, partition_index - 1);

        // sort the second partition of array
        quick_sort_recursive(array, partition_index + 1, end);
    }
}

// Function : print_array
// Description : prints all elements of the array
// Parameters : array -> pointer to array to be printed
//              length -> number of elements to be printed
// Return Value : void
void print_array(int* array, int length)
{
    // repeat the following for all elements
    for (int i = 0; i < length; ++i)
        // print the current element
        cout << array[i] << " ";
    // goto the next line
    cout << "\n";
}

// MAIN FUNCTION
int main()
{
    // variable to hold the length of array
    int length = 10;

    // array to be sorted using recursion
    int array_recursion[length] = {25, 64, 69, 36, 88, 94, 96, 56, 43, 46};
    // array to be sorted using iteration
    int array_iteration[length] = {25, 64, 69, 36, 88, 94, 96, 56, 43, 46};

    // NOW SORT USING RECURSION
    cout << "\nUsing Recursive Quick Sort ...\n\n";

    // print array before sorting
    cout << " Before Recursion Sorting : ";
    print_array(array_recursion, length);

    // sort the array using recursive quick sort
    quick_sort_recursive(array_recursion, 0, length - 1);

    // print the array after sorting
    cout << "  After Recursion Sorting : ";
    print_array(array_recursion, length);


    return 0;
}

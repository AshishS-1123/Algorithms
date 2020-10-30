#include <iostream>

#define endl "\n";

using namespace std;

// Function : get_max_element
// Description : returns the largest element in array using divide and conquer method
// Paramters : array -> pointer to array to be processed
//             index -> the starting index from where to search
//             length -> length of array to be processed
// Return Value : max -> largest element in array
int get_max_element(int* array, int index, int length)
{
    // create a variable to hold the largest element
    int max = 0;
    
    // if we are dealing with the last or second last element
    if ( index >= length - 2 )
    {
        // compare the second last element with last element
        if ( array[index] > array[index+1] )
            // if last element is larger, return it
            return array[index];
        // else, return second last element
        return array[index+1];
    }
    
    // get the largest element recursivly
    max = get_max_element(array, index + 1, length);
    
    // if the current element is greater than largest element,
    if ( array[index] > max )
        // return current element
        return array[index];
    // else, return largest element
    return max;
}

// Function : get_min_element
// Description : returns the smallest element in array using divide and conquer method
// Paramters : array -> pointer to array to be processed
//             index -> the starting index from where to search
//             length -> length of array to be processed
// Return Value : min -> smallest element in array
int get_min_element(int* array, int index, int length)
{
    // create a variable to hold the smallest element
    int min = 0;
    
    // if we are dealing with last or secodn last element
    if ( index >= length - 2 )
    {
        // if last element is less than second last element
        if ( array[index] < array[index+1] )
            // return last element
            return array[index];
        // else, return second last element
        return array[index+1];
    }
    
    // store smallest element for remaining array
    min = get_min_element(array, index + 1, length);
    
    // if current element is less than current element
    if ( array[index] < min )
        // return current element
        return array[index];
    // else, return smallest element
    return min;
}

int main()
{
    // variable to hold length of array
    int length = 5;
    
    // array to be processed
    int array[length] = {10, 20, 30, 40, 50};
    
    // get the largest element
    int max = get_max_element(array, 0, length);
    // get the smallest element
    int min = get_min_element(array, 0, length);
    
    // print the largest element
    cout << "Max element is " << max << endl;
    // print the smallest element
    cout << "Min element is " << min << endl;
    
    return 0;
}

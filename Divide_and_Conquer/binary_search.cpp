#include <iostream>

using namespace std;

// Function : binary_search
// Description : searches the array to find element using divide and conquer
// Parameters : array -> pointer to array containing elements to be searched
//              start -> starting index in array to be searched
//              end -> ending index in array to be searched
//              key -> value to be searched in array
// Return Value : location of element or -1 if not found
int binary_search(int* array, int start, int end, int key)
{
    // if starting index is lower than ending index, some array is still to be searched
    if ( start <= end )
    {
        // find the middle element in the range to be searched
        int mid = ( start + end ) / 2;
        
        // if element at middle is less than key
        if ( array[mid] > key )
            // search in the left half of array
            return binary_search(array, start, mid-1, key);
        // if middle element is equal to key
        else if ( array[mid] == key )
            // return the middle index
            return mid;
        // if element at middle is greater than key
        else
            // search in right half
            return binary_search(array, mid+1, end, key);
    }
    
    // if no element is left to search, return -1 for Not Found
    return -1;
}

int main()
{
    // variable to hold length of array
    int length = 5;
    
    // array to  be searched
    int array[length] = {10, 20, 30, 40, 50};
    
    // value to be searched
    int key = 30;
    
    // find the element using binary search
    int loc = binary_search(array, 0, length-1, key);
    
    // if the returned value is -1
    if ( loc == -1 )
        // it means element does not exist
        cout << "Could not be found\n";
    // else, print what index was found
    else
        cout << "Element " << key << " found at index " << loc << endl;
        
    return 0;
}

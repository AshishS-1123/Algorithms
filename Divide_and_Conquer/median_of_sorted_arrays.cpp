// import iostream for input output handling
#include <iostream>
// import vector for holding values of sorted arrays
#include <vector>

using namespace std;

// Define a shortform for iterator of vector
#define iterator vector < int > :: iterator

// Function : array_median
// Description : returns the median of a sorted array
// Paramters : array -> iterator for vector containing the sorted values
//             length -> length of the vector
// Return Value : median -> median of the given vector
int array_median( iterator array, int length )
{
    // if there are odd number of elements in the vector
    if( length % 2 != 0 )
        // return the middle element
        return array[ int( length / 2 ) ];
    // otherwise,
    else
        // return the average of the two center elements
        return ( array[ int( length / 2 ) ] + array[ int( length / 2 - 1 ) ] ) / 2;
}

// Function : get_median
// Description : returns the median of two sorted arrays
// Paramters : array_a -> iterator for vector containing first sorted array
//             array_b -> iterator for vector containing second sorted array
//             array_length -> length of both vectors
// Return Value : median -> median of the two sorted arrays
int get_median( iterator array_a, iterator array_b, int array_length )
{
    // if there are no elements in the vector
    if( array_length == 0 )
        // return -1
        return -1;

    // if there is only one element in both arrays
    if( array_length == 1 )
        // return the average of both the elements in the vectors
        return ( array_a[0] + array_b[0] ) / 2;

    // if there are two elements in both arrays
    if( array_length == 2 )
        // return the average of center elements in both the arrays
        return ( max( array_a[0], array_b[0] ) + min( array_a[1], array_b[1] ) ) / 2;

    // FOR THE REMAINING CASES

    // get the index of center-most element in both the arrays
    int mid_length = int( array_length / 2 );

    // calculate the median of first vector
    int median_a = array_median( array_a, array_length );

    // calculate the median of second vector
    int median_b = array_median( array_b, array_length );

    // if both medians are equal,
    if( median_a == median_b )
        // median of resultant will the the same value regardless the number of elements
        return median_a;
    // if median of first vector is larger,
    else if( median_a < median_b )
        // median of resultant will lie between second half of first vector and first half of second vector
        return get_median(array_a + mid_length, array_b, mid_length );
    // if median of second vector is larger,
    else
        // median of resultant will lie between first half of first vector and second half of second vector
        return get_median(array_a, array_b + mid_length, mid_length );

}

// MAIN FUNCTION
int main()
{
    // first vector containing sorted elements
    vector<int> array_a = {1,3,5,7};
    // second vector containing sorted elements
    vector<int> array_b = {2,4,6,8};

    // get the number of elements in the vectors
    int length = array_a.size();

    // print the first vector
    cout << "\n\t First Array ";
    for ( int i = 0; i < length; ++i )
        cout << array_a[i] << " " ;
    cout << "\n";

    // print the second vector
    cout << "\tSecond Array ";
    for ( int i = 0; i < length; ++i )
        cout << array_b[i] << " " ;
    cout << "\n\n";

    // calculate the median of the sorted vectors
    int median = get_median(array_a.begin(), array_b.begin(), length);

    // print the median
    cout << "\tMedian Is :: " << median << "\n";

    return 0;
}

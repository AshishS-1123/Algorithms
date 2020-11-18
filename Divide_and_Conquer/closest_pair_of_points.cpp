#include <bits/stdc++.h>

using namespace std;

// Use the alphabet x to represent first value in pair
#define x first
// Use the alphabet y to represent second value in pair
#define y second

// Rename a Pair of Two Points as Point, this makes code more intuitive
typedef pair< int, int > Point;

// Function : compare_points
// Description : compare function for sorting a vector of points
// Parameters : point_a -> first point to be compared
//              point_b -> second point to be compared
// Return Value : True or False -> whether point_a should come before or after point_b
int compare_points( const Point &point_a, const Point &point_b )
{
    // Compare the x coordinates of the points first, then compare the second point

    // if x coordinate of first point is less than that of second
    if ( point_a.x < point_b.x )
        // return 1 to indicate true
        return 1;
    // if x coordinate of both points is equal,
    else if ( point_a.x == point_b.x )
        // return whether y coordinate of first point is greater than that of second
        return point_a.y < point_b.y;
    // otherwise
    else
        // return 0 to indicate false
        return 0;

}

// Function : distance
// Description : computes and returns the distance between two points
// Parameters : point_a -> first point
//              point_b -> second point
// Return Value : distance -> cartesian distance between the points
float distance( Point a, Point b )
{
    // calculate the cartesian distance between the points
    float distance = ( a.first - b.first ) * ( a.first - b.first );
          distance += ( a.second - b.second ) * ( a.second - b.second );

    // return the distance
    return sqrt( distance );
}

// Function : closest_distance_bruteforce
// Description : calculates the least distance between the points using brute force method
// Parameters : coordinates -> iterator for vector of points that are to computed
//              length -> number of element to be considered for comparing
// Return Value : min_distance -> least distance between a pair of points computed using brute force
float closest_distance_bruteforce( vector < Point > :: iterator coordinates, int length )
{
    // initialize the least distance variable to a large value
    float min_distance = 1e10;

    // repeat the following for all elements in vector
    for ( int i = 0; i < length; ++i)
        // compare the current element with all remaining element in vector
        for ( int j = i + 1; j < length; ++j)
            // if distance between the current 2 points is less than the minimum distance
            if ( distance( coordinates[i], coordinates[j] ) < min_distance )
                // update the min distance
                min_distance = distance( coordinates[i], coordinates[j] );

    // return the minimum distance
    return min_distance;
}

// Function : closest_distance_in_strip
// Description : returns the points with the least distance in the strip
// Parameters : strip -> vector of points to be computed
//              min_distance -> expected value for minimum distance.
//                              Computed distance should be less than this value
// Return Value : min_distance -> least distance between the points
float closest_distance_in_strip( vector < Point > strip, float min_distance )
{
    // create a variable to hold the length of vector
    int length = strip.size();

    // sort the given list of points
    sort( strip.begin(), strip.end(), compare_points);

    // repeat the following for all points in the strip
    for ( int i = 0; i < length; ++i )
        // repeat for remaining points until the y coordinate is within the min_distance range
        for( int j = i + 1; j < length && ( strip[j].second - strip[i].second < min_distance ); ++j)
            // if the distance between the two points is less than the min distance
            if ( distance( strip[i], strip[j] ) < min_distance )
                // update the min_distance with the current value
                min_distance = distance( strip[i], strip[j] );

    // return the minimum distance
    return min_distance;
}

// Function : least_dist_in_subarray
// Description : recursively calculates the least distance between between two points
// Parameters : coordinates -> iterator for vector if points
//              length -> size of the vector
// Return Value : True or False -> whether point_a should come before or after point_b
float least_dist_in_subarray( vector < Point > :: iterator coordinates, int length )
{
    // if number of points to be computed is less than 4, brute force method can be used
    if ( length < 4 )
        // use the brute force method to calculate the least distance
        return closest_distance_bruteforce( coordinates, length );

    // calculate the position of middle element
    int mid_index = int( length / 2 );

    // recursively calculate the least distance between the left sub-vector
    float least_distance_left_subarray = least_dist_in_subarray(coordinates, mid_index);
    // recursively calculate the least distance between the right sub-vector
    float least_distance_right_subarray = least_dist_in_subarray(coordinates + mid_index, length - mid_index);

    // get the upper limit for minimum distance. this will be the threshold for calculating strip of points
    float threshold_distance = min( least_distance_left_subarray, least_distance_right_subarray );

    // create a vector to hold the points lying inside the strip
    vector < Point > points_within_strip;

    // get the points at the center of the vector
    Point mid_point = coordinates[ mid_index ];

    // repeat the folowinf got all points in vector, for constructing the strip
    for ( int i = 0; i < length; ++i )
        // if current point is within threshold on left of mid_point
        if ( coordinates[i].first - mid_point.first < threshold_distance )
            // add this point to the strip
            points_within_strip.push_back( coordinates[i] );
        // if current point is within threshold on right of the mid_point
        else if ( mid_point.first - coordinates[i].first < threshold_distance )
            // add this point to the strip
            points_within_strip.push_back( coordinates[i] );

    // get the least distance from the strip and return this value
    return min( threshold_distance, closest_distance_in_strip(points_within_strip, threshold_distance) );
}

// Function : get_closest_distance
// Description : auxilary function for calling the recursive function least_dist_in_subarray
// Parameters : coordinates -> vector of points to be computed
// Return Value : distance -> least distance between these points
float get_closest_distance( vector < Point > coordinates)
{
    // create a variable to hold the size of vector
    int length = coordinates.size();

    // sort the points in increasing order
    sort( coordinates.begin(), coordinates.end(), compare_points );

    // compute the least distance for te=he vector and return it
    return least_dist_in_subarray( coordinates.begin(), length );
}

//  MAIN FUNCTION
int main()
{
    // create a variable to hold the number of elements in the vector
    int length = 5;

    // store all the points in a vector
    vector< Point > coordinates = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {3, 4}};

    // print the current elements in the vector
    cout << "\nGiven Points Are :: ";
    for( int i = 0; i < length; ++i)
        cout << " {" << coordinates[i].first << "," << coordinates[i].second << "} ";
    cout << "\n";

    // get the least distance between the points in the vector
    float distance = get_closest_distance( coordinates );

    // print this value to terminal
    cout << "\n\tLeast Distance Between These Points Is :: " << distance << "\n";

    return 0;
}

// import iostream for input handling
#include <iostream>
// import vector for storing time values
#include <vector>
// import algorithm for sorting vector
#include <algorithm>

using namespace std;

// create a shortcut for holding the start and times of an activity
typedef pair < int, int > activity;
// rename first element of pair as start_time
#define start_time first
// rename second element of pair as end_time
#define end_time second

// Function : compare_activities
// Description : compares two activities by their end times, used for sorting
// Parameters : a -> first activity to be compared
//              b -> second activity to be compared
// Return Value : true if end time of 'a' is less than that of 'b'
int compare_activities( activity a, activity b )
{
    // compare end times of 'a' and 'b' and return truth value
    return a.end_time < b.end_time;
}

// Function : get_optimal_activities
// Description : returns a vector max possible activities that can be performed
// Parameters : activities -> vector of activities available
// Return Value : optimal_activities -> vector of optimal activities that can be performed
vector < activity > get_optimal_activities( vector < activity > activities )
{
    // create a vector to hold the list of optimal avtivities that can be  performed
    vector < activity > optimal_activities;
    // create a variable to store the total number of activities tha can be performed
    int number_of_optimal_activities = 0;

    // get the number of elements in the vector
    int length = activities.size();

    // sort the list of activities by their end times
    sort( activities.begin(), activities.end(), compare_activities );

    // select the first element of sorted vector as first activity to be performed
    optimal_activities.push_back( activities[0] );

    // repeat the following for the rest of the activities
    for ( int i = 1; i < length; ++i )
    {
        // if the current activity start after or at same time as last optimal activity,
        if ( activities[i].start_time >= optimal_activities[ number_of_optimal_activities ].end_time )
        {
            // add this activity to the list of activities to be performed
            optimal_activities.push_back( activities[i] );
            // increment the number of activities that can be performed
            ++number_of_optimal_activities;
        }
    }

    // return the vector containing the list of optimal activiites
    return optimal_activities;
}

// MAIN FUNCTION
int main()
{
    // create a vector to hold the list of all activities
    vector < activity > activities = { {1, 2}, {3, 4}, {0, 6}, {5,7}, {8,9}, {5,9} };

    // print the start and end times of all available activities
    cout << "\n Available Activity Timings Are ::\n\t\t";
    for( int i = 0; i < activities.size(); ++i )
        cout << " {" << activities[i].start_time << " , " << activities[i].end_time << " }";
    cout << "\n";

    // get the list of optimal activities that can be performed
    vector<activity> optimal = get_optimal_activities(activities);

    // print the start and end times of optimal activities
    cout << "\n Optimal Activities To Perform Are ::\n\t\t";
    for( int i = 0; i < optimal.size(); ++i )
        cout << " {" << optimal[i].start_time << " , " << optimal[i].end_time << " }";
    cout << "\n";

    return 0;
}

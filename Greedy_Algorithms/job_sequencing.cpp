// import iostream for input output handling
#include <iostream>
// import vector for storing list of jobs
#include <vector>
// import algorithm for sorting vector
#include <algorithm>

using namespace std;

// create a shortform for job as pair of deadline and profit
typedef pair < int, int > job;

// rename the first item of job as deadline
#define deadline first
// rename the second item of job as the profit
#define profit second

// Function : compare_jobs
// Description : compares two jobs by their profits
// Parameters : a -> first job to be compared
//              b -> second job to be compared
// Return Value : true if a has higher profit than b
int compare_jobs( job a, job b )
{
    // return the truth value of whether a has higher profit than b
    return a.profit > b.profit;
}

// Function :  get_optimal_job_sequence
// Description : return the optimal order of performing jobs to get maximum profit
// Parameters : jobs-> vector containing list of jobs to be performed
// Return Value : optimal_jobs -> vector containing order of jobs to be performed
vector < job > get_optimal_job_sequence( vector < job > jobs )
{
    // get the number of jobs to be performed
    int number_of_jobs = jobs.size();

    // create a vector to store optimal orderof performing jobs
    vector < job > optimal_jobs(number_of_jobs);

    // array to store whether a time slot is available for performing a job
    bool slot_available[ number_of_jobs ];

    // set the default value of slots as true (available)
    for ( int i = 0; i < number_of_jobs; ++i )
        slot_available[i] = true;

    // sort the jobs in decreasing order of their profit
    sort( jobs.begin(), jobs.end(), compare_jobs);

    // repeat the following for all the jobs
    for ( int i = 0; i < number_of_jobs; ++i )
    {
        // get the maximum possible time we can start the job from based on the deadline
        int max_start_time = min( number_of_jobs, jobs[i].deadline ) - 1;

        // repeat the following for all the slots that come before the deadline
        for( int j = max_start_time; j > -1; --j)
        {
            // if the current slot is available
            if ( slot_available[j] )
            {
                // add this job to the optimal list of jobs
                optimal_jobs[j] = jobs[i];
                // mark the current slot as unavailable
                slot_available[j] = false;
                // break out of the loop and move onto to next job
                break;
            }
        }
    }

    // return the list of optimal jobs to be performed
    return optimal_jobs;
}

int main()
{
    // create a vector to hold the available jobs profits and deadlines
    vector < job > jobs = { { 2, 100 }, { 1, 19 }, { 2, 27 }, { 1, 25 }, { 3, 15 } };

    // print the deadlines and profits of all available jobs
    cout << "\n Available Job Deadlines and their Profits are ::\n\t";
    for ( int i = 0; i < jobs.size(); ++i )
        cout << " { " << jobs[i].deadline << " , " << jobs[i].profit << " }";
    cout << "\n";

    // get the optimal order of jobs and their profits
    vector < job > optimal_jobs = get_optimal_job_sequence( jobs );

    // print the deadlines and profits of optimal list of jobs
    cout << "\n Optimal Job Deadlines and their Profits are ::\n\t";
    for ( int i = 0; i < optimal_jobs.size(); ++i )
        if ( optimal_jobs[i].deadline != 0 )
        cout << " { " << optimal_jobs[i].deadline << " , " << optimal_jobs[i].profit << " }";
    cout << "\n";

    return 0;
}

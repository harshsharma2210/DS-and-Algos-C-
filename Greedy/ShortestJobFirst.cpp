// Program for Shortest Job First (or SJF) CPU Scheduling | Set 1 (Non- preemptive)
// Difficulty Level : Easy
// Last Updated : 15 Jun, 2021

// Shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. SJN is a non-preemptive algorithm.

// Shortest Job first has the advantage of having a minimum average waiting time among all scheduling algorithms.
// It is a Greedy Algorithm.
// It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing.
// It is practically infeasible as Operating System may not know burst time and therefore may not sort them. While it is not possible to predict execution time, several methods can be used to estimate the execution time for a job, such as a weighted average of previous execution times. SJF can be used in specialized environments where accurate estimates of running time are available.
// Algorithm:

// Sort all the process according to the arrival time.

// Then select that process which has minimum arrival time and minimum Burst time.

// After completion of process make a pool of process which after till the completion of previous process and select that process among the pool which is having minimum Burst time.

// How to compute below times in SJF using a program?

// Completion Time: Time at which process completes its execution.
// Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time
// Waiting Time(W.T): Time Difference between turn around time and burst time.
// Waiting Time = Turn Around Time – Burst Time
// In this post, we have assumed arrival times as 0, so turn around and completion times are same.

// C++ program to implement Shortest Job first with Arrival Time
// Program for SJF(shortest job first) CPU Scheduling
// This is a non-preemptive scheduling

#include <bits/stdc++.h>
using namespace std;

// Structure for Process in RAM
class process
{
public:
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
};

bool sortByArrival(process a, process b)
{
    return a.arrival_time < b.arrival_time;
}

bool sortById(process a, process b)
{
    return a.id < b.id;
}

// to set priority_queue comparision criteria as burst_time
class compare
{
public:
    bool operator()(process *a, process *b)
    {
        return a->burst_time > b->burst_time;
    }
};

int main()
{
    int n;
    cout << "Enter no of processes: ";
    cin >> n;

    process p[n];
    cout << "\nEnter burst and arrival time for " << n << " processes: \n";
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        cout << "Process " << i + 1 << " :\nArrival time- ";
        cin >> p[i].arrival_time;
        cout << "Burst time- ";
        cin >> p[i].burst_time;
        cout << endl;
    }

    sort(p, p + n, sortByArrival);

    priority_queue<process *, vector<process *>, compare> readyQueue; // min heap based on burst_time
    int timeElapsed = 0, processesLeft = n, toBeInserted = 0, i;

    // Executing all processes
    while (processesLeft)
    {

        for (i = toBeInserted; i < n && p[i].arrival_time <= timeElapsed; i++)
        {
            readyQueue.push(p + i); // adding process to ready queue
        }
        toBeInserted = i;

        // finding the process to execute in the ready queue
        if (readyQueue.empty())
        { // ready queue is empty

            timeElapsed = p[toBeInserted].arrival_time;
        }
        else
        {

            process *processToExecute = readyQueue.top();

            (*processToExecute).waiting_time = timeElapsed - (*processToExecute).arrival_time;
            timeElapsed += processToExecute->burst_time;
            (*processToExecute).completion_time = timeElapsed;

            readyQueue.pop(); // removing process from ready queue
            processesLeft--;  // reducing the number of process left to execute
        }
    }

    sort(p, p + n, sortById);

    // printing values
    double avgWaitingTime = 0;
    printf("    Process \t Arrival Time \t Burst Time \t Waiting Time \t Completion Time\n\n");
    for (int i = 0; i < n; i++)
    {

        cout << "\t" << p[i].id << "\t\t" << p[i].arrival_time << "\t\t" << p[i].burst_time << "\t\t" << p[i].waiting_time << "\t\t" << p[i].completion_time << endl;
        avgWaitingTime += p[i].waiting_time;
    }
    avgWaitingTime /= n;

    cout << "\nAverage waiting time: " << avgWaitingTime;
    return 0;
}
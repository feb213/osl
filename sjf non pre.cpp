#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    // Declare arrays
    int at[n];   // Arrival Time
    int bt[n];   // Burst Time
    int ct[n];   // Completion Time
    int tat[n];  // Turnaround Time
    int wt[n];   // Waiting Time

    bool completed[n]; // Track completed processes

    // ===== INPUT SECTION =====
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Arrival Time and Burst Time for P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
        completed[i] = false;
    }

    int time = 0;
    int done = 0;

    // ===== MAIN SJF LOGIC =====
    while(done < n)
    {
        int minBT = 9999;
        int index = -1;

        // Check all processes
        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == false)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    index = i;
                }
            }
        }

        if(index != -1)
        {
            time = time + bt[index];

            ct[index] = time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            completed[index] = true;
            done++;
        }
        else
        {
            time++;
        }
    }

    // ===== OUTPUT SECTION =====
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }
 cout<<"sjf non pre";    
    return 0;
}

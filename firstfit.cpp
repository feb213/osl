#include<iostream>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];

    // Initially no allocation
    for(int i = 0; i < n; i++)
        allocation[i] = -1;

    // Allocate processes
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";

    for(int i = 0; i < n; i++)
    {
        if(allocation[i] != -1)
            cout << "Process " << i+1 << " -> Block " << allocation[i]+1 << endl;
        else
            cout << "Process " << i+1 << " -> Not Allocated" << endl;
    }
}

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = 5;
    int n = 4;

    firstFit(blockSize, m, processSize, n);

    return 0;
}

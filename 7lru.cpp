#include<iostream>
using namespace std;

void LRU(int pages[], int n, int frames)
{
    int frame[10];

    int time[10];

    int faults = 0;

    int counter = 0;

    // Initialize frames
    for(int i = 0; i < frames; i++)
    {
        frame[i] = -1;

        time[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int found = 0;

        // Check if page already exists
        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                counter++;

                time[j] = counter;

                found = 1;

                break;
            }
        }

        // Page Fault
        if(!found)
        {
            int min = 0;

            for(int j = 1; j < frames; j++)
            {
                if(time[j] < time[min])
                    min = j;
            }

            frame[min] = pages[i];

            counter++;

            time[min] = counter;

            faults++;
        }
    }

    cout << "LRU Page Faults = " << faults << endl;
}

int main()
{
    int pages[] = {7,0,1,2,0,3,0,4};

    int n = 8;

    int frames = 3;

    LRU(pages, n, frames);

    return 0;
}

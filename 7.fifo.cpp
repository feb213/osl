#include<iostream>
using namespace std;

bool isPresent(int frame[], int frames, int page)
{
    for(int i = 0; i < frames; i++)
    {
        if(frame[i] == page)
            return true;
    }

    return false;
}

void FIFO(int pages[], int n, int frames)
{
    int frame[10];

    int index = 0;

    int faults = 0;

    // Initialize frames
    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    for(int i = 0; i < n; i++)
    {
        if(!isPresent(frame, frames, pages[i]))
        {
            frame[index] = pages[i];

            index = (index + 1) % frames;

            faults++;
        }
    }

    cout << "FIFO Page Faults = " << faults << endl;
}

int main()
{
    int pages[] = {7,0,1,2,0,3,0,4};

    int n = 8;

    int frames = 3;

    FIFO(pages, n, frames);

    return 0;
}

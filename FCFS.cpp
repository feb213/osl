#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter AT and BT for P"<<i+1<<": ";
        cin>>at[i]>>bt[i];
    }

    int time=0;

    for(int i=0;i<n;i++)
    {
        if(time<at[i])
            time=at[i];

        time+=bt[i];
        ct[i]=time;

        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
    
    cout<<"FCFS";
}

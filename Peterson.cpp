#include<iostream>
#include<thread>

using namespace std;

int flag[2] = {0,0};

int turn;

int shared = 0;

void process1()
{
    flag[0] = 1;

    turn = 1;

    while(flag[1] && turn == 1);

    cout<<"Process 1 Entering Critical Section"<<endl;

    shared++;

    cout<<"Shared Value = "<<shared<<endl;

    cout<<"Process 1 Leaving Critical Section"<<endl;

    flag[0] = 0;
}

void process2()
{
    flag[1] = 1;

    turn = 0;

    while(flag[0] && turn == 0);

    cout<<"Process 2 Entering Critical Section"<<endl;

    shared++;

    cout<<"Shared Value = "<<shared<<endl;

    cout<<"Process 2 Leaving Critical Section"<<endl;

    flag[1] = 0;
}

int main()
{
    thread t1(process1);

    thread t2(process2);

    t1.join();

    t2.join();

    cout<<"Final Shared Value = "<<shared;

    return 0;
}

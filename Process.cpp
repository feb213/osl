#include<iostream>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;

void processManagement()
{
    cout << "\n===== PROCESS MANAGEMENT =====\n";

    pid_t pid;

    // Create Child Process
    pid = fork();

    if(pid < 0)
    {
        cout << "Fork failed\n";
        return;
    }

    else if(pid == 0)
    {
        // Child Process
        cout << "Child Process Running\n";

        cout << "Child PID: " << getpid() << endl;

        // Execute Linux Command
        execl("/bin/ls", "ls", NULL);

        cout << "Execution failed\n";
    }

    else
    {
        // Parent Process
        wait(NULL);

        cout << "Parent Process Running\n";

        cout << "Parent PID: " << getpid() << endl;
    }
}

int main()
{
    processManagement();

    return 0;
}
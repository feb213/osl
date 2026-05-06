#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

using namespace std;

void directoryManagement()
{
    cout << "\n===== DIRECTORY MANAGEMENT =====\n";

    // Create Directory
    mkdir("MyDirectory", 0777);

    cout << "Directory created\n";

    // Change Directory
    chdir("MyDirectory");

    cout << "Changed to MyDirectory\n";

    // Display Current Path
    char path[100];

    getcwd(path, sizeof(path));

    cout << "Current Directory Path: " << path << endl;

    // Go back to parent directory
    chdir("..");

    // List Directory Contents
    DIR *dir;

    struct dirent *entry;

    dir = opendir(".");

    cout << "\nDirectory Contents:\n";

    while((entry = readdir(dir)) != NULL)
    {
        cout << entry->d_name << endl;
    }

    closedir(dir);

    // Remove Directory
    rmdir("MyDirectory");

    cout << "Directory removed successfully\n";
}

int main()
{
    directoryManagement();

    return 0;
}
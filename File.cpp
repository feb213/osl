file #include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>

using namespace std;

void fileManagement()
{
    cout << "\n===== FILE MANAGEMENT =====\n";

    int fd;

    // Create File
    fd = creat("demo.txt", 0777);

    if(fd < 0)
    {
        cout << "File creation failed\n";
        return;
    }

    cout << "File created successfully\n";

    // Write into File
    const char *data = "Hello Operating System";

    write(fd, data, strlen(data));

    cout << "Data written successfully\n";

    close(fd);

    // Open File in Read Mode
    fd = open("demo.txt", O_RDONLY);

    char buffer[100];

    int bytes = read(fd, buffer, sizeof(buffer));

    buffer[bytes] = '\0';

    cout << "Data from file: " << buffer << endl;

    close(fd);

    // Delete File
    unlink("demo.txt");

    cout << "File deleted successfully\n";
}

int main()
{
    fileManagement();

    return 0;
}
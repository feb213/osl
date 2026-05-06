#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int flag[2] = {0, 0};
int turn;
int shared = 0;

void *process1(void *arg)
{
    flag[0] = 1;
    turn = 1;

    while (flag[1] && turn == 1);

    printf("Process 1 entering Critical Section\n");

    shared++;
    printf("Shared Value = %d\n", shared);

    printf("Process 1 leaving Critical Section\n");

    flag[0] = 0;

    return NULL;
}

void *process2(void *arg)
{
    flag[1] = 1;
    turn = 0;

    while (flag[0] && turn == 0);

    printf("Process 2 entering Critical Section\n");

    shared++;
    printf("Shared Value = %d\n", shared);

    printf("Process 2 leaving Critical Section\n");

    flag[1] = 0;

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, process1, NULL);
    pthread_create(&t2, NULL, process2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Shared Value = %d\n", shared);

    return 0;
}
